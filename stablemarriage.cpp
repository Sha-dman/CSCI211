#include<iostream>
using namespace std;
bool ok ( int q[], int c){
    int mp [3][3] = {
        {0,2,1},
        {0,2,1},
        {1,2,0}
    };
    int wp [3][3] ={
        {2,1,0},
        {0,1,2},
        {2,0,1}
    };
    for ( int i = 0; i < c; i++){
            if (q[i] == q[c]) return false;
        		if( mp[i][q[c]] < mp[i][q[i]] && ( wp[q[c]][i] < wp[q[c]][c] ))               
			return false ;
		
		//if (Man#c) and (Man#i's wife) both like each other more than their own spouse
		if  ( mp[c][q[i]] < mp[c][q[c]] && ( wp[q[i]][c] < wp[q[i]][i] ) )
			return false ;
    }
    return true;
}
void print ( int b[],int c){
    static int sol = 0;
    cout << "Solution #" << ++sol << ":\nMan\tWomen\n";
    for ( int i = 0;i < c; i++){
        cout << i << "\t" << b[i] <<endl;
    }
    cout << endl;
}
int main(){
    int b [3] = {0}, c = 0;
    b [c] = 1;
    while ( c >=0 ){
        c++;
        if ( c == 3 ){
            print(b,c);
            c--;
        }
        else b[c] = -1;
    while ( c >= 0){
        b[c]++;
        if ( b[c] == 3){
            c--;
        }
        else if (ok(b ,c))
        break;
    }
    }
    return 0;
}