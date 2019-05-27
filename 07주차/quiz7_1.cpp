#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class GeneralTree;

template <typename T>
class Node
{
private:
	T data;
	Node* par; // 부모노드
	vector<Node*> chi; // 자식노드
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

	~Node() {}

	void setParent(Node* par)
	{
		this->par = par;
		return;
	}

	void insertChild(Node* chi)
	{
		this->chi.push_back(chi);
		return;
	}

	void delChild(Node* chi)
	{
		for (int i = 0; i < this->chi.size(); i++)
		{
			if (this->chi[i] == chi)
				this->chi.erase(this->chi.begin() + i);
		}
		return;
	}

	friend GeneralTree<T>;
};

template <typename T>
class GeneralTree
{
private:
	Node<T>* root;
	vector<Node<T>*> node_list;
	int tree_size = 0;
public:
	int cnt;
	GeneralTree()
	{
		root = NULL;
		cnt = 0;
	}

	GeneralTree(T data)
	{
		root = new Node<T>(data);
		node_list.push_back(root);
	}

	~GeneralTree() {}

	void insertNode(T parent_data, T data)
	{
		Node<T>* par;
		for (auto &i : this->node_list)
		{
			if (i->data == parent_data)
			{
				par = i;
				Node<T>* newnode = new Node<T>(data);
				par->insertChild(newnode);
				newnode->setParent(par);
				node_list.push_back(newnode);
				return;
			}
		}
		return;
	}

	void delNode(T data)
	{
		Node<T>* nownode;
		Node<T>* par;
		for (int i = 0; i < this->node_list.size(); i++)
		{
			if (this->node_list[i]->data == data)
			{
				nownode = node_list[i];
				par = nownode->par;
				for (auto &child : nownode->chi)
				{
					par->insertChild(child);
					child->setParent(par);
				}
				par->delChild(nownode);
				this->node_list.erase(this->node_list.begin() + i);
				delete nownode;
			}
		}
		return;
	}

	Node<T>* getRoot()
	{
		return root;
	}

	void preorder(Node<T>* node)
	{
		if (node->chi.size() != 0)
		{
			if (node->data == -1 || node->data == 0)
				cout << "";
			else
				cout << (node->data) << " ";
			for (auto &v : node->chi)
				preorder(v);
		}
		else
			return;
	}

	void postorder(Node<T>* node)
	{
		for (auto &v : node->chi)
			postorder(v);
		if (node->chi.size() != 0)
		{
			if (node->data == -1 || node->data == 0)
				cout << "";
			else
				cout << (node->data) << " ";
		}
		return;
	}
};

int main(void)
{
	GeneralTree<int> g(-1);

	int N; // 반복횟수
	cin >> N;

	g.insertNode(-1, 1);

	// tree에 삽입
	int temp;

	for (int i = 1; i <= N; i++)
	{
		do
		{
			cin >> temp;
			g.insertNode(i, temp);
		} while (temp != 0);
	}

	g.preorder(g.getRoot());
	cout << endl;
	g.postorder(g.getRoot());

	system("pause");
	return 0;
}