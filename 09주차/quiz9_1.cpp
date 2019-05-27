#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#define MAX_ELEMENT	200 // �ִ� ���� �� �ִ� ũ��
using namespace std;

class HeapNode
{
public:
	int	key;
	HeapNode(int key = 0) : key(key) { } // ������
	~HeapNode(void) { } // �Ҹ���
	void setKey(int k) { key = k; } // setter
	int	 getKey() { return key; } // getter
	void display() { printf("%d ", key); } // ������尪 ���
};

class MinHeap // �ּ���
{
public:
	int	size;
	HeapNode node[MAX_ELEMENT];

	MinHeap() : size(0) { } // ������

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; } // �θ� ����
	HeapNode& getLeft(int i) { return node[i * 2]; } // �����ڽ� ����
	HeapNode& getRight(int i) { return node[i * 2 + 1]; } // �������ڽ� ����

	// ���� �Լ�
	void insert(int key)
	{
		if (isFull())
			return;

		int i = ++size; // ��ü ũ�� �ϳ� ����

		// ��Ʈ�� �ƴϰ�, key < par�� �� (heap�� �������� ����)
		while (i != 1 && key < getParent(i).getKey()) // �� ��ġ�� ã�� ���� 
		{
			node[i] = getParent(i); // �ᱹ �θ� �ڱ��ڸ��� �����
			i /= 2; // �ε����� �θ�� �̵�
		}
		node[i].setKey(key); // ���������� �� ��ġ�� �� ����
	}

	// ���� �Լ�
	HeapNode remove()
	{
		if (isEmpty())
			return NULL;

		HeapNode root = node[1];
		HeapNode last = node[size--];

		int parent = 1;
		int	child = 2;

		while (child <= size)
		{
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
				child++;
			if (last.getKey() <= node[child].getKey())
				break;
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return root;
	}

	void display()
	{
		for (int i = 1, level = 1; i <= size; i++)
			node[i].display();
		cout << endl;
	}
};

int main(void)
{
	MinHeap	heap;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;

		heap.insert(M);
	}
	heap.display();

	//vector<int> v;
	//for (int i = 0; i < N; i++)
	//{
	//	int temp = heap.remove().getKey();
	//	v.push_back(temp);
	//	cout << v.front() << " ";
	//	v.pop_back();
	//} cout << endl;

	//system("pause");
	return 0;
}