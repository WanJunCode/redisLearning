// 题目描述：开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，
// 从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。输入：合法坐标为A(或者D或者W或者S) + 数字（两位以内），
// 坐标之间以“;”分隔。非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。
// 例如：输入A10;S20;W10;D30;X;A1A;B10A11;;A10;，输出10,-10。

#include <iostream>
#include <string>
#include <cstddef>   //std::size_t
using namespace std;
 
int main()
{
	string str;
	while (cin >> str) {
		pair<int, int> point(0, 0);               //point.first point.second
		size_t found = str.find_first_of(';');  //找到第一个';'的位置
		int start = 0;
 
		while (found != string::npos) {
			string s1 = str.substr(start, found - start);
			start = found + 1;
			found = str.find_first_of(';', found + 1);
 
			if (s1.size()>1 && s1.size() <= 3) {    //合法的字符个数：2或3
				char c = s1[0];
				int n = 0;
				int invalid = 0;    //数字为是否非法
				for (int i = 1; i<s1.size(); ++i) { //数字位判断与提取，A1A
					// 判断数字是否合法
					if (s1[i] >= '0'&&s1[i] <= '9')
						n = n * 10 + (s1[i] - '0');
					else {
						invalid = 1;
						break;
					}
				}
				if (invalid == 0) {
					switch (c)
					{
					case 'A': {point.first -= n; break; }
					case 'D': {point.first += n; break; }
					case 'W': {point.second += n; break; }
					case 'S': {point.second -= n; break; }
					}
				}
 
			}
		}
		cout << point.first << ',' << point.second << endl;
	}
 
	return 0;
}