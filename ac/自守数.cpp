#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
 
int main(){
    long n;
    while(cin>>n)
    {
        int cnt=2;   //0和2也是
        for(long i=2; i<=n; i++){
            long n2=i*i;
            string s1=to_string(i);
            string s2=to_string(n2);
            int pos=s2.size()-s1.size();
            if(s2.find(s1,pos) != -1)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
