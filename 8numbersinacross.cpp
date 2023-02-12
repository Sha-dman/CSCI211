//Shadman Rahman
#include<iostream>
#include<cmath>
using namespace std;
bool ok(int a[], int b){
    int c[8][5]={    // possible values for board, as loop iterates the values change, satifying the tests.

          {1,-1},
        {0,-1},
        {0,-1},
        {0,1,2,-1},
        {0,1,3,-1},
        {1,4,-1},
        {2,3,4,-1},
        {3,4,5,6,-1},
    };
    for ( int i = 0; i < b; i++)    // tests to see if the values are the same
        if ( a[b] == a[i])
        return false;

    for ( int i = 0; c[b][i] != -1; i++)    // tests to see of the numbers adjacent are consective
        if ( abs ( a[b] - a[c[b][i]] ) == 1)
        return false;
    
    return true;
}
void print(int q[]) {
static int sol = 1;
cout << "Solution#:" << sol++ << endl;
cout << " " << q[0] << q[1] << endl;
cout << q[2] << q[3] << q[4] << q[5] << endl;
cout << " " << q[6] << q[7] << endl;
cout << endl;
}
int main(){
        int b[8], c = 0;
        b[c] = 1;
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
