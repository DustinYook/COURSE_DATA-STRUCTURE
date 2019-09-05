#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data;
	Node* par;
	vector<Node*> chi;

	Node(int v)
	{
		data = v;
		par = NULL;
	}

	void insertChild(Node* n)
	{
		chi.push_back(n);
		return;
	}

	void deleteChild(Node* t)
	{
		for (unsigned int i = 0; i < chi.size(); i++)
		{
			if (chi.at(i) == t) // ���ϴ� �� ã��
				chi.erase(chi.begin() + i);
		}
	}
};

class Tree
{
public:
	Node* root;
	vector<Node*> tree_list;

	Tree(){ root = NULL; }

	Tree(int v)
	{
		root = new Node(v); // root ��� ����
		tree_list.push_back(root); // Ʈ����Ͽ� ����
	}

	Node* searchNode(int t)
	{
		for (auto &i : tree_list)
		{
			if (i->data == t)
				return i;
		}
	}

	void insertNode(int t, int v)
	{
		Node* tar = searchNode(t); // Ÿ�ٹ޾ƿ�

		// 1�ܰ� : ������
		Node* newnode = new Node(v); 

		// 2�ܰ� : ��ũ����
		newnode->par = tar;
		tar->chi.push_back(newnode);

		// 3�ܰ� : Ʈ����� �߰�
		tree_list.push_back(newnode);
	}

	void deleteNode(int t)
	{
		for (unsigned int i = 0; i < tree_list.size(); i++) // Ʈ����� ������ ã��
		{
			if (tree_list.at(i)->data == t)
			{
				Node* now = tree_list.at(i);
				Node* nowPar = now->par;

				for (auto &i : now->chi)
				{
					i->par = nowPar; // ����� �θ� �缳��
					nowPar->chi.push_back(i); // �� �θ� �ڽ��� �Ҵ�
				}

				tree_list.erase(tree_list.begin() + i);
				nowPar->deleteChild(now);
				delete now;
			}
		}
	}

	void preorder(Node* t)
	{
		cout << t->data << " ";

		if (t->chi.size() != 0)
		{
			for (auto &i : t->chi)
				preorder(i);
		}
	}

	void postorder(Node* t)
	{
		if (t->chi.size() == 0)
		{
			cout << t->data << " ";
			return;
		}
		else
		{
			for (auto &i : t->chi)
				postorder(i);
			cout << t->data << " ";
		}
	}
};

int main(void)
{
	Tree t(1);

	int M; // ��ü ��� ��
	cin >> M;

	// Ʈ���� �����ϴ� ó��
	for (int i = 0; i < M; i++)
	{
		int P; // �θ��ȣ
		cin >> P;

		for (int j = 0; j < 6; j++) // �ڽ��� 5������
		{
			int C;
			cin >> C;

			if (C == 0)
				break;
			else
				t.insertNode(P, C);
		}
	}

	t.preorder(t.searchNode(1));
	cout << endl;
	t.deleteNode(6);
	t.preorder(t.searchNode(1));

	system("pause");
	return 0;
}