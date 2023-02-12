#include<iostream>
using namespace std;
int main(){
    int b[8] = {0}, c= 0;
nc:
    c++;
    if ( c == 8) goto print;
    b[c] = -1;
nr:
    b[c]++;
    if ( b[c] == 8) goto backtrack;
    for ( int i = 0 ; i < c; i++){
        if ( b[i]== b[c] || abs ( b[i] - b[c]) == c-i) goto nr;
    }
    goto nc;
backtrack:
    c--;
    if ( c == -1) return 0;
    goto nr;
print:
    static int sol = 0;
        cout << "Solution: # " << ++sol << endl;
        for ( int i = 0; i < 8; i++){
            cout << b[i] << " ";
        }
        cout << endl;
        goto backtrack;
}