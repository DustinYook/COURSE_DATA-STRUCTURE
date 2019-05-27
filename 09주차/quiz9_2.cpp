#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
	vector<int> v;
	int heap_sz;
	int root_index = 1;

	Heap()
	{
		v.push_back(-1);
		heap_sz = 0;
	}

	void _swap(int index1, int index2)
	{
		v[0] = v[index1];
		v[index1] = v[index2];
		v[index2] = v[0];
	}

	void Upheap(int index)
	{
		if (index == root_index)
			return; // 트리의 root라면 멈춤

		int parent = index / 2;
		if (v[parent] > v[index]) // 여기 부등호 바꿈
		{
			_swap(parent, index);
			Upheap(parent); // 다시 부모를 기준으로 Upheap 호출
		}
		else
			return;
	}

	void Downheap(int index)
	{
		int left = index * 2; // 왼쪽 자식
		int right = index * 2 + 1; // 오른쪽 자식

		if (right <= heap_sz) // 왼쪽, 오른쪽 자식 다 있는 경우
		{
			if (v[left] < v[right]) // 여기 부등호 바꿈
			{
				if (v[left] < v[index]) // 여기 부등호 바꿈
				{
					_swap(left, index);
					Downheap(left);
				}
				else
					return;
			}
			else
			{
				if (v[right] < v[index]) // 여기 부등호 바꿈
				{
					_swap(right, index);
					Downheap(right);
				}
				else
					return;
			}
		}
		else
		{
			if (left <= heap_sz) // 왼쪽 자식만 있는 경우
			{
				if (v[left] < v[index]) // 여기 부등호 바꿈
					_swap(left, index);
				else // 자식이 없을 경우
					return;
			}
		}
	}

	void insert(int num)
	{
		v.push_back(num);
		heap_sz++;
		Upheap(heap_sz);
	}

	int remove()
	{
		int ret = v[1];
		v[1] = v[heap_sz--];
		v.pop_back();
		Downheap(root_index);
		return ret;
	}
};

int main(void)
{
	Heap h;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;

		h.insert(M);
	}

	for (int i = 1; i <= N; i++)
		cout << h.v[i] << " ";
	cout << endl;

	// 1번 문제 채점 시 여기 주석처리 안하면 틀렸다고 나오니 반드시 주석처리하고 돌릴 것
	for (int i = N - 1; i >= 0; i--) // 정렬된 것
		cout << h.remove() << " ";
	cout << endl;

	system("pause");
	return 0;
}