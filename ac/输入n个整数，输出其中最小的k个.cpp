#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int total,min_sum;
    while(cin>>total>>min_sum)
    {
        vector<int> array;
        int temp=0;
        for(int i=0;i<total;i++)
        {
            cin>>temp;
            array.push_back(temp);
        }
        sort(array.begin(),array.end());
        for(int i=0;i<min_sum-1;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<array[min_sum-1]<<endl;
    }
    return 0;
}