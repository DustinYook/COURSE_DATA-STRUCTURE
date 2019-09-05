#include<iostream>

using namespace std;

void Array_insert(int* Array, int current_size, int pos, int value) {

	/* 
		Array : 값이 저장되어 있는 배열 
		currrent_size : 현재 배열의 원소 개수
		pos : 새로운 값이 들어갈 index
		value : 들어갈 새로운 값
	*/

	for (int i = current_size; i >= pos; i--) {
		Array[i + 1] = Array[i]; // 들어갈 위치의 기존 값을을 하나씩 미루는 과정 강의자료 4p 슬라이드 참조
	}
	Array[pos] = value; // pos 위치에, 새로운 value값 삽입

}

int Array_Delete(int* Array, int current_size, int pos) {

	/*
		Array : 값이 저장되어 있는 배열
		currrent_size : 현재 배열의 원소 개수
		pos : 삭제될 index
	*/

	int ret = Array[pos]; // 제거될 값
	for (int i = pos; i < current_size; i++) {
		Array[i] = Array[i + 1]; // 값이 제거가 되므로, 이후의 값들을 하나씩 땡겨주는 과정 강의자료 3p 슬라이드 참조
	}
	return ret; // 제거되는 값을 return 해준다
}

int main() {

	const int size = 10; // Array의 최대 크기

	int Array[size] = { 4,3,2,1,6,7 };
	int current_size = 6; // 현재 Array의 크기 ( 원소 개수 )

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

