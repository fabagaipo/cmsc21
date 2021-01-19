#include <stdio.h>

int div(int, int,int);//no.1
int relPrime(int,int);//no.2
int isValid(int,int);
int searchSet(int arr[], int, int);
int checkArray(int arr[], int);

int main(){
    int loop, choice, cases;
    int n1,n2, arr[100], a, b, c, i;
        printf("Input the Number of test cases: ");
        scanf("%d", &cases);
        for(loop=0; loop < cases; loop++){ //loops the menu until loop reaches the number of test cases
        printf("\n====================================\n");
        printf("[MENU]:\n\t1. DIVISION\n\t2. RELATIVE PRIME\n\t3. SEARCH SET\n\t0. Terminate\n====================================\n[INPUT]: ");
        scanf("%d", &choice);
        if(choice<=0 || choice>4){
            break;
        }
            switch(choice){
                case 1:
                printf("\nI.N.P.U.T: \n");
                printf("Enter Dividend: ");
                scanf("%d",&n1);
                printf("Enter Divisor: ");
                scanf("%d",&n2);
                printf("\nO.U.T.P.U.T: \n");
                if(isValid(n1,n2)==0){
                    printf("INVALID");
                }else{
                printf("Quotient: %d\n", div(n1,n2,0));
                }
                break;

                case 2:
                printf("\nI.N.P.U.T: \n");
                printf("Enter 1st Integer: ");
                scanf("%d",&n1);
                printf("Enter 2nd Integer: ");
                scanf("%d",&n2);
                printf("\nO.U.T.P.U.T: \n");
                if(isValid(n1,n2)==0){
                    printf("INVALID");
                }else{
                    if(relPrime(n1,n2)>1){
                        printf("\nNOT RELATIVELY PRIME\n");
                    }else{
                        printf("\nRELATIVELY PRIME\n");
                    }
                }
                break;

                case 3:
                printf("\nI.N.P.U.T: \n");
                printf("Enter number of values in array: ");
                scanf("%d", &a);
                printf("Enter values in array: ");
                for(i=0; i<a; i++){
                    scanf("%d", &arr[i]);
                }
                if(checkArray(arr, a)==0){
                    printf("INVALID\n");
                }else{
                    printf("Enter number to search in array: ");
                    scanf("%d", &b);
                    if(searchSet(arr,b,a)==0){
                        printf("Number is not found");
                    }else{
                        printf("Number is found");
                    }
                }
                break;
            }
        }
        printf("\n====================================\n");
        printf("  XXXXX Program Terminated. XXXXX\n");
        printf("====================================\n");
    return 0;
}
//no.1 DIVISION
int div(int n1, int n2, int val){
    if(0<=n1-n2){ //base case
    n1 -= n2; //subtract n2 from n1
    val++;
    return div(n1,n2,val);
    }else{ //recursive case
    return val;
    }
}
//no.2 RELATIVE PRIME
int relPrime(int n1, int n2) {
    if (n2==0){ //base case
        return n1;
    }
    if (n1 > n2){
        return relPrime(n2, n1 % n2);
    }
    return relPrime(n2,n1);
}

//no. 3 SEARCH SET FUNCTION
int searchSet(int arr[], int x, int index){
    if(index==0){ //if index is 0 element is not found
        return 0;
    }if(x==arr[index-1]){
        return 1;
    }else{
        return searchSet(arr,x,index-1); //decrements 1 from index until element is found
    }
}

//Extra Function
int isValid(int n1,int n2){ //checks if number is positive for no. 1
    if(n1<0||n2<0){
        return 0;
    }else{
        return 1;
    }
}

int checkArray(int arr[], int n) { //check if array is sorted in no.3
  int a = 1, d = 1, i = 0;

  while ((a == 1 || d == 1) && i < n - 1) {
    if (arr[i] < arr[i+1])
      d = 0;
    else if (arr[i] > arr[i+1])
      a = 0;
    i++;
  }

  if (a == 1)
    return 1;
  else if (d == 1)
    return 2;
  else
    return 0;
}