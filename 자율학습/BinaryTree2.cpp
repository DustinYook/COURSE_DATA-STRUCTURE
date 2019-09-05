#include <iostream>
using namespace std;

/* Node */
class Node
{
public:
	char data; // �������ʵ� 
	Node* left; // ���� �ڽ��� ����Ű�� ��ũ�ʵ�
	Node* right; // ������ �ڽ��� ����Ű�� ��ũ�ʵ�

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
	Node* root; // Ʈ���� ���� �������(��Ʈ)�� ����Ű�� ������
	Node* now; // ���� �������� ���Ե� ��带 ����Ű�� ������
	int count; // Ʈ���� �����ϴ� ������ ���� 

	Tree()
	{
		root = NULL;
		now = NULL;
		count = 0;
	}

	void insert(char p, char lc, char rc) // parent, left child, right child
	{ // ������ ���ʿ��� ������ ������ ����
		if (root == NULL) // Ʈ���� ����ִ� ���
		{
			// 1�ܰ� : ���ο� ��� ����
			Node* parent = new Node(p);
			count++; // ��ü ī��Ʈ ����
			Node* l_child = new Node(lc);
			count++; // ��ü ī��Ʈ ����
			Node* r_child = new Node(rc);
			count++; // ��ü ī��Ʈ ����

			// 2�ܰ� : ���� ����� ��ũ�ʵ� ����
			root = parent;
			root->left = l_child;
			root->right = r_child;
			now = parent;
		}
		else // Ʈ���� ������� ���� ���
		{
			Node* temp = search(root, p); // p�� ���� ���� ��带 ã��

			// p�� ���� ���� ��尡 ���� ��� -> ���� ������ ������ġ�� ����
			if (temp == NULL)
			{
				// 1�ܰ� : left child ����
				Node* l_child = new Node(lc); // left child ����
				now = l_child; // now�� ���尪�� ����
				count++;

				// 2�ܰ� : right child ����
				Node* r_child = new Node(rc); // right child ����
				now = r_child; // now�� ���尪�� ����
				count++; // ��ü ī��Ʈ ����
			}
			// p�� ���� ���� ��尡 �ִ� ���
			else
			{
				// 1�ܰ� : ���ο� ��� ����
				Node* l_child = new Node(lc);
				count++;
				Node* r_child = new Node(rc);
				count++;

				// 2�ܰ� : ���� ����� ��ũ�ʵ� ����
				temp->left = l_child;
				temp->right = r_child;
			}
		}
	}

	Node* search(Node* ptr, char target)
	{
		if (ptr->data == target) // target ���� ����� ��带 ã�� ���
			return ptr;
		else // target ���� ����� ��尡 �ƴ� ��� -> ã�� ������ �ݺ�
		{
			if (ptr->left == NULL && ptr->right == NULL) // external node�� ���
				return NULL;
			else // internal node�� ���
			{
				search(ptr->left, target); // left child Ž��
				search(ptr->right, target); // right child Ž��
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