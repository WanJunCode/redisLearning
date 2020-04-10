// 链接：https://www.nowcoder.com/questionTerminal/81544a4989df4109b33c2d65037c5836
// 来源：牛客网
// 对字符串中的所有单词进行倒排。
// 说明：
// 1、每个单词是以26个大写或小写英文字母构成；
// 2、非构成单词的字符均视为单词间隔符；
// 3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
// 4、每个单词最长20个字母；

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
 
int main(){
    stack<string> ss;
    string str;
    while(getline(cin,str)){
        string temp;
        if(str.length()<1)
            continue;
        for(int i=0;i<=str.length();i++)
        {
            if(std::isalpha(str[i])){
                temp+=str[i];
            }else{
                if(temp.length()>0)
                {
                    ss.push(temp);
                    temp.clear();
                }
            }
        }

        while(!ss.empty())
        {
            cout<<ss.top();
            ss.pop();
            if(!ss.empty())
                cout<<" ";
            else
                cout<<endl;
        }
    }
    return 0;
}