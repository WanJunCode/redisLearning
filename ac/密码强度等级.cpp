#include<string>

#include<iostream>
  
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        int val = 0;
        int len = s.size();
          
        if(len <= 4){
            val += 5;
        }else if(len >=8){
            val += 25;
        }else{
            val += 10;
        }
          
        int hasNum=0, hasAlphaL=0, hasAlphaS=0, ch =0;
        for(char c : s){
            if(c>='0' && c<='9'){
                hasNum++;
            }else if(c>='a' && c<='z'){
                hasAlphaS++;
            }else if(c>='A' && c<='Z'){
                hasAlphaL++;
            }else{
                ch++;
            }
        }
          
        if(hasAlphaL == len || hasAlphaS == len){
            val += 10;
        }else if(hasAlphaL >0 && hasAlphaS >0){
            val += 20;
        }
          
        if(hasNum == 1){
            val += 10;
        }else if(hasNum > 1){
            val += 20;
        }
          
        if(ch ==1){
            val += 10;
        }else if(ch >1){
            val += 25;
        }
          
        if(hasNum>0 && hasAlphaL>0 && hasAlphaS>0 && ch >0){
            val += 5;
        }else if(hasNum>0 && hasAlphaL>0 && hasAlphaS>0){
            val += 3;
        }else if(hasNum>0 && (hasAlphaL>0 || hasAlphaS>0)){
            val += 2;
        }

        if(val >= 90){
            cout << "VERY_SECURE" << endl;
        }else if(val >= 80){
            cout << "SECURE" << endl;
        }else if(val >=70){
            cout << "VERY_STRONG" << endl;
        }else if(val >= 60){
            cout << "STRONG" << endl;
        }else if(val >= 50){
            cout << "AVERAGE" << endl;
        }else if(val >=25){
            cout << "WEAK" << endl;
        }else {
            cout << "WERY_WEAK" << endl;
        }
    }
          
      
}
