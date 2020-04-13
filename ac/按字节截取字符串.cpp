#include <iostream>
#include <string>
using namespace std;


// 中文字符
int main(){
    string s;
    int N;
    while(cin>>s>>N){
        string ss;
        if(s[N-1]>=128)//判断尾字符是否是汉字的前一个字节
            ss=s.substr(0,N-1);
        else
            ss=s.substr(0,N);
        cout<<ss<<endl;
    }
    return 0;
}