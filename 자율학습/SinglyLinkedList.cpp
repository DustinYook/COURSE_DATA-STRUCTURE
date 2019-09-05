#include<iostream>
using namespace std;

/* 링크드리스트의 노드 */
class Node
{
public:
	int data; // 데이터필드
	Node* link; // 링크필드
	Node(int num)
	{
		data = num;
		link = NULL;
	}
};

/* 단일링크드리스트 */
class SinglyLinkedList
{
public:
	Node* head; // 리스트의 헤드노드를 가리키는 포인터
	Node* tail; // 리스트의 테일노드를 가리키는 포인터

	// 생성자 함수 : head와 tail 포인터를 NULL로 초기화
	SinglyLinkedList()
	{
		head = NULL;
		tail = NULL;
	};

	void insert_Node(int number)
	{
		// 단일 링크드 리스트 삽입
		// 새로운 노드를 생성하고, 가장 앞 노드를 가리키는 포인터인 head를 업데이트 시켜준다
		// 강의자료 7p 참조

		// 초기에 리스트가 비어있는 경우
		if (head == NULL)
		{
			// head가 가리키는것이 없는 경우, 즉 리스트에 어떠한 노드도 없을때 처리
			Node* newNode = new Node(number);
			newNode->data = number; // 새로운 노드 데이터 설정
			newNode->link= tail; // 테일노드를 가리키는 포인터 설정
			head = newNode; // 헤드노드를 가리키는 포인터 설정
		}
		else
		{
			// head가 가리키는것이 있는 경우 처리
			Node* newNode = new Node(number);
			newNode->data = number;
			newNode->link = head; // 새로운 노드가 기존의 head를 가리킨다.
			head = newNode; // head는 새로운 노드가 된다.
		}
	}

	void delete_Node()
	{
		// 단일 링크드 리스트 삭제
		// 노드를 삭제하고 head를 업데이트 시킨다
		// 강의자료 8p 참조
		if (head != NULL)
		{
			// 삭제할 노드가 있을 경우 처리
			Node* prev = head;
			head = head->link; // 기존 head의 다음 노드를 head로 변경
			delete prev; // 노드의 메모리 해제
		}
	}

	void traverseNodes()
	{
		Node* ptr;

		/* for문을 이용하여 구현 */
		for (ptr = head; ptr != NULL; ptr = ptr->link)
			cout << (ptr->data) << " ";
		cout << endl;

		/* while문을 이용하여 구현 */
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->link;
		}
	}
};

int main()
{
	SinglyLinkedList sl;

	sl.insert_Node(5);
	sl.insert_Node(10);
	sl.insert_Node(3);
	sl.traverseNodes();

	system("pause");
	return 0;
}