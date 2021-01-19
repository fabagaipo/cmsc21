#include <stdio.h>

int wordCount(char st[]);
void flames(char st1[], char st2[]);
int isValid(char st[]);
char toLower(char ch[]);

int main(){
    int input;
    char arr1[100], arr2[100], arr3[100];

        printf("====================================\n");
        printf("[MENU]:\n\t1. Count Words\n\t2. FLAMES\n\t3. Exit\n====================================\n[INPUT]: ");
        scanf("%d", &input);

        while (input > 0 && input < 3){//loops menu until inputted exit or wrong value
            switch(input){

                case 1:
                printf("Enter a string: ");
                scanf(" %[^\n]s", arr1);
                while(isValid(arr1) == 0){ //checks if input is a valid character with function isValid
                    printf("INVALID Input. Try Again.\n");
                    printf("Enter a string: ");
                    scanf(" %[^\n]s", arr1);
                }
                printf("[OUTPUT]: %d word/s\n", wordCount(arr1));
                break;

                case 2:
                printf("Enter a name: ");
                scanf(" %[^\n]s", arr2);
                while(isValid(arr2) == 0){ //checks if input is a valid character with function isValid
                    printf("INVALID Input. Try Again.\n");
                    printf("Enter a name: ");
                    scanf(" %[^\n]s", arr2);
                }
                printf("Enter another name: ");
                scanf(" %[^\n]s", arr3);
                while(isValid(arr3) == 0){ //checks if input is a valid character with function isValid
                    printf("INVALID Input. Try Again.\n");
                    printf("Enter another name: ");
                    scanf(" %[^\n]s", arr3);
                }
                toLower(arr2);
                toLower(arr3);
                flames(arr2, arr3);
                break;
            }
        printf("====================================\n");
        printf("Menu:\n\t1. Count Words\n\t2. FLAMES\n\t3. Exit\n====================================\n[INPUT]: ");
        scanf ("%d",&input);
        }
    printf("====================================\n");
    printf("Exiting...\n");
    printf("====================================\n");
    return 0;
}

int wordCount(char st[]){
    int i = 0;
    int count = 1;
    while (st[i] != '\0'){ //loops till end
        if(st[i] == ' ' && st[i+1] != ' ' && st[i+1] != '\0'){
            count++; //counts the words in the string
        }
        i++; //if the previous if-statement is not satisfied, variable i will increment
    }
    return count;
}

int isValid(char st[]){
    int i, check;
    for(i=0; st[i] != '\0'; i++){
        if((st[i] >='A' && st[i] <='Z') || (st[i]>= 'a' && st[i] <= 'z') || st[i] == ' '){ //makes sure that string is composed of characters and/or spaces
        }else{ //if invalid character, variable check will be initalized to 0
            check = 0;
            break;
        }
    }
    return check;
}

char toLower(char ch[]){
    int i;
    for(i=0; ch[i] != '\0'; i++){
        if (ch[i]>= 'A' && ch[i] <= 'Z'){
            ch[i] = ch[i] + 32; //changes all found uppercase characters into lowercase to equalize the values of the lowercase and uppercase
        }
    }
}

void flames(char st1[], char st2[]){
   int i, j, name1 = 0, name2 = 0;
   int sum;
   char new1[100], new2[100];

    for(i=0; st1[i] != '\0'; i++){
        new1[i] = st1[i]; //copies what is inside of st1 to new1
    }
    for(i=0; st2[i] != '\0'; i++){
        new2[i] = st2[i];
    }

   for(i=0; st1[i] != '\0'; i++){
       for(j=0; st2[j] != '\0'; j++){
           if(st1[i] == new2[j] && st1[i] != ' '){
               name1++; //increments for every time there st1 and st2 have same letters
               st1[i] = 0; // initializes the first array to 0 and now the new array will be used
           }
       }
   }
   for(i=0; st2[i] != '\0'; i++){
       for(j=0; new1[j] != '\0'; j++){
           if(st2[i] == new1[j] && st2[i] != ' '){
               name2++;
               st2[i] = 0;
           }
       }
   }
   sum = name1 + name2; //adds the incremented amounts of st1 and st2
   name1 = name1 % 6; //counts the amount of times it loops for FLAMES (there are 6 letters in FLAMES)
   name2 = name2 % 6;
   sum = sum % 6;

    switch(name1){//switch case to print which letter from FLAMES is the value

        case 0:
        printf("====================================");
        printf("\n%s and %s are SWEETHEARTS\n", new1, new2);
        break;

        case 1:
        printf("====================================");
        printf("\n%s and %s are FRIENDS\n", new1, new2);
        break;

        case 2:
        printf("====================================");
        printf("\n%s and %s are LOVERS\n", new1, new2);
        break;

        case 3:
        printf("====================================");
        printf("\n%s and %s have ACCEPTANCE\n", new1, new2);
        break;

        case 4:
        printf("====================================");
        printf("\n%s and %s are MARRIED\n", new1, new2);
        break;

        case 5:
        printf("====================================");
        printf("\n%s and %s are ENGAGED\n", new1, new2);
        break;
    }

    switch(name2){

        case 0:
        printf("\n%s and %s are SWEETHEARTS\n", new2, new1);
        break;

        case 1:
        printf("\n%s and %s are FRIENDS\n", new2, new1);
        break;

        case 2:
        printf("\n%s and %s are LOVERS\n", new2, new1);
        break;

        case 3:
        printf("\n%s and %s have ACCEPTANCE\n", new2, new1);
        break;

        case 4:
        printf("\n%s and %s are MARRIED\n", new2, new1);
        break;

        case 5:
        printf("\n%s and %s are ENGAGED\n", new2, new1);
        break;
    }

    switch(sum){

        case 0:
        printf("\n%s and %s are SWEETHEARTS\n", new1, new2);
        printf("====================================\n");
        break;

        case 1:
        printf("\n%s and %s are FRIENDS\n", new1, new2);
        printf("====================================\n");
        break;

        case 2:
        printf("\n%s and %s are LOVERS\n", new1, new2);
        printf("====================================\n");
        break;

        case 3:
        printf("\n%s and %s have ACCEPTANCE\n", new1, new2);
        printf("====================================\n");
        break;

        case 4:
        printf("\n%s and %s are MARRIED\n", new1, new2);
        printf("====================================\n");
        break;

        case 5:
        printf("\n%s and %s are ENGAGED\n", new1, new2);
        printf("====================================\n");
        break;
    }
}

