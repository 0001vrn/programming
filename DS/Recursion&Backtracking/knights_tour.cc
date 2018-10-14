// C++ program for Knight Tour problem 
#include<iostream>
using namespace std;

#define board_size 8

bool isSafe(int x, int y, int sol[board_size][board_size]){
    return (x>=0&&
            x<board_size&&
            y>=0&&
            y<board_size&&
            sol[x][y]==-1);
}
void printSolution(int sol[board_size][board_size]){
    for(int x=0;x<board_size;++x){
        for(int y=0;y<board_size;++y)
            printf(" %2d ", sol[x][y]); 
        cout<<'\n';
    }
}
bool solveKTUtil(int x, int y, int movei, int sol[board_size][board_size], int xMove[board_size], int yMove[board_size]){
    
    int k, next_x, next_y;
    if(movei==board_size*board_size)
        return true;
        
    for(k=0;k<8;++k){
        
        next_x=x+xMove[k];
        next_y=y+yMove[k];
        
        if(isSafe(next_x,next_y,sol)){
            
            sol[next_x][next_y]=movei;
            
            if(solveKTUtil(next_x,next_y,movei+1,sol,xMove,yMove)==true)
                return true;
            else
                sol[next_x][next_y]=-1;
        }
    }
    
    return false;
}

bool solveKT(){
    int sol[board_size][board_size];
    
    for(int x=0;x<board_size;++x)
        for(int y=0;y<board_size;++y)
            sol[x][y]=-1;
            
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    
    // Since the Knight is initially at the first block 
    sol[0][0]  = 0;
    
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false) 
    { 
        printf("Solution does not exist"); 
        return false; 
    } 
    else
        printSolution(sol); 
  
    return true; 
}

int main(void){
    solveKT();
    return 0;
}