#include <iostream>
#include <cstddef>
using namespace std;
constexpr auto S_SIZE = 10; // ������ ũ��

/* ������ ������� */
template <typename E>
class Node
{
public:
	E data; // �������ʵ�
	Node* next; // ��ũ�ʵ�
	// ������ (�ʱ�ȭ)
	Node(E value) 
	{
		data = value;
		next = NULL;
	}
};

/* ���� ADT�� ���� */
template <typename E>
class LinkedStack
{
public:
	Node<E>* head; // ��ũ�帮��Ʈ�� ���� ���� ����Ű�� ������
	Node<E>* tail; // ��ũ�帮��Ʈ�� ���� �ڸ� ����Ű�� ������
	Node<E>* sp; // ������ top�� ����Ű�� ������ - ��� �Ǵ� ���� �� ����
	size_t cnt; // ������ ũ�⸦ �����ϴ� ����
	
	// ������
	LinkedStack()
	{
		head = NULL;
		tail = NULL;
		sp = head; // ���������͸� ���� ���� (������ ���Ա�)
		cnt = 0; // ������ ���� ������ 0���� �ʱ�ȭ
	}

	// 1) ���ÿ� ���Ҹ� �����ϴ� �Լ�
	void push(Node<E>& n)
	{
		if (size() < S_SIZE) // ������ �� ���� ���� ���
		{
			Node<E>* temp = new Node<E>(n); // 1�ܰ�: �޸� �Ҵ�
			if (sp == NULL) // ��尡 �ϳ��� ���� ���
			{
				head = temp; 
				tail = temp;
				sp = head;
				cnt++;
			}
			else // ��尡 �̹� �����ϴ� ���
			{
				temp->next = head; // 2�ܰ�: ��带 �޴�
				head = temp; // 3�ܰ�: ����Ʈ�� ����
				sp = head; // 4�ܰ�: ���������� ����
				cnt++;
			}
		}
		else // ������ �� �� ���
		{
			cout << "stack overflow" << endl;
			/* stack overflow exception handling */
		}
	}

	// 2) ���ÿ��� ���Ҹ� �����ϴ� �Լ�
	Node<E>& pop(void)
	{
		Node<E>* temp = head;
		if (!isEmpty()) // ������ ���� ���� ���
		{
			return *temp;
			head = temp->next; // ���� ������ ��带 �ű�
			delete(temp); // �޸� ȸ��
			sp = head;
			cnt--;
		}
		else // ������ �� ���
		{
			cout << "stack underflow" << endl;
			/* stack underflow exception handling */
			return *temp;
		}
	}

	// 3) ������ top�� �ִ� ���Ҹ� ��ȯ�ϴ� �Լ�
	Node<E>& top(void) const
	{
		if (!isEmpty()) // ������ ���� ���� ���
			return *sp; // ���� �����Ͱ� ����Ű�� �ּҿ� ����� ���� ��ȯ
		else // ������ �� ���
		{
			cout << "stack underflow" << endl;
			/* stack underflow exception handling */
			return NULL;
		}
	}
	
	// 4) ���� ������ ������ ��ȯ�ϴ� �Լ�
	size_t size(void) const
	{
		return cnt;
	}

	// 5) ������ ������� Ȯ���ϴ� �Լ�
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