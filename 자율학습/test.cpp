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
			if (chi.at(i) == t) // 원하는 것 찾음
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
		root = new Node(v); // root 노드 생성
		tree_list.push_back(root); // 트리목록에 넣음
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
		Node* tar = searchNode(t); // 타겟받아옴

		// 1단계 : 노드생성
		Node* newnode = new Node(v); 

		// 2단계 : 링크갱신
		newnode->par = tar;
		tar->chi.push_back(newnode);

		// 3단계 : 트리목록 추가
		tree_list.push_back(newnode);
	}

	void deleteNode(int t)
	{
		for (unsigned int i = 0; i < tree_list.size(); i++) // 트리목록 뒤져서 찾음
		{
			if (tree_list.at(i)->data == t)
			{
				Node* now = tree_list.at(i);
				Node* nowPar = now->par;

				for (auto &i : now->chi)
				{
					i->par = nowPar; // 고아의 부모 재설정
					nowPar->chi.push_back(i); // 새 부모에 자식을 할당
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

	int M; // 전체 노드 수
	cin >> M;

	// 트리에 삽입하는 처리
	for (int i = 0; i < M; i++)
	{
		int P; // 부모번호
		cin >> P;

		for (int j = 0; j < 6; j++) // 자식은 5개까지
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