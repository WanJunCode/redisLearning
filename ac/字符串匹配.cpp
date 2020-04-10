#include <iostream>
#include <string>

using namespace std;
 
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        int i;
        for(i=0;i<str1.size();i++)
        {
            if(str2.find(str1[i])==-1)
            {
                cout<<"false"<<endl;
                break;
            }
        }
         
        if(i==str1.size())
            cout<<"true"<<endl;
    }
    return 0;
}