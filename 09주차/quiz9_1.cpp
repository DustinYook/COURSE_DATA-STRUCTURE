#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#define MAX_ELEMENT	200 // 최대 가질 수 있는 크기
using namespace std;

class HeapNode
{
public:
	int	key;
	HeapNode(int key = 0) : key(key) { } // 생성자
	~HeapNode(void) { } // 소멸자
	void setKey(int k) { key = k; } // setter
	int	 getKey() { return key; } // getter
	void display() { printf("%d ", key); } // 노드저장값 출력
};

class MinHeap // 최소힙
{
public:
	int	size;
	HeapNode node[MAX_ELEMENT];

	MinHeap() : size(0) { } // 생성자

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; } // 부모 리턴
	HeapNode& getLeft(int i) { return node[i * 2]; } // 왼쪽자식 리턴
	HeapNode& getRight(int i) { return node[i * 2 + 1]; } // 오른쪽자식 리턴

	// 삽입 함수
	void insert(int key)
	{
		if (isFull())
			return;

		int i = ++size; // 전체 크기 하나 증가

		// 루트가 아니고, key < par일 때 (heap의 순서조건 위반)
		while (i != 1 && key < getParent(i).getKey()) // 들어갈 위치를 찾는 과정 
		{
			node[i] = getParent(i); // 결국 부모를 자기자리로 끌어내림
			i /= 2; // 인덱스를 부모로 이동
		}
		node[i].setKey(key); // 최종적으로 들어갈 위치에 값 삽입
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