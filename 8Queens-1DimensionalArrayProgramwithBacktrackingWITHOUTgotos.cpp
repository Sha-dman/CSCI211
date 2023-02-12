// Shadman Rahman
#include<iostream>
using namespace std;
bool ok ( int a[], int b){ // checks if tests are met
    for ( int i = 0 ; i < b; i++){
    if ( a[b] == a[i] || abs ( a[b] - a[i]) == b-i) // row, up/down diag test
    return false; // returns boolean , if true, conditions are met
    }
        return true;
}
void print(int a[]){    // print function
    static int sol = 0; // dynamic variable
    cout << "Solution # " << ++sol << ": "; // solution is incremented everytime the function is ran.
    for ( int i = 0; i < 8; i++){
        cout << a[i] << " ";    // prints array
    }
    cout << endl;
    cout << "\n";
    for ( int r = 0 ; r < 8; r++){
        for ( int c = 0; c < 8; c++)
        if ( a[c] == r){
            cout << "1" << " ";
        }
        else cout << "0" << " ";
        cout << endl;
    }
    cout << endl;
}
int main(){
    int b[8]= {0}, c = 0;   // board and column variable 
    while ( c >= 0){
        c++;    
        if ( c == 8){   // off the board so run print function
            print(b);
            c--;    // get back onto board
        }
        else b[c] = -1; // start on the next column but row before the first

    while ( c >= 0){
        b[c]++; // starts on first row, thenn increments with loop
        if ( b[c] == 8)     // backtrack, go back then go to ok function to see if conditions are met
            c--;
        else if (ok(b,c))
        break; // ends loop
    
        }
    }
        return 0;
}