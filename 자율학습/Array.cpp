#include<iostream>

using namespace std;

void Array_insert(int* Array, int current_size, int pos, int value) {

	/* 
		Array : ���� ����Ǿ� �ִ� �迭 
		currrent_size : ���� �迭�� ���� ����
		pos : ���ο� ���� �� index
		value : �� ���ο� ��
	*/

	for (int i = current_size; i >= pos; i--) {
		Array[i + 1] = Array[i]; // �� ��ġ�� ���� ������ �ϳ��� �̷�� ���� �����ڷ� 4p �����̵� ����
	}
	Array[pos] = value; // pos ��ġ��, ���ο� value�� ����

}

int Array_Delete(int* Array, int current_size, int pos) {

	/*
		Array : ���� ����Ǿ� �ִ� �迭
		currrent_size : ���� �迭�� ���� ����
		pos : ������ index
	*/

	int ret = Array[pos]; // ���ŵ� ��
	for (int i = pos; i < current_size; i++) {
		Array[i] = Array[i + 1]; // ���� ���Ű� �ǹǷ�, ������ ������ �ϳ��� �����ִ� ���� �����ڷ� 3p �����̵� ����
	}
	return ret; // ���ŵǴ� ���� return ���ش�
}

int main() {

	const int size = 10; // Array�� �ִ� ũ��

	int Array[size] = { 4,3,2,1,6,7 };
	int current_size = 6; // ���� Array�� ũ�� ( ���� ���� )

	Array_insert(Array, current_size++, 5, 5);
	Array_insert(Array, current_size++, 2, 10);
	Array_insert(Array, current_size++, 8, 1);
	for (int i = 0; i < size; i++) cout << Array[i] << " ";
	cout << endl;

	Array_Delete(Array, current_size--, 4);
	Array_Delete(Array, current_size--, 2);
	Array_Delete(Array, current_size--, 5);
	for (int i = 0; i < size; i++) cout << Array[i] << " ";
	cout << endl;

	return 0;
}

