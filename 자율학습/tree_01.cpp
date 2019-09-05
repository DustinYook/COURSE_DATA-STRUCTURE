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
	void insertChild(Node* n)
	{
		chi.push_back(n); // 자식노드 삽입
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

	/* 자식노드 출력연산 */
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
};

class Tree
{
public:
	Node* root; // 트리의 루트노드를 가리키는 포인터
	vector<Node*> tree_list; // 트리의 노드목록

	/* 빈 트리 생성 */
	Tree() { root = NULL; }

	/* 루트노드만 있는 트리생성 */
	Tree(int v)
	{
		root = new Node(v); // 노드생성
		tree_list.push_back(root); // 노드삽입
	}

	/* 노드 탐색연산 */
	// 입력 : 찾고자 하는 노드번호
	// 출력 : 해당 노드의 주소
	Node* searchNode(int v)
	{
		for (auto &i : tree_list) // 모든 트리노드 탐색
		{
			if (i->data == v) // 원하는 값 가진 노드 발견
				return i; // 해당 노드의 주소를 반환
		}
	}

	/* 트리 노드 삽입연산 */
	// 입력 : 타겟노드 번호, 입력할 값
	// 출력 : 삽입된 상태
	void insertNode(int t, int v)
	{
		Node* tar = searchNode(t); // t의 값을 가진 노드를 받아옴

		// 1단계 : 노드생성
		Node* n = new Node(v); // 삽입할 노드생성

		// 2단계 : 링크필드 갱신
		tar->insertChild(n); // 자식 링크필드 갱신
		n->par = tar; // 부모 링크필드 갱신

		// 3단계 : 트리목록 추가
		tree_list.push_back(n); // 트리의 목록에 추가

		return; // 할 일 다했으므로 caller에게 제어권 반환
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

		for (int j = 0; j < 5; j++) // 자식노드는 최대 5개까지
		{
			int C; // 자식노드
			cin >> C;

			if (C != 0)
				t.insertNode(P, C);
			else
				break;
		}
	}

	// 특정 노드의 자식을 모두 출력
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