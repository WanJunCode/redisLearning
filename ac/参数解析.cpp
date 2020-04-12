#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main(){
    vector<string> mystr;
    string tmp;

    while(cin>>tmp){
        mystr.push_back(tmp);
    }

    string each;
    string eve;
    cout<<mystr.size()<<endl;
    for(int i=0;i<mystr.size();i++){
        each=mystr[i];
        if(each[0]=='\"'){
            int a=each.size();
            eve=each.substr(1,a-2);
            cout<<eve<<endl;
        }else{
            cout<<each<<endl;
        }
    }
    return 0;
}