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
			return; // Ʈ���� root��� ����

		int parent = index / 2;
		if (v[parent] > v[index]) // ���� �ε�ȣ �ٲ�
		{
			_swap(parent, index);
			Upheap(parent); // �ٽ� �θ� �������� Upheap ȣ��
		}
		else
			return;
	}

	void Downheap(int index)
	{
		int left = index * 2; // ���� �ڽ�
		int right = index * 2 + 1; // ������ �ڽ�

		if (right <= heap_sz) // ����, ������ �ڽ� �� �ִ� ���
		{
			if (v[left] < v[right]) // ���� �ε�ȣ �ٲ�
			{
				if (v[left] < v[index]) // ���� �ε�ȣ �ٲ�
				{
					_swap(left, index);
					Downheap(left);
				}
				else
					return;
			}
			else
			{
				if (v[right] < v[index]) // ���� �ε�ȣ �ٲ�
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
			if (left <= heap_sz) // ���� �ڽĸ� �ִ� ���
			{
				if (v[left] < v[index]) // ���� �ε�ȣ �ٲ�
					_swap(left, index);
				else // �ڽ��� ���� ���
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

	// 1�� ���� ä�� �� ���� �ּ�ó�� ���ϸ� Ʋ�ȴٰ� ������ �ݵ�� �ּ�ó���ϰ� ���� ��
	for (int i = N - 1; i >= 0; i--) // ���ĵ� ��
		cout << h.remove() << " ";
	cout << endl;

	system("pause");
	return 0;
}