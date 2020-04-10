#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;

int main()
{
   string key,str;
    while(cin>>key>>str){
            string uniqueStr;
            for(auto c:key){//去重
                if(uniqueStr.find(c)==string::npos)
                    uniqueStr+=c;
            }
            string littleForm="abcdefghijklmnopqrstuvwxyz";
            string bigForm="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string encryptLittleForm=littleForm;
            string encryptBigForm=bigForm;
            if(islower(uniqueStr[0])){//小写
                encryptLittleForm.erase(0,uniqueStr.size());
                encryptLittleForm.insert(0,uniqueStr);
                int j=uniqueStr.size();
                for(int i=0;i<26;i++){
                    if(encryptLittleForm.find(littleForm[i])==string::npos){
                        encryptLittleForm[j]=littleForm[i];
                        j++;
                    }
                }
                for(auto &c:str){
                    int pos=littleForm.find(c);
                    c=encryptLittleForm[pos];
                }
            }
            else{//大写
                encryptBigForm.erase(0,uniqueStr.size());
                encryptBigForm.insert(0,uniqueStr);
                int j=uniqueStr.size();
                for(int i=0;i<26;i++){
                    if(encryptBigForm.find(bigForm[i])==string::npos){
                        encryptBigForm[j]=bigForm[i];
                        j++;
                    }
                }
                for(auto &c:str){
                    int pos=bigForm.find(c);
                    c=encryptBigForm[pos];
                }
            }
            //cout<<encryptBigForm<<endl<<encryptLittleForm<<endl;
            cout<<str<<endl;
    }
   return 0;
}