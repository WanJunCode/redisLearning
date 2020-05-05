// 给定n个字符串，请对n个字符串按照字典序排列。
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int num;
    while(cin>>num){
        vector<string> ss;
        string tmp;
        while(num--){
            cin>>tmp;
            ss.push_back(tmp);
        }

        sort(ss.begin(),ss.end());
        vector<string>::iterator iter;
        for(iter=ss.begin();iter!=ss.end();iter++){
            cout<<*iter<<endl;
        }
    }
    return 0;
}