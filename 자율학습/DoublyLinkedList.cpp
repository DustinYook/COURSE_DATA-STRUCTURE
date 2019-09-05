#include <iostream>
using namespace std;

class Node
{
public:
	char data; // �������ʵ�
	Node* prev; // ��ũ�ʵ�1
	Node* next; // ��ũ�ʵ�2

	Node(char value)
	{
		data = value;
		prev = NULL;
		next = NULL;
	}
};

class DoublyLinkedList
{
public:
	Node* head; // ���� �� ��带 ����Ű�� ������
	Node* tail; // ���� �� ��带 ����Ű�� ������
	int count;

	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	void insert(int p, char x) // �Է���ġ, �Է°� -> p�� �տ� ��带 ����
	{
		if (p != 0 && p <= count) // �Է� ���� ��ȿ�� ���
		{
			Node* ptr; // ���ϴ� ��ġ(p)�� ������ ����
			int now = 0; // ��ġ�� ī��Ʈ�ϱ� ���� ����ϴ� ����
			for (ptr = head; ptr != NULL; ptr = ptr->next) // ��� ��ü ��ȸ
			{
				if (now == p) // ���ϴ� ��ġ���� Ȯ��
					break;
				now++;
			}
			if (ptr->prev == head) // �����ϴ� ��ġ�� �� ��尡 head�� ���
			{
				// 1�ܰ� : ������
				Node* temp = new Node(x); 
				// 2�ܰ� : ���ο� ��带 �޴� - �߿�) �׻� ���ο� ������ ó��
				temp->prev = head; 
				temp->next = head; 
				// 3�ܰ� : ���� ����� ��ũ�ʵ带 ����
				head = temp;
				(temp->next)->prev = temp;
				// 4�ܰ� : ����Ʈ ��ü�� ī��Ʈ�� ����
				count++;
			}
			else // �����ϴ� ��ġ�� �� ��尡 head�� �ƴ� ���
			{
				// 1�ܰ� : ������
				Node* temp = new Node(x);
				// 2�ܰ� : ���ο� ��带 ���� ����Ʈ�� �޴� - �߿�) �׻� ���ο� ������ ó��
				temp->prev = ptr->prev;
				temp->next = ptr;
				// 3�ܰ� : ���� ����� ��ũ�ʵ带 ����
				(temp->prev)->next = temp;
				ptr->prev = temp;
				// 4�ܰ� : ����Ʈ ��ü�� ī��Ʈ�� ����
				count++;
			}
		}
		else // �Է°��� ��ȿ���� ���� ���
			cerr << "�߸��� ����Դϴ�." << endl;
	}

	void insert(char x) // head�� insert
	{
		if (count == 0) // ����Ʈ�� �� ���
		{
			// 1�ܰ� : ���ο� ��� ����
			Node* temp = new Node(x); 
			// 2�ܰ� : ���ο� ��带 ���� ����Ʈ�� �޴�
			temp->prev = head;
			temp->next = tail;
			// 3�ܰ� : ���� ����� ��ũ�ʵ带 ����
			head = temp;
			tail = temp;
			// 4�ܰ� : ����Ʈ ��ü�� ī��Ʈ�� ����
			count++;
		}
		else // ����Ʈ�� ������� ���� ���
		{
			// 1�ܰ� : ���ο� ��� ����
			Node* temp = new Node(x);
			// 2�ܰ� : ���ο� ��带 ���� ����Ʈ�� �޴�
			temp->prev = head;
			temp->next = head; // head�� �������� ��� head->next�� ����
			// 3�ܰ� : ���� ����� ��ũ�ʵ带 ����
			head = temp;
			(temp->next)->prev = temp;
			// 4�ܰ� : ����Ʈ ��ü�� ī��Ʈ�� ����
			count++;
		}
	}

	void remove(int p) // p��° ��ġ�� ���尪�� ����
	{
		if (p != 0 && p < count) // �Է°��� ��ȿ�� ���
		{
			/* ������ ��ġ�� �ش�Ǵ� ��带 ã�� ó�� */
			Node* ptr; // ���ϴ� ��ġ(p)�� ������ ����
			int now = 0; // ��ġ�� ī��Ʈ�ϱ� ���� ����ϴ� ����
			for (ptr = head; ptr != NULL; ptr = ptr->next) // ��� ��ü ��ȸ
			{
				if (now == p) // ���ϴ� ��ġ���� Ȯ��
					break;
				now++;
			}

			if (ptr->next != tail) // ��� ����� ���� ��尡 tail�� �ƴ� ���
			{
				// 1�ܰ� : ������ ��� �����͸� �ӽ�����
				Node* rmv = ptr;
				// 2�ܰ� : ���� ����� ��ũ�ʵ带 ����
				(ptr->prev)->next = ptr->next;
				(ptr->next)->prev = ptr->prev;
				// 3�ܰ� : �޸� ȸ��
				delete rmv;
				// 4�ܰ� : ����Ʈ ��ü�� ī��Ʈ ����
				count--;
			}
			else // ��� ����� ���� ��尡 tail�� ���
			{
				// 1�ܰ� : ������ ��� �����͸� �ӽ�����
				Node* rmv = ptr;
				// 2�ܰ� : ���� ����� ��ũ�ʵ带 ����
				(ptr->prev)->next = tail;
				tail = ptr->prev;
				// 3�ܰ� : �޸� ȸ��
				delete rmv;
				// 4�ܰ� : ����Ʈ ��ü�� ī��Ʈ ����
				count--;
			}
		}
		else // �Է°��� ��ȿ���� ���� ���
			cerr << "�߸��� ����Դϴ�." << endl;
	}

	void traverse(void) // ��ȸ
	{
		for (Node* ptr = head; ptr != NULL; ptr = ptr->next)
			cout << (ptr->data) << " ";
		cout << endl;
	}
};

int main(void)
{
	DoublyLinkedList d;
	for (char c = 'a'; c <= 'd'; c++)
		d.insert(c);
	d.traverse();

	d.insert(2, 'x');
	d.traverse();

	d.insert(0, 'y'); // insert(0, x)�� ��쿡 ����
	d.traverse();

	d.insert(3, 'y');
	d.traverse();

	d.insert(1, 'z');
	d.traverse();

	d.remove(2);
	d.traverse();

	d.remove(0);
	d.traverse();

	system("pause");
	return 0;
}