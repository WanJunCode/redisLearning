#include <iostream>
#include <string>
using namespace std;
string& code(string &s)
{
    for(int i=0;i<s.size();++i)
    {
        if(std::isalpha(s[i]))
        {
            if(s[i]<='z'&&s[i]>='a')
            {
                // 小写字母转换为大写字母后加1
                if(s[i]=='z')
                {
                    s[i]='A';
                }
                else
                {
                    s[i]=std::toupper(s[i])+1;
                }
            }
            else
            {
                // 大写字母转换为小写字母后加1
                if(s[i]=='Z')
                {
                    s[i]='a';
                }
                else
                {
                    s[i]=std::tolower(s[i])+1;
                }
            }
        }//end if
        else if(std::isalnum(s[i]))
        {
            if(s[i]=='9')
                s[i]='0';
            else
                s[i]=s[i]+1;
        }
    }
    return s;
}

string& decode(string &s)
{
    for(int i=0;i<s.size();++i)
    {
        // 判断如果是英文字母
        if(std::isalpha(s[i]))
        {
            if(s[i]<='z'&&s[i]>='a')
            {
                if(s[i]=='a')
                {
                    s[i]='Z';
                }else{
                    s[i]=std::toupper(s[i])-1;
                }
            }else{
                if(s[i]=='A')
                {
                    s[i]='z';
                }else{
                    s[i]=std::tolower(s[i])-1;
                }
            }
        }//end if
        else if(std::isalnum(s[i]))
        {
            if(s[i]=='0')
                s[i]='9';
            else
                s[i]=s[i]-1;
        }
    }
    return s;

}
int main()
{
    string s1;
    string s2;
    while(cin>>s1>>s2)
    {
        s1=code(s1);
        s2=decode(s2);
        cout<<s1<<endl;
        cout<<s2<<endl;
    }
    return 0;
}