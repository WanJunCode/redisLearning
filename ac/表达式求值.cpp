// 链接：https://www.nowcoder.com/questionTerminal/9566499a2e1546c0a257e885dfdbf30d
// 来源：牛客网

// 给定一个字符串描述的算术表达式，计算出结果值。
// 输入字符串长度不超过100，合法的字符包括”+, -, *, /, (, )”，”0-9”，字符串内容的合法性及表达式语法的合法性由做题者检查。
// 本题目只涉及整型计算。

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		stack<char> opera;
		vector<int> numcnt;
		string s1;//后缀表达式

		//中缀表达式转后缀表达式
		for (int i = 0; i<s.size(); i++)
		{
			// 获得数值，存入 numcnt
			if ( s[i] >= '0'&&s[i] <= '9' )
			{
				int tmp = 0;
				while (s[i] >= '0'&&s[i] <= '9')
				{
					tmp++;
					s1 += s[i];
					i++;
				}
				i--;
				numcnt.push_back(tmp);
			}
			else if ( s[i] == '-' || s[i] == '+' )
			{
				if (s[i] == '-' && (s[i - 1] == '(' ))
					s1 += '0';
				while (!opera.empty() && (opera.top() == '*' || opera.top() == '/' || opera.top() == '+' || opera.top() == '-'))
				{
					s1 += opera.top();
					opera.pop();
				}
				opera.push(s[i]);
			}
			else if ( s[i] == '*' || s[i] == '/' )
			{
				while (!opera.empty() && (opera.top() == '*' || opera.top() == '/'))
				{
					s1 += opera.top();
					opera.pop();
				}
				opera.push(s[i]);
			}
			else if ( s[i] == '(' )
				opera.push(s[i]);
			else if ( s[i] == ')' )
			{
				while (opera.top() != '(')
				{
					s1 += opera.top();
					opera.pop();
				}
				opera.pop();
			}
			else
				cout << "Invalid input!" << endl;
		}

		while (!opera.empty())
		{
			s1 += opera.top();
			opera.pop();
		}

		//计算后缀表达式的值
		stack<int> nums;
		int ind = 0;
		for (int i = 0; i<s1.size(); i++)
		{
			if (s1[i] >= '0'&&s1[i] <= '9')
			{
				int total = 0;
				while (numcnt[ind]--)
					total = 10 * total + (s1[i++] - '0');
				i--;
				nums.push(total);
				ind++;
			}
			else
			{
				int tmp1 = nums.top();
				nums.pop();
				int tmp2 = nums.top();
				nums.pop();
				if (s1[i] == '+')
					nums.push(tmp2 + tmp1);
				else if (s1[i] == '-')
					nums.push(tmp2 - tmp1);
				else if (s1[i] == '*')
					nums.push(tmp2*tmp1);
				else
					nums.push(tmp2 / tmp1);
			}
		}
		cout << nums.top() << endl;
	}
}