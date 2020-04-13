// 链接：https://www.nowcoder.com/questionTerminal/6d9d69e3898f45169a441632b325c7b4
// 来源：牛客网

// N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
// 合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，   
// 则他们的身高满足存在i（1<=i<=K）使得T1<T2<......<Ti-1<Ti>Ti+1>......>TK。
// 你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int num;
    while(cin>>num){
        vector<int> mlist(num);
        for(int i=0;i<num;i++){
            cin>>mlist[i];
        }
        // 反向
        vector<int> rlist(mlist.rbegin(),mlist.rend());
        // vector<int, vector<int> >  dp(num, vector<int>(num,0));
        // !! 默认初始化为1
        vector<int> dp1(num,1);
        vector<int> dp2(num,1);

        // 如果有6个人，i从1遍历到5
        for(int i=1;i<num;i++){
            for(int j=0;j<i;j++){
                if(mlist[i]>mlist[j])// i 的身高大于 j
                {
                    dp1[i]=max(dp1[i],dp1[j]+1);
                }
            }
        }

        for(int i=1;i<num;i++){
            for(int j=0;j<i;j++){
                if(rlist[i]>rlist[j])// i 的身高大于 j
                {
                    dp2[i]=max(dp2[i],dp2[j]+1);
                }
            }
        }

        int max = 0;
        for(int i=0;i<num;i++){
            // dp1[i] 表示在位置i左侧有多少人是依次身高下降的
            // dp2[j] 表示在位置j左侧有多少人是依次身高下降的
            int j = num-i-1;
            if(dp1[i]+dp2[j]>max){
                max = dp1[i]+dp2[j];
            }
        }
        cout<<(num-max+1)<<endl;
    }
}