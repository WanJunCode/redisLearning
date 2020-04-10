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
            ss.push(tmp);
        }

        sort(ss.begin(),ss.end());
        vector<string>::iterator iter;
        for(iter=ss.begin();iter!=iter.end();iter++){
            cout<<*iter<<endl;
        }
    }
    return 0;
}