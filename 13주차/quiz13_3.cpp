#include <iostream>
#include <vector>
#include <string>
#define MAX 1000
using namespace std;

/* VERTEX */
class Vertex
{
public:
	int degree; // ������ ����
	Vertex() { this->degree = 0; } // �ʱ�ȭ
	void increase_deg() { this->degree++; } // ��������
	void decrease_deg() { this->degree--; } // ��������
};

/* EDGE */
class Edge
{
public:
	Vertex* src; // ������
	Vertex* dest; // ����
	string data; // ����ġ
	Edge(Vertex* _src, Vertex* _dest, string _data) : src(_src), dest(_dest), data(_data) { }
};

/* GRAPH */
class Graph
{
public:
	int v_sz; // ��������
	int e_sz; // ��������
	int max_sz; // ��������� ũ��
	Vertex** v; // ���� ������
	vector<Edge*> e; // ���� ������
	Edge*** matrix; // �������

	Graph(int sz)
	{
		this->max_sz = sz; // ��������� ũ��
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

	/* INSERT OPERATION FOR VERTEX */
	void insert_vertex(int n)
	{
		// graph�� �� �̻� ���� ���� �Ұ� �� ����
		if (v_sz + 1 > max_sz)
			return; 

		// ������ ������ ����
		if (v[n] == NULL)
		{
			Vertex* new_v = new Vertex();
			v[n] = new_v;
			this->v_sz++;
		}
		// �̹� ���������� ����
		else 
			return;
	}

	/* DELETE OPERATION FOR VERTEX */
	void erase_vertex(int n) // �߰��� �κ�
	{
		// ������ ������ ����
		if (v_sz <= 0)
		{
			cout << -1 << endl;
			return; 
		}

		// ��������� ����
		if (v[n] == NULL)
		{
			cout << -1 << endl; // �����޼���
			return; 
		}
		// ������� ������ ��������
		else
		{
			Vertex* rmv = v[n]; // ������ �� �ӽ�����

			for (int i = 0; i < max_sz; i++)
			{
				if (matrix[n][i] != NULL) // ���𰡰� ������
				{
					erase_edge(n, i); // ������ ����� �Լ� ȣ��
					// ������ �׷����̹Ƿ� �ݵ�� ��Ī������ ������ ��
					matrix[n][i] = NULL; 
					matrix[i][n] = NULL;
				}
			}

			v[n] = NULL; // ������ �����ϴ� ���������� ����
			delete rmv; // �޸� ��ȯ
			v_sz--; // ������ ���� �ϳ� ����

			// ���� �� ������ ����� ������ ��� ����ϴ� ó��
			for (auto &i : e)
				cout << i->data << " ";
			cout << endl;
		}
		return;
	}

	/* INSERT OPERATION FOR EDGE */
	void insert_edge(int src, int dest, string data)
	{
		// �� �� ���� �� �ϳ��� ���� ��� ����
		if (v[src] == NULL || v[dest] == NULL) 
		{
			cout << 0 << endl;
			return;
		}

		// �̹� ���� �����Ͽ� ����
		if (matrix[src][dest] != NULL || matrix[dest][src] != NULL)
		{
			cout << 0 << endl;
			return; 
		}

		Edge* new_e = new Edge(v[src], v[dest], data); // ���⿡�� ����ġ�� �Է���

		// ���� �׷����̹Ƿ� ��Ī������ �����͸� �����ؾ� ��
		matrix[src][dest] = new_e;
		matrix[dest][src] = new_e;

		// �ش� ������ ������ ������Ŵ (�������� ���� ��� ����)
		v[src]->increase_deg();
		v[dest]->increase_deg();

		e.push_back(new_e); // ���� �������� ����
		e_sz++; // �׷��� ��ü���� ������ ���� ������Ŵ
		return;
	}

	/* DELETE OPERATION FOR VERTEX */
	void erase_edge(int src, int dest)
	{
		// ������ �������� �ʴ´ٸ� �ٷ� ����
		if (matrix[src][dest] == NULL || matrix[dest][src] == NULL)
			return;

		for (unsigned int i = 0; i < e.size(); i++)
		{
			if (e[i] == matrix[src][dest] || e[i] == matrix[dest][src])
			{
				e.erase(e.begin() + i);
				break;
			}
		}

		// ������ ���������� ����� �� ������ ������ ���ҽ�Ŵ
		v[src]->decrease_deg();
		v[dest]->decrease_deg();

		// ��������� ���Ž��� ��
		matrix[src][dest] = NULL;
		matrix[dest][src] = NULL;

		e_sz--; // �׷��� ��ü���� ������ ���� ���ҽ�Ŵ
		return;
	}
};

int main(void)
{
	Graph g(MAX);

	int N; // ���� ��
	int M; // ���� ��
	int T; // ������ ���� ��ȣ
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
		string str;
		cin >> s >> d;
		cin >> str;
		g.insert_edge(s, d, str);
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