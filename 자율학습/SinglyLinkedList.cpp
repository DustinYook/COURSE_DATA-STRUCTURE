#include<iostream>
using namespace std;

/* ��ũ�帮��Ʈ�� ��� */
class Node
{
public:
	int data; // �������ʵ�
	Node* link; // ��ũ�ʵ�
	Node(int num)
	{
		data = num;
		link = NULL;
	}
};

/* ���ϸ�ũ�帮��Ʈ */
class SinglyLinkedList
{
public:
	Node* head; // ����Ʈ�� ����带 ����Ű�� ������
	Node* tail; // ����Ʈ�� ���ϳ�带 ����Ű�� ������

	// ������ �Լ� : head�� tail �����͸� NULL�� �ʱ�ȭ
	SinglyLinkedList()
	{
		head = NULL;
		tail = NULL;
	};

	void insert_Node(int number)
	{
		// ���� ��ũ�� ����Ʈ ����
		// ���ο� ��带 �����ϰ�, ���� �� ��带 ����Ű�� �������� head�� ������Ʈ �����ش�
		// �����ڷ� 7p ����

		// �ʱ⿡ ����Ʈ�� ����ִ� ���
		if (head == NULL)
		{
			// head�� ����Ű�°��� ���� ���, �� ����Ʈ�� ��� ��嵵 ������ ó��
			Node* newNode = new Node(number);
			newNode->data = number; // ���ο� ��� ������ ����
			newNode->link= tail; // ���ϳ�带 ����Ű�� ������ ����
			head = newNode; // ����带 ����Ű�� ������ ����
		}
		else
		{
			// head�� ����Ű�°��� �ִ� ��� ó��
			Node* newNode = new Node(number);
			newNode->data = number;
			newNode->link = head; // ���ο� ��尡 ������ head�� ����Ų��.
			head = newNode; // head�� ���ο� ��尡 �ȴ�.
		}
	}

	void delete_Node()
	{
		// ���� ��ũ�� ����Ʈ ����
		// ��带 �����ϰ� head�� ������Ʈ ��Ų��
		// �����ڷ� 8p ����
		if (head != NULL)
		{
			// ������ ��尡 ���� ��� ó��
			Node* prev = head;
			head = head->link; // ���� head�� ���� ��带 head�� ����
			delete prev; // ����� �޸� ����
		}
	}

	void traverseNodes()
	{
		Node* ptr;

		/* for���� �̿��Ͽ� ���� */
		for (ptr = head; ptr != NULL; ptr = ptr->link)
			cout << (ptr->data) << " ";
		cout << endl;

		/* while���� �̿��Ͽ� ���� */
		while (ptr != NULL)
		{
			cout << ptr->data << " ";
			ptr = ptr->link;
		}
	}
};

int main()
{
	SinglyLinkedList sl;

	sl.insert_Node(5);
	sl.insert_Node(10);
	sl.insert_Node(3);
	sl.traverseNodes();

	system("pause");
	return 0;
}