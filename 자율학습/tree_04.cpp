#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data;
	int size;
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
			if (chi.at(i) == t)
				chi.erase(chi.begin() + i);
		}
	}
};

class Tree
{
public:
	Node* root;
	vector<Node*> tree_list;

	Node* searchNode(int t)
	{
		for (auto& i : tree_list)
		{
			if (i->data == t)
				return i;
		}
	}

	void insertNode(int t, int v)
	{
		Node* tar = searchNode(t);

		// 1단계 : 노드생성
		Node* newnode = new Node(v);

		// 2단계 : 링크갱신
		newnode->par = tar;
		tar->chi.push_back(newnode);

		// 3단계 : 트리 노드목록 추가
		tree_list.push_back(newnode);

		return;
	}

	void deleteNode(int t)
	{
		for (unsigned int i = 0; i < tree_list.size(); i++)
		{
			if (tree_list.at(i)->data == t)
			{
				Node* now = tree_list.at(i);
				Node* nowPar = now->par;

				for (auto &i : now->chi)
				{
					nowPar->chi.push_back(i);
					i->par = nowPar;
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
	int N;
	cin >> N;

	int M;
	cin >> M;

	for(int i = 0; i < N;)

	return 0;
}