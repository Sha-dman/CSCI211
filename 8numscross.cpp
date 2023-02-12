#include<iostream>
using namespace std;
bool ok(int a[], int b){
    int help[8][5] = {
{-1},//0            01
{0,-1},//1         2345
{0,-1},//2          67
{0,1,2,-1},//3
{0,1,3,-1},//4
{1,4,-1},//5
{2,3,4,-1},
{3,4,5,6,-1}
    };
    for ( int i = 0; i < b; i++){
        if (a[b] == a[i]) return false;
    }
    for ( int i = 0; help[b][i] != -1; i++){
        if (abs(a[b] - a[help[b][i]]) == 1) return false;
    }
    return true;
}
void print ( int b[]){
    cout << " " << b[0] << b[1] << " " << endl;
    cout << b[2] << b[3] << b[4] << b[5] << endl;
    cout << " " << b[6] << b[7] << " " << endl;
    cout << endl;
}
int main(){
    int b[8]={0},c = 0;
    b[c] = 1;
    while ( c >= 0){
        c++;
        if (c==8){
            print(b);
            c--;
        }
        else b[c] = -1;
    while ( c >= 0){
        b[c]++;
        if ( b[c] == 8){
            c--;
        }
        else if ( ok(b,c))
        break;
    }
    }
}