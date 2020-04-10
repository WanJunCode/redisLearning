#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
 
int main(){
    int n;
    vector<int>  ivec;
    while(cin>>n)
    {
        ivec.clear();
        ivec.resize(n);
        int negcount=0;
        int poscount=0;
        for(int i=0;i<n;i++)
        {
            cin>>ivec[i];
        }
        float sum=0;
        for(int i=0;i<n;++i)
        {
            if(ivec[i]>0){
                sum+=ivec[i];
                poscount++;
            }else if(ivec[i]<0){
                negcount++;
            }
        }
        cout<<negcount<<" ";
        printf("%0.1f\n",sum/poscount);
    }
    return 0;
}