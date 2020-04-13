#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<char,char> tb;

char change(char ch){
    if( (ch>='a'&&ch<='f') || (ch>='A'&&ch<='F') || isdigit(ch)){
        return tb[ch];
    }else{
        return ch;
    }
}

int main(){
    tb['0']='0';
    tb['1']='8';
    tb['2']='4';
    tb['3']='C';
    tb['4']='2';
    tb['5']='A';
    tb['6']='6';
    tb['7']='E';
    tb['8']='1';
    tb['9']='9';
    tb['a']='5';
    tb['A']='5';
    tb['b']='D';
    tb['B']='D';
    tb['c']='3';
    tb['C']='3';
    tb['d']='B';
    tb['D']='B';
    tb['e']='7';
    tb['E']='7';
    tb['f']='F';
    tb['F']='F';
    string str1,str2;
    while(cin>>str1>>str2){
        // 合并
        string merge = str1+str2;
        vector<char> singlestr;
        vector<char> doublestr;
        // 分开
        for(int i=0;i<merge.size();i++){
            if(i%2==0)
                doublestr.push_back(merge[i]);
            else
                singlestr.push_back(merge[i]);
        }
        // 排序
        sort(doublestr.begin(),doublestr.end());
        sort(singlestr.begin(),singlestr.end());
        
        int di=0;
        int si=0;
        for(int i=0;i<merge.size();i++){
            if(i%2==0){
                cout<<change(doublestr[di++]);
            }else{
                cout<<change(singlestr[si++]);
            }
        }
        cout<<endl;
    }
    return 0;
}