#include <iostream> 
#include <time.h> 
using namespace std;

class Stack
{
public:
	int historyX[50]; // ������ x ��ǥ 	
	int historyY[50]; // ������ y ��ǥ 	
	int pointer; // ������ top�� ǥ���ϴ� ������ 	
	bool full; // ������ �� á���� Ȯ�� 	

	Stack()
	{
		pointer = 1;
		full = false;
	}

	void push(int x, int y)
	{
		if (!full)
		{
			historyX[pointer - 1] = x;
			historyY[pointer - 1] = y;
			pointer++;
			if (pointer == 51)
				full = true;
		}
	}

	void pop()
	{
		if (pointer == 1)
			pointer = 0;
		else
		{
			historyX[pointer - 1] = -1;
			historyY[pointer - 1] = -1;
			pointer--;
		}
	}

	void print()
	{
		for (int i = pointer - 2; i >= 0; i--)
			cout << historyX[i] << " " << historyY[i] << endl;
	}
};

int main()
{
	Stack stack;
	int maze[10][10]; // �̷θ� ���� �������迭 	
	int x = 1; // �������� x ��ǥ�� ����
	int y = 1; // �������� y ��ǥ�� ����
	bool arrive = false; // �����ߴ��� ���θ� �˷��ִ� �÷���

	// �������� �̷λ���
	srand((unsigned)time(NULL));
	// ���� for���� �̿��Ͽ� �̷ι迭�� �ʱ�ȭ
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maze[i][j] = rand() % 2;

	// �̷��� �׵θ��� ����
	for (int i = 0; i < 10; i++)
	{
		// ����� 1�� ���̰�, 0�� ���̴�
		maze[0][i] = 1; // ó�� ���� 1�� ���� 		
		maze[i][0] = 1; // ó�� ���� 1�� ����
		maze[9][i] = 1; // ������ ���� 1�� ����
		maze[i][9] = 1; // ������ ���� 1�� ����
	}

	maze[1][1] = 0; // �����
	maze[8][8] = 0; // ������ 	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << maze[j][i] << " ";
		cout << endl;
	}

	while (!arrive)
	{
		system("cls");
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				cout << maze[j][i] << " ";
			cout << endl;
		}

		// ���������� 		
		if (x == 8 && y == 8)
			arrive = true;

		// �ذ� �Ұ����� ��������
		if (stack.pointer == 0)
		{
			cout << "cannot be solved" << endl;
			break;
		}

		// �����̵� 		
		if (maze[x + 1][y] == 0)
		{
			maze[x + 1][y] = 2;
			stack.push(x, y);
			x = x + 1;
		}
		else if (maze[x][y + 1] == 0)
		{
			maze[x][y + 1] = 2;
			stack.push(x, y);
			y = y + 1;
		}
		else if (maze[x - 1][y] == 0)
		{
			maze[x - 1][y] = 2;
			stack.push(x, y);
			x = x - 1;
		}
		else if (maze[x][y - 1] == 0)
		{
			maze[x][y - 1] = 2;
			stack.push(x, y);
			y = y - 1;
		}

		// �밢���̵� 		
		else if (maze[x - 1][y - 1] == 0)
		{
			maze[x - 1][y - 1] = 2;
			stack.push(x, y);
			x = x - 1;
			y = y - 1;
		}
		else if (maze[x + 1][y - 1] == 0)
		{
			maze[x + 1][y - 1] = 2;
			stack.push(x, y);
			x = x + 1;
			y = y - 1;
		}
		else if (maze[x - 1][y + 1] == 0)
		{
			maze[x - 1][y + 1] = 2;
			stack.push(x, y);
			x = x - 1;
			y = y + 1;
		}
		else if (maze[x + 1][y + 1] == 0)
		{
			maze[x + 1][y + 1] = 2;
			stack.push(x, y);
			x = x + 1;
			y = y + 1;
		}

		// �ǵ�����	
		else
		{
			stack.pop();
			x = stack.historyX[stack.pointer - 1];
			y = stack.historyY[stack.pointer - 1];
		}
	}
	stack.print();

	system("pause");
	return 0;
}