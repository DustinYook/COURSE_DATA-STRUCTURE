#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data; // �������ʵ�
	Node* par; // �θ� ����Ű�� ��ũ�ʵ�
	vector<Node*> chi; // �ڽ��� ����Ű�� ��ũ�ʵ�

	Node(int v)
	{
		data = v;
		par = NULL;
	}

	/* �ڽĳ�� ���Կ��� */
	void insertChild(Node* n)
	{
		chi.push_back(n); // �ڽĳ�� ����
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

	/* �ڽĳ�� ��¿��� */
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
};

class Tree
{
public:
	Node* root; // Ʈ���� ��Ʈ��带 ����Ű�� ������
	vector<Node*> tree_list; // Ʈ���� �����

	/* �� Ʈ�� ���� */
	Tree() { root = NULL; }

	/* ��Ʈ��常 �ִ� Ʈ������ */
	Tree(int v)
	{
		root = new Node(v); // ������
		tree_list.push_back(root); // ������
	}

	/* ��� Ž������ */
	// �Է� : ã���� �ϴ� ����ȣ
	// ��� : �ش� ����� �ּ�
	Node* searchNode(int v)
	{
		for (auto &i : tree_list) // ��� Ʈ����� Ž��
		{
			if (i->data == v) // ���ϴ� �� ���� ��� �߰�
				return i; // �ش� ����� �ּҸ� ��ȯ
		}
	}

	/* Ʈ�� ��� ���Կ��� */
	// �Է� : Ÿ�ٳ�� ��ȣ, �Է��� ��
	// ��� : ���Ե� ����
	void insertNode(int t, int v)
	{
		Node* tar = searchNode(t); // t�� ���� ���� ��带 �޾ƿ�

		// 1�ܰ� : ������
		Node* n = new Node(v); // ������ ������

		// 2�ܰ� : ��ũ�ʵ� ����
		tar->insertChild(n); // �ڽ� ��ũ�ʵ� ����
		n->par = tar; // �θ� ��ũ�ʵ� ����

		// 3�ܰ� : Ʈ����� �߰�
		tree_list.push_back(n); // Ʈ���� ��Ͽ� �߰�

		return; // �� �� �������Ƿ� caller���� ����� ��ȯ
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
};

int main(void)
{
	Tree t(1);

	int N; // ����� ����
	cin >> N;

	int M; // �ڽ��� ���� ���� ���� ��
	cin >> M;

	// Ʈ���� ��带 ����
	for (int i = 0; i < N; i++)
	{
		int P; // �����
		cin >> P;

		for (int j = 0; j < 5; j++) // �ڽĳ��� �ִ� 5������
		{
			int C; // �ڽĳ��
			cin >> C;

			if (C != 0)
				t.insertNode(P, C);
			else
				break;
		}
	}

	// Ư�� ����� �ڽ��� ��� ���
	for (int i = 0; i < M; i++)
	{
		int T;
		cin >> T;

		Node* N = t.searchNode(T);
		N->printChild(N);
	}

	system("pause");
	return 0;
}