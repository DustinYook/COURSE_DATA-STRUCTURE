#include<iostream>
using namespace std;

/* Node */
class Node
{
public:
	int number; // �������ʵ�
	Node* next; // ��ũ�ʵ�
	Node(int num) // ������ (�ʱ�ȭ)
	{
		number = num;
		next = NULL;
	}
};

/* Circular LinkedList */
class Circular
{
public:
	Node* head; // ����带 ����Ű�� ������
	Node* now; // ���� Ŀ�� ��ġ�� ����Ű�� ������

	// 1) ������
	Circular()
	{
		head = NULL;
		now = NULL;
	}

	// 2) ������
	void insert_Node(Node* newNode)
	{
		// list�� ����ִ� ���
		if (head == NULL)
		{
			head = newNode; // head�� ���� ������ ��带 ����Ŵ
			now = newNode; // now�� ���� ������ ��带 ����Ŵ
			newNode->next = newNode; // �ڱ� �ڽ��� ����Ű�� �� (ȯ���̱� ����)
		}
		// list�� ��尡 �ִ� ���
		else
		{
			now->next = newNode;
			now = newNode;
			now->next = head;
		}
	}

	// 3) ������
	void delete_Node(int M)
	{
		int count = 1;
		Node* prev = NULL;

		while (count != M)
		{
			prev = now;
			now = now->next;
			count++; // ī��Ʈ�� �ϳ��� ������Ŵ
			// �ݺ����� ����Ͽ� 1���� ���������鼭 M��° ������ �̵�
		}
		cout << (now->number); // �����Ǵ� ����� �� ��� - �����̵忡�� üũ ǥ�õ� ��
		prev->next = now->next;
		now = now->next;
	}
};

int main(void)
{
	int N, M;
	cin >> N >> M; // ���� N�� M �Է� 

	Circular circular; // Circular Linked List ����
	for (int i = 1; i <= N; i++)
	{
		Node* newNode = new Node(i); // Node ���� �� ��
		circular.insert_Node(newNode); // Ciruclar List�� ����
	}
	circular.now = circular.head;

	cout << "<";
	while (N--)
	{
		circular.delete_Node(M); // Circular List���� ��� �ϳ��� ����
		if (N != 0)
			cout << ", ";
	}
	cout << ">";

	return 0;
}