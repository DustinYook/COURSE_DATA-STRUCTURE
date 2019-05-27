#include <iostream>
#include <vector>
using namespace std;

class Vertex
{
public:
	int degree;
	bool visited; // DFS�d ���� visit�� ��� true�� ����
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
	bool explore; // Ȯ��?
	bool discovery; // ���� ��?
	bool back; // ���� �ȵ�?

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
	Edge*** matrix; // �������
	int max_sz; // �ִ� ũ��

	Vertex** v; // ���� ������
	int v_sz; // ���� �������� ũ�� 
	
	vector<Edge*> e; // ���� ������

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
		if (v_sz + 1 > max_sz) // �� �̻� �������� �Ұ��� ��� �ٷ� ����
			return;
		if (v[n] == NULL)
		{
			Vertex* new_v = new Vertex(c);
			v[n] = new_v;
			this->v_sz++;
		}
		else
			return; // �̹� ���� ������ �ٷ� ����
	}

	void insert_edge(int src, int dst)
	{
		if (v[src] == NULL || v[dst] == NULL) // ���Ե� ������ �糡 ���� �� �ϳ��� ������ �ٷ� ����
			return;
		if (matrix[src][dst] != NULL || matrix[dst][src] != NULL) // �̹� ���� �����Ͽ� ����
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
		for (int i = 0; i < max_sz; i++) // ������� ��� - ��� �࿡ ���� Ȯ��
		{
			if (matrix[start][i] != NULL || matrix[i][start] != NULL) // || ����
			{
				if (v[i]->get_visited() == false) // ���� ���� visit �� �� ��� ����
				{
					matrix[start][i]->set_explore();
					matrix[start][i]->set_discovery();
					matrix[i][start]->set_explore(); //
					matrix[i][start]->set_discovery(); //
					dfs(i);
				}
				else // �̹� visited�� ��� ����
				{
					if (matrix[start][i]->get_discovery() || matrix[i][start]->get_discovery()) // discovered edge�̸� �ٷ� ���� // || ����
					{
						continue;
					}
					else
					{
						matrix[start][i]->set_explore();
						matrix[start][i]->set_back(); // ���� ������ visit�̱� ������ back edge�� ����
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
	// ������� ũ�� ����
	//cout << "������� ũ�� : ";
	int T = 500;
	//cin >> T;
	Graph g(T);

	/* �������� */
	//cout << "���� ���� : ";
	int N; // ������ ��
	cin >> N;

	/* �������� */
	//cout << "���� ���� : ";
	int M; // ������ ��
	cin >> M;

	//cout << "�������� ��ȣ : ";
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