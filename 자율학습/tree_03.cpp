#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data; // 데이터필드
	Node* par; // 부모를 가리키는 링크필드
	vector<Node*> chi; // 자식을 가리키는 링크필드

	// this 포인터는 현재 객체를 가리키는 포인터
	Node(int v)
	{
		data = v;
		par = NULL;
	}

	/* 자식노드 삽입연산 */
	void insertChild(Node* nPtr)
	{
		chi.push_back(nPtr); // 자식노드 삽입
		return;
	}

	/* 자식노드 삭제연산 */
	void deleteChild(Node* t)
	{
		// 모든 child 리스트 탐색
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
			for (auto &i : chi) // 모든 child에 대해서
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
		Node* ptr = t; // 제어변수
		int cnt = 0; // 카운트

		while (ptr->par != NULL)
		{
			ptr = getParent(ptr); // ptr의 부모로 이동
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
	Node* root; // 루트노드 가리키는 포인터
	vector<Node*> tree_list; // 트리 노드목록

	/* 빈 트리 생성 */
	Tree() { root = NULL; }

	/* 루트노드만 있는 트리생성 */
	Tree(int v)
	{
		root = new Node(v); // 노드생성
		tree_list.push_back(root); // 노드삽입
	}

	/* 트리 노드 탐색연산 */
	Node* searchNode(int t)
	{
		for (auto &i : tree_list) // 모든 트리요소 -> i는 Node*
		{
			if (i->data == t) // 원하는 노드값을 가진 노드를 찾음
				return i;
		}
	}

	/* 트리 노드 삽입연산 */
	void insertNode(int t, int v)
	{
		Node* tar = searchNode(t); // 타겟 받아옴

		// 1단계 : 노드생성
		Node* newnode = new Node(v);

		// 2단계 : 링크갱신
		newnode->par = tar; // newnode의 부모노드로 tar 등록
		tar->chi.push_back(newnode); // tar의 자식노드로 newnode 등록

		// 3단계 : 트리목록 갱신
		tree_list.push_back(newnode);

		return; // 처리종료되어 호출함수에 제어권 반환
	}

	/* 트리 노드 삭제연산 */
	void deleteNode(int t)
	{
		for (unsigned int i = 0; i < tree_list.size(); i++)
		{
			if (tree_list.at(i)->data == t)
			{
				Node* now = tree_list.at(i); // 현재노드의 주소
				Node* nowPar = now->par; // 현재노드의 부모주소

				// 해당 노드 i의 모든 children에 대해 수행
				for (auto &i : now->chi)
				{
					nowPar->insertChild(i); // 부모에 기존 자식할당
					i->par = nowPar; // 기존 자식의 부모를 바꿈
				}

				nowPar->deleteChild(now);
				tree_list.erase(tree_list.begin() + i);
				delete now;
			}
		}
	}

	/* 전위순회 연산 */
	void preorder(Node* n)
	{
		cout << n->data << " "; // process

		if (n->isExternal(n))
			return;
		else
		{
			for (auto &i : n->chi) // 모든 chi에 대해서 (Node*)
				preorder(i);
		}
	}

	/* 후위순회 연산 */
	void postorder(Node* n)
	{
		if (n->isExternal(n)) // 단말노드 도달하면 비로소 처리후 리턴
		{
			cout << n->data << " "; // process
			return; // 처리종료되어 caller에게 제어권 반환
		}
		else
		{
			// 비단말노드일 때 자식을 먼저 처리 (L -> R)
			for (auto &i : n->chi) // 모든 chi에 대해서 (Node*)
				postorder(i);

			// 자식처리가 모두 종료되면 부모노드 처리 (V)
			cout << n->data << " "; // process
		}
	}
};

int main(void)
{
	Tree t(1);

	int N; // 노드의 개수
	cin >> N;

	// 트리에 노드를 삽입
	for (int i = 0; i < N; i++)
	{
		int P; // 대상노드
		cin >> P;

		for (int j = 0; j < 6; j++) // 자식노드는 최대 5개까지
		{
			int C; // 자식노드
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