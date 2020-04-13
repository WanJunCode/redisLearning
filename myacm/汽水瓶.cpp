#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    while(cin>>num){
        int count = 0;
        // 大于等于3
        while(num>=3){
            count = count + num/3;
            num = num/3 + num%3;
        }
        if(num==2)
            count=count+1;
        cout<<count<<endl;
    }
    return 0;
}