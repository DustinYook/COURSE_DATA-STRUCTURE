#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str; // 문자열 입력받음
	cin >> str;

	int eos; // 문장의 끝 위치
	int curr; // 현재 커서 위치

	eos = str.length() - 1;
	curr = eos + 1;

	int N; // 수행할 연산의 수
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char cmd; // 명령어 입력
		cin >> cmd;

		switch (cmd)
		{
		case 'L': // 왼쪽으로 커서이동
			if (curr <= 0) // 맨 앞에 커서가 위치한 경우
				curr = 0;
			else // 맨 앞이 아닌 위치에 커서가 위치한 경우
				curr -= 1;
			break;
		case 'D': // 오른쪽으로 커서이동
			if (curr >= eos + 1) // 맨 뒤에 커서가 위치한 경우
				curr = eos + 1;
			else // 맨 뒤가 아닌 위치에 커서가 위치한 경우
				curr += 1;
			break;
		case 'B': // 커서 왼쪽에 문자제거
			if (curr >= 1)
			{
				str.erase(curr - 1, 1); // 커서 왼쪽의 문자를 하나 지움
				curr--; // 커서의 위치를 왼쪽으로 하나 옮김
				eos--; // 문자열 마지막 위치를 하나 당김
			}
			else // curr < 1
				curr = 0; // 커서가 맨 앞에서 이동하지 않음
			break;
		case 'P': // 커서 왼쪽에 문자추가
			char X; // 입력할 문자
			cin >> X;
			if (curr == 0) // 커서가 맨 앞에 있는 경우
			{
				str.insert(str.begin(), X); // 시작 위치에 문자를 추가
				curr++; // 커서 위치가 하나 증가
				eos++; // 문자열 마지막 위치를 하나 밈
			}
			else
			{
				str.insert(str.begin() + curr, X);
				curr++; // 커서 위치가 하나 증가
				eos++; // 문자열 마지막 위치를 하나 밈
			}
			break;
		}
	}
	cout << str << endl; // 최종 편집된 문자열을 출력

	system("pause");
	return 0;
}