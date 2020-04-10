#include<iostream>
#include<string>
using namespace std;
 
int main(){
    int month;
    while(cin>>month){
        int a=1,b=0,c=0;   //a表示1个月的兔子数，b表示2个月的兔子数，c表示3个月的兔子数
        while(--month){
            c+=b;
            b=a;
            a=c;
        }
        cout<<a+b+c<<endl;
    }
    return 0;
}