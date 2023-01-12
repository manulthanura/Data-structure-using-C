#include <stdio.h>
#include<stdlib.h>
#include<windows.h>

char world[8][8] = {{'x',' ',' ',' ',' ',' ',' ','x'},
                    {'x',' ','x','x','x','x',' ','x'},
                    {'x',' ','x','x','x','x',' ','x'},
                    {'x',' ',' ',' ',' ','x',' ','x'},
                    {' ',' ',' ',' ','x',' ',' ',' '},
                    {' ','x','x',' ','x','x','x',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' '},
                    {'x','x','x',' ','x','x','x','x'}};
int x_b,y_b,x_f,y_f,rot_st = 1 ;  //bug positions, rotation and food position
int conf_b,conf_f,next,win =0;
char bug = 2 ; 
char food = 4;

void main_menu();
void display_bord();
void sense();
void turn();
void step();
void start();
void won();
void go();

int main()
{
    main_menu();
    start();
    win = 0;
    display_bord();
    go();
    printf("Game Over.\n");
    printf("Bug ate food\n\n");

    return 0;
}

void main_menu(){
    system("cls");
    printf("     X - %c \n",26);
    printf("        0     1     2     3     4    5     6     7\n");
    printf("      _____ _____ _____ _____ _____ _____ _____ _____ \n");
    printf(" y 0 |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[0][0],world[0][1],world[0][2],world[0][3],world[0][4],world[0][5],world[0][6],world[0][7]);
    printf("     |_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf(" | 1 |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[1][0],world[1][1],world[1][2],world[1][3],world[1][4],world[1][5],world[1][6],world[1][7]);
    printf("     |_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf(" %C 2 |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",25,world[2][0],world[2][1],world[2][2],world[2][3],world[2][4],world[2][5],world[2][6],world[2][7]);
    printf("     |_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("   3 |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[3][0],world[3][1],world[3][2],world[3][3],world[3][4],world[3][5],world[3][6],world[3][7]);
    printf("     |_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("   4 |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[4][0],world[4][1],world[4][2],world[4][3],world[4][4],world[4][5],world[4][6],world[4][7]);
    printf("     |_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("   5 |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[5][0],world[5][1],world[5][2],world[5][3],world[5][4],world[5][5],world[5][6],world[5][7]);
    printf("     |_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("   6 |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[6][0],world[6][1],world[6][2],world[6][3],world[6][4],world[6][5],world[6][6],world[6][7]);
    printf("     |_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("   7 |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[7][0],world[7][1],world[7][2],world[7][3],world[7][4],world[7][5],world[7][6],world[7][7]);
    printf("     |_____|_____|_____|_____|_____|_____|_____|_____|\n\n");

    printf("Bug - %c  || Food - %c\n\n",bug,food); 
}

void display_bord(){
    system("cls");
    printf(" _____ _____ _____ _____ _____ _____ _____ _____ \n");
    printf("|  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[0][0],world[0][1],world[0][2],world[0][3],world[0][4],world[0][5],world[0][6],world[0][7]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[1][0],world[1][1],world[1][2],world[1][3],world[1][4],world[1][5],world[1][6],world[1][7]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[2][0],world[2][1],world[2][2],world[2][3],world[2][4],world[2][5],world[2][6],world[2][7]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[3][0],world[3][1],world[3][2],world[3][3],world[3][4],world[3][5],world[3][6],world[3][7]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[4][0],world[4][1],world[4][2],world[4][3],world[4][4],world[4][5],world[4][6],world[4][7]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[5][0],world[5][1],world[5][2],world[5][3],world[5][4],world[5][5],world[5][6],world[5][7]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[6][0],world[6][1],world[6][2],world[6][3],world[6][4],world[6][5],world[6][6],world[6][7]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|\n");
    printf("|  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |  %C  |\n",world[7][0],world[7][1],world[7][2],world[7][3],world[7][4],world[7][5],world[7][6],world[7][7]);
    printf("|_____|_____|_____|_____|_____|_____|_____|_____|\n\n");
}

void sense(){
    next = 0;
    if(rot_st ==1){
        if(world[y_b-1][x_b] != 'x' && y_b > 0){
            next = 1;
        }
    }else if(rot_st == 2){
        if(world[y_b][x_b+1] != 'x' && x_b < 7){
            next = 1;
        }
    }else if(rot_st == 3){
        if(world[y_b+1][x_b] != 'x' && y_b < 7 ){
            next = 1;
        }
    }else if(rot_st == 4){
        if(world[y_b][x_b-1] != 'x' && x_b > 0){
            next = 1;
        }
    }
}

void turn(){
    if(rot_st ==1 ){
        rot_st = 2;
    }else if(rot_st == 2 ){
        rot_st = 3;
    }else if(rot_st == 3){
        rot_st = 4;
    }else if(rot_st == 4){
        rot_st = 1;
    }
}

void step(){
    if(rot_st ==1){
        world[y_b-1][x_b] = bug;
        world[y_b][x_b] = ' ';
        y_b = y_b - 1;
    }else if(rot_st == 2){
        world[y_b][x_b+1] = bug;
        world[y_b][x_b] = ' ';
        x_b = x_b + 1;
    }else if(rot_st == 3){
        world[y_b+1][x_b] = bug;
        world[y_b][x_b] = ' ';
        y_b = y_b + 1;
    }else if(rot_st == 4){
        world[y_b][x_b-1] = bug;
        world[y_b][x_b] = ' ';
        x_b = x_b - 1;
    }
}

void start(){
    conf_b = 0;
    while (conf_b != 1){
        printf("Enter bug position (x): ");
        scanf("%d", &x_b);
        printf("Enter bug position (y): ");
        scanf("%d", &y_b);
        

        if(world[y_b][x_b] != 'x' && x_b < 8 && y_b < 8){
            world[y_b][x_b] = bug;
            conf_b = 1;
        }else {
            printf("Invalid bug Positions.\n");
            
        }
        printf("\n");
        printf("-------------------------------\n");
    }
    conf_f = 0;
    while(conf_f != 1){
        printf("Enter food position (x): ");
        scanf("%d", &x_f);
        printf("Enter food position (y): ");
        scanf("%d", &y_f);
        

        if(world[y_f][x_f] != 'x' && x_f < 8 && y_f < 8){
            world[y_f][x_f] = food;
            conf_f = 1;
        }else {
            printf("Invalid food Positions.\n");
        }
        printf("\n");
        printf("-------------------------------\n");
    }


}

void won(){
    if(x_b == x_f && y_b == y_f){
        win = 1;
    }
}

void go(){
    int t; 
    while(win != 1){
        sense();
        t = 0;
        while(next != 1){
            t++;
            if(t == 1){
                turn();
            }else if(t == 2){
                turn();
                turn();
            }else if(t == 3){
                turn();
                turn();
                turn();
            }
            sense();
        }
        step();
        display_bord();
        Sleep(600);
        won();
    }
}

