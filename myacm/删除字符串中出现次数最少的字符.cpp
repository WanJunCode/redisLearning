#include <iostream>
#include <string>

using namespace std;

int main(){

    string str;
    while(cin>>str){
        char num[26] = {0};
        for(int i=0;i<str.size();i++){
            // 只有小写英文
            num[str[i]-'a']+=1;
        }
        int index = 1000;
        for(int i=0;i<26;i++){
            if(num[i]!=0 && num[i]<index){
                index = num[i];
            }
        }
        for(int i=0;i<str.size();i++){
            if( num[str[i]-'a']!=index )
                cout<<str[i];
        }
        cout<<endl;
    }

    return 0;
}