#include <iostream>
using namespace std;

int main()
{
	int n;			// 子串长度
	string str;		// 基因序列
	while(cin>>str>>n){
		double maxRatio=0;
		string maxRatioStr;
		for(int i=0;i<=str.size()-n;i++){
			string subStr=str.substr(i,n);
			int cnt[4]={0};
			for(auto c:subStr)
            {
				if(c=='A')cnt[0]++;
				else if(c=='C')cnt[1]++;
				else if(c=='G')cnt[2]++;
				else if(c=='T')cnt[3]++;
			}
			double gcRatio=(double)(cnt[1]+cnt[2])/subStr.size();
			if(gcRatio>maxRatio)
            {
				maxRatio=gcRatio;
				maxRatioStr=subStr;
			}
		}
		cout<<maxRatioStr<<endl;
	}
	return 0;
}