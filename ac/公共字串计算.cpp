#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    string str1,str2;
    while(cin>>str1)
    {
        cin>>str2;
        vector<vector<int> > matrix(str1.size(),vector<int>(str2.size()));
        int max_num=0;
        for(int i=0;i<str1.size();i++)
        {
            for(int j=0;j<str2.size();j++)
            {
                if(str1[i]!=str2[j])
                    matrix[i][j]=0;
                else if(i==0||j==0)
                {
                    matrix[i][j]=1;
                    if(max_num<1)
                        max_num=1;
                }else{
                    matrix[i][j]=matrix[i-1][j-1]+1;
                    if(matrix[i][j]>max_num)
                        max_num=matrix[i][j];
                }
            }
        }
        cout<<max_num<<endl;
    }
    return 0;
}