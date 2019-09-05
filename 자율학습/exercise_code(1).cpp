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
		head = NULL; // circular list의 첫번째 노드
		now = NULL; // cursor가 현재 가리키는 노드
	}

	void insert_Node(Node* newNode) {
		if (head == NULL) { // list에 노드가 없을 경우
			/* 
				head, now는 새로 생성된 노드를 가리킨다.
				Circular 이기 때문에, 새로운 노드의 next 포인터를 자기자신으로 설정
				
				채워넣으세요!
			*/
		}
		else {
			/*
				now 를 이용하여 새로운 노드 추가 - 문제 설명 애니메이션 참고
				Circular 이기 때문에, 새로운 노드의 next 포인터를 head로 설정

				채워넣으세요!
			*/
		}
	}

	void delete_Node(int M) {

		int count = 1;
		Node* prev = NULL;

		while (count != M) {
			/* 
				반복문을 사용하여 1부터 순서를세면서 M번째 노드까지 이동

				채워넣으세요!
			*/
		}

		cout << now->number; // 삭제되는 노드의 값 출력 - 슬라이드에서 체크 표시된 값

		/*
			삭제 된 후, 링크 재설정 필요

			채워넣으세요!
		*/
	}

};

int main() {

	int N, M;
	cin >> N >> M; // Input 되는 변수 N과 M 입력 

	Circular circular; // Ciruclar List 생성
	for (int i = 1; i <= N; i++) {
		Node* newNode = new Node(i); // Node 생성 한 뒤
		circular.insert_Node(newNode); // Ciruclar List에 삽입
	}
	circular.now = circular.head;

	cout << "<";
	while (N--) {
		circular.delete_Node(M); // Circular List에서 노드 하나씩 삭제
		cout << ", ";
	}
	cout << ">";
	return 0;
}