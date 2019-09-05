#include <iostream>
#include <cstddef>
#define MAX 5
using namespace std;

/* 기본노드 */
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

/* 링크드리스트 */
class LinkedList
{
public:
	Node* head; // 맨 앞 노드를 가리키는 포인터
	Node* tail; // 맨 뒤 노드를 가리키는 포인터
	LinkedList()
	{
		head = new Node(-1);
		tail = new Node(-1);
	}
	int deleteHead(void) // 링크드리스트의 삭제연산
	{
		Node* temp = head; // 삭제 전 임시저장
		int value = temp->number;
		head = head->next; // 헤드노드 다음노드를 헤드노드로 지정
		delete(temp); // garbage collection
		return value;
	}
	void insertTail(int value) // 링크드리스트의 삽입연산
	{
		Node* newNode = new Node(value);
		if (head->next == NULL) // 링크드리스트가 빈 경우
		{
			head = newNode;
			tail = newNode;
		}
		else // 링크드리스트가 비지 않은 경우
		{
			newNode->next = tail->next; // 기존노드의 next를 새로운노드의 next로 지정
			tail->next = newNode; // 기존테일노드의 다음노드를 새로운노드로 지정
			tail = newNode; // 새로운노드를 새로운테일노드로 지정
		}
	}
};

/* 기본 큐 */
class Queue
{
public:
	LinkedList* lk; // 링크드리스트를 가리키는 포인터
	size_t n; // 원소의 개수
	Node* front; // 삭제가 일어나는 큐의 가장 앞 노드
	Node* rear; // 삽입이 일어나는 큐의 가장 뒤 노드
	Queue()
	{
		this->lk = new LinkedList(); // 객체생성
		this->n = 0; // 전체 개수를 0으로 초기화
		this->front = lk->head; // front와 head를 연결
		this->rear = lk->tail; // rear와 tail을 연결
	}
	size_t size(void)
	{
		return n;
	}
	bool isEmpty(void)
	{
		return (n == 0);
	}
	void enqueue(int value)
	{
		if (size() >= MAX)
			cerr << "Overflow Exception" << endl;
		else
		{
			lk->insertTail(value); // value 값을 가진 노드를 삽입
			n++; // 전체노드의 개수를 하나 증가시킴
		}
	}
	int dequeue(void)
	{
		if (isEmpty()) // true일 때
		{
			cerr << "Underflow Exception" << endl;
			return -1;
		}
		else // false일 때
		{
			cout << lk->deleteHead() << endl;
			n--; // 전체노드의 개수를 하나 감소시킴
		}
	}
	void traverseNodes(void)
	{
		Node* nPtr;
		for (nPtr = (this->lk)->head; nPtr != NULL; nPtr = nPtr->next)
			cout << (nPtr->number) << " ";
		cout << endl;
	}
};

int main(void)
{
	Queue* q = new Queue();
	q->enqueue(5);
	q->enqueue(3);
	q->dequeue();
	system("pause");
	return 0;
}