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

	Single_LinkedList() { // 생성자 함수 : head와 tail 포인터를 NULL로 초기화 한다.
		head = NULL;
		tail = NULL;
	};

	void insert_Node(int number) {
		
		/*
			단일 링크드 리스트 삽입
			새로운 노드를 생성하고, 가장 앞 노드를 가리키는 포인터인 head를 업데이트 시켜준다
			강의자료 7p 참조
		*/

		if (head == NULL) { // head가 가리키는것이 없는 경우, 즉 리스트에 어떠한 노드도 없을때 처리
			Single_LinkedList_Node* newNode = new Single_LinkedList_Node(number);
			newNode->number = number;
			newNode->next = tail;
			head = newNode;
		}

		else { // head가 가리키는것이 있는 경우 처리
			Single_LinkedList_Node* newNode = new Single_LinkedList_Node(number);
			newNode->number = number;
			newNode->next = head; // 새로운 노드가 기존의 head를 가리킨다.
			head = newNode; // head는 새로운 노드가 된다.
		}
	}

	void delete_Node() {
		/*
			단일 링크드 리스트 삭제
			노드를 삭제하고 head를 업데이트 시킨다
			강의자료 8p 참조
		*/
		if (head != NULL) { // 삭제할 노드가 있을 경우 처리
			Single_LinkedList_Node* prev = head; 
			head = head->next; // 기존 head의 다음 노드를 head로 변경
			delete prev; // 노드의 메모리 해제
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
	Double_LinkedList() { // 생성자 함수 : head와 tail 포인터를 NULL로 초기화 한다.
		head = new Double_LinkedList_Node(-1);
		tail = new Double_LinkedList_Node(-1);
	}

	void insert_Node(int num) {

		/*
			이중 링크드 리스트 삽입
			새로운 노드를 생성하고, 가장 앞 노드를 가리키는 포인터인 head를 업데이트 시켜준다
			강의자료 10p 참조
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
			이중 링크드 리스트 삭제
			노드를 삭제하고 head를 업데이트 시킨다
			강의자료 11p 참조
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