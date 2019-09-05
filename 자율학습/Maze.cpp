#include <iostream> 
#include <time.h> 
using namespace std;

class Stack
{
public:
	int historyX[50]; // 지나온 x 좌표 	
	int historyY[50]; // 지나온 y 좌표 	
	int pointer; // 스택의 top을 표시하는 포인터 	
	bool full; // 스택이 꽉 찼는지 확인 	

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
	int maze[10][10]; // 미로를 담을 다차원배열 	
	int x = 1; // 시작점의 x 좌표를 지정
	int y = 1; // 시작점의 y 좌표를 지정
	bool arrive = false; // 도착했는지 여부를 알려주는 플래그

	// 랜덤으로 미로생성
	srand((unsigned)time(NULL));
	// 이중 for문을 이용하여 미로배열을 초기화
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			maze[i][j] = rand() % 2;

	// 미로의 테두리를 설정
	for (int i = 0; i < 10; i++)
	{
		// 참고로 1은 벽이고, 0은 길이다
		maze[0][i] = 1; // 처음 행을 1로 만듦 		
		maze[i][0] = 1; // 처음 열은 1로 만듦
		maze[9][i] = 1; // 마지막 행을 1로 만듦
		maze[i][9] = 1; // 마지막 열을 1로 만듦
	}

	maze[1][1] = 0; // 출발지
	maze[8][8] = 0; // 도착지 	

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

		// 도착지인지 		
		if (x == 8 && y == 8)
			arrive = true;

		// 해결 불가능한 문제인지
		if (stack.pointer == 0)
		{
			cout << "cannot be solved" << endl;
			break;
		}

		// 직진이동 		
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

		// 대각선이동 		
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

		// 되돌리기	
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