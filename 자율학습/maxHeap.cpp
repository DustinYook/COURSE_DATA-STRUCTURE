#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT	200 // 최대 가질 수 있는 크기

class HeapNode
{
	int	key;
public:
	HeapNode(int key = 0) : key(key) { } // 생성자
	~HeapNode(void) { } // 소멸자
	void setKey(int k) { key = k; } // setter
	int	 getKey() { return key; } // getter
	void display() { printf("\t%d", key); } // 노드저장값 출력
};

class MaxHeap
{
	HeapNode node[MAX_ELEMENT];
	int	size;
public:
	MaxHeap() : size(0) { }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	// 삽입 함수
	void insert(int key)
	{
		if (isFull())
			return;
		int i = ++size;
		while (i != 1 && key > getParent(i).getKey())
		{
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}

	// 삭제 함수
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
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
				child++;
			if (last.getKey() >= node[child].getKey())
				break;
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return root;
	}
	HeapNode find() { return node[1]; }

	void display()
	{
		for (int i = 1, level = 1; i <= size; i++)
		{
			if (i == level)
			{
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
		printf("\n-------------------------------------------");
	}
};

// 우선 순위 큐인 힙을 이용한 정렬
inline void heapSort(int a[], int n)
{
	MaxHeap h;
	for (int i = 0; i < n; i++)
		h.insert(a[i]);
	for (int i = n - 1; i >= 0; i--)
		a[i] = h.remove().getKey();
}

// 주함수 
int main(void)
{
	MaxHeap	heap;

	// 삽입
	heap.insert(10);
	heap.insert(5);
	heap.insert(30);
	heap.insert(8);
	heap.insert(9);
	heap.insert(3);
	heap.insert(7);
	heap.display();

	// 삭제
	heap.remove();
	heap.display();
	heap.remove();
	heap.display();

	// 정렬
	int data[10];
	for (int i = 0; i < 10; i++)
		data[i] = rand() % 100;

	printf("\n정렬전: ");
	for (int i = 0; i < 10; i++)
		printf("%3d", data[i]);

	heapSort(data, 10);

	printf("\n정렬후: ");
	for (int i = 0; i < 10; i++)
		printf("%3d", data[i]);
	printf("\n");

	system("pause");
	return 0;
}