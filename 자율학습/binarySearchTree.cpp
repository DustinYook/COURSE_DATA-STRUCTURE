#include <iostream>
using namespace std;

/* NODE */
class Node
{
public:
	int data;  // data field
	Node* par; // link field for parent
	Node* lc;  // link field for left-child
	Node* rc;  // link field for right-child
	Node(int v) : data(v), par(NULL), lc(NULL), rc(NULL) { } // initialize function
};

/* BINARY SEARCH TREE */
class Tree
{
public:
	Node* root; // access pointer for tree
	Tree() : root(NULL) { } // initialize function

	/* SEARCH OPERATION */
	Node* searchNode(int k, Node* &v)
	{
		if (v == NULL)
		{
			cerr << -1 << endl;
			return v;
		}
		else
		{
			if (k == v->data)
				return v;
			else
			{
				if (k < v->data) // �� ���� ��� : ���� ����Ʈ�� Ž��
					searchNode(k, v->lc);
				else // �� ū ��� : ������ ����Ʈ�� Ž��
					searchNode(k, v->rc);
			}
		}
	}

	/* INSERT OPERATION */
	void insertNode(int k, Node* &v)
	{
		if (v == NULL) // ��尡 Ʈ���� ���� ���
			v = new Node(k);
		else
		{
			if (k == v->data) // �ߺ��� Ű �Է��� ����ó��
				cerr << -1 << endl;
			else
			{
				if (k < v->data)
					insertNode(k, v->lc);
				else
					insertNode(k, v->rc);
			}
		}
	}

	/* DELETE OPERATION */
	void removeNode(int k, Node* &v)
	{
		// 1.1) if v is external node
		if (v == NULL)
			cerr << -1 << endl; // cannot find the requested node
		// 1.2) if v is internal node
		else
		{
			// 2.1) if you didn't find the requested node yet
			if (k != v->data)
			{
				// 3.1.1) if requested value is smaller than v's data
				if (k < v->data)
					removeNode(k, v->lc); // search left subtree
				// 3.1.2) if requested value is bigger than v's data
				else if (k > v->data)
					removeNode(k, v->rc); // search right subtree
			}
			// 2.2) if you find the requested node
			else
			{
				// 3.2.1) if v has at least one external child
				if (v->lc == NULL || v->rc == NULL)
				{
					if (v->lc == NULL)
						v = v->rc;
					else if (v->rc == NULL)
						v = v->lc;
				}
				// 3.2.2) if v has only internal child
				else
				{
					Node* temp = v->rc;

					while (temp->lc != NULL)
						temp = temp->lc;
					int succ = temp->data;

					removeNode(succ, root);
					v->data = succ;
				}
			}
		}
	}

	/* PREORDER TRAVERSAL */
	void preorder(Node* n)
	{
		if (n != NULL)
		{
			cout << n->data << " "; // �ڽ� ó��
			preorder(n->lc); // ���� ����Ʈ�� Ž��
			preorder(n->rc); // ������ ����Ʈ�� Ž��
		}
		cout << endl;
	}

	/* INORDER TRAVERSAL */
	void inorder(Node* n)
	{
		if (n != NULL)
		{
			inorder(n->lc); // ���� ����Ʈ�� Ž��
			cout << n->data << " "; // �ڽ� ó��  
			inorder(n->rc); // ������ ����Ʈ�� Ž��
		}
	}

	/* POSTORDER TRAVERSAL */
	void postorder(Node* n)
	{
		if (n != NULL)
		{
			postorder(n->lc); // ���� ����Ʈ�� Ž��
			postorder(n->rc); // ������ ����Ʈ�� Ž��
			cout << n->data << " "; // �ڽ� ó��
		}
	}
};

int main()
{
	Tree t;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;

		t.insertNode(M, t.root);
	}
	cout << "�ʱ����: ";
	t.inorder(t.root);
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		int M;
		cout << "�����ϰ��� �ϴ� ����� ��ȣ�� �Է����ּ��� : ";
		cin >> M;
		cout << endl;

		t.removeNode(M, t.root);
		t.inorder(t.root);
		cout << endl;
	}

	system("pause");
	return 0;
}