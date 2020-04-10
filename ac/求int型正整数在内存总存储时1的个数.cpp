#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    int count = 0;
    while(cin>>num){
        while(num){
            if(num&1){
                count++;
            }
            num>>=1;
        }
    }
    cout<<count<<endl;
    return 0;
}