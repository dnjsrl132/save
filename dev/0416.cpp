#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num = 0;
	int i = 1;
	string s;
	getline(cin, s);
	while (s[i+1] != '\0') {
		if (s[i] == ' '&&s[i-1]!=' ') num++;
		i++;
	}
	cout << num+1;
	return 0;
}
