#include<iostream>
 using namespace std;
void m_p(int n)
{
    switch(n)
    {
        case 0: cout<<"零";break;
        case 1: cout<<"壹";break;
        case 2: cout<<"贰";break;
        case 3: cout<<"叁";break;
        case 4: cout<<"肆";break;
        case 5: cout<<"伍";break;
        case 6: cout<<"陆";break;
        case 7: cout<<"柒";break;
        case 8: cout<<"捌";break;
        case 9: cout<<"玖";break;
        default:break;
    }
}

void m_d(int n)
{
    switch(n)
    {
        case 0: cout<<"拾";break;
        case 1: cout<<"佰";break;
        case 2: cout<<"仟";break;
        case 3: cout<<"万";break;
        case 4: cout<<"亿";break;
        case 5: cout<<"元";break;
        case 6: cout<<"角";break;
        case 7: cout<<"分";break;
        case 8: cout<<"整";break;
        default:break;
    }
}

void p(int n)
{
    int i=n,flag=0;
    i = n/1000;
    if(i)
    {
        m_p(i);
        m_d(2);
        flag=1;
    }
    i = (n/100)%10;
    if(i||flag)
    {
        flag=1;
        m_p(i);
        m_d(1);
    }
    i = (n/10)%10;
    if(i||flag)
    {
        flag=1;
        if(n>=20)
        {
            m_p(i);
        }
        m_d(0);
    }
    i = n%10;
    if(i||flag)
    {
        m_p(i);
    }
}

int main()
{
    double d;
    int n;
    while(scanf("%lf",&d) != EOF)
    {
        cout<<"人民币";
        n = (int)d/10000;
        if(n != 0)
        {
            p(n);
            m_d(3);
        }
        n = (int)d%10000;
        if(n != 0)
        {
            p(n);
            m_d(5);
        }
        int m = (int)(100*d+0.5)%100;
        if(m == 0)
        {
            m_d(8);
        }
        else
        {
            n = m/10;
            if(n)
            {
                m_p(n);
                m_d(6);
            }
            n = m%10;
            if(n)
            {
                m_p(n);
                m_d(7);
            }
        }
       cout<<"\n";
    }
}