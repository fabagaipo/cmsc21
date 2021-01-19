#include <stdio.h>

void display(char table[3][3]);

int main(){
    char tic[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int a, b, i, j, moves=1, checker = 0, win1 = 0, another;

    printf("[TIC TAC GAME] Press 1 to Play: ");
    scanf("%d", &another);
    while(another == 1){
        do{
            if(moves % 2 != 0){
                while(checker == 0){
                    printf("YOU ARE PLAYER 1\n");

                    do{
                    printf("\nEnter row: ");
                    scanf("%d", &a);
                    a = a-1; 
                    }while ((a < 0) || (a >= 3));

                    do{
                    printf("Enter column: ");
                    scanf("%d", &b);
                    b = b-1; 
                    }while ((b < 0) || (b >= 3));

                    if(tic[a][b] == ' '){
                        tic[a][b]='X';
                        checker = 1;
                        display(tic);
                    }else{
                        printf("INVALID SLOT\n");
                        printf("Enter again\n");
                    }
                }
            }else{
                while(checker == 1){
                    printf("YOU ARE PLAYER 2\n");
                    do{
                    printf("\nEnter row: ");
                    scanf("%d", &a);
                    a = a-1; 
                    }while ((a < 0) || (a >= 3));

                    do{
                    printf("Enter column: ");
                    scanf("%d", &b);
                    b = b-1; 
                    }while ((b < 0) || (b >= 3));

                    if(tic[a][b] == ' '){
                        tic[a][b]='O';
                        checker = 0;
                        display(tic);
                    }else{
                        printf("INVALID SLOT\n");
                        printf("Enter again\n");
                    }
                }
            }
            //Horizontal Win Checker
            for(i=0; i<3; i++){
                if(tic[i][0] == 'X'){
                    if(tic[i][0] == tic[i][1] && tic[i][0] == tic[i][2]){
                        if(tic[i][0] == 'X'){
                            printf("PLAYER 1 WINS");
                        }else{
                            printf("PLAYER 2 WINS"); 
                        }
                        win1 = 1;
                    }
                }
            }
            //Vertical Win Checker
            for(i=0; i<3; i++){
                if(tic[0][i] != ' '){
                    if(tic[0][i] == tic[1][i] && tic[0][i] == tic[2][i]){
                        if(tic[0][i] == 'X'){
                            printf("PLAYER 1 WINS");
                        }else{
                            printf("PLAYER 2 WINS"); 
                        }
                        win1 = 1;
                    }
                }
            }
            //Diagonal Win Checker
            if(tic[0][0] == tic[1][1] && tic[0][0] == tic[2][2]){
                if(tic[0][0] == 'X'){
                    printf("PLAYER 1 WINS");
                    win1 = 1;
                }if(tic[0][0] == 'O'){
                    printf("PLAYER 2 WINS");
                    win1 = 1;
                }
            }
            if(tic[0][2] == tic[1][1] && tic[0][2] == tic[2][0]){
                if(tic[0][2] == 'X'){
                    printf("PLAYER 1 WINS");
                    win1 = 1;
                }if(tic[0][2] == 'O'){
                    printf("PLAYER 2 WINS");
                    win1 = 1;
                }
            }
            moves++;
        }while((moves <= 9 || moves > 0) && win1 == 0);
        printf("\nDo you want to play again?\n");
        printf("Press 1: Play Again\n");
        printf("Press 0: Exit\n");
        scanf("%d", &another);
    }
    return 0;
}
void display(char table[3][3]){
    //201 203 187 188 185 204 205 206 186
    printf("\u2554\u2550\u2550\u2550\u2566\u2550\u2550\u2550\u2566\u2550\u2550\u2550\u2557\n");
    printf("\u2551 %c \u2551 %c \u2551 %c \u2551\n",table[0][0],table[0][1],table[0][2]);
    printf("\u2560\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u2563\n");
    printf("\u2551 %c \u2551 %c \u2551 %c \u2551\n",table[1][0],table[1][1],table[1][2]);
    printf("\u2560\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u256C\u2550\u2550\u2550\u2563\n");
    printf("\u2551 %c \u2551 %c \u2551 %c \u2551\n",table[2][0],table[2][1],table[2][2]);
    printf("\u255A\u2550\u2550\u2550\u2569\u2550\u2550\u2550\u2569\u2550\u2550\u2550\u255D\n");
}
