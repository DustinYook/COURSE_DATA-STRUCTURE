#include <iostream>
#include <cstddef>
using namespace std;
constexpr auto S_SIZE = 10; // 스택의 크기

/* 스택의 노드정의 */
template <typename E>
class Node
{
public:
	E data; // 데이터필드
	Node* next; // 링크필드
	// 생성자 (초기화)
	Node(E value) 
	{
		data = value;
		next = NULL;
	}
};

/* 스택 ADT의 구현 */
template <typename E>
class LinkedStack
{
public:
	Node<E>* head; // 링크드리스트의 가장 앞을 가리키는 포인터
	Node<E>* tail; // 링크드리스트의 가장 뒤를 가리키는 포인터
	Node<E>* sp; // 스택의 top을 가리키는 포인터 - 헤드 또는 테일 중 선택
	size_t cnt; // 스택의 크기를 저장하는 변수
	
	// 생성자
	LinkedStack()
	{
		head = NULL;
		tail = NULL;
		sp = head; // 스택포인터를 헤드로 설정 (데이터 출입구)
		cnt = 0; // 스택의 원소 개수를 0으로 초기화
	}

	// 1) 스택에 원소를 삽입하는 함수
	void push(Node<E>& n)
	{
		if (size() < S_SIZE) // 스택이 꽉 차지 않은 경우
		{
			Node<E>* temp = new Node<E>(n); // 1단계: 메모리 할당
			if (sp == NULL) // 노드가 하나도 없는 경우
			{
				head = temp; 
				tail = temp;
				sp = head;
				cnt++;
			}
			else // 노드가 이미 존재하는 경우
			{
				temp->next = head; // 2단계: 노드를 메닮
				head = temp; // 3단계: 리스트로 연결
				sp = head; // 4단계: 스택포인터 갱신
				cnt++;
			}
		}
		else // 스택이 꽉 찬 경우
		{
			cout << "stack overflow" << endl;
			/* stack overflow exception handling */
		}
	}

	// 2) 스택에서 원소를 삭제하는 함수
	Node<E>& pop(void)
	{
		Node<E>* temp = head;
		if (!isEmpty()) // 스택이 비지 않은 경우
		{
			return *temp;
			head = temp->next; // 이전 것으로 헤드를 옮김
			delete(temp); // 메모리 회수
			sp = head;
			cnt--;
		}
		else // 스택이 빈 경우
		{
			cout << "stack underflow" << endl;
			/* stack underflow exception handling */
			return *temp;
		}
	}

	// 3) 스택의 top에 있는 원소를 반환하는 함수
	Node<E>& top(void) const
	{
		if (!isEmpty()) // 스택이 비지 않은 경우
			return *sp; // 스택 포인터가 가리키는 주소에 저장된 값을 반환
		else // 스택이 빈 경우
		{
			cout << "stack underflow" << endl;
			/* stack underflow exception handling */
			return NULL;
		}
	}
	
	// 4) 스택 원소의 개수를 반환하는 함수
	size_t size(void) const
	{
		return cnt;
	}

	// 5) 스택이 비었는지 확인하는 함수
	bool isEmpty(void) const 
	{
		if (sp == NULL)
			return true;
		else
			return false;
	}
};

int main(void)
{
	LinkedStack<int> A;
	Node<int> e1(7);
	A.push(e1);
	cout << A.size() << endl;
	Node<int> e2(13);
	A.push(e2);
	cout << A.size() << endl;
	A.pop();
	cout << A.size() << endl;
	Node<int> e3(9);
	A.push(e3);
	A.pop();

	system("pause");
	return 0;
}