#include <stdio.h>

int main(void){
    int arr1[20], arr2[10] = {0,0,0,0,0,0,0,0,0,0};
    int i, count = 0, new;

    for(i=0; i<20; i++){
        printf("Entry no. %d : ", i+1); //Input 20 values to store inside arr1
        scanf("%d", &arr1[i]);
        if(arr1[i]<0){ //Checks if input is negative and ask user to input again if it is
            printf("You have inputted a negative number. Try again. \n");
            i--;
        }
    }
    for(i=0; i<20; i++){
        new = arr1[i];
        count = 0;
        while (new != 0){ //counts the digits of each number in new
            new = new/10;
            count++;
        }
        arr2[count-1]++; //stores value into respective arrays
    }
    printf("Number of digits for each inputted value: \n");
    for(i=0; i<10; i++){
        printf("%d = %d\t", i+1, arr2[i]);
    }
    int min = arr2[0];
    for(i=0; i<10; i++){
            if (arr2[i]!=0){
                if(arr2[i]<min){
                min = arr2[i];
                }
            }
    }
    int max = arr2[0];
    for(i=0; i<10; i++){
        if(max < arr2[i]){
            max = arr2[i];
        }
    }
    for(i=0; i<10; i++){
        if(arr2[i] == max){
            printf("\n%d digit/s are the most frequently inputted value/s", i+1);
        }
    }
    for(i=0; i<10; i++){
        if(arr2[i] == min){
            printf("\n%d digit/s are the least frequently inputted value/s", i+1);
        }
    }
    return 0;
}

