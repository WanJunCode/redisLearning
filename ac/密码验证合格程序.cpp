// 密码要求:
// 1.长度超过8位
// 2.包括大小写字母.数字.其它符号,以上四种至少三种
// 3.不能有相同长度超2的子串重复
// 说明:长度超过2的子串

#include <iostream>
#include <string>
using namespace std;
  
int main()
{  
    string s;
    while(cin>>s)
    {
        bool ok=true;
        if(s.size()<9)
            ok=false;
        if(ok)
        {
            int a[4]={0};
            for(int i=0;i<s.size();i++)
            {
                if(isupper(s[i]))
                    a[0]=1;
                else if(islower(s[i]))
                    a[1]=1;
                else if(s[i]>='0'&&s[i]<='9')
                    a[2]=1;
                else
                    a[3]=1;
            }
            if(a[0]+a[1]+a[2]+a[3]<3)
                ok=false;                                               
        }
        if(ok)
        {
            for(int i=0;i<=s.size()-3;i++)
            {
                string s1=s.substr(i,3);
                bool flag=true;
                for(int j=i+3;j<=s.size()-3;j++)
                {               
                    string s2=s.substr(j,3);
                    if(s1==s2)
                    {
                        ok=false;
                        flag=false;
                        break;                                         
                    }                                              
                } 
                if(!flag)
                    break;
            }
        }
        if(ok)
            cout<<"OK"<<endl;
        else
            cout<<"NG"<<endl;                    
    }
    return 0;  
}