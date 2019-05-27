/* Week3.cpp : This program is made to implement stack (written by Dustin Yook) */
#include <iostream>
#include <string>
using namespace std;

/* Node */
class Node
{
public:
	int data; // data field
	Node* next; // link field

	/* Overloaded Construcotr */
	Node(int value) // work as initialize function
	{
		data = value;
		next = NULL;
	}
};

/* LinkedList */
class LinkedList
{
public:
	Node* head; // head pointer pointing at the front node
	Node* tail; // tail pointer pointer at the last node
	size_t count; // the number of elements in the list

	/* Overloaded Constructor */
	LinkedList() // work as initialize function 
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	/* Delete Operation */
	int deleteHead(void) // this operation is same both in Stack and Queue
	{
		if (isEmpty()) // if the list is empty
			return -1; // return -1 instead of exception handling
		else // if the list is non-empty
		{
			Node* rmv = head; // temporarily save value
			head = head->next; // relocate head pointer to the next front node
			int temp = rmv->data; // set return value
			delete rmv; // return memory
			count--; // decrease the number of elements in the list
			return temp;
		}
	}

	/* Insert Operation */
	void insertHead(int value)
	{
		if (isEmpty()) // if the list is empty
		{
			Node* temp = new Node(value); // generate node and set data field for new node	
			head = temp; // set head pointer to new node
			tail = temp; // set tail pointer to tail node
			count++; // increase the number of elements in the list
		}
		else // is the list is non-empty
		{
			Node* temp = new Node(value); // generate node and set data field for new node
			temp->next = head; // set link field for new node
			head = temp; // relocate head pointer to the start address of new node
			count++; // increase the number of elemtns in the list
		}
	}

	/* Empty Check Operation */
	int isEmpty() // check whether list is empty or not
	{
		return ((count == 0) ? 1 : 0);
	}

	/* Get Element Number Operation */
	int size() // return the number of elements in the list
	{
		return count;
	}

	/* Get Head Node Value Operation */
	int returnHead()
	{
		return (isEmpty() ? -1 : (head->data));
	}
};

/* Stack */
class Stack : public LinkedList
{
public:
	Node* top; // top pointer where both data insertion and deletion happens
	int max; // the maximum size for stack

	/* Overloaded Constructor */
	Stack(int value)
	{
		top = head; // set top to head
		max = value;
	}

	/* Insert Operation */
	void push(int value)
	{
		insertHead(value);
	}

	/* Delete Operation */
	int pop(void)
	{
		return deleteHead();
	}
};

int main(void)
{
	int num;
	cin >> num;
	Stack s(num);

	for (int i = 0; i < num; i++)
	{
		string cmd; // save command
		cin >> cmd;
		if (cmd == "push")
		{
			int val;
			cin >> val;
			s.push(val);
		}
		else if (cmd == "top")
			cout << s.returnHead() << endl;
		else if (cmd == "pop")
			cout << s.pop() << endl;
		else if (cmd == "size")
			cout << s.size() << endl;
		else if (cmd == "empty")
			cout << s.isEmpty() << endl;
	}

	system("pause");
	return 0;
}