#include <iostream>
#include <vector> // ���͸� �̿��Ͽ� �ڽĳ�� ��ũ�ʵ� ����
using namespace std;

template <typename T>
class GeneralTree;

/* Node */
template <typename T>
class Node
{
private:
	T data; // �������ʵ�
	Node* par; // �θ� ����Ű�� ��ũ�ʵ�
	vector<Node*> chi; // �ڽ��� ����Ű�� ��ũ�ʵ�

public:
	Node()
	{
		this->data = NULL;
		this->par = NULL;
	}

	Node(T data)
	{
		this->data = data;
		this->par = NULL;
	}

	~Node() { }

	void setParent(Node* par) // �θ��� ����
	{
		this->par = par;
		return;
	}

	void insertChild(Node* chi) // ���� ��忡 �ڽĳ�带 �߰�
	{
		this->chi.push_back(chi); // �ڽ� ��ũ�ʵ忡 �߰�
		return;
	}

	void delChild(Node* chi) // �������� �ڽĳ�� �� Ư����Ʈ �ϳ��� ����
	{
		for (int i = 0; i < this->chi.size(); i++)
		{
			// ���ϴ� �ڽĳ���� �ּҸ� �˾Ƴ� ���
			if (this->chi[i] == chi)
			{
				this->chi.erase(this->chi.begin() + i);
				// �ڽĸ�ũ������ i��° element�� ����
			}
		}
	}
	friend GeneralTree<T>;
};

/* GeneralTree */
template <typename T>
class GeneralTree
{
private:
	Node<T>* root; // ��Ʈ��带 ����Ű�� ������
	vector<Node<T>*> node_list; // ����� ��� -> ��ȸ�� ���� ����Ʈ
	int tree_size = 0;

public:
	GeneralTree() // �� Ʈ�� ����
	{
		root = NULL;
	}

	GeneralTree(T data) // ��Ʈ��带 ������ Ʈ������
	{
		root = new Node<T>(data);
		node_list.push_back(root);
	}

	~GeneralTree() { }

	void insertNode(T parent_data, T data)
	{
		Node<T>* par; // �ڽ��� ������ �����
		for (auto &i : this->node_list)
		{
			if (i->data == parent_data)
			{
				par = i;
				Node<T>* newnode = new Node<T>(data); // �� ��� ����
				par->insertChild(newnode); // parent�� ��ũ�ʵ� ����
				newnode->setParent(par);
				node_list.push_back(newnode); // Ʈ����� ��Ͽ� ����
				return;
			}
		}
		return;
	}

	void delNode(T data) // data�� ������ �ִ� ������
	{
		Node<T>* nownode; // �����带 ����Ű�� ������
		Node<T>* par; // now ����� ����θ� ����Ű�� ������

		// Ʈ���� ��帮��Ʈ�� Ž��
		for (int i = 0; i < this->node_list.size(); i++)
		{
			// ���嵥���Ͱ� �츮�� ���ϴ� �������̸�
			if (this->node_list[i]->data == data)
			{
				nownode = node_list[i]; // �������� ��ġ�� ����
				par = nownode->par; // �������� ����θ� ��ġ�� ����

				// �������� ��� �ڽĵ��� ����θ��� �ڽ����� ����
				for (auto &child : nownode->chi)
				{
					// ��Ƴ�带 ��������� ����θ��� �ڽ����� ����
					par->insertChild(child);

					// ��Ƴ���� �θ�ũ�� ��������� ����θ� ����Ű�� ��
					child->setParent(par);
				}
				par->delChild(nownode); // ��������� ����θ� ������带 ������
				this->node_list.erase(this->node_list.begin() + i);
				delete nownode; // �޸𸮹�ȯ
			}
		}
	}

	void printChild(T data)
	{
		// Ʈ�� ����Ʈ�� Ž��
		for (auto &i : this->node_list)
		{
			// ���ϴ� �����Ͱ� ������
			if (i->data == data)
			{
				if (i->chi.size() == 0)
					cout << "0";
				for (auto &child : i->chi)
					cout << child->data << " ";
				cout << endl;

				// ���������� ����� ��� caller���� ����� ����
				return; // ���⿡ ������ ������ ����� '-1'�� �׻� ��µǴ� ������������
			}
		}
		// ������������ ����� ��� '-1'�� ���
		cout << "-1" << endl;
		return;
	}

	int countDept(T data) // data�� ������ ����� ���� ���
	{
		Node<T>* nownode;
		int depth = 0;
		for (auto &i : this->node_list)
		{
			if (i->data == data)
			{
				nownode = i;
				while (true)
				{
					if (nownode == root)
						return depth;
					nownode = nownode->par;
					depth++;
				}
			}
		}
	}
};

int main(void)
{
	GeneralTree<int> t(1);

	int N;
	cin >> N;

	int M;
	cin >> M;

	for (int i = 1; i <= N; i++)
	{
		int node;
		cin >> node;
		t.insertNode(i, node);

		for (int j = 0; j < 5; j++) // �ڽ��� �ִ� 5�� ����
		{
			int val; // �ڽĳ���� �������ʵ尪 �Է�
			cin >> val;
			t.insertNode(i, val);

			if (val == 0) // 0�� �ԷµǸ� ù��° ���� Ż��
				break;
		}
	}

	vector<int> request;
	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;

		request.push_back(input);
	}

	for (unsigned int i = 0; i < request.size(); i++)
		cout << t.countDept(request.at(i)) << endl;

	system("pause");
	return 0;
}