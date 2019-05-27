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
	Vertex** v; // vertex ������
	Edge*** matrix;
	vector<Edge*> e;
	int v_sz; // ��������
	int e_sz; // ��������
	int max_sz;

	Graph(int sz)
	{
		this->max_sz = sz;
		this->v_sz = 0; // vertex ����

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
			return; // graph�� �� �̻� ���� ���� �Ұ� �� ����
		if (v[n] == NULL)
		{
			Vertex* new_v = new Vertex();
			v[n] = new_v;
			this->v_sz++;
		}
		else // �̹� ���������� ����
			return;
	}

	void insert_edge(int src, int dest)
	{
		if (v[src] == NULL || v[dest] == NULL) // �� �� ���� ���� ��� ����
		{
			cout << 0 << endl;
			return;
		}
		if (matrix[src][dest] != NULL || matrix[dest][src] != NULL)
		{
			cout << 0 << endl;
			return; // �̹� ���� �����Ͽ� ����
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
	}
};

int main(void)
{
	Graph g(MAX);

	int N; // ���� ��
	int M; // ���� ��
	cin >> N >> M;

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
	cout << g.v_sz << " " << g.e_sz << endl;

	//system("pause");
	return 0;
}