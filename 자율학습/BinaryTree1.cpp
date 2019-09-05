#include <iostream>
using namespace std;

class Node
{
public:
	char data;
	Node* left;
	Node* right;

	Node(char value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
public:
	Node* root;

	Tree()
	{
		root = NULL;
	}

	void add(char p, char lc, char rc)
	{
		if (root == NULL)
		{
			Node* parent = new Node(p);
			root = parent;

			Node* l_child = new Node(lc);
			parent->left = l_child;

			Node* r_child = new Node(rc);
			parent->right = r_child;
		}
		else
			search(root, p, lc, rc);
	}

	void search(Node* ptr, char p, char lc, char rc)
	{
		if (ptr == NULL)
			return;
		else if (ptr->data == p)
		{
			Node* l_child = new Node(lc);
			ptr->left = l_child;

			Node* r_child = new Node(rc);
			ptr->right = r_child;
		}
		else
		{
			search(ptr->left, p, lc, rc);
			search(ptr->right, p, lc, rc);
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
};

int main(void)
{
	int N;
	cin >> N;

	Tree t;

	for (int i = 0; i < N; i++)
	{
		char parent;
		char left;
		char right;

		cin >> parent >> left >> right;

		t.add(parent, left, right);
	}
	t.preorder(t.root);
	cout << endl;

	t.inorder(t.root);
	cout << endl;

	t.postorder(t.root);
	cout << endl;

	system("pause");
	return 0;
}