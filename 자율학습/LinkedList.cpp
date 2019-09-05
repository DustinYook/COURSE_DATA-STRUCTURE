#include <iostream>
#include <cstddef>
using namespace std;

/* Node */
class Node
{
public:
	int data; // data field
	Node* next; // link field

	/* overloaded constructor for initializing object */
	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

/* LinkedList */
class LinkedList
{
public:
	Node* head; // the pointer pointing the front Node object
	Node* tail; // the pointer pointing the last Node object
	size_t count; // the number of elements in the list

	/* Overloaded Constructor */
	LinkedList() // initializing object
	{
		head = NULL; // set head pointer to new node
		tail = NULL; // set tail pointer to new node
		count = 0; // set count to 0
	}

	/* Delete Operation */
	void deleteHead(void) // delete at head node
	{
		if (isEmpty()) // when the LinkedList is empty
			cerr << "underflow exception" << endl;
		else // when the LinkedList is not empty
		{
			Node* temp = head; // temporarily saves target Node object in temp
			head = head->next; // relocate head pointer to the second-front Node object
			delete temp; // delete temp from the memory to prevent dangling pointer		
			count--; // decrease the number of nodes in the LinkedList
		}
	}

	/* Insert Operation */
	void insertTail(int value) // insert at tail node
	{
		if (isEmpty()) // when the LinkedList is empty
		{
			Node* temp = new Node(value); // create a node
			head = temp; // set head pointer to new node
			tail = temp; // set tail pointer to tail node
			count++; // increase the number of nodes in the LinkedList
		}
		else // when the LinkedList is not empty
		{
			Node* temp = new Node(value); // create a node
			tail->next = temp; // hang a new node up on the tail
			tail = temp; // relocate tail pointer to the new node
			count++; // increase the number of nodes in the LinkedList
		}
	}

	// Auxiliary Operations

	/* Check Empty Operation */
	bool isEmpty() // check whether the LinkedList is empty or not
	{
		return (count == 0);
	}

	/* Get Element Number Operation */
	size_t size() // return the number of elements in the LinkedList
	{
		return count;
	}
	
	/* Traverse Operation */
	void traverseNodes() // traverse all nodes in the LinkedList
	{
		for (Node* ptr = head; ptr != NULL; ptr = ptr->next)
			cout << (ptr->data) << " ";
		cout << endl;
	}
};

int main(void)
{
	LinkedList l;

	// insert operation and the result
	for (size_t i = 0; i < 10; i++)
	{
		l.insertTail(i);
		l.traverseNodes();
	}
	
	// delete operation and the result
	for (size_t i = 0; i < 10; i++)
	{
		l.deleteHead();
		l.traverseNodes();
	}
	
	system("pause");
	return 0;
}