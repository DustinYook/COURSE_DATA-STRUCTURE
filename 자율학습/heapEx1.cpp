#include <iostream> 
#include <vector>
using namespace std;

class Heap
{
public:
	vector<int> pos;
	int* root; // root position
	int cnt;

	Heap(int v)
	{
		root = &pos[1]; // generate root
		pos[1] = v;
		cnt = 1;
	}

	int* getRoot()
	{
		return root;
	}

	int* getLast()
	{
		return &pos[size()];
	}

	int size(void)
	{
		return (cnt - 1);
	}

	int rankOf(int* p) // position -> rank
	{
		return (p - &pos[0]) / sizeof(int) - 1;
	}

	int* rankAt(int r) // rank -> position
	{
		return &pos[r];
	}

	int* left(int*& p)
	{
		return rankAt(2 * rankOf(p));
	}

	int* right(int*& p)
	{
		return rankAt(2 * rankOf(p) + 1);
	}

	int* parent(int*& p)
	{
		return rankAt(rankOf(p) / 2);
	}

	int* root()
	{
		return rankAt(1);
	}

	bool hasLeft(int*& p)
	{
		return (2 * rankOf(p)) <= size();
	}

	bool hasRight(int*& p)
	{
		return (2 * rankOf(p)) + 1 <= size();
	}

	void insert(int e)
	{
		// new element to last position of tree
		int i = cnt;
		pos[i] = e;

		// up-heap bubbling
		while (i != 0) // during last is not root
		{
			if (*parent(i) < harr[i]) // if heap property is satisfied
				break;

			if()
			else // restore heap property
			{
				swap(&harr[i], &harr[parent(i)]);
				i = parent(i);
			}
		}
	}

	int removeMin()
	{
		int temp = 0;

		if (now <= 0) // if no node in the tree
			return -1; // underflow
		else
		{
			if (now == 1)
			{
				now--;
				return harr[0]; // return root (need to be modified)
			}
			else
			{
				int temp = harr[0]; // temporarily save the root node
				swap(&harr[0], &harr[now - 1]); // swap root for last one
				now--; // decrease the number in the array
				return temp; // return the first element

				while (hasLeft(0))
				{
					int v = left(0);
				}
			}
		}
	}

	void swap(int* x, int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}


	// Method to remove minimum element (or root) from min heap 
	// to extract the root which is the minimum element 
	int extractMin()
	{
		if (now <= 0)
			return INT_MAX;
		if (now == 1)
		{
			now--;
			return harr[0];
		}

		// Store the minimum value, and remove it from heap 
		int root = harr[0];
		harr[0] = harr[now - 1];
		now--;
		MinHeapify(0);

		return root;
	}

	// A recursive method to heapify a subtree with the root at given index 
	// This method assumes that the subtrees are already heapified 
	// to heapify a subtree with the root at given index 
	void MinHeapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int smallest = i;

		if (l < now && harr[l] < harr[i])
			smallest = l;
		if (r < now && harr[r] < harr[smallest])
			smallest = r;
		if (smallest != i)
		{
			swap(&harr[i], &harr[smallest]);
			MinHeapify(smallest);
		}
	}

	// Decreases value of key at index 'i' to new_val. It is assumed that 
	// new_val is smaller than harr[i]. 
	//void decreaseKey(int i, int new_val)
	//{
	//	harr[i] = new_val;
	//	while (i != 0 && harr[parent(i)] > harr[i])
	//	{
	//		swap(&harr[i], &harr[parent(i)]);
	//		i = parent(i);
	//	}
	//}

	// Returns the minimum key (key at root) from min heap 
	int getMin() 
	{ 
		return harr[0]; 
	}

	// This function deletes key at index i. It first reduced value to minus 
	// infinite, then calls extractMin() 
	// Deletes a key stored at index i 
	void deleteKey(int i)
	{
		decreaseKey(i, INT_MIN);
		extractMin();
	}
};