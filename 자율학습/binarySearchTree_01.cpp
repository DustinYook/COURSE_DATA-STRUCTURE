#include <iostream>
using namespace std;

class Node
{
public: 
	int key;
	Node* par;
	Node* lc;
	Node* rc;

	Node(int v)
	{
		key = v;
		par = NULL;
		lc = NULL;
		rc = NULL;
	}

	bool isExternal()
	{
		return (lc == NULL && rc == NULL);
	}
};

class BinarySearchTree
{
public:
	Node* root;
	int count = 0;

	BinarySearchTree() { root = NULL; }
	
	BinarySearchTree(int v)
	{
		root = new Node(v);
	}

	void insert(int k, Node* v)
	{
		count++;
		if (k < v->key)
		{
			if (v->lc == NULL)
			{
				Node* newnode = new Node(k);
				v->lc = newnode;
				newnode->par = v;
			}
			else
				insert(k, v->lc);
		}
		else
		{
			if (v->rc == NULL)
			{
				Node* newnode = new Node(k);
				v->rc = newnode;
				newnode->par = v;
			}
			else
				insert(k, v->rc);
		}
	}
};

int main(void)
{
	int N; // 입력크기
	cin >> N;

	int R;
	cin >> R;

	BinarySearchTree t(R); 
	cout << t.count << endl;

	for (int i = 0; i < N-1; i++)
	{
		int M;
		cin >> M;

		t.insert(M, t.root);
		cout << t.count << endl;
	}

	//system("pause");
	return 0;
}