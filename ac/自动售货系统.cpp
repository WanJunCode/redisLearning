#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
       
using namespace std;
int A_num[]={0,0,0,0,0,0,0};//货的数目
int A_price[]={0,2,3,4,5,8,6};//货的价格
int M_num[]={0,0,0,0};//钱币数目
int M[]={1,2,5,10};//钱币面值
int pay=0;//付的钱数
     
void process(string str,int pos);
   
int main()
{
    int i,k,tmp,len;
    string  str;
    while (getline(cin,str))
    {
        cout<<"S001:Initialization is successful"<<endl;//初始化成功
        tmp=0;
        k=1;
        for(i=2;str[i]!=' ';i++)//取货的个数
        {
            if(str[i]=='-'){A_num[k++]=tmp;tmp=0;}
            else if(isdigit(str[i]))tmp=tmp*10+str[i]-'0';
        }
        A_num[k]=tmp;
        len=i;//保存空格位置
        k=0;
        tmp=0;
        for(i=len;str[i]!=';';i++)//取钱的个数
        {
            if(str[i]=='-'){M_num[k++]=tmp;tmp=0;}
            else if(isdigit(str[i]))tmp=tmp*10+str[i]-'0';
        }
        M_num[k]=tmp;
        pay=0;//初始清零
        for(i=13;i<str.size();i++)//功能处理
        {
            if((i+1)<str.size()&&str[i]==';')
            process(str,i+1);
        }
    }
    return 0;
}
     
     
void process(string str,int pos)
{
    int i,tmp=0;
    switch(str[pos])
    {
        case 'p'://付钱
            for(i=pos+2;str[i]!=';';i++)
            {
                tmp=tmp*10+str[i]-'0';
            }
            if(tmp!=1&&tmp!=2&&tmp!=5&&tmp!=10)
                cout<<"E002:Denomination error"<<endl;
            else
            {
                if(tmp>2&&(M_num[0]+2*M_num[1])<tmp)
                    cout<<"E003:Change is not enough, pay fail"<<endl;
                else if(tmp>10)
                    cout<<"E004:Pay the balance is beyond the scope biggest"<<endl;
                else if(A_num[3]==0&&A_num[2]==0&&A_num[1]==0&&A_num[0]==0)
                    cout<<"E005:All the goods sold out"<<endl;
                else
                {
                    pay+=tmp;
                    switch(tmp)
                    {
                        case 1:M_num[0]++;cout<<"S002:Pay success,balance="<<pay<<endl;break;
                        case 2:M_num[1]++;cout<<"S002:Pay success,balance="<<pay<<endl;break;
                        case 5:M_num[2]++;cout<<"S002:Pay success,balance="<<pay<<endl;break;
                        case 10:M_num[3]++;cout<<"S002:Pay success,balance="<<pay<<endl;break;
                        default:break;
                    }
                }
            }
            break;
        case 'q'://查询
            tmp=str[pos+2]-'0';
            if(tmp==0)
            {
                for(i=1;i<=6;i++)cout<<"A"<<i<<" "<<A_price[i]<<" "<<A_num[i]<<endl;
            }
            else if(tmp==1)
            {
                for(i=0;i<4;i++)cout<<M[i]<<" yuan coin number="<<M_num[i]<<endl;
            }
            else cout<<"E010:Parameter error";
            break;
        case 'b'://买商品
            tmp=str[pos+3]-'0';
            if(tmp>=1&&tmp<=6)
            {
                if(A_num[tmp]==0)cout<<"E007:The goods sold out"<<endl;
                else if(pay<A_price[tmp])cout<<"E008:Lack of balance"<<endl;
                else {pay-=A_price[tmp];cout<<"S003:Buy success,balance="<<pay<<endl;A_num[tmp]--;}
            }
            else
                cout<<"E006:Goods does not exist"<<endl;
            break;
        case 'c'://找钱退币
            if(pay==0)cout<<"E009:Work failure";
            else
            {
                int cnt[4]={0,0,0,0};
                while((pay-10)>=0&&M_num[3]>0){pay-=10;M_num[3]--;cnt[3]++;}
                while((pay-5)>=0&&M_num[2]>0){pay-=5;M_num[2]--;cnt[2]++;}
                while((pay-2)>=0&&M_num[1]>0){pay-=2;M_num[1]--;cnt[1]++;}
                while((pay-1)>=0&&M_num[0]>0){pay-=1;M_num[0]--;cnt[0]++;}
                for(i=0;i<4;i++)cout<<M[i]<<" yuan coin number="<<cnt[i]<<endl;
                pay=0;
            }
            break;
        default:
            break;
    }
}