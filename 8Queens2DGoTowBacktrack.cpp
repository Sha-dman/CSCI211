//Shadman Rahman
#include<iostream>
using namespace std;
int main(){
    int board[8][8]={0},r=0, c = -1;    // board, row , column
  board[0][0] = 1;                     // sets queen to top right (first) position of the board;

nc:                                 // This tells the program to go to the next column if all the rows are filled with zeros and has a queen
    c++;                           //increments a column
    if ( c == 8) goto print;      // This conditions shows that a solution has been found and goes to the print command.
    r = -1;                      // this sets it up so in the next row, r is 0
nr:
    r++;    
    if (r == 8 ) goto backtrack;            // this tells the program to go to backtrack if there are no suitable spots for the queen
    //row test
        for(int i = 0 ; i < c; i++)
            if (board[r][i]== 1) goto nr;  // If there is a queen in the same row, go to the next row
        
    // up diagtest
       for( int i = 1; ((r-i) >= 0) && ((c - i) >= 0); i++) 
            if (board [r-i][c-i] == 1) goto nr;                 // if there is a queen in the upwards left diagonals of the spot, then it show go to next row
        
    // down diagtest
        for (int i = 1; ((r + i) < 8) && ((c - i) >= 0) ; i++) // if there is a queen in the downwards left diagonals of the spot, then it show go to next row
            if (board [r+i][c-i] == 1 ) goto nr;    // if there is a queen in the downwards left diagonals of the spot, then it show go to next row
        
        board[r][c] = 1;            // places a queen because all the test have been passed
        goto nc;                   // can go to find solution for the next column
backtrack:
    c--;                        // goes to previous row
    if ( c < 0 ) return 0;     // this means there are no more possible solutions, so  the program exits
    r = 0;                    // starts the row at 0
    while (board[r][c] != 1 )   // sees if there are any queens in the column
        r++;
    
    board[r][c] = 0;        // if a queen is found, it is now set to 0
    
    goto nr;        // goes to next row to find next possible spot for the queen
print: 
    static int numSol= 1;   // when the program runs, the variable updates as it goes
    cout << "Solution #" << numSol++ << endl;
    for ( int r = 0; r < 8; r++){
        for ( int c = 0; c < 8; c++){
            cout << board[r][c] << " "; // prints out solution of the board
    }
    cout << endl;
    }
    cout << endl;

    goto backtrack; //Checks for next solution
}