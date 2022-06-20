#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;
    int level[10][10];
    int stage = 1;
    int goalIndex[2][10];
    int x = 10;
    int y = 10;
    bool checkWon;
    int count = 0;
    int button(int x1, int y1, int x2, int y2, char *text){
    rectangle(x1,y1,x2,y2);
    settextstyle(0,0,3);
    outtextxy(x1+25,y1+30,text);
}
    void fillVoidFull(){
    readimagefile("images\\void.jpg",0,0,600,600);
    }
    void selectLevelMenu(){
        fillVoidFull();
        button(100,100,300,180,"LEVEL 1");
        button(350,100,550,180,"LEVEL 2");
        button(100,260,300,340,"LEVEL 3");
        button(350,260,550,340,"LEVEL 4");
        int xc,yc;
        do{
        getmouseclick(WM_LBUTTONDOWN,xc,yc);
        if(xc < 300 && 100 < xc && 100 < yc && yc < 180){
            stage = 1;
            break;
        }else if(xc < 550 && 350 < xc && 100 < yc && yc < 180){
            stage = 2;
            break;
        }else if(xc < 300 && 100 < xc && 260 < yc && yc < 340){
            stage = 3;
            break;
        }else if(xc < 550 && 350 < xc && 260 < yc && yc < 340){
            stage = 4;
            break;
        }
        }while(true);
    }
    int levels(int h,int m){
    int firstLevel[10][10] =
   {{2,2,2,2,2,2,2,2,2,2},
    {2,4,0,4,2,2,0,1,0,2},
    {2,4,4,4,0,0,0,3,0,2},
    {2,0,0,2,0,2,0,0,0,2},
    {2,4,2,2,0,2,0,3,0,2},
    {2,2,2,0,0,2,3,0,0,2},
    {2,0,0,0,3,2,0,3,0,2},
    {2,0,0,3,0,0,3,0,0,2},
    {2,4,0,0,2,2,0,0,0,2},
    {2,2,2,2,2,2,2,2,2,2}};
    int secondLevel[10][10] =
   {{2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,0,0,2,2,2,2},
    {2,2,0,0,0,0,2,2,2,2},
    {2,0,3,0,3,0,0,0,2,2},
    {2,0,2,3,2,0,2,3,2,2},
    {2,0,4,1,4,3,4,0,0,2},
    {2,2,4,0,4,0,2,3,0,2},
    {2,2,2,2,4,0,0,0,2,2},
    {2,2,2,2,0,0,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2}};
    int thirdLevel[10][10] =
   {{2,2,2,2,2,2,2,2,2,2},
    {2,2,0,0,0,2,2,0,0,2},
    {2,2,0,0,0,0,0,0,0,2},
    {2,2,2,3,2,0,2,3,3,2},
    {2,2,0,0,0,0,0,0,0,2},
    {2,2,4,4,4,4,4,4,4,2},
    {2,2,0,2,3,2,3,2,0,2},
    {2,0,0,3,0,1,0,3,0,2},
    {2,0,0,0,2,0,0,0,2,2},
    {2,2,2,2,2,2,2,2,2,2}};
    int fourthLevel[10][10] =
   {{2,2,2,2,2,2,2,2,2,2},
    {2,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,1,3,4,0,0,2},
    {2,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,2},
    {2,2,2,2,2,2,2,2,2,2}};
    switch(stage){
case(1):
    return(firstLevel[h][m]);
    break;
case(2):
    return(secondLevel[h][m]);
    break;
case(3):
    return(thirdLevel[h][m]);
    break;
case(4):
    return(fourthLevel[h][m]);
    break;
default:
    return(firstLevel[h][m]);
    break;
    }
    }
    void fillVoid(int a,int b){
        int y = 10 + a*50;
        int x = 10 + b*50;
        readimagefile("images\\void.jpg",x,y,x+50,y+50);
    }
    void findGoals(){
            for(int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                if (level[a][b] == 4) {
                    goalIndex[0][count] = a;
                    goalIndex[1][count] = b;
                    count++;
                }
            }
        }
    }
    void clearGoals(){
        int h = count;
        for(int a = 0; a < h; a++) {
            goalIndex[0][count] = NULL;
            goalIndex[1][count] = NULL;
            count--;
        }
    }
    void screen(){
        for(int i = 0;i < 10;i++){
            for(int j = 0;j < 10;j++){
            int b = level[i][j];
            if(b == 2){
                setcolor(2);
                readimagefile("images\\wall.jpg",x,y,x+50,y+50);
                }
            if(b == 4){
                readimagefile("images\\goal.jpg",x,y,x+50,y+50);
            }
            x += 50;
            }
            x = 10;
            y += 50;
        }
        y = 10;
    }
    void repaint(int u){
        for(int i = 0;i < 10;i++){
            for(int j = 0;j < 10;j++){
            int b = level[i][j];
            if(b == 1){
                switch(u){
                case(1):
                    readimagefile("images\\gamer.jpg",x,y,x+50,y+50);
                    break;
                case(2):
                    readimagefile("images\\gamerUp.jpg",x,y,x+50,y+50);
                    break;
                case(3):
                    readimagefile("images\\gamerLeft.jpg",x,y,x+50,y+50);
                    break;
                case(4):
                    readimagefile("images\\gamerRight.jpg",x,y,x+50,y+50);
                    break;
                default:
                    readimagefile("images\\gamer.jpg",x,y,x+50,y+50);
                    break;
                }
            }
            if(b == 3){
                readimagefile("images\\box.jpg",x,y,x+50,y+50);
            }
            x += 50;
            }
            x = 10;
            y += 50;
        }
        y = 10;
    }
    int indexX(){
        int s;
        for(int i = 0;i < 10;i++){
            for(int j = 0;j < 10;j++){
            int b = level[i][j];
                if(b == 1){
                s = j;
                }
            }
        }
        return s;
    }
    int indexY(){
        int d;
        for(int i = 0;i < 10;i++){
            for(int j = 0;j < 10;j++){
            int b = level[i][j];
                if(b == 1){
                d = i;
                }
            }
        }
        return d;
    }
    void moveRight() {
        int y = indexY();
        int x = indexX();
        if(level[y][x + 1] == 3) {
            if(level[y][x + 2] == 0 || level[y][x + 2] == 4) {
                level[y][x + 1] = 0;
                level[y][x + 2] = 3;
            }
        }
        if(level[y][x + 1] == 0 || level[y][x + 1] == 4) {
            level[y][x] = 0;
            fillVoid(y,x);
            level[y][x + 1] = 1;
        }
    }
    void moveLeft(){
        int y = indexY();
        int x = indexX();
        if(level[y][x - 1] == 3) {
            if(level[y][x - 2] == 0 || level[y][x - 2] == 4) {
                level[y][x - 1] = 0;
                level[y][x - 2] = 3;
            }
        }
        if(level[y][x - 1] == 0 || level[y][x - 1] == 4) {
            level[y][x] = 0;
            fillVoid(y,x);
            level[y][x - 1] = 1;
        }
    }
    void moveUp(){
        int y = indexY();
        int x = indexX();
        if(level[y-1][x] == 3) {
            if(level[y - 2][x] == 0 || level[y - 2][x] == 4) {
                level[y - 1][x] = 0;
                level[y - 2][x] = 3;
            }
        }
        if(level[y - 1][x] == 0 || level[y - 1][x] == 4) {
            level[y][x] = 0;
            fillVoid(y,x);
            level[y - 1][x] = 1;
        }
    }
    void moveDown(){
        int y = indexY();
        int x = indexX();
        if(level[y + 1][x] == 3) {
            if(level[y + 2][x] == 0 || level[y + 2][x] == 4) {
                level[y + 1][x] = 0;
                level[y + 2][x] = 3;
            }
        }
        if(level[y + 1][x] == 0 || level[y + 1][x] == 4) {
            level[y][x] = 0;
            fillVoid(y,x);
            level[y + 1][x] = 1;
        }
    }
    void getLevel(){
        for(int l = 0;l < 10;l++){
            for(int n = 0;n < 10;n++){
                level[l][n] = levels(l,n);
            }
        }
    }
    void menu(){
        int xr,yr;
        fillVoidFull();
        button(240,130,395,200,"PLAY");
        button(240,210,395,280,"LEVELS");
        button(240,290,395,360,"EXIT");
        do{
        getmouseclick(WM_LBUTTONDOWN,xr,yr);
        if(240 < xr && xr < 395 && 130 < yr && yr < 200 ){
            fillVoidFull();
            clearGoals();
            getLevel();
            screen();
            findGoals();
            repaint(1);
            break;
        }else if(240 < xr && xr < 395 && 210 < yr && yr < 280){
            selectLevelMenu();
            fillVoidFull();
            clearGoals();
            getLevel();
            screen();
            findGoals();
            repaint(1);
            break;
        }else if(240 < xr && xr < 395 && 290 < yr && yr < 360){
            closegraph();
            break;
        }
        }while(true);
    }
    void won(){
    MessageBox(GetActiveWindow(), "You won", "Congratulations", MB_OK);
    stage++;
    fillVoidFull();
    clearGoals();
    getLevel();
    screen();
    findGoals();
    repaint(1);
    }
    void checkGoal() {
        checkWon = true;
        for(int y = 0; y < count; y++) {
            int q = goalIndex[0][y];
            int w = goalIndex[1][y];
            if(level[q][w] == 0){
                level[q][w] = 4;
                int j = 10 + w * 50;
                int h = 10 + q * 50;
                readimagefile("images\\goal.jpg",j,h,j+50,h+50);
            }
            if(level[q][w] != 3){
                checkWon = false;
            }
        }
        if(checkWon){
            won();
        }
    }
    int main(){
    int GrDr, GrMod, rez;
    GrDr=DETECT ;
   initgraph(&GrDr,&GrMod," ");
   rez=graphresult();
   if(rez != grOk)
    {
        printf("\n Error graph mode") ;
        return(1) ;
    }
    char ch;
    menu();
    while(true){
    ch=getch();
    switch(ch)
    {
        case('M'):
            moveRight();
            repaint(4);
            checkGoal();
            break;
        case('K'):
            moveLeft();
            repaint(3);
            checkGoal();
            break;
        case('P'):
            moveDown();
            repaint(1);
            checkGoal();
            break;
        case('H'):
            moveUp();
            repaint(2);
            checkGoal();
            break;
        case('p'):
            stage--;
            fillVoidFull();
            clearGoals();
            getLevel();
            screen();
            findGoals();
            repaint(1);
            break;
        case('n'):
            stage++;
            fillVoidFull();
            clearGoals();
            getLevel();
            screen();
            findGoals();
            repaint(1);
            break;
        case(27):
            menu();
        default:
            std::cout << ch;
    }
    };
}
