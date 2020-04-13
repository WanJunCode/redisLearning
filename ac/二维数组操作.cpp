#include<iostream>
#include<string.h>
 
using namespace::std;

int main(){
    int row,col;
    while(cin >> row >> col){
        int ret[5];
        memset(ret,0,sizeof(int)*5);
        if(row <=0 || col <= 0) ret[0] = -1;
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a < 0 || a >= row || c <0 || c >= row || b <0 || b >= col || d<0 || d >=col) ret[1] = -1;;
        int e,f;
        cin >> e >> f;
        if(e<0 || e>=row) ret[2] = -1;
        if(f<0 || f>=col) ret[3] = -1;
        int m,n;
        cin >> m >> n;
        if(m<0 || m >= row || n<0 || n >= col) ret[4] = -1;
        for(int i=0; i<5; i++){
            cout << ret[i] << endl;
        }
    }
}