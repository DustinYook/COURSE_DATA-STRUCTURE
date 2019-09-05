#include<iostream>

using namespace std;

class Single_LinkedList_Node { 
public:
	int number;
	Single_LinkedList_Node * next;
	Single_LinkedList_Node(int num) {
		number = num;
		next = NULL;
	}
};

class Single_LinkedList {
public:
	Single_LinkedList_Node* head;
	Single_LinkedList_Node* tail;

	Single_LinkedList() { // ������ �Լ� : head�� tail �����͸� NULL�� �ʱ�ȭ �Ѵ�.
		head = NULL;
		tail = NULL;
	};

	void insert_Node(int number) {
		
		/*
			���� ��ũ�� ����Ʈ ����
			���ο� ��带 �����ϰ�, ���� �� ��带 ����Ű�� �������� head�� ������Ʈ �����ش�
			�����ڷ� 7p ����
		*/

		if (head == NULL) { // head�� ����Ű�°��� ���� ���, �� ����Ʈ�� ��� ��嵵 ������ ó��
			Single_LinkedList_Node* newNode = new Single_LinkedList_Node(number);
			newNode->number = number;
			newNode->next = tail;
			head = newNode;
		}

		else { // head�� ����Ű�°��� �ִ� ��� ó��
			Single_LinkedList_Node* newNode = new Single_LinkedList_Node(number);
			newNode->number = number;
			newNode->next = head; // ���ο� ��尡 ������ head�� ����Ų��.
			head = newNode; // head�� ���ο� ��尡 �ȴ�.
		}
	}

	void delete_Node() {
		/*
			���� ��ũ�� ����Ʈ ����
			��带 �����ϰ� head�� ������Ʈ ��Ų��
			�����ڷ� 8p ����
		*/
		if (head != NULL) { // ������ ��尡 ���� ��� ó��
			Single_LinkedList_Node* prev = head; 
			head = head->next; // ���� head�� ���� ��带 head�� ����
			delete prev; // ����� �޸� ����
		}
	}

	void print_List() {
		Single_LinkedList_Node* tmp = head;
		while (tmp != NULL) {
			cout << tmp->number << endl;
			tmp = tmp->next;
		}
	}
};

class Double_LinkedList_Node {
public:
	int number;
	Double_LinkedList_Node* prev;
	Double_LinkedList_Node* next;
	Double_LinkedList_Node(int num) {
		number = num;
		prev = NULL;
		next = NULL;
	}
};

class Double_LinkedList {
public:
	Double_LinkedList_Node* head;
	Double_LinkedList_Node* tail;
	Double_LinkedList() { // ������ �Լ� : head�� tail �����͸� NULL�� �ʱ�ȭ �Ѵ�.
		head = new Double_LinkedList_Node(-1);
		tail = new Double_LinkedList_Node(-1);
	}

	void insert_Node(int num) {

		/*
			���� ��ũ�� ����Ʈ ����
			���ο� ��带 �����ϰ�, ���� �� ��带 ����Ű�� �������� head�� ������Ʈ �����ش�
			�����ڷ� 10p ����
		*/
		if (head->next == NULL) {
			Double_LinkedList_Node* newNode = new Double_LinkedList_Node(num);
			newNode->prev = head;
			newNode->next = tail;
			head->next = newNode;
			tail->prev = newNode;
		}
		else {
			Double_LinkedList_Node* newNode = new Double_LinkedList_Node(num);
			newNode->prev = head;
			newNode->next = head->next;
			head->next->prev = newNode;
			head->next = newNode;
		}
	}
	
	void delete_Node() {
		/*
			���� ��ũ�� ����Ʈ ����
			��带 �����ϰ� head�� ������Ʈ ��Ų��
			�����ڷ� 11p ����
		*/
		if (head->next != NULL) {
			Double_LinkedList_Node* temp = head->next;
			head->next = temp->next;
			temp->next->prev = head;
		}
	}

	void print_List() {
		Double_LinkedList_Node* tmp = head->next;
		while (tmp != tail) {
			cout << tmp->number << endl;
			tmp = tmp->next;
		}
	}
};

int main() {

	Single_LinkedList SL;

	SL.insert_Node(5);
	SL.insert_Node(10);
	SL.insert_Node(3);
	SL.print_List();

	Double_LinkedList DL;
	DL.insert_Node(10);
	DL.insert_Node(23);
	DL.insert_Node(99);
	DL.print_List();

	return 0;
}