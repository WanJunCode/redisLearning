#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    while(cin>>num){
        int a=1,b=0,c=0;
        // !先进行 -- 操作
        while(--num){
            c=c+b;
            b=a;
            a=c;
        }
        cout<<a+b+c<<endl;
    }
    return 0;
}