#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    while(cin>>str){
        bool flag = true;
        if(str.size()<9){
            flag=false;
        }

        if(flag){
            int a[4]={0};
            for(int i=0;i<str.size();i++)
            {
                if(isupper(str[i]))
                    a[0]=1;
                else if(islower(str[i]))
                    a[1]=1;
                else if(str[i]>='0'&&str[i]<='9')
                    a[2]=1;
                else
                    a[3]=1;
            }
            if(a[0]+a[1]+a[2]+a[3]<3)
                flag=false;     
        }
        if(flag){
            for(int i=0;i<str.size()-3;i++){
                string tmp = str.substr(i,3);
                for(int j=i+1;j<str.size()-3;j++){
                    string suit = str.substr(j,3);
                    if(suit==tmp){
                        flag = false;
                    }
                }
            }

        }

        if(flag){
            cout<<"OK"<<endl;
        }else{
            cout<<"NG"<<endl;
        }
    }

    return 0;
}