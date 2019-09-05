#include<iostream>

using namespace std;

class Node {
public:
	int number;
	Node* next;
	Node(int num) {
		number = num;
		next = NULL;
	}
};

class Circular {

public:
	Node* head;
	Node* now;
	Circular() {
		head = NULL; // circular list�� ù��° ���
		now = NULL; // cursor�� ���� ����Ű�� ���
	}

	void insert_Node(Node* newNode) {
		if (head == NULL) { // list�� ��尡 ���� ���
			/* 
				head, now�� ���� ������ ��带 ����Ų��.
				Circular �̱� ������, ���ο� ����� next �����͸� �ڱ��ڽ����� ����
				
				ä����������!
			*/
		}
		else {
			/*
				now �� �̿��Ͽ� ���ο� ��� �߰� - ���� ���� �ִϸ��̼� ����
				Circular �̱� ������, ���ο� ����� next �����͸� head�� ����

				ä����������!
			*/
		}
	}

	void delete_Node(int M) {

		int count = 1;
		Node* prev = NULL;

		while (count != M) {
			/* 
				�ݺ����� ����Ͽ� 1���� ���������鼭 M��° ������ �̵�

				ä����������!
			*/
		}

		cout << now->number; // �����Ǵ� ����� �� ��� - �����̵忡�� üũ ǥ�õ� ��

		/*
			���� �� ��, ��ũ �缳�� �ʿ�

			ä����������!
		*/
	}

};

int main() {

	int N, M;
	cin >> N >> M; // Input �Ǵ� ���� N�� M �Է� 

	Circular circular; // Ciruclar List ����
	for (int i = 1; i <= N; i++) {
		Node* newNode = new Node(i); // Node ���� �� ��
		circular.insert_Node(newNode); // Ciruclar List�� ����
	}
	circular.now = circular.head;

	cout << "<";
	while (N--) {
		circular.delete_Node(M); // Circular List���� ��� �ϳ��� ����
		cout << ", ";
	}
	cout << ">";
	return 0;
}