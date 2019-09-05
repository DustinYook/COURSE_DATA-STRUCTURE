#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* par;
	Node* lc;
	Node* rc;
	Node(int v) : data(v), par(NULL), lc(NULL), rc(NULL) { }
};

class Tree
{
public:
	Node* root;
	Tree() : root(NULL) { }

	void insertNode(int k, Node* &v)
	{
		if (v == NULL)
			v = new Node(k);
		else
		{
			if (k == v->data)
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

	void removeNode(int k, Node* &v)
	{
		if (v == NULL)
			cerr << -1 << endl;
		else
		{
			if (k != v->data)
				(k < v->data) ? removeNode(k, v->lc) : removeNode(k, v->rc);
			else
			{
				if (v->lc == NULL || v->rc == NULL)
				{
					if (v->lc == NULL)
						v = v->rc;
					else if (v->rc == NULL)
						v = v->lc;
				}
				else
				{ 
					// 1�ܰ� : ���������� �� ��
				/*	Node* temp = v->rc; 

					while (temp->lc != NULL) 
						temp = temp->lc;
					int succ = temp->data;
					removeNode(succ, root);
					v->data = succ;
					*/

					Node* temp = v->lc;
					while (temp->rc != NULL)
						temp = temp->rc; 
					int pred = temp->data;
					removeNode(pred, root);
					v->data = pred;
				}
			}
		}
	}

	void preorder(Node* n)
	{
		if (n != NULL)
		{
			cout << n->data << " "; // �ڽ� ó��
			preorder(n->lc); // ���� ����Ʈ�� Ž��
			preorder(n->rc); // ������ ����Ʈ�� Ž��
		}
	}
	void inorder(Node* n)
	{
		if (n != NULL)
		{
			inorder(n->lc); // ���� ����Ʈ�� Ž��
			cout << n->data << " "; // �ڽ� ó��  
			inorder(n->rc); // ������ ����Ʈ�� Ž��
		}
	}
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