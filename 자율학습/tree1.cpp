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
		for(unsigned int i = 0; i < chi.size(); i++) 
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
};

class Tree
{
public:
	Node* root; // Ʈ���� ��Ʈ��带 ����Ű�� ������
	vector<Node*> tree_list; // ? 
	int tree_size; 

	/* �� Ʈ�� ���� */
	Tree() { root = NULL; } 

	/* ��Ʈ��常 �ִ� Ʈ������ */
	Tree(int v)
	{
		root = new Node(v); // ������
		tree_list.push_back(root); // ������
	}

	/* Ʈ�� ��� ���Կ��� */
	void insertNode(int t, int v)
	{
		// range-based for-loop
		for (auto &i : tree_list) // i�� ����Ʈ�� �����ϴ� element (Node*) 
		{
			if (i->data == t) // t�� ���� ���� ��� Ž��
			{
				Node* n = new Node(v); // ������ ������
				i->insertChild(n); // �θ����� �ڽ� ��ũ�ʵ� ����
				n->par = i; // �ش����� �θ� ��ũ�ʵ� ����
				tree_list.push_back(n); // Ʈ���� ��Ͽ� �߰�
				return; // �� �� �������Ƿ� caller���� ����� ��ȯ
			}
		}
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

	void searchNode(int t)
	{
		for (auto &i : tree_list) // ��� Ʈ����� -> i�� Node*
		{
			if (i->data == t) // ���ϴ� ��尪�� ���� ��带 ã��
			{
				i->printChild(i);
				return;
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
		
		t.searchNode(T);
	}
	
	system("pause");
	return 0;
}