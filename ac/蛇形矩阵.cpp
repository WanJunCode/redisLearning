#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int num=0;
    // 输入蛇形矩阵的行数
    while(cin>>num){
        int n=1;        //n记录每一行的开头数值
        int row_add=1;      //列增长
        while(num)
        {
            int sum=n;
            int col_add=row_add+1;//行增长 设置为列增长加1
            for(int i=1;i<=num;i++)
            {
                cout<<sum;
                if(i<num){
                    cout<<" ";
                }
                sum+=col_add;
                col_add++;
            }
            cout<<endl;
            n=n+row_add;
            row_add++;
            num--;
        }
    }
    return 0;
}