/* Week4.cpp : This program is made to implement queue (written by Dustin Yook) */
#include <iostream>
#include <string>
using namespace std;

// Common Module for Stack and Queue

/* Node */
class Node
{
public:
	int data; // Data field
	Node* next; // Link field

	/* Overloaded Constructor */
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
	Node* head; // head pointer pointing at the front Node
	Node* tail; // taile pointer pointing at the last Node
	int count; // the number of elements in the list

	/* Overloaded Constructor */
	LinkedList() // work as initialize function
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	/* Delete Operation */
	int deleteHead(void)
	{
		if (isEmpty()) // if the list is empty
			return -1; // return -1 instead of exception handling
		else // if the list is non-empty
		{
			Node* rmv = head; // temporarily save the value
			int temp = rmv->data; // set the return value
			head = head->next; // relocate head pointer the second front node
			delete rmv; // return memory to prevent dangling pointer
			count--; // decrease the number of elements in the list
			return temp;
		}
	}

	/* Insert Operation */
	void insertTail(int value)
	{
		if (isEmpty()) // if the list is empty
		{
			Node* temp = new Node(value); // generate new node
			head = temp; // set head pointer to new node
			tail = temp; // set tail pointer to new node
			count++; // increase the number of elements in the list
		}
		else // if the list is non-empty
		{
			Node* temp = new Node(value); // generate node and set data field for new node
			temp->next = tail->next; // set link field for new node
			tail->next = temp; // hang new node up on list
			tail = temp; // 
			count++; // increase the number of elements in the list
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

	/* Get Head Value Operation */
	int getHead() // return data field value for head node
	{
		return (isEmpty() ? -1 : head->data);
	}

	/* Get Tail Value Operation */
	int getTail() // return data field value for tail node
	{
		return (isEmpty() ? -1 : tail->data);
	}
};

/* Queue */
class Queue : public LinkedList // warning: YOU MUST INHERIT FROM THE LINKED_LIST CLASS 
{
public:
	Node* front; // front pointer where data deletion happens
	Node* rear; // rear pointer where data insertion happens
	int max; // the maximum size of the queue

	/* Overloaded Constructor */
	Queue(int value) // work as initialize function
	{
		// YOU MUST SET FRONT TO HEAD TO GUARANTEE O(1) TIME COMPLEXITY
		front = head; // set front to head
		rear = tail; // set rear to tail
		max = value; // set the maximum size of the queue
	}

	/* Insert Operation */
	void push(int value) // the name should be 'enqueue'
	{
		insertTail(value);
	}

	/* Delete Operation */
	int pop(void) // the name should be 'dequeue'
	{
		return deleteHead();
	}
};

int main(void)
{
	int num;
	cin >> num;
	Queue q(num);

	for (int i = 0; i < num; i++)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int input;
			cin >> input;
			q.push(input);
		}
		else if (cmd == "pop")
			cout << q.pop() << endl;
		else if (cmd == "size")
			cout << q.size() << endl;
		else if (cmd == "empty")
			cout << q.isEmpty() << endl;
		else if (cmd == "front")
			cout << q.getHead() << endl;
		else if (cmd == "back")
			cout << q.getTail() << endl;
	}

	system("pause");
	return 0;
}