#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data; // 데이터필드
	int size; // 폴더의 용량
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

	void setSize(int v)
	{
		size = v;
	}
};

class Tree
{
public:
	Node* root; // 트리의 루트노드를 가리키는 포인터
	vector<Node*> tree_list; // 트리의 노드 목록을 저장하는 리스트

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
		// range-based for-loop
		for (auto &i : tree_list) // i는 리스트를 구성하는 element (Node*) 
		{
			if (i->data == t) // t의 값을 가진 노드 탐색
			{
				Node* n = new Node(v); // 삽입할 노드생성
				i->insertChild(n); // 부모노드의 자식 링크필드 갱신
				n->par = i; // 해당노드의 부모 링크필드 갱신
				tree_list.push_back(n); // 트리의 목록에 추가
				return; // 할 일 다했으므로 caller에게 제어권 반환
			}
		}
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

	int postorder(Node* n)
	{
		int sum = 0;

		if (n->isExternal(n)) // 단말노드
			return n->size;
		else // 비단말노드
		{
			// 자식들을 우선 모두처리 (from left to right)
			for (auto &i : n->chi)
				sum += postorder(i);
			sum += n->size;
		}
		return sum;
	}
};

int main(void)
{
	Tree t(1);

	int N; // 노드의 개수
	cin >> N;

	int M; // 확인할 폴더의 개수
	cin >> M;

	// 폴더의 사이즈를 받아옴
	int sizeArr[27] = { 0 };
	for (int i = 1; i <= N; i++)
	{
		int F; // 폴더의 번호
		cin >> F;

		int S; // 폴더의 사이즈
		cin >> S;

		sizeArr[F] = S;
	}

	// 트리에 노드를 삽입
	for (int i = 0; i < N; i++)
	{
		int P; // 대상노드
		cin >> P;

		for (int j = 0; j < 5; j++) // 자식노드는 최대 5개까지
		{
			int C; // 자식노드
			cin >> C;

			if (C != 0)
			{
				t.insertNode(P, C);
				t.searchNode(P)->size = sizeArr[P];
				t.searchNode(C)->size = sizeArr[C];
			}
			else
				break;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int tar; // 확인할 폴더의 번호
		cin >> tar;

		cout << t.postorder(t.searchNode(tar)) << endl;
	}

	system("pause");
	return 0;
}