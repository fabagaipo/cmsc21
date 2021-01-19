#include <stdio.h>

void display(int A[100][100], int, int );
int recursive(int B[100][100], int, int, int);
int pic(int image[100][100], int, int);

int main(){

    int box[100][100];
    int t, row, column, i, j,checker=0, temp=0, loop;

    printf("Test cases: ");
    scanf("%d", &t);

    for(loop=0; loop<t; loop++){
        printf("Enter number of rows: ");
        scanf("%d", &row);
        printf("Enter number of columns: ");
        scanf("%d", &column);

        for(i=0; i<row; i++){
            for(j=0; j<column; j++){
                scanf("%d", &box[i][j]);
                if(box[i][j]<0 || box[i][j]>1){
                checker = 1;
                }
            }
        }if(checker==1){
            printf("INVALID");
        }else{
            printf("\n");
            display(box, row, column);
            if(temp==0){
                pic(box, row, column);
            }else{
                printf("INVALID");
            }
        }
    }
    return 0;
}

void display(int A[100][100],int r,int c){
	int i,j;
	for(i=0; i<r; i++){
		for(j=0; j<c; j++)
			printf("%i ",A[i][j]);
		printf("\n");
	}
}

int pic(int image[100][100], int row, int column){
int label=2, i=0, j=0;
    if((row<=0||row>=100)||(column<=0||column>=100)){
    printf("INVALID");
    return 0;
    }else{
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
                recursive(image,label,i,j);
                    if(image[i][j]==label){\
                    label++;
                    }
                }
        }
        printf("\n%d Object/s found\n", label-2);
        return 0;
    }
}

int recursive(int box[100][100], int label, int i, int j){
    if ( box[i][j] == 0){
        return label;
    }if(box[i][j] == 1){
        box[i][j] = label;
        return (recursive(box, label, i-1, j-1) + recursive(box, label, i-1, j) + recursive(box, label, i-1, j+1) + recursive(box, label, i, j-1) + recursive(box, label, i, j+1) + recursive(box, label, i+1, j-1) + recursive(box, label, i+1, j) + recursive(box, label, i+1, j+1));
    }
}
