#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> ve;
        ve.push_back(a[0]);
        for(int i=1;i<n;i++){           
            if(lower_bound(ve.begin(),ve.end(),a[i])==ve.end()) 
                ve.push_back(a[i]);
            else 
                *lower_bound(ve.begin(),ve.end(),a[i])=a[i];  
        }
        cout<<ve.size()<<endl;
    }
    return 0;
}