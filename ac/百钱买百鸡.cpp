#include<iostream>
 
using namespace std;
 
int main()
{
    int num;
    while(cin>>num)
    {
        int money=0;
        int c=0;
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<33;j++)
            {
                money=100-5*i-3*j;
                c=money*3;
                if(i+j+c==100)
                {
                    cout<<i<<' '<<j<<' '<<c<<endl;
                }                                            
            }
        }
    }
    return 0;
}





