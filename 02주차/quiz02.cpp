#include<iostream>
using namespace std;

/* Node */
class Node
{
public:
	int number; // 데이터필드
	Node* next; // 링크필드
	Node(int num) // 생성자 (초기화)
	{
		number = num;
		next = NULL;
	}
};

/* Circular LinkedList */
class Circular
{
public:
	Node* head; // 헤드노드를 가리키는 포인터
	Node* now; // 현재 커서 위치를 가리키는 포인터

	// 1) 생성자
	Circular()
	{
		head = NULL;
		now = NULL;
	}

	// 2) 노드삽입
	void insert_Node(Node* newNode)
	{
		// list가 비어있는 경우
		if (head == NULL)
		{
			head = newNode; // head는 새로 생성된 노드를 가리킴
			now = newNode; // now는 새로 생성된 노드를 가리킴
			newNode->next = newNode; // 자기 자신을 가리키게 함 (환형이기 때문)
		}
		// list에 노드가 있는 경우
		else
		{
			now->next = newNode;
			now = newNode;
			now->next = head;
		}
	}

	// 3) 노드삭제
	void delete_Node(int M)
	{
		int count = 1;
		Node* prev = NULL;

		while (count != M)
		{
			prev = now;
			now = now->next;
			count++; // 카운트를 하나씩 증가시킴
			// 반복문을 사용하여 1부터 순서를세면서 M번째 노드까지 이동
		}
		cout << (now->number); // 삭제되는 노드의 값 출력 - 슬라이드에서 체크 표시된 값
		prev->next = now->next;
		now = now->next;
	}
};

int main(void)
{
	int N, M;
	cin >> N >> M; // 변수 N과 M 입력 

	Circular circular; // Circular Linked List 생성
	for (int i = 1; i <= N; i++)
	{
		Node* newNode = new Node(i); // Node 생성 한 뒤
		circular.insert_Node(newNode); // Ciruclar List에 삽입
	}
	circular.now = circular.head;

	cout << "<";
	while (N--)
	{
		circular.delete_Node(M); // Circular List에서 노드 하나씩 삭제
		if (N != 0)
			cout << ", ";
	}
	cout << ">";

	return 0;
}