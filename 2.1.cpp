#include <iostream>
using namespace std;
int transition(int cs, char e)
{
	if (cs == 1)
	{
		if (e == 'a')
			return 2;
		else
			return 4;
	}
	if (cs == 2 || cs == 3)
	{
		if (e == 'a')
			return 3;
		else
			return 5;
	}
	if (cs == 4)
	{
		if (e == 'a')
			return 6;
		else
			return 5;
	}
	if (cs == 5)
	{
		if (e == 'a')
			return 0;
		else
			return 5;
	}
	if (cs == 6)
	{
		if (e == 'a')
			return 0;
		else
			return 7;
	}
	if (cs == 7)
	{
		if (e == 'a')
			return 0;
		else
			return 8;
	}
	return 0;
}

bool recognized(char str[], int n)
{
	int cs = 1;
	int i = 0;
	while (i < n && cs != 0)
	{
		cs = transition(cs, str[i]);
		i++;
	}

	bool flag = false;
	int fs[4] = {2, 4, 5, 8};

	for (int j = 0; j < 4; j++)
	{
		if (fs[j] == cs)
		{
			flag = true;
			break;
		}
	}

	return flag;
}

int main()
{
	char str[10];
	int n;

	cout << "Enter the length of string: ";
	cin >> n;
	cout << "Enter the string: ";
	cin >> str;

	bool hasRecognized = recognized(str, n);

	if (hasRecognized)
	{
		cout << "The string is recognized.";
	}
	else
	{
		cout << "The string is not recognized";
	}
}