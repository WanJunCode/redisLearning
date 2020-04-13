// 简单错误记录
// 开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
// 处理：
// 1、 记录最多8条错误记录，循环记录（或者说最后只输出最后出现的八条错误记录），对相同的错误记录（净文件名称和行号完全匹配）
//     只记录一条，错误计数增加；
// 2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
// 3、 输入的文件可能带路径，记录文件名称不能带路径。
#include <iostream>
#include <string.h>
using namespace std;
  
struct memory
{
    char s[100];
    int line;
    int count;
};
int main()
{
    char input[100];
    int line;
    int cnt = 0;
    memory record[1000];
    while(cin>>input>>line)
    {
        char *p = strrchr(input, '\\');
        p++;
        if(strlen(p) > 16)
        {
            p = p + strlen(p) - 16;
        }
        int flag = 0;
          
        for(int i = 0; i < cnt; i++)
        {
            if(strcmp(record[i].s, p) == 0)
            {
                if(record[i].line == line)
                {
                    flag = 1;
                    record[i].count++;
                    break;
                }
            }
                  
        }
        if(!flag)
        {
            strcpy(record[cnt].s, p);
            record[cnt].line  = line;
            record[cnt].count = 1;
            cnt++;
        }      
    }
    int j;
    if(cnt > 8)
        j = cnt - 8;
    else
        j = 0;
    for(;j < cnt; j++)
    {
        cout << record[j].s << ' ' << record[j].line << ' ' << record[j].count << endl;
    }
    return 0;
}