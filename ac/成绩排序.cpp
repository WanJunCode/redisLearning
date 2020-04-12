#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n, bs, score[500], r[500];

bool cmp(int i,int j){
    return score[i]<score[j];
}

bool cmp1(int i,int j){
    return score[i]>score[j];
}

int main() {
    string name[500];
    int i,j,k;
    while(cin>>n>>bs)
    {
        for(i=0;i<n;i++){
            r[i]=i;
            cin>>name[i]>>score[i];
        }

        if(bs==1)
            stable_sort(r,r+n,cmp);
        else
            stable_sort(r,r+n,cmp1);

        for(i=0;i<n;i++){
            int t = r[i];
            cout << name[t]<<' '<<score[t]<<endl;
        }
    }
    return 0;
}