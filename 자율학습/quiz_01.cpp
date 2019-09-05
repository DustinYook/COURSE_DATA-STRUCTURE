#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	char data;
	Node* par;
	vector<Node*> chi;

	Node(char v)
	{
		data = v;
		par = NULL;
	}

	void insertChild(Node* n)
	{
		chi.push_back(n);
		return;
	}
};

class Tree
{
public:
	Node* root;
	vector<Node*> tree_list;

	Tree() { root = NULL; }

	Tree(char v)
	{
		root = new Node(v);
		tree_list.push_back(root);
	}

	Node* searchNode(char t)
	{
		for (auto &i : tree_list)
		{
			if (i->data == t)
				return i;
		}
	}

	void insertNode(char t, char v)
	{
		for (auto &i : tree_list)
		{
			if (i->data == t)
			{
				Node* n = new Node(v);
				i->insertChild(n);
				n->par = i;
				tree_list.push_back(n);
				return;
			}
		}
	}

	void preorder(Node* n)
	{
		if (n->data == '#')
			cout << "";
		else
			cout << n->data << ""; // process

		if (n->chi.size() != 0)
		{
			for (auto &i : n->chi) // ��� chi�� ���ؼ� (Node*)
				preorder(i);
		}
	}

	void inorder(Node* n)
	{
		int left = 0;
		int right = 0;
		// left�� ó��
		if (n->chi.size() != 0) // left != '#' inorder left -> left++
		{
			Node* left = n->chi.at(0);
			inorder(left);
			left++;
		}

		// �ڽ� ó��
		if (n->data == '#')
			cout << "";
		else
			cout << n->data << "";

		// right�� ó��
		if (n->chi.size() != 0) // right != '#' inorder right - > right++
		{
			Node* right = n->chi.at(1);
			inorder(right);
		}
	}

	void postorder(Node* n)
	{
		if (n->chi.size() == 0)
		{
			if (n->data == '#')
				cout << "";
			else
				cout << n->data;
			return;
		}
		else
		{
			for (auto &i : n->chi)
				postorder(i);

			if (n->data == '#')
				cout << "";
			else
				cout << n->data;
		}
	}
};

int main(void)
{
	Tree t('A');

	int N; // ����� ����
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char P;
		cin >> P;

		for (int j = 0; j < 2; j++) // �ڽĳ��� �ִ� 2��
		{
			char C; // �ڽĳ��
			cin >> C;

			t.insertNode(P, C);
		}
	}

	t.preorder(t.searchNode('A'));
	cout << endl;
	t.inorder(t.searchNode('A'));
	cout << endl;
	t.postorder(t.searchNode('A'));
	cout << endl;

	system("pause");
	return 0;
}