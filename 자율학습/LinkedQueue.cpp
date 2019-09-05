#include <iostream>
#include <cstddef>
#define MAX 5
using namespace std;

/* �⺻��� */
class Node
{
public:
	int number; // �������ʵ�
	Node* next; // ��ũ�ʵ�
	Node(int num) // ������ (�ʱ�ȭ)
	{
		number = num;
		next = NULL;
	}
};

/* ��ũ�帮��Ʈ */
class LinkedList
{
public:
	Node* head; // �� �� ��带 ����Ű�� ������
	Node* tail; // �� �� ��带 ����Ű�� ������
	LinkedList()
	{
		head = new Node(-1);
		tail = new Node(-1);
	}
	int deleteHead(void) // ��ũ�帮��Ʈ�� ��������
	{
		Node* temp = head; // ���� �� �ӽ�����
		int value = temp->number;
		head = head->next; // ����� ������带 ������ ����
		delete(temp); // garbage collection
		return value;
	}
	void insertTail(int value) // ��ũ�帮��Ʈ�� ���Կ���
	{
		Node* newNode = new Node(value);
		if (head->next == NULL) // ��ũ�帮��Ʈ�� �� ���
		{
			head = newNode;
			tail = newNode;
		}
		else // ��ũ�帮��Ʈ�� ���� ���� ���
		{
			newNode->next = tail->next; // ��������� next�� ���ο����� next�� ����
			tail->next = newNode; // �������ϳ���� ������带 ���ο���� ����
			tail = newNode; // ���ο��带 ���ο����ϳ��� ����
		}
	}
};

/* �⺻ ť */
class Queue
{
public:
	LinkedList* lk; // ��ũ�帮��Ʈ�� ����Ű�� ������
	size_t n; // ������ ����
	Node* front; // ������ �Ͼ�� ť�� ���� �� ���
	Node* rear; // ������ �Ͼ�� ť�� ���� �� ���
	Queue()
	{
		this->lk = new LinkedList(); // ��ü����
		this->n = 0; // ��ü ������ 0���� �ʱ�ȭ
		this->front = lk->head; // front�� head�� ����
		this->rear = lk->tail; // rear�� tail�� ����
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
			lk->insertTail(value); // value ���� ���� ��带 ����
			n++; // ��ü����� ������ �ϳ� ������Ŵ
		}
	}
	int dequeue(void)
	{
		if (isEmpty()) // true�� ��
		{
			cerr << "Underflow Exception" << endl;
			return -1;
		}
		else // false�� ��
		{
			cout << lk->deleteHead() << endl;
			n--; // ��ü����� ������ �ϳ� ���ҽ�Ŵ
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