// 链接：https://www.nowcoder.com/questionTerminal/6d9d69e3898f45169a441632b325c7b4
// 来源：牛客网

// N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
// 合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，   
// 则他们的身高满足存在i（1<=i<=K）使得T1<T2<......<Ti-1<Ti>Ti+1>......>TK。
// 你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
    	vector<int> a(n);
        vector<int> dp1(n+1,1);//
        vector<int> dp2(n+1,1);//
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        // 翻转
        vector<int> ra(a.rbegin(),a.rend());

        for(int i=1;i<a.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                if(a[i]>a[j])
                {
                    dp1[i]=max(dp1[i],dp1[j]+1);
                }
            }
        }
        
        for(int i=1;i<ra.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                if(ra[i]>ra[j])
                {
                    dp2[i]=max(dp2[i],dp2[j]+1);
                }
            }
        }

        int mm=std::numeric_limits<int>::min();
        for(int i=0;i<a.size();++i)
        {
            int j=a.size()-i-1;
            if(dp1[i]+dp2[j]>mm)
            {
                mm=dp1[i]+dp2[j];
            }
        }
        cout<<a.size()-mm+1<<endl;
    }

    return 0;
}