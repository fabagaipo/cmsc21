#include <stdio.h>

int logBase10Esimate(int n);
int floor(float n);
int ceiling(float n);
int isAlNum(char ch);
int isAlpha(char ch);
int isUpper(char ch);
int isLower(char ch);
char toUpper(char ch);
char toLower(char ch);
int isPunctuation(char ch);
int toInteger(char st[]);
float toFloat(char st[]);
int isFloat(char st[]);
int abs(int n);
void stringCopy(char src[], char dest[]);
int subString(char s1[], char s2[]);
int stringCompare(char s1[], char s2[]);
void camelCase(char st[]);
void reverse1 (char st[]);
int reverse2(int n);
int humbleNumber(int n);

int main(void){
    int input;
    int n;
    float y;
    char a, b[1000], c[1000];

        printf("===============================\n");
        printf("Menu:\n\t1. logBase10Estimate\n\t2. floor\n\t3. ceiling\n\t4. isAlNum\n\t5. isAlpha\n\t6. isUpper\n\t7. isLower\n\t8. toUpper\n\t9. toLower\n\t10. isPunctuation\n\t11. toInteger\n\t12. toFloat\n\t13. isFloat\n\t14. abs\n\t15. stringCopy\n\t16. substring\n\t17. stringCompare\n\t18. camelCase\n\t19. reverse(s)\n\t20. reverse(i)\n\t21. humbleNumber\n===============================\nAny number outside 1 to 21. Exit.\n===============================\nChoose one: ");
        scanf ("%d",&input);

        while (input>0 && input<22){

        switch(input){

            case 1:
                printf("===============================\n\n");
                printf("Enter a positive integer: ");
                scanf("%d", &n);
                printf("\nOUTPUT: %d\n",logBase10Esimate(n));
                printf("===============================\n\n");
                break;
                
            case 2:
                printf("===============================\n\n");
                printf("Enter a value: ");
                scanf("%d", &n);
                printf("\nOUTPUT: %d\n", floor(n));
                printf("===============================\n\n");
                break;

            case 3:
                printf("===============================\n\n");
                printf("Enter a value: ");
                scanf("%d", &n);
                printf("\nOUTPUT: %d\n", ceiling(n));
                printf("===============================\n\n");
                break;

            case 4:
                printf("===============================\n\n");
                printf("Enter a character: ");
                scanf("%s", &a);
                printf("\nOUTPUT: %d\n", isAlNum(a));
                printf("===============================\n\n");
                break;

            case 5:
                printf("===============================\n\n");
                printf("Enter a character: ");
                scanf("%s", &a);
                printf("\nOUTPUT: %d\n", isAlpha(a));
                printf("===============================\n\n");
                break;

            case 6:
                printf("===============================\n\n");
                printf("Enter a character: ");
                scanf("%s", &a);
                printf("\nOUTPUT: %d\n", isUpper(a));
                printf("===============================\n\n");
                break;

            case 7:
                printf("===============================\n\n");
                printf("Enter a character: ");
                scanf("%s", &a);
                printf("\nOUTPUT: %d\n", isLower(a));
                printf("===============================\n\n");
                break;

            case 8:
                printf("===============================\n\n");
                printf("Enter a character: ");
                scanf("%s", &a);
                printf("\nOUTPUT: %c\n", toUpper(a));
                printf("===============================\n\n");
                break;

            case 9:
                printf("===============================\n\n");
                printf("Enter a character: ");
                scanf("%s", &a);
                printf("\nOUTPUT: %c\n", toLower(a));
                printf("===============================\n\n");
                break;

            case 10:
                printf("===============================\n\n");
                printf("Enter a character: ");
                scanf("%s", &a);
                printf("\nOUTPUT: %d\n", isPunctuation(a));
                printf("===============================\n\n");
                break;

            case 11:
                printf("===============================\n\n");
                printf("Enter a string of integers: ");
                scanf("%s",&b);
                printf("\nOUTPUT: %d\n",toInteger(b));
                printf("===============================\n\n");
                break;

            case 12:
                printf("===============================\n\n");
                printf("Enter a string of float: ");
                scanf("%s",&b);
                printf("\nOUTPUT: %f\n",toFloat(b));
                printf("===============================\n\n");
                break;
            
            case 13:
                printf("===============================\n\n");
                printf("Enter a value: ");
                scanf("%s",&b);
                printf("\nOUTPUT: %d\n",isFloat(b));
                printf("===============================\n\n");
                break;

            case 14:
                printf("===============================\n\n");
                printf("Enter an integer: ");
                scanf("%d",&n);
                printf("\nOUTPUT: %d\n",abs(n));
                printf("===============================\n\n");
                break;

            case 15:
                printf("===============================\n\n");
                printf("Enter a string: src[]: ");
                scanf(" %999[^\n]s", &b);
                stringCopy(b,c);
                printf("\nOUTPUT: dest[]: %s\n", c);
                printf("===============================\n\n");
                break;

            case 16:
                printf("===============================\n\n");
                printf("Enter first: ");
                scanf(" %999[^\n]s", &b);
                printf("Enter second: ");
                scanf(" %999[^\n]s", &c);
                printf("\nOUTPUT: %d\n", subString(b,c));
                printf("===============================\n\n");
                break;

            case 17:
                printf("===============================\n\n");
                printf("Enter a string: ");
                scanf("%s",&b);
                printf("\nEnter another string: ");
                scanf("%s",&c);
                if(stringCompare(b,c) == 0){
                    printf("\nOUTPUT: 0\n");
                }else if (stringCompare(b,c) == 1){
                    printf("\nOUTPUT: -1\n");
                }else{
                    printf("\nOUTPUT: 1\n");
                }
                printf("===============================\n\n");
                break;

            case 18:
                printf("===============================\n\n");
                printf("Enter a string: ");
                scanf(" %999[^\n]s", &b);
                camelCase(b);
                printf("\nOUTPUT: %s\n", b);
                printf("===============================\n\n");
                break;
                
            case 19:
                printf("===============================\n\n");
                printf("Enter a string: ");
                scanf(" %999[^\n]s", &b);
                reverse1(b);
                printf("===============================\n\n");
                break;

            case 20:
                printf("===============================\n\n");
                printf("Enter an integer: ");
                scanf("%d",&n);
                printf("\nOUTPUT: %d\n", reverse2(n));
                printf("===============================\n\n");
                break;

            case 21:
                printf("===============================\n\n");
                printf("Enter an integer: ");
                scanf("%d",&n);
                printf("\nOUTPUT: %d\n", humbleNumber(n));
                printf("===============================\n\n");
                break;
            }
        printf("===============================\n");
        printf("Menu:\n\t1. logBase10Estimate\n\t2. floor\n\t3. ceiling\n\t4. isAlNum\n\t5. isAlpha\n\t6. isUpper\n\t7. isLower\n\t8. toUpper\n\t9. toLower\n\t10. isPunctuation\n\t11. toInteger\n\t12. toFloat\n\t13. isFloat\n\t14. abs\n\t15. stringCopy\n\t16. substring\n\t17. stringCompare\n\t18. camelCase\n\t19. reverse(s)\n\t20. reverse(i)\n\t21. humbleNumber\n===============================\nAny number outside 1 to 21. Exit.\n===============================\nChoose one: ");
        scanf ("%d",&input);
        }
    printf("===============================\n");
    printf("Exiting...\n");
    printf("===============================\n");
    return 0;
}

int logBase10Esimate(int n){
    int i;
    int counter=0;
    do{
        n = n / 10;
        counter++;
    } while (n > 9);
    return(counter);
}

int floor(float n){
    int i = n;
    return i;
}

int ceiling(float n){
    int i = n;
    if (n>i){
        i++;
    }
    return i;
}

int isAlNum(char ch){
    int i = 0;
    if((ch >='A' && ch <='Z')||(ch >= 'a' && ch <= 'z')){
        i = 1;
        return 1;
    }else if(ch >= '0' && ch <= '9'){
        i = 1;
        return 1;
    }else{
        return 0;
    }
}

int isAlpha(char ch){
    int i = 0;
    if((ch >='A' && ch <='Z') || (ch >= 'a' && ch <= 'z')){
        i = 1;
        return 1;
    }else{
        return 0;
    }
}

int isUpper(char ch){
    int i = 0;
    if(ch >='A' && ch <='Z'){
        i = 1;
        return 1;
    }else{
        return 0;
    }
}

int isLower(char ch){
    int i = 0;
    if(ch >= 'a' && ch <= 'z'){
        i = 1;
        return 1;
    }else{
        return 0;
    }
}

char toUpper(char ch){
    if (ch >= 'a' && ch <= 'z'){
        ch = ch - 32;
    }
    return(ch);
}

char toLower(char ch){
    if (ch >= 'A' && ch <= 'Z'){
        ch = ch + 32;
    }
    return(ch);
}

int isPunctuation(char ch){
    int i = 0;
    if (ch >= 33 && ch <= 47 || ch >= 58 && ch <=64 || ch >=91 && ch <=96|| ch>=123 && ch<=126){
            i = 1;
            return 1;
    }else{
        return 0;
    }
}

int toInteger(char st[]){
    int j = 0; 
    int k = 1;
    if(st[0]== '-'){
        k = -1;
    }for(int i = 0; st[i]!='\0'; i++){
        if(st[i]!= '-'){
            if(st[i]!= '.'){
                j *= 10;
                j = j + st[i] - 48;
            }else{
                break;
            }
        }
    }

    return (j*k);
}

float toFloat(char st[]){
    int i;
    int a = 0, b = 0, j = 0;
    double x = 0;

    for(i = 0; st[i] != '\0'; i++){
        if(st[i] != '-' && st[i] != '.'){
            j++;
        }
    }
    for(int i = 0 ; st[i] != '\0'; i++){
        if(st[i] != '.'){
            a++;
        }else{
            break;
        }
    }
    if(st[0] == '-'){
        a--;
    }

    b = j - a;

    for(i = 0; st[i]!='\0'; i++){
        if(st[i]!= '-'){
            if(st[i]!= '.'){
                x *= 10;
                x = x + st[i]-48;
            }
        }
    }
    int deci = 1;
    int l = 1;
    while(b > 0){
        deci *= 10;
        b--;
    }

    return l*(x/deci);
}

int isFloat(char st[]){
    int i;
    int comp;
    int check = 0;
    int length = 0;
    while(st[length] != '\0'){
        length++;
    }
    for(i = 0; i <= length; i++){
        if(st[i] = '.'){
            check++;
        }
    }
    if(st[0] == '.'){
        printf("0");
    }else if(st[length]){
        printf("0");
    }else if(check>1){
        printf("0");
    }else{
        printf("1");
    }
}

int abs(int n){
    if (n < 0){
        n = -1 * n;
    }    
    return(n);
}

void stringCopy(char src[], char dest[]){
    int i;
    for (i = 0; src[i] != '\0'; i++){
        dest[i] = src[i];
    }
}

int subString(char s1[], char s2[]){
    int i;
    int j;
    int counter;
    for (i = 0; s1[i] != '\0'; i++){
        for (j = 0; s2[j] != '\0'; j++){
            if (s1[i] == s2[j]){
                counter += 1;
            }
        }if (counter == 0){
            return 0;
        }else if (counter == 1){
            return 1;
        }
    }
}

int stringCompare(char s1[], char s2[]){
    int i = 0; 
    int j = 0;
    for(i = 0; s1[i] != '\0'; i++){
        if (s1[i+1] == '\0' && s2[i+1]!= '\0'){
            j = -1;
            break;
        }

        if(s1[i]>s2[i]){
            j = 1;
           break;
        }
        if(s1[i]<s2[i]){
           j = -1;
            break;
        }
        if(s1[i] == s2[i]){
          j = 0;
        }
        if ((s1[i]>='A' && s1[i]<='Z')){
        s1[i] = s1[i] + 32;
        }
        if ((s2[i]>='A' && s2[i]<='Z')){
        s2[i] = s2[i] + 32;
        }
    }
    return j;
}

void camelCase(char st[]){
    int i;
    for(i = 0; st[i] != '\0'; i++){
            if(st[0] >= 'A' && st[0] <= 'Z'){
                if(i == 0){
                    st[i] = toLower(st[i]);
                }else{
                    if(i % 2 == 0){
                        st[i] = toUpper(st[i]);
                    }else{
                        st[i] = toLower(st[i]);
                    }
                }
            }else{
                if(i == 0){
                    st[i] = toUpper(st[i]);
                }else{
                    if(i % 2 == 0){
                        st[i]=toLower(st[i]);
                    }else{
                        st[i]=toUpper(st[i]);
                    }
                }
            }

        }
}

void reverse1(char st[]){
    int n = 0; 
    int m = 0;

    for(int i=0; st[i]!='\0';i++){
        n++;
    }
    int j = n-1;
    int k = n-1;
    int i = 0;

    for(j; j > ((k-1)/2); j--){
        m = st[j];
        st[j] = st[i];
        st[i] = m;
        i++;

    }
    for(int i=0; st[i]!= '\0'; i++){
        printf("%c", st[i]);
    }
}

int reverse2(int n){
    int y = 0;
    while(n > 0 || n < 0){
        y *= 10;
        y= y + (n % 10);
        n /= 10;
    }
    return y;
}

int humbleNumber(int n){
    int i, j = 0;
    for (i = 2; i < n; i++){
        if (n % i == 0){
            n = n / i;
            i = 1;
        }
    }if (n % 2 == 0||n % 3 == 0||n % 5 == 0||n % 7 == 0||n == 1){
            j = 1;
            return 1;
    }else{
        return 0;
    }
}
