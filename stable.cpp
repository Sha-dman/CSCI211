#include<iostream>
using namespace std;
bool ok(int q[],int c){
    int mp[3][3]={
        {0,2,1},
        {0,2,1},
        {1,2,0}
    };
    int wp[3][3]={
        {2,1,0},
        {0,1,2},
        {2,0,1}
    };
    for ( int i = 0; i < c; i++){
        if (q[i] == q[c]) return false;
        //    if the current man  prefers the new woman to his partner 
        if (mp[i][q[c]] < mp[i][q[i]]) return false;
        //   if the new woman  prefers the current man  to her partner
        if(wp[q[c]][i] < wp [q[c]][c]) return false;
        // if the new man prefers the current woman to his partner 
        if(mp[c][q[i]] < mp[c][q[c]]) return false;
        // if the current woman prefers the new man to her parnter
        if(wp[q[i]][c] < wp[q[i]][i]) return false;
    }
    return true;
}
void print( int q[]){
    static int sol =1;
    cout << "Solution #" << sol++;
    cout << "Man\tWomen\n";
    for ( int i = 0; i < 3; i++){
    cout << i << "\t" << q[i] << endl;
}
    cout << endl;
}
int main(){
    int q [3] = {0}, c = 0;
    q[c] = 1;
    while ( c >= 0){
        c++;
        if ( c == 3){
            print(q);
            c--;
        }
        else q[c] = -1;
    while ( c >= 0){
        q[c]++;
        if ( q[c] == 3){
            c--;
        }
        else if (ok(q,c))
        break;
    }
    }
    return 0;
}