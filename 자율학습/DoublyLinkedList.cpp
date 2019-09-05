#include <iostream>
using namespace std;

class Node
{
public:
	char data; // 데이터필드
	Node* prev; // 링크필드1
	Node* next; // 링크필드2

	Node(char value)
	{
		data = value;
		prev = NULL;
		next = NULL;
	}
};

class DoublyLinkedList
{
public:
	Node* head; // 가장 앞 노드를 가리키는 포인터
	Node* tail; // 가장 뒤 노드를 가리키는 포인터
	int count;

	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	void insert(int p, char x) // 입력위치, 입력값 -> p의 앞에 노드를 삽입
	{
		if (p != 0 && p <= count) // 입력 값이 유효한 경우
		{
			Node* ptr; // 원하는 위치(p)를 저장할 변수
			int now = 0; // 위치를 카운트하기 위해 사용하는 변수
			for (ptr = head; ptr != NULL; ptr = ptr->next) // 노드 전체 순회
			{
				if (now == p) // 원하는 위치인지 확인
					break;
				now++;
			}
			if (ptr->prev == head) // 삽입하는 위치의 앞 노드가 head인 경우
			{
				// 1단계 : 노드생성
				Node* temp = new Node(x); 
				// 2단계 : 새로운 노드를 메닮 - 중요) 항상 새로운 노드부터 처리
				temp->prev = head; 
				temp->next = head; 
				// 3단계 : 기존 노드의 링크필드를 수정
				head = temp;
				(temp->next)->prev = temp;
				// 4단계 : 리스트 전체의 카운트를 증가
				count++;
			}
			else // 삽입하는 위치의 앞 노드가 head가 아닌 경우
			{
				// 1단계 : 노드생성
				Node* temp = new Node(x);
				// 2단계 : 새로운 노드를 기존 리스트에 메닮 - 중요) 항상 새로운 노드부터 처리
				temp->prev = ptr->prev;
				temp->next = ptr;
				// 3단계 : 기존 노드의 링크필드를 수정
				(temp->prev)->next = temp;
				ptr->prev = temp;
				// 4단계 : 리스트 전체의 카운트를 증가
				count++;
			}
		}
		else // 입력값이 유효하지 않은 경우
			cerr << "잘못된 명령입니다." << endl;
	}

	void insert(char x) // head에 insert
	{
		if (count == 0) // 리스트가 빈 경우
		{
			// 1단계 : 새로운 노드 생성
			Node* temp = new Node(x); 
			// 2단계 : 새로운 노드를 기존 리스트에 메닮
			temp->prev = head;
			temp->next = tail;
			// 3단계 : 기존 노드의 링크필드를 수정
			head = temp;
			tail = temp;
			// 4단계 : 리스트 전체의 카운트를 증가
			count++;
		}
		else // 리스트가 비어있지 않은 경우
		{
			// 1단계 : 새로운 노드 생성
			Node* temp = new Node(x);
			// 2단계 : 새로운 노드를 기존 리스트에 메닮
			temp->prev = head;
			temp->next = head; // head가 포인터인 경우 head->next는 없음
			// 3단계 : 기존 노드의 링크필드를 수정
			head = temp;
			(temp->next)->prev = temp;
			// 4단계 : 리스트 전체의 카운트를 증가
			count++;
		}
	}

	void remove(int p) // p번째 위치의 저장값을 삭제
	{
		if (p != 0 && p < count) // 입력값이 유효한 경우
		{
			/* 삭제할 위치에 해당되는 노드를 찾는 처리 */
			Node* ptr; // 원하는 위치(p)를 저장할 변수
			int now = 0; // 위치를 카운트하기 위해 사용하는 변수
			for (ptr = head; ptr != NULL; ptr = ptr->next) // 노드 전체 순회
			{
				if (now == p) // 원하는 위치인지 확인
					break;
				now++;
			}

			if (ptr->next != tail) // 대상 노드의 다음 노드가 tail이 아닌 경우
			{
				// 1단계 : 삭제할 노드 포인터를 임시저장
				Node* rmv = ptr;
				// 2단계 : 기존 노드의 링크필드를 수정
				(ptr->prev)->next = ptr->next;
				(ptr->next)->prev = ptr->prev;
				// 3단계 : 메모리 회수
				delete rmv;
				// 4단계 : 리스트 전체의 카운트 감소
				count--;
			}
			else // 대상 노드의 다음 노드가 tail인 경우
			{
				// 1단계 : 삭제할 노드 포인터를 임시저장
				Node* rmv = ptr;
				// 2단계 : 기존 노드의 링크필드를 수정
				(ptr->prev)->next = tail;
				tail = ptr->prev;
				// 3단계 : 메모리 회수
				delete rmv;
				// 4단계 : 리스트 전체의 카운트 감소
				count--;
			}
		}
		else // 입력값이 유효하지 않은 경우
			cerr << "잘못된 명령입니다." << endl;
	}

	void traverse(void) // 순회
	{
		for (Node* ptr = head; ptr != NULL; ptr = ptr->next)
			cout << (ptr->data) << " ";
		cout << endl;
	}
};

int main(void)
{
	DoublyLinkedList d;
	for (char c = 'a'; c <= 'd'; c++)
		d.insert(c);
	d.traverse();

	d.insert(2, 'x');
	d.traverse();

	d.insert(0, 'y'); // insert(0, x)인 경우에 에러
	d.traverse();

	d.insert(3, 'y');
	d.traverse();

	d.insert(1, 'z');
	d.traverse();

	d.remove(2);
	d.traverse();

	d.remove(0);
	d.traverse();

	system("pause");
	return 0;
}