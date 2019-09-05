#include<iostream>
#include<cstdio> // scanf를 쓰기 위함
#include<algorithm> // max를 쓰기 위함
#include<map> // 원하는 값을 빨리 찾아올 수 있는 자료구조

typedef long long int INT;
using namespace std;

int main(void) 
{
	int size; // 크기를 입력받음
	scanf("%d", &size);

	INT count = 0; // 처리하고자 하는 값
	map<int, INT> mapArr; // 결과저장

	/* 런타임 에러를 방지하기 위한 바운드 테크닉 */
	map<int, INT>::iterator l_bound; // 시작 위치를 정의
	map<int, INT>::iterator u_bound; // 끝 위치를 정의
	mapArr.insert(pair<int, INT>(0, -1)); // 시작위치 마킹 
	mapArr.insert(pair<int, INT>(300001, -1)); // 끝위치 마킹

	for (int i = 0; i < size; i++) 
	{
		int N;
		scanf("%d", &N); // 키 값 입력받음

		INT depth; // 깊이
		l_bound = --mapArr.lower_bound(N); // 이전 iterator를 받아옴
		u_bound = mapArr.upper_bound(N); // 다음 iterator를 받아옴
		depth = max(l_bound->second, u_bound->second) + 1; // depth 값 중 더 큰 것에 1을 더함

		mapArr.insert(pair<int, INT>(N, depth)); // 순서쌍을 집어 넣음
		count += depth; // 카운트를 증가시킴

		printf("%lld\n", count); // 카운트를 출력
	}
	return 0;
}
// http://vvshinevv.tistory.com/27