// 输入一个字符串和一个字符，统计该字符在该字符串中出现的次数。
// for循环比较即可，没什么好说的
// 不区分大小写

#include <iostream>
#include <string>

using namespace std;

int main(int argc,char **argv)
{
    string str;
    char c;

    getline(cin,str);
    cin>>c;

    int count=0;
    for(int i=0;i<str.size();++i)
    {
        if(tolower(str[i])==tolower(c))
            ++count;
    }
    cout << count<<endl;
    return 0;
}