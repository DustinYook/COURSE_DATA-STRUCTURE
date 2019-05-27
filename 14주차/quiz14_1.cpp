#include <iostream>
#include <vector>
using namespace std;

class Vertex
{
public:
	int degree;
	bool visited; // DFS릁 통해 visit된 경우 true로 변경
	char info; 
	
	Vertex(char c)
	{
		this->degree = 0;
		this->visited = false;
		this->info = c;
	}

	void increase_deg() { this->degree++; }
	void decrease_deg() { this->degree--; }

	void set_visited() { this->visited = true; }
	bool get_visited() { return this->visited; }
};

class Edge
{
public:
	Vertex* src;
	Vertex* dst;
	bool explore; // 확인?
	bool discovery; // 가도 됨?
	bool back; // 가면 안됨?

	Edge(Vertex* src, Vertex* dst)
	{
		this->src = src;
		this->dst = dst;
		this->explore = false;
		this->discovery = false;
		this->back = false;
	}

	bool get_explore() { return this->explore; }
	void set_explore() { this->explore = true;  }

	bool get_discovery() { return this->discovery; }
	void set_discovery() { this->discovery = true; }

	bool get_back() { return this->back; }
	void set_back() { this->back = true; }
};

class Graph
{
public:
	Edge*** matrix; // 인접행렬
	int max_sz; // 최대 크기

	Vertex** v; // 정점 시퀀스
	int v_sz; // 정점 시퀀스의 크기 
	
	vector<Edge*> e; // 간선 시퀀스

	Graph(int sz)
	{
		this->max_sz = sz;
		this->v_sz = 0;

		this->v = new Vertex*[sz];
		for (int i = 0; i < sz; i++)
			v[i] = NULL;

		this->matrix = new Edge**[sz];
		for (int i = 0; i < sz; i++)
		{
			matrix[i] = new Edge*[sz];
			for (int j = 0; j < sz; j++)
				matrix[i][j] = NULL;
		}
	}

	void insert_vertex(int n, char c)
	{
		if (v_sz + 1 > max_sz) // 더 이상 정점삽입 불가한 경우 바로 종료
			return;
		if (v[n] == NULL)
		{
			Vertex* new_v = new Vertex(c);
			v[n] = new_v;
			this->v_sz++;
		}
		else
			return; // 이미 정점 있으면 바로 종료
	}

	void insert_edge(int src, int dst)
	{
		if (v[src] == NULL || v[dst] == NULL) // 삽입된 간선의 양끝 정점 중 하나라도 없으면 바로 종료
			return;
		if (matrix[src][dst] != NULL || matrix[dst][src] != NULL) // 이미 간선 존재하여 종료
			return;

		Edge* new_e = new Edge(v[src], v[dst]);;
		matrix[src][dst] = new_e;
		matrix[dst][src] = new_e;

		v[src]->increase_deg();
		v[dst]->increase_deg();

		e.push_back(new_e);
	}

	void dfs(int start)
	{
		cout << v[start]->info; 
		if (v[start]->get_visited() == true)
		{
			return;
		}
		v[start]->set_visited();
		for (int i = 0; i < max_sz; i++) // 인접행렬 기반 - 모든 행에 대해 확인
		{
			if (matrix[start][i] != NULL || matrix[i][start] != NULL) // || 이후
			{
				if (v[i]->get_visited() == false) // 다음 정점 visit 안 된 경우 수행
				{
					matrix[start][i]->set_explore();
					matrix[start][i]->set_discovery();
					matrix[i][start]->set_explore(); //
					matrix[i][start]->set_discovery(); //
					dfs(i);
				}
				else // 이미 visited인 경우 수행
				{
					if (matrix[start][i]->get_discovery() || matrix[i][start]->get_discovery()) // discovered edge이면 바로 종료 // || 이후
					{
						continue;
					}
					else
					{
						matrix[start][i]->set_explore();
						matrix[start][i]->set_back(); // 다음 정점이 visit이기 때문에 back edge로 설정
						matrix[i][start]->set_explore();
						matrix[i][start]->set_back(); //
					}
				}
			}
		}
	}
};

int main(void)
{
	// 인접행렬 크기 지정
	//cout << "인접행렬 크기 : ";
	int T = 500;
	//cin >> T;
	Graph g(T);

	/* 정점삽입 */
	//cout << "정점 개수 : ";
	int N; // 정점의 수
	cin >> N;

	/* 간선삽입 */
	//cout << "간선 개수 : ";
	int M; // 간선의 수
	cin >> M;

	//cout << "시작정점 번호 : ";
	int S; 
	cin >> S;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		char c;
		cin >> c;

		g.insert_vertex(n, c);
	}

	
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;

		g.insert_edge(n1, n2);
	}

	g.dfs(S);

	system("pause");
}