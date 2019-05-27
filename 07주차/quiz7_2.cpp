#include <iostream>
#include <vector>
using namespace std;

int slist[30] = { 0 };

class Node
{
public:
	int data; // ���嵥����
	int size; // �޸𸮿뷮
	Node* par; // �θ�ũ�ʵ�
	vector<Node*> chi; // �ڽĸ�ũ�ʵ�

	Node()
	{
		this->par = NULL;
	}
	Node(int d, int s)
	{
		this->data = d;
		this->size = s;
		this->par = NULL;
	}

	void insertChild(Node* c)
	{
		this->chi.push_back(c);
	}

	void delChild(Node* c)
	{
		for (unsigned int i = 0; i < this->chi.size(); i++)
		{
			if (this->chi[i] == c)
				this->chi.erase(this->chi.begin() + i);
		}
	}
};

class Tree
{
public:
	Node* root;
	vector<Node*> list;
	int sum;

	Tree()
	{
		root = NULL;
		sum = 0;
	}
	Tree(int d, int s)
	{
		sum = 0;
		root = new Node(d, s);
		list.push_back(root);
	}

	void insertNode(int t, int d, int s)
	{
		Node* p;
		for (auto &i : this->list)
		{
			if (i->data == t)
			{
				p = i;
				Node* n = new Node(d, s);
				p->insertChild(n);
				n->par = p;
				list.push_back(n);
				return;
			}
		}
		return;
	}

	int post(Node* n)
	{
		if (n->chi.size() != 0) // internal
		{
			for (auto &i : n->chi) // ��� child�� ���� ����
				sum += post(i);
		}
		else // external
			return  slist[n->data];
	}
};

int main(void)
{
	Tree t(-1, 0);
	t.insertNode(-1, 1, 0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int num; // ����ȣ
		int size; // ����� �뷮
		cin >> num >> size;
		slist[num] = size; // ��忡 ������ ����
	}

	// Ʈ���� �θ��ڽİ��踦 �Է¹��� 
	int temp;
	for (int i = 1; i <= N; i++)
	{
		do {
			cin >> temp;
			t.insertNode(i, temp, slist[i]);
		} while (temp != 0);
	}

	int req;
	for (int i = 0; i < M; i++)
	{
		cin >> req;
		cout << t.post(t.root) << endl;
		t.sum = 0;
	}

	system("pause");
	return 0;
}