#include <iostream>
using namespace std;

/* Node */
class Node
{
public:
	char data; // 데이터필드 
	Node* left; // 왼쪽 자식을 가리키는 링크필드
	Node* right; // 오른쪽 자식을 가리키는 링크필드

	Node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};

/* Tree */
class Tree
{
public:
	Node* root; // 트리의 가장 상위노드(루트)를 가리키는 포인터
	Node* now; // 가장 마지막에 삽입된 노드를 가리키는 포인터
	int count; // 트리에 존재하는 원소의 개수 

	Tree()
	{
		root = NULL;
		now = NULL;
		count = 0;
	}

	void insert(char p, char lc, char rc) // parent, left child, right child
	{ // 삽입은 왼쪽에서 오른쪽 순서로 진행
		if (root == NULL) // 트리가 비어있는 경우
		{
			// 1단계 : 새로운 노드 생성
			Node* parent = new Node(p);
			count++; // 전체 카운트 증가
			Node* l_child = new Node(lc);
			count++; // 전체 카운트 증가
			Node* r_child = new Node(rc);
			count++; // 전체 카운트 증가

			// 2단계 : 기존 노드의 링크필드 갱신
			root = parent;
			root->left = l_child;
			root->right = r_child;
			now = parent;
		}
		else // 트리가 비어있지 않은 경우
		{
			Node* temp = search(root, p); // p의 값을 가진 노드를 찾음

			// p의 값을 가진 노드가 없는 경우 -> 가장 마지막 삽입위치에 삽입
			if (temp == NULL)
			{
				// 1단계 : left child 삽입
				Node* l_child = new Node(lc); // left child 생성
				now = l_child; // now의 저장값을 갱신
				count++;

				// 2단계 : right child 삽입
				Node* r_child = new Node(rc); // right child 생성
				now = r_child; // now의 저장값을 갱신
				count++; // 전체 카운트 증가
			}
			// p의 값을 가진 노드가 있는 경우
			else
			{
				// 1단계 : 새로운 노드 생성
				Node* l_child = new Node(lc);
				count++;
				Node* r_child = new Node(rc);
				count++;

				// 2단계 : 기존 노드의 링크필드 갱신
				temp->left = l_child;
				temp->right = r_child;
			}
		}
	}

	Node* search(Node* ptr, char target)
	{
		if (ptr->data == target) // target 값이 저장된 노드를 찾은 경우
			return ptr;
		else // target 값이 저장된 노드가 아닌 경우 -> 찾을 때까지 반복
		{
			if (ptr->left == NULL && ptr->right == NULL) // external node의 경우
				return NULL;
			else // internal node의 경우
			{
				search(ptr->left, target); // left child 탐색
				search(ptr->right, target); // right child 탐색
			}
		}
	}

	void preorder(Node* ptr)
	{
		if (ptr->data != '.')
			cout << (ptr->data);
		if (ptr->left != NULL)
			preorder(ptr->left);
		if (ptr->right != NULL)
			preorder(ptr->right);
	}

	void inorder(Node* ptr)
	{
		if (ptr->left != NULL)
			inorder(ptr->left);
		if (ptr->data != '.')
			cout << (ptr->data);
		if (ptr->right != NULL)
			inorder(ptr->right);
	}

	void postorder(Node* ptr)
	{
		if (ptr->left != NULL)
			postorder(ptr->left);
		if (ptr->right != NULL)
			postorder(ptr->right);
		if (ptr->data != '.')
			cout << (ptr->data);
	}

	bool isRoot(Node* ptr)
	{
		if (ptr == getRoot())
			return true;
		else
			return false;
	}

	bool isExternal(Node* ptr)
	{
		if (ptr->left == NULL && ptr->right == NULL)
			return true;
		else
			return false;
	}

	int size(void)
	{
		return count;
	}

	bool isEmpty(void)
	{
		return (count == 0);
	}

	Node* getRoot(void)
	{
		return root;
	}
};

int main(void)
{
	Tree t;

	int N;
	cin >> N;



	t.insert('a', 'b', 'c');
	cout << t.root->data << " ";
	cout << (t.root->left)->data << " ";
	cout << (t.root->right)->data << endl;
	cout << t.count << endl;

	system("pause");
	return 0;
}