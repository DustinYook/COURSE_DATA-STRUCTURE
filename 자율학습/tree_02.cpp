#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data; // 데이터필드
	Node* par; // 부모를 가리키는 링크필드
	vector<Node*> chi; // 자식을 가리키는 링크필드

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

	/* 자식노드를 출력하는 연산 */
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

	/* 노드의 깊이 구하는 연산 */
	int depth(Node* t)
	{
		Node* ptr = t; // 제어변수
		int cnt = 0; // 카운트

		while (ptr->par != NULL)
		{
			ptr = ptr->par; // ptr의 부모로 이동
			cnt++;
		}
		return cnt;
	}

	/* 조상노드를 출력하는 연산 */
	void ansestors(Node* t)
	{
		Node* ptr = t;

		while (ptr->par != NULL)
		{
			ptr = ptr->par;
			cout << ptr->data << " ";
		}
		cout << endl;
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

	/* 트리노드 탐색연산 */
	Node* searchNode(int v)
	{
		for (auto &i : tree_list) // 트리리스트 탐색
		{
			if (i->data == v) // 대상 노드 발견
				return i;
		}
	}

	/* 트리노드 삽입연산 */
	void insertNode(int t, int v)
	{
		Node* tar = searchNode(t); // 대상노드 찾기

		// 1단계: 노드생성
		Node* n = new Node(v);

		// 2단계: 링크필드 갱신
		tar->insertChild(n); // 자식 링크필드 갱신
		n->par = tar; // 부모 링크필드 갱신

		// 3단계: 트리 목록추가
		tree_list.push_back(n);

		return; // 할 일 다했으므로 caller에게 제어권 반환
	}

	/* 트리노드 삭제연산 */
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

	/* 트리의 높이를 구하는 연산 */
	int height(void)
	{
		int max = -999;
		for (auto &i : tree_list)
		{
			if (i->depth(i) > max)
				max = i->depth(i);
		}
		return max;
	}
};

int main(void)
{
	Tree t(1);

	int N; // 노드의 개수
	cin >> N;

	int M; // 자식의 수를 묻는 질문 수
	cin >> M;

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
	cout << "트리의 높이 : " << t.height() << endl;

	// 특정 노드의 자식을 모두 출력
	for (int i = 0; i < M; i++)
	{
		int T;
		cin >> T;

		Node* N = t.searchNode(T);
		N->depth(N);
		//N->ansestors(N);
	}

	system("pause");
	return 0;
}