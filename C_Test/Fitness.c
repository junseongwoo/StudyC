#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int num;
	char name[20];
	double weight;
} Fitness;

Fitness* ary[100];
Fitness* ary[100];									// ������ �迭 ����
void total_number(int count);						// ��ü ��� ȸ�� �� ��ȯ
double average_weight(Fitness** pary, int count);	// ��� ü�� ��ȯ
int max_weight(Fitness** pary, int count);			// �ִ� ü�� ȸ���� index ��ȯ
void print_info(Fitness** pary, int index);			// ȸ�� ���� ���
void free_ary(Fitness** pary, int count);			// ���� �Ҵ� ���� ���� 

int main(void)
{

	return 0;
}