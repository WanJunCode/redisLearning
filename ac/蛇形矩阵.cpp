#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    int num=0;
    // 输入蛇形矩阵的行数
    while(cin>>num){
        int n=1;
        int add_col=1;//行增长
        while(num)
        {
            int sum=n;
            int add_row=add_col+1;//列增长
            for(int i=1;i<=num;i++)
            {
                cout<<sum;
                if(i<num){
                    cout<<" ";
                }
                sum+=add_row;
                add_row++;
            }
            cout<<endl;
            n=n+add_col;
            add_col++;
            num--;
        }
    }
    return 0;
}