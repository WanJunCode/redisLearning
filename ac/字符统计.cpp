#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
int main()
{
    string str;
    while(getline(cin,str))
    {
        int a[128] = {0};
        for(int i =0;i<str.length();i++)
        {
            if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')||(str[i]>='0'&&str[i]<='9')||str[i]==' ')
                a[str[i]]++;
        }
        vector<char> vec;
        for(int i=0; i<128; i++)
        {
           if(a[i])
                vec.push_back(i);
        }

        char ch;
        for(vector<char>::size_type i=0; i<vec.size()-1; i++)
            for(vector<char>::size_type j=0; j<vec.size()-1-i; j++)
            {
                if(a[vec[j]]<a[vec[j+1]])
                {
                    ch = vec[j];
                    vec[j] = vec[j+1];
                    vec[j+1] = ch;
                }
                else if(a[vec[j]]==a[vec[j+1]])
                {
                    if(vec[j]>vec[j+1])
                    {
                        ch = vec[j];
                        vec[j] = vec[j+1];
                        vec[j+1] = ch;
                    }           
                }
            }
        
        for(vector<char>::size_type i=0; i!=vec.size(); i++)
            cout<<vec[i];
        cout<<endl;
    }
    return 0;
}
