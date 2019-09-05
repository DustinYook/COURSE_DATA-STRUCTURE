#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data; // �������ʵ�
	Node* par; // �θ� ����Ű�� ��ũ�ʵ�
	vector<Node*> chi; // �ڽ��� ����Ű�� ��ũ�ʵ�

	// this �����ʹ� ���� ��ü�� ����Ű�� ������
	Node(int v)
	{
		data = v;
		par = NULL;
	}

	/* �ڽĳ�� ���Կ��� */
	void insertChild(Node* nPtr)
	{
		chi.push_back(nPtr); // �ڽĳ�� ����
		return;
	}

	/* �ڽĳ�� �������� */
	void deleteChild(Node* t)
	{
		// ��� child ����Ʈ Ž��
		for (unsigned int i = 0; i < chi.size(); i++)
		{
			if (chi.at(i) == t)
				chi.erase(chi.begin() + i);
		}
	}

	void printChild(Node* t)
	{
		if (chi.size() == 0)
			cout << "0" << endl;
		else
		{
			for (auto &i : chi) // ��� child�� ���ؼ�
				cout << i->data << " ";
			cout << endl;
		}
	}

	Node* getParent(Node* t)
	{
		return t->par;
	}

	void depth(Node* t)
	{
		Node* ptr = t; // �����
		int cnt = 0; // ī��Ʈ

		while (ptr->par != NULL)
		{
			ptr = getParent(ptr); // ptr�� �θ�� �̵�
			cnt++;
		}
		cout << cnt << endl;
	}

	bool isExternal(Node* t)
	{
		return (t->chi.size() == 0);
	}
};

class Tree
{
public:
	Node* root; // ��Ʈ��� ����Ű�� ������
	vector<Node*> tree_list; // Ʈ�� �����

	/* �� Ʈ�� ���� */
	Tree() { root = NULL; }

	/* ��Ʈ��常 �ִ� Ʈ������ */
	Tree(int v)
	{
		root = new Node(v); // ������
		tree_list.push_back(root); // ������
	}

	/* Ʈ�� ��� Ž������ */
	Node* searchNode(int t)
	{
		for (auto &i : tree_list) // ��� Ʈ����� -> i�� Node*
		{
			if (i->data == t) // ���ϴ� ��尪�� ���� ��带 ã��
				return i;
		}
	}

	/* Ʈ�� ��� ���Կ��� */
	void insertNode(int t, int v)
	{
		Node* tar = searchNode(t); // Ÿ�� �޾ƿ�

		// 1�ܰ� : ������
		Node* newnode = new Node(v);

		// 2�ܰ� : ��ũ����
		newnode->par = tar; // newnode�� �θ���� tar ���
		tar->chi.push_back(newnode); // tar�� �ڽĳ��� newnode ���

		// 3�ܰ� : Ʈ����� ����
		tree_list.push_back(newnode);

		return; // ó������Ǿ� ȣ���Լ��� ����� ��ȯ
	}

	/* Ʈ�� ��� �������� */
	void deleteNode(int t)
	{
		for (unsigned int i = 0; i < tree_list.size(); i++)
		{
			if (tree_list.at(i)->data == t)
			{
				Node* now = tree_list.at(i); // �������� �ּ�
				Node* nowPar = now->par; // �������� �θ��ּ�

				// �ش� ��� i�� ��� children�� ���� ����
				for (auto &i : now->chi)
				{
					nowPar->insertChild(i); // �θ� ���� �ڽ��Ҵ�
					i->par = nowPar; // ���� �ڽ��� �θ� �ٲ�
				}

				nowPar->deleteChild(now);
				tree_list.erase(tree_list.begin() + i);
				delete now;
			}
		}
	}

	/* ������ȸ ���� */
	void preorder(Node* n)
	{
		cout << n->data << " "; // process

		if (n->isExternal(n))
			return;
		else
		{
			for (auto &i : n->chi) // ��� chi�� ���ؼ� (Node*)
				preorder(i);
		}
	}

	/* ������ȸ ���� */
	void postorder(Node* n)
	{
		if (n->isExternal(n)) // �ܸ���� �����ϸ� ��μ� ó���� ����
		{
			cout << n->data << " "; // process
			return; // ó������Ǿ� caller���� ����� ��ȯ
		}
		else
		{
			// ��ܸ������ �� �ڽ��� ���� ó�� (L -> R)
			for (auto &i : n->chi) // ��� chi�� ���ؼ� (Node*)
				postorder(i);

			// �ڽ�ó���� ��� ����Ǹ� �θ��� ó�� (V)
			cout << n->data << " "; // process
		}
	}
};

int main(void)
{
	Tree t(1);

	int N; // ����� ����
	cin >> N;

	// Ʈ���� ��带 ����
	for (int i = 0; i < N; i++)
	{
		int P; // �����
		cin >> P;

		for (int j = 0; j < 6; j++) // �ڽĳ��� �ִ� 5������
		{
			int C; // �ڽĳ��
			cin >> C;

			if (C != 0)
				t.insertNode(P, C);
			else
				break;
		}
	}

	t.preorder(t.searchNode(1));
	cout << endl;
	t.postorder(t.root);

	system("pause");
	return 0;
}