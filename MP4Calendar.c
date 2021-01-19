#include <stdio.h>
#include <math.h>

void func1(int,int,int); //function for julian calendar
void func2(int,int); //function for gregorian calendar
int isValid1(int,int,int); //valid checker function for day, month and year
int isValid2(int,int); //valid checker function for the year and the number of days in it


int main(){
    char date[100];
    int day, month, year;
    int choice, cases, loop;
        printf("Input the Number of test cases: ");
        scanf("%d", &cases);
        for(loop=0; loop < cases; loop++){ //loops the menu until loop reaches the number of test cases
        printf("====================================\n");
        printf("[MENU]:\n1. JULIAN (Day/Month/Year)\n2. GREGORIAN (Day of the Year/Year)\nAny other number will terminate\n====================================\n[INPUT]: ");
        scanf("%d", &choice);
        if(choice<=0 || choice>2){
            break;
        }
            switch(choice){
                case 1:
                printf("Enter Date: Day/Month/Year\n");
                printf("Day: ");
                scanf("%d", &day);
                printf("Month: ");
                scanf("%d", &month);
                printf("Year: ");
                scanf("%d", &year);
                while(isValid1(day,month,year)==0){ //all three variables must have inputs first before checking for their validity
                    printf("INVALID Input. Try Again.\n");
                    printf("Day: ");
                    scanf("%d", &day);
                    printf("Month: ");
                    scanf("%d", &month);
                    printf("Year: ");
                    scanf("%d", &year);
                }
                func1(day,month,year);
                break;

                case 2:
                printf("Enter Date: Day of the Year/Year\n");
                printf("Day of the Year: ");
                scanf("%d", &day);
                printf("Year: ");
                scanf("%d", &year);
                while(isValid2(day,year)==0){  //all two variables must have inputs first before checking for their validity
                    printf("INVALID Input. Try Again.\n");
                    printf("Day: ");
                    scanf("%d", &day);
                    printf("Year: ");
                    scanf("%d", &year);
                }
                func2(year, day);
                break;
            }
        }
        printf("====================================\n");
        printf("  XXXXX Program Terminated. XXXXX\n");
        printf("====================================\n");
    return 0;
}

void func1(int d,int m,int y){
    int table[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
    //the zeroth month is present so as to align the actual corresponding digits of 1-12 to the array since numbering always starts with 0
    char days[][10]={"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
    char ordinal[][10]={"st", "nd", "rd", "th"};
    int i,j,a,b,e,f,week,finalWeek,finalDay=0,temp = m, day;
    float c,jd;
    if(m==1||m==2){ //if month is January or February, year will be decremented 1 and month will be incremented 12 to get a new y and m
        y-=1;
        temp=m+12; //new m will be stored in a temp variable so as finalWeek and finalDay results will not vary
    }
    a=y/100;
    b=a/4;
    c=2-a+b;
    e=365.25*(y+4716);
    f=30.6001*(temp+1);
    jd=c+d+e+f-1524.5;
    //JD ends in .5 because the Julian Day begins at noon, Greenwich time which is why a half day extra is always given 
    week=ceil(jd); //ceiling function is used as the decimals that follow jd will be rounded up to the nearest integer
    finalWeek=(week%7); //getting the modulo 7 of the ceiling of jd helps us find out which day of the week it is
    if(y%4==0&&y%100!=0||y%400==0){ //checks if leap year and counts the number of days in the year starting with 1
        for(i=0;i<m;i++){
            finalDay+=table[1][i];
        }
        finalDay+=d;
    }else{ //if not leap year then number of days will be counted starting with 0
        for(i=1;i<m;i++){
            finalDay+=table[0][i];
        }
        finalDay+=d;
    }
    day = finalDay%10; //appends the appropriate suffixes for the days in a year
    switch(day){
        case 1: 
        j = 0;
        break;

        case 2:
        j = 1;
        break;

        case 3:
        j = 2;
        break;

        default:
        j = 3;
        break;
    }
    printf("[OUTPUT]: %s, %d%s day\n", days[finalWeek], finalDay, ordinal[j]);
}

void func2(int year, int yearday){
    int table[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
    char days[][10]={"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
    char months[][10]={"January","February","March","April","May","June","July","August","September","October","November","December"}; 
    int i,leap,a,b,e,f,week,finalWeek,temp;
    float c,jd;
    leap = year % 4 == 0 && year%100 != 0 || year%400 == 0;
    for(i=1;yearday > table[leap][i];i++){ //we subtract days of each month from the day, till the day is lesser than days in that month
        yearday -= table[leap][i];
    }
    temp = i;
    if(i==1||i==2){
        year-=1;
        temp=i+12;
    }
    a=year/100;
    b=a/4;
    c=2-a+b;
    e=365.25*(year+4716);
    f=30.6001*(temp+1);
    jd=c+yearday+e+f-1524.5;
    week=ceil(jd);
    finalWeek=(week%7);
    printf("[OUTPUT]: %s, %s %d\n", days[finalWeek], months[i-1], yearday);

}

int isValid1(int d, int m, int y){ //validity checker for the years, months and their corresponding days
int count = 0;
int newyear = y; //y will be stored in a new temporary variable so as to not change the original value of y
    while(newyear!=0){
        newyear= newyear/10;
        ++count;
    }
    if(count == 4){
        if (m >=1 && m <= 12){ //a series of if- statements that correspond to each month's designated number of days and etc.
            if((d>=1 && d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)){
                return 1;
            }else if((d>=1 && d<=3) && (m==4 || m==6 || m==9 || m==11)){
                return 1;
            }else if((d>=1 && d<=28) && (m==2)){
                return 1;
            }else if((d==29 && m==2) && (y%400==0 || (y%4==0 && y%100!=0))){
                return 1;
            }else{
                return 0;
            }
        }
    }else{
        return 0;
    }
}

int isValid2(int d, int y){ //validity checker for year and the days in a year
int count = 0;
int newyear = y; //y will be stored in a new temporary variable so as to not change the original value of y
    while(newyear!=0){
        newyear= newyear/10;
        ++count;
    }
    if(count == 4){ //makes sure number of digits in year is 4 and day values are not less than 1 and greater than 366
        if((d==366) && (y%400==0 || (y%4==0 && y%100!=0))){ //allows day input 366 only if year input is a leap year
            return 1;
        }else if(d>=1 && d<=365){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}
