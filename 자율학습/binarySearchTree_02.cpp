#include<iostream>
#include<cstdio> // scanf�� ���� ����
#include<algorithm> // max�� ���� ����
#include<map> // ���ϴ� ���� ���� ã�ƿ� �� �ִ� �ڷᱸ��

typedef long long int INT;
using namespace std;

int main(void) 
{
	int size; // ũ�⸦ �Է¹���
	scanf("%d", &size);

	INT count = 0; // ó���ϰ��� �ϴ� ��
	map<int, INT> mapArr; // �������

	/* ��Ÿ�� ������ �����ϱ� ���� �ٿ�� ��ũ�� */
	map<int, INT>::iterator l_bound; // ���� ��ġ�� ����
	map<int, INT>::iterator u_bound; // �� ��ġ�� ����
	mapArr.insert(pair<int, INT>(0, -1)); // ������ġ ��ŷ 
	mapArr.insert(pair<int, INT>(300001, -1)); // ����ġ ��ŷ

	for (int i = 0; i < size; i++) 
	{
		int N;
		scanf("%d", &N); // Ű �� �Է¹���

		INT depth; // ����
		l_bound = --mapArr.lower_bound(N); // ���� iterator�� �޾ƿ�
		u_bound = mapArr.upper_bound(N); // ���� iterator�� �޾ƿ�
		depth = max(l_bound->second, u_bound->second) + 1; // depth �� �� �� ū �Ϳ� 1�� ����

		mapArr.insert(pair<int, INT>(N, depth)); // �������� ���� ����
		count += depth; // ī��Ʈ�� ������Ŵ

		printf("%lld\n", count); // ī��Ʈ�� ���
	}
	return 0;
}
// http://vvshinevv.tistory.com/27