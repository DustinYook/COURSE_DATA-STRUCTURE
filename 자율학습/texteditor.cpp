#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str; // ���ڿ� �Է¹���
	cin >> str;

	int eos; // ������ �� ��ġ
	int curr; // ���� Ŀ�� ��ġ

	eos = str.length() - 1;
	curr = eos + 1;

	int N; // ������ ������ ��
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char cmd; // ��ɾ� �Է�
		cin >> cmd;

		switch (cmd)
		{
		case 'L': // �������� Ŀ���̵�
			if (curr <= 0) // �� �տ� Ŀ���� ��ġ�� ���
				curr = 0;
			else // �� ���� �ƴ� ��ġ�� Ŀ���� ��ġ�� ���
				curr -= 1;
			break;
		case 'D': // ���������� Ŀ���̵�
			if (curr >= eos + 1) // �� �ڿ� Ŀ���� ��ġ�� ���
				curr = eos + 1;
			else // �� �ڰ� �ƴ� ��ġ�� Ŀ���� ��ġ�� ���
				curr += 1;
			break;
		case 'B': // Ŀ�� ���ʿ� ��������
			if (curr >= 1)
			{
				str.erase(curr - 1, 1); // Ŀ�� ������ ���ڸ� �ϳ� ����
				curr--; // Ŀ���� ��ġ�� �������� �ϳ� �ű�
				eos--; // ���ڿ� ������ ��ġ�� �ϳ� ���
			}
			else // curr < 1
				curr = 0; // Ŀ���� �� �տ��� �̵����� ����
			break;
		case 'P': // Ŀ�� ���ʿ� �����߰�
			char X; // �Է��� ����
			cin >> X;
			if (curr == 0) // Ŀ���� �� �տ� �ִ� ���
			{
				str.insert(str.begin(), X); // ���� ��ġ�� ���ڸ� �߰�
				curr++; // Ŀ�� ��ġ�� �ϳ� ����
				eos++; // ���ڿ� ������ ��ġ�� �ϳ� ��
			}
			else
			{
				str.insert(str.begin() + curr, X);
				curr++; // Ŀ�� ��ġ�� �ϳ� ����
				eos++; // ���ڿ� ������ ��ġ�� �ϳ� ��
			}
			break;
		}
	}
	cout << str << endl; // ���� ������ ���ڿ��� ���

	system("pause");
	return 0;
}