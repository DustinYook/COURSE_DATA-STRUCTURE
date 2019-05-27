#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node* head;
	Node* tail;
	int count;

	LinkedList()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	int deleteHead(void)
	{
		if (isEmpty())
			return -1;
		else
		{
			Node* rmv = head;
			int temp = rmv->data;
			head = head->next;
			delete rmv;
			count--;
			return temp;
		}
	}

	void insertHead(int value)
	{
		if (isEmpty())
		{
			Node* temp = new Node(value); // 노드생성
			head = temp;
			tail = temp;
			count++;
		}
		else
		{
			Node* temp = new Node(value); // 노드생성
			temp->next = head; // 메달기
			head = temp; // 멤버로 인정
			count++;
		}
	}

	bool isEmpty(void)
	{
		return (count == 0);
	}

	int size(void)
	{
		return count;
	}

	int getHead(void)
	{
		return head->data;
	}
};

class Stack : public LinkedList
{
public:
	Node* top;
	int max;

	Stack(int value)
	{
		top = head;
		head = top;
		max = value;
	}

	void push(int value)
	{
		insertHead(value);
	}

	int pop(void)
	{
		return deleteHead();
	}

	int size(void)
	{
		return count;
	}

	int Top(void)
	{
		return (isEmpty() ? -1 : getHead());
	}
};

int main(void)
{
	int num;
	cin >> num;
	Stack s(num);

	for (int i = 0; i < num; i++)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int input;
			cin >> input;
			s.insertHead(input);
		}
		else if (cmd == "pop")
			cout << s.deleteHead() << endl;
		else if (cmd == "size")
			cout << s.size() << endl;
		else if (cmd == "top")
			cout << s.Top() << endl;
		else if (cmd == "empty")
			cout << ((s.isEmpty() == 1) ? "true" : "false") << endl;
	}

	system("pause");
	return 0;
}