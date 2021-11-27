
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool lengthSortLess(const string &s1, const string &s2)
{
	return s1.length() > s2.length();  //长度大为true,则说明是按长度从大到小排序
}
bool lengthSortGreater(const string &s1, const string &s2)
{
	return s1.length() < s2.length();  //长度大为true,则说明是按长度从大到小排序
}

int main()
 {
	vector<string> re = { "2","156","0","8","4564","489798798" };
	sort(re.begin(), re.end(), lengthSortLess);
	cout << "全局函数形式的自定义排序" << endl;
	for (auto i : re)
	{
		cout << i << endl;
	}

	cout << "lambda表达式的自定义排序" << endl;
	sort(re.begin(), re.end(), [&](string s1,string s2) {
		return s1.length() < s2.length();
	});
	for (auto i : re)
	{
		cout << i << endl;
	}
	return 0;
}
