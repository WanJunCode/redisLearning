#include<iostream>
#include<vector>
 
using namespace std;
 
int main()
{
    int num;
    while(cin>>num)
    {
        int col=1+2*num;
        vector<vector<int>> yh(num,vector<int>(col,0));
        yh[0][(col-1)/2]=1;
        for(int i=1;i<num;i++)
        {
            for(int j=1;j<col-1;j++)
            {
                yh[i][j]=yh[i-1][j-1]+yh[i-1][j]+yh[i-1][j+1];
            }
        }

        int res=1;
        for(int i=1;i<col-1;i++)
        {
            if(yh[num-1][i]%2!=0){
                res++;
            }else{
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}