// 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0,


#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<char,int> code;
    code['a']=2;
    code['b']=2;
    code['c']=2;
    code['d']=3;
    code['e']=3;
    code['f']=3;
    code['g']=4;
    code['h']=4;
    code['i']=4;
    code['j']=5;    
    code['k']=5;
    code['l']=5;
    code['m']=6;
    code['n']=6;
    code['o']=6;
    code['p']=7;
    code['q']=7;
    code['r']=7;
    code['s']=7;
    code['t']=8;
    code['u']=8;
    code['v']=8;
    code['w']=9;
    code['x']=9;
    code['y']=9;
    code['z']=9;
    string str;
    while(cin>>str){
        for(int i=0;i<str.size();i++){
            if(islower(str[i])){
                cout<<code[str[i]];
            }else if(isupper(str[i])){
                str[i]+=32;
                if(str[i]=='z')
                    str[i]='a';
                else
                    str[i]+=1;
                cout<<str[i];
            }else{
                cout<<str[i];
            }
        }
    }
    return 0;
}