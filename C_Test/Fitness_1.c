#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int num;
	char name[20];
	double weight;
}Fitness;
Fitness* ary[100];									// ������ �迭 ����
void total_number(int count);						// ��ü ��� ȸ�� �� ��ȯ
double average_weight(Fitness** pary, int count);	// ��� ü�� ��ȯ
int max_weight(Fitness** pary, int count);			// �ִ� ü�� ȸ���� index ��ȯ
void print_info(Fitness** pary, int index);			// ȸ�� ���� ���
void free_ary(Fitness** pary, int count);			// ���� �Ҵ� ���� ���� 


int main() {
	int i = 0;
	int n;
	int num;
	double count = 0;
	
	char name[20];
	double weight;
	int max_weight;

	while (1) {
		printf("---------------------------------------\n");
		printf("(1) ȸ������ \n");
		printf("(2) ��ü ��� ȸ�� �� Ȯ��\n");
		printf("(3) ��� ü�� Ȯ��\n");
		printf("(4) �ִ� ü�� ȸ�� ��ȣ Ȯ��\n");
		printf("(5) ȸ�� ���� ���\n"); 
		printf("(6) ����\n");
		printf("������ ��ȣ �Է� : ");
		scanf(" %d", &n);
		printf("---------------------------------------\n");

		
		switch (n) {
		case 1 : // ȸ�� ����
			printf("ȸ�� ��ȣ �Է�: ", i + 1);
			scanf_s("%d", &num);
			printf("%d�� ȸ�� �̸� �Է� : ", i + 1);
			scanf_s("%s", name, sizeof(name));
			strcat_s(name, sizeof(name), ""); 
			printf("%d�� ȸ�� ü�� �Է� : ", i + 1);
			scanf_s("%lf", &weight);
			count += 1;
			break;
		case 2 : // ��ü ��� �� Ȯ��
			if (count == 0)
			{
				printf("��ϵ� ȸ���� �����ϴ�.\n");
			}
			else
			{
				total_number(count);
			}
			break;
		case 3: // ��� ü�� Ȯ��
			average_weight(ary, count);
		}
	}

	//while (i < 100) {

	//	printf("[%d] ȸ�� ��ȣ : ", i + 1);
	//	scanf_s("%d", &num);

	//	 ���� �Է½� ���� ��� �� ���α׷� ����
	//	if (num < 0) {
	//		 printf("ȸ�� �Է� ����!\n");
	//		total_number(i);
	//		printf("��� ü�� : %.2lf\n", average_weight(ary, i));
	//		max = max_weight(ary, i);
	//		print_info(ary, max);
	//		free_ary(ary, i);
	//		exit(0);
	//	}

	//	printf("%d�� ȸ�� �̸� �Է� : ", i + 1);
	//	scanf_s("%s", name, sizeof(name));
	//	strcat_s(name, sizeof(name), ""); // C6054 ���� ���� 
	//	printf("%d�� ȸ�� ü�� �Է� : ", i + 1);
	//	scanf_s("%lf", &weight);

	//}

	return 0;
}

void total_number(int count) {
	printf("�� ȸ�� �� : %d\n", count);
}

double average_weight(Fitness** pary, int count) { 
	int sum = 0;
	double result;
	for (int i = 0; pary[i] != NULL; i++) {
		sum += pary[i]->weight;
	}
	result = sum / (double)count;
	return printf("��� ü���� %.2lf\n", result);
}

int max_weight(Fitness** pary, int count) {
	int max = 0;
	double result;
	for (int i = 0; pary[i] != NULL; i++) {
		if (max < pary[i]->weight) max = i;
	}
	return max;
}

void print_info(Fitness** pary, int index) {
	printf("ü���� ���� ������ ȸ��\n");
	printf("ȸ�� ��ȣ : %d\n", ary[index]->num);
	printf("�̸� : %s\n", ary[index]->name);
	printf("ü�� : %.1lf\n", ary[index]->weight);


}

void free_ary(Fitness** pary, int count) {
	for (int i = 0; pary[i] != NULL; i++) {
		free(pary[i]);
		pary[i] = NULL;
	}
}

