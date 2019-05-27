#include <iostream>
using namespace std;

class Node
{
public:
	Node* parent;
	Node* left;
	Node* right;
	int data;
	Node(int n)
	{
		parent = NULL;
		left = NULL;
		right = NULL;
		data = n;
	}
};

class BinarySearchTree
{
public:
	Node* root;
	BinarySearchTree() { root = NULL; }

	Node* search(Node* node, int num)
	{
		if (node == NULL || node->data == num)
			return node;
		if (node->data > num)
			return search(node->left, num);
		else
			return search(node->right, num);
	}

	int count = 0;
	void bst_insert_iter(int num)
	{
		Node* new_Node = new Node(num);
		Node* current = root;
		Node* parent = NULL;

		while (current != NULL)
		{
			count++;
			parent = current;
			if (current->data > num)
				current = current->left;
			else
				current = current->right;
		}
		new_Node->parent = parent;
		
		if (parent == NULL)
			root = new_Node;
		else if (parent->data > new_Node->data)
			parent->left = new_Node;
		else
			parent->right = new_Node;
	}

	void transplant(Node* parent, Node* child)
	{
		if (parent->parent == NULL)
			root = child;
		else if (parent == parent->parent->left)
			parent->parent->left = child;
		else
			parent->parent->right = child;

		if (child != NULL)
			child->parent = parent->parent;
	}
	
	void bst_delete(int num)
	{
		Node* n = search(root, num);
		if (n->left == NULL && n->right == NULL)
		{
			if (n->parent == NULL)
				root = NULL;
			else
			{
				if (n == n->parent->right)
					n->parent->right = NULL;
				else
					n->parent->left = NULL;
			}
		}
		else if (n->left == NULL && n->right != NULL)
			transplant(n, n->right);
		else if (n->left != NULL && n->right == NULL)
			transplant(n, n->left);
		else
		{
			Node* min_Node = n->right;
			while (min_Node->left != NULL)
				min_Node = min_Node->left;

			if (min_Node->parent != n)
			{
				transplant(min_Node, min_Node->right);
				min_Node->right = n->right;
				min_Node->right->parent = min_Node;
			}
			transplant(n, min_Node);
			min_Node->left = n->left;
			min_Node->left->parent = min_Node;
		}
		delete n;
	}
};


int main(void)
{
	BinarySearchTree t;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;

		t.bst_insert_iter(M);
		cout << t.count << endl;
	}

	system("pause");
	return 0;
}