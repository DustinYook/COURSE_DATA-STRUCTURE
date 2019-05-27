#include <iostream>
#include <string>
using namespace std;

int left1 = 0;
int right1 = 0;
int left2 = 0;
int right2 = 0;
int left3 = 0;
int right3 = 0;
int flag = 0;

int main(void)
{
	// 반복할 횟수를 지정함
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		// 괄호를 입력받음
		string cmd;
		cin >> cmd;

		char token;
		int num = cmd.size();

		for (int j = 0; j < num; j++)
		{
			token = cmd.at(j);

			if (token == '[')
				left1++;
			if (token == ']')
			{
				if (left1 == 0)
					flag = -1;
				right1++;
			}

			if (token == '{')
				left2++;
			if (token == '}')
			{
				if (left2 == 0)
					flag = -1;
				right2++;
			}

			if (token == '(')
				left3++;
			if (token == ')')
			{
				if (left3 == 0)
					flag = -1;
				right3++;
			}
		}

		if ((left1 != right1) || (left2 != right2) || (left3 != right3) || flag == -1)
			cout << "false" << endl;
		else
			cout << "true" << endl;

		left1 = left2 = left3 = 0;
		right1 = right2 = right3 = 0;
		flag = 0;
	}
	system("pause");
	return 0;
}