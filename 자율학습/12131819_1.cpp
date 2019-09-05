#include <iostream>
#define MAX 10
using namespace std;

class Node
{
public:
	int key;
	Node* next; 
	Node(int v) : key(v), next(NULL) {}
};

class HashTable
{
public:
	Node* hashTable[MAX] = { NULL };
	HashTable(){}

	int hashFunc(int k)
	{
		int index = k % MAX;
		return index;
	}

	Node* searchNode(int k)
	{
		int hashVal = hashFunc(k);

		if (hashTable[hashVal] == NULL)
			return NULL;
		else
		{
			if (hashTable[hashVal]->key == k)
				return hashTable[hashVal];
			else
			{
				Node* ptr = hashTable[hashVal]->next;
				while (ptr != NULL)
				{
					if (ptr->key == k)
						return ptr;
					ptr = ptr->next;
				}
				return NULL;
			}
		}
	}

	void insertNode(int k)
	{
		int hashVal = hashFunc(k); // key로부터 hash value를 얻음
		Node* newnode = new Node(k);

		if (hashTable[hashVal] == NULL)
			hashTable[hashVal] = newnode;
		else
		{
			newnode->next = hashTable[hashVal];
			hashTable[hashVal] = newnode;
		}
	}

	int deleteNode(int k)
	{
		int hashVal = hashFunc(k);
		if (hashTable[hashVal] == NULL)
			return -1;
		else
		{
			Node* rmv;
			if (hashTable[hashVal]->key == k)
			{
				rmv = hashTable[hashVal];
				int temp = rmv->key;
				hashTable[hashVal] = hashTable[hashVal]->next;
				delete rmv;
				return temp;
			}
			else
			{
				Node* ptr = hashTable[hashVal]->next;
				while (ptr != NULL)
				{
					if (ptr->key == k)
					{
						rmv = ptr;
						int temp = rmv->key;
						ptr = ptr->next;
						delete rmv;
						return temp;
					}
					else
						ptr = ptr->next;
				}
				return -1;
			}
		}
	}

	void printNodes()
	{
		for (int i = 0; i < MAX; i++)
		{
			cout << i << " : ";
			if (hashTable[i] != NULL)
			{
				Node* ptr = hashTable[i];
				while (ptr != NULL)
				{
					cout << ptr->key << " ";
					ptr = ptr->next;
				}
				cout << -1 << endl;
			}
			else
				cout << -1 << endl;
		}
	}
};

int main(void)
{
	HashTable h;
	for (int i = 0; i < 20; i++)
		h.insertNode(rand() % 100);
	h.printNodes();

	system("pause");
	return 0;
}