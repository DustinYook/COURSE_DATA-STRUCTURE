#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

class Vertex
{
public:
	int degree;

	Vertex() { this->degree = 0; }
	void increase_deg()
	{
		this->degree++;
	}

	void decrease_deg()
	{
		this->degree--;
	}
};

class Edge
{
public:
	Vertex* src;
	Vertex* dest;

	Edge(Vertex* src, Vertex* dest)
	{
		this->src = src;
		this->dest = dest;
	}
};

class Graph
{
public:
	Vertex** v; // vertex 시퀀스
	Edge*** matrix;
	vector<Edge*> e;
	int v_sz; // 정점개수
	int e_sz; // 간선개수
	int max_sz;

	Graph(int sz)
	{
		this->max_sz = sz;
		this->v_sz = 0; // vertex 개수

		this->v = new Vertex*[sz + 1];
		for (int i = 0; i <= sz; i++)
			v[i] = NULL;

		this->matrix = new Edge**[sz + 1];
		for (int i = 0; i <= sz; i++)
		{
			matrix[i] = new Edge*[sz + 1];
			for (int j = 0; j <= sz; j++)
				matrix[i][j] = NULL;
		}
	}

	void insert_vertex(int n)
	{
		if (v_sz + 1 > max_sz)
			return; // graph에 더 이상 정점 삽입 불가 시 종료
		if (v[n] == NULL)
		{
			Vertex* new_v = new Vertex();
			v[n] = new_v;
			this->v_sz++;
		}
		else // 이미 정점있으면 종료
			return;
	}

	void erase_vertex(int n)
	{
		if (v_sz <= 0)
		{
			cout << -1 << endl;
			return; // 정점이 없으면 종료
		}
		if(v[n] == NULL)
		{
			cout << -1 << endl;
			return; // 비어있으면 종료
		}
		else
		{
			Vertex* rmv = v[n]; // 삭제할 것 임시저장
			for (int i = 0; i < max_sz; i++)
			{
				if (matrix[n][i] != NULL) // 무언가가 있으면
				{
					erase_edge(n, i);
					matrix[n][i] = NULL;
					matrix[i][n] = NULL;
				}
			}
			v[n] = NULL; // 비움
			delete rmv;
			v_sz--;

			cout << v_sz << " " << e_sz << endl;
		}
	}

	void insert_edge(int src, int dest)
	{
		if (v[src] == NULL || v[dest] == NULL) // 양 끝 정점 없는 경우 종료
		{
			cout << 0 << endl;
			return;
		}
		if (matrix[src][dest] != NULL || matrix[dest][src] != NULL)
		{
			cout << 0 << endl;
			return; // 이미 간선 존재하여 종료
		}

		Edge* new_e = new Edge(v[src], v[dest]);
		matrix[src][dest] = new_e;
		matrix[dest][src] = new_e;

		v[src]->increase_deg();
		v[dest]->increase_deg();

		e.push_back(new_e);
		e_sz++;
		return;
	}

	void erase_edge(int src, int dest)
	{
		if (matrix[src][dest] == NULL || matrix[dest][src] == NULL)
			return;
		v[src]->decrease_deg();
		v[dest]->decrease_deg();

		for (unsigned int i = 0; i < e.size(); i++)
		{
			if (e[i] == matrix[src][dest] || e[i] == matrix[dest][src])
			{
				e.erase(e.begin() + i);
				break;
			}
		}

		matrix[src][dest] = NULL;
		matrix[dest][src] = NULL;
		e_sz--;
	}
};

int main(void)
{
	Graph g(MAX);

	int N; // 정점 수
	int M; // 간선 수
	int T; // 삭제할 간선 번호
	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		g.insert_vertex(v);
	}

	for (int j = 0; j < M; j++)
	{
		int s, d;
		cin >> s >> d;
		g.insert_edge(s, d);
	}

	for (int k = 0; k < T; k++)
	{
		int t;
		cin >> t;
		g.erase_vertex(t);
	}

	system("pause");
	return 0;
}