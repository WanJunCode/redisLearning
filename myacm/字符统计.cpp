#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string str;
    map<char,int> tb;
    while(cin>>str){
        // str 存入 map 中
        for(int i=0;i<str.size();i++){
            if(tb.find(str[i])!=tb.end()){
                tb[str[i]]+=1;
            }else{
                tb[str[i]]=0;
            }
        }

        for(int i=0;i<tb.size();i++){
            char maxch;
            int maxcount;
            for(std::map<char,int>::iterator iter=tb.begin(); iter!=tb.end();iter++){
                if(iter->second>maxcount){
                    maxcount = iter->second;
                    maxch = iter->first;
                }
            }
            cout<<maxch;
            tb[maxch]=0;
        }
        cout<<endl;
    }
}