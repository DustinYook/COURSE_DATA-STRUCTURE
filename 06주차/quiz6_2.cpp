#include <iostream>
#include <vector> // 벡터를 이용하여 자식노드 링크필드 제어
using namespace std;

template <typename T>
class GeneralTree;

/* Node */
template <typename T>
class Node
{
private:
	T data; // 데이터필드
	Node* par; // 부모를 가리키는 링크필드
	vector<Node*> chi; // 자식을 가리키는 링크필드

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

	void setParent(Node* par) // 부모노드 설정
	{
		this->par = par;
		return;
	}

	void insertChild(Node* chi) // 현재 노드에 자식노드를 추가
	{
		this->chi.push_back(chi); // 자식 링크필드에 추가
		return;
	}

	void delChild(Node* chi) // 현재노드의 자식노드 중 특정노트 하나를 삭제
	{
		for (int i = 0; i < this->chi.size(); i++)
		{
			// 원하는 자식노드의 주소를 알아낸 경우
			if (this->chi[i] == chi)
			{
				this->chi.erase(this->chi.begin() + i);
				// 자식링크벡터의 i번째 element를 삭제
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
	Node<T>* root; // 루트노드를 가리키는 포인터
	vector<Node<T>*> node_list; // 노드의 목록 -> 순회를 위한 리스트
	int tree_size = 0;

public:
	GeneralTree() // 빈 트리 생성
	{
		root = NULL;
	}

	GeneralTree(T data) // 루트노드를 가지는 트리생성
	{
		root = new Node<T>(data);
		node_list.push_back(root);
	}

	~GeneralTree() { }

	void insertNode(T parent_data, T data)
	{
		Node<T>* par; // 자식을 삽입할 대상노드
		for (auto &i : this->node_list)
		{
			if (i->data == parent_data)
			{
				par = i;
				Node<T>* newnode = new Node<T>(data); // 새 노드 생성
				par->insertChild(newnode); // parent의 링크필드 설정
				newnode->setParent(par);
				node_list.push_back(newnode); // 트리노드 목록에 저장
				return;
			}
		}
		return;
	}

	void delNode(T data) // data를 가지고 있는 노드삭제
	{
		Node<T>* nownode; // 현재노드를 가리키는 포인터
		Node<T>* par; // now 노드의 직계부모를 가리키는 포인터

		// 트리의 노드리스트를 탐색
		for (int i = 0; i < this->node_list.size(); i++)
		{
			// 저장데이터가 우리가 원하는 데이터이면
			if (this->node_list[i]->data == data)
			{
				nownode = node_list[i]; // 현재노드의 위치를 저장
				par = nownode->par; // 현재노드의 직계부모 위치를 저장

				// 현재노드의 모든 자식들을 직계부모의 자식으로 만듦
				for (auto &child : nownode->chi)
				{
					// 고아노드를 기존노드의 직계부모의 자식으로 만듦
					par->insertChild(child);

					// 고아노드의 부모링크를 기존노드의 직계부모를 가리키게 함
					child->setParent(par);
				}
				par->delChild(nownode); // 기존노드의 직계부모가 기존노드를 삭제함
				this->node_list.erase(this->node_list.begin() + i);
				delete nownode; // 메모리반환
			}
		}
	}

	void printChild(T data)
	{
		// 트리 리스트를 탐색
		for (auto &i : this->node_list)
		{
			// 원하는 데이터가 있으면
			if (i->data == data)
			{
				if (i->chi.size() == 0)
					cout << "0";
				for (auto &child : i->chi)
					cout << child->data << " ";
				cout << endl;

				// 정상적으로 수행된 경우 caller에게 제어권 리턴
				return; // 여기에 리턴을 무조건 써줘야 '-1'이 항상 출력되는 오류방지가능
			}
		}
		// 비정상적으로 수행된 경우 '-1'을 출력
		cout << "-1" << endl;
		return;
	}

	int countDept(T data) // data를 가지는 노드의 깊이 출력
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

		for (int j = 0; j < 5; j++) // 자식은 최대 5개 까지
		{
			int val; // 자식노드의 데이터필드값 입력
			cin >> val;
			t.insertNode(i, val);

			if (val == 0) // 0이 입력되면 첫번째 루프 탈출
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