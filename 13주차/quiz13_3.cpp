#include <iostream>
#include <vector>
#include <string>
#define MAX 1000
using namespace std;

/* VERTEX */
class Vertex
{
public:
	int degree; // 정점의 차수
	Vertex() { this->degree = 0; } // 초기화
	void increase_deg() { this->degree++; } // 차수증가
	void decrease_deg() { this->degree--; } // 차수감소
};

/* EDGE */
class Edge
{
public:
	Vertex* src; // 시작점
	Vertex* dest; // 끝점
	string data; // 가중치
	Edge(Vertex* _src, Vertex* _dest, string _data) : src(_src), dest(_dest), data(_data) { }
};

/* GRAPH */
class Graph
{
public:
	int v_sz; // 정점개수
	int e_sz; // 간선개수
	int max_sz; // 인접행렬의 크기
	Vertex** v; // 정점 시퀀스
	vector<Edge*> e; // 간선 시퀀스
	Edge*** matrix; // 인접행렬

	Graph(int sz)
	{
		this->max_sz = sz; // 인접행렬의 크기
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

	/* INSERT OPERATION FOR VERTEX */
	void insert_vertex(int n)
	{
		// graph에 더 이상 정점 삽입 불가 시 종료
		if (v_sz + 1 > max_sz)
			return; 

		// 정점이 없으면 삽입
		if (v[n] == NULL)
		{
			Vertex* new_v = new Vertex();
			v[n] = new_v;
			this->v_sz++;
		}
		// 이미 정점있으면 종료
		else 
			return;
	}

	/* DELETE OPERATION FOR VERTEX */
	void erase_vertex(int n) // 추가된 부분
	{
		// 정점이 없으면 종료
		if (v_sz <= 0)
		{
			cout << -1 << endl;
			return; 
		}

		// 비어있으면 종료
		if (v[n] == NULL)
		{
			cout << -1 << endl; // 에러메세지
			return; 
		}
		// 비어있지 않으면 삭제연산
		else
		{
			Vertex* rmv = v[n]; // 삭제할 것 임시저장

			for (int i = 0; i < max_sz; i++)
			{
				if (matrix[n][i] != NULL) // 무언가가 있으면
				{
					erase_edge(n, i); // 간선을 지우는 함수 호출
					// 무방향 그래프이므로 반드시 대칭적으로 비워줘야 함
					matrix[n][i] = NULL; 
					matrix[i][n] = NULL;
				}
			}

			v[n] = NULL; // 간선을 저장하는 시퀀스에서 삭제
			delete rmv; // 메모리 반환
			v_sz--; // 간선의 수를 하나 줄임

			// 삭제 후 간선에 저장된 값들을 모두 출력하는 처리
			for (auto &i : e)
				cout << i->data << " ";
			cout << endl;
		}
		return;
	}

	/* INSERT OPERATION FOR EDGE */
	void insert_edge(int src, int dest, string data)
	{
		// 양 끝 정점 중 하나라도 없는 경우 종료
		if (v[src] == NULL || v[dest] == NULL) 
		{
			cout << 0 << endl;
			return;
		}

		// 이미 간선 존재하여 종료
		if (matrix[src][dest] != NULL || matrix[dest][src] != NULL)
		{
			cout << 0 << endl;
			return; 
		}

		Edge* new_e = new Edge(v[src], v[dest], data); // 여기에서 가중치를 입력함

		// 무향 그래프이므로 대칭적으로 포인터를 저장해야 함
		matrix[src][dest] = new_e;
		matrix[dest][src] = new_e;

		// 해당 정점의 차수를 증가시킴 (시작점과 끝점 모두 수행)
		v[src]->increase_deg();
		v[dest]->increase_deg();

		e.push_back(new_e); // 간선 시퀀스에 저장
		e_sz++; // 그래프 전체에서 간선의 수를 증가시킴
		return;
	}

	/* DELETE OPERATION FOR VERTEX */
	void erase_edge(int src, int dest)
	{
		// 간선이 존재하지 않는다면 바로 종료
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

		// 간선을 성공적으로 지우면 각 정점의 차수를 감소시킴
		v[src]->decrease_deg();
		v[dest]->decrease_deg();

		// 인접행렬을 갱신시켜 줌
		matrix[src][dest] = NULL;
		matrix[dest][src] = NULL;

		e_sz--; // 그래프 전체에서 간선의 수를 감소시킴
		return;
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