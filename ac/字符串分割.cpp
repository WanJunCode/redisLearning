#include <iostream>
#include <string>

using namespace std;

void fun(string str){
    while (str.size()>8){
        cout<<str.substr(0,8)<<endl;
        str=str.substr(8);
    }
    cout<<str.append(8-str.size(),'0')<<endl;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    fun(s1);
    fun(s2);
    return 0;
}