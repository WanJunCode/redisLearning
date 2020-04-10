#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string str;
    while(cin>>str)
    {   
        int num=0;
        for (int i=0;i<str.length();i++){
            if (str[i]>='A' && str[i]<='Z'){
                num++;
            }
        }
        cout<<num<<endl;         
    }
    return 0;
}