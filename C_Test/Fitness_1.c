#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int num;
	char name[20];
	double weight;
}Fitness;
Fitness* ary[100];									// 포인터 배열 선언
void total_number(int count);						// 전체 등록 회원 수 반환
double average_weight(Fitness** pary, int count);	// 평균 체중 반환
int max_weight(Fitness** pary, int count);			// 최대 체중 회원의 index 반환
void print_info(Fitness** pary, int index);			// 회원 정보 출력
void free_ary(Fitness** pary, int count);			// 동적 할당 영역 해제 


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
		printf("(1) 회원가입 \n");
		printf("(2) 전체 등록 회원 수 확인\n");
		printf("(3) 평균 체중 확인\n");
		printf("(4) 최대 체중 회원 번호 확인\n");
		printf("(5) 회원 정보 출력\n"); 
		printf("(6) 종료\n");
		printf("수행할 번호 입력 : ");
		scanf(" %d", &n);
		printf("---------------------------------------\n");

		
		switch (n) {
		case 1 : // 회원 가입
			printf("회원 번호 입력: ", i + 1);
			scanf_s("%d", &num);
			printf("%d번 회원 이름 입력 : ", i + 1);
			scanf_s("%s", name, sizeof(name));
			strcat_s(name, sizeof(name), ""); 
			printf("%d번 회원 체중 입력 : ", i + 1);
			scanf_s("%lf", &weight);
			count += 1;
			break;
		case 2 : // 전체 등록 수 확인
			if (count == 0)
			{
				printf("등록된 회원이 없습니다.\n");
			}
			else
			{
				total_number(count);
			}
			break;
		case 3: // 평균 체중 확인
			average_weight(ary, count);
		}
	}

	//while (i < 100) {

	//	printf("[%d] 회원 번호 : ", i + 1);
	//	scanf_s("%d", &num);

	//	 음수 입력시 정보 출력 및 프로그램 종료
	//	if (num < 0) {
	//		 printf("회원 입력 종료!\n");
	//		total_number(i);
	//		printf("평균 체중 : %.2lf\n", average_weight(ary, i));
	//		max = max_weight(ary, i);
	//		print_info(ary, max);
	//		free_ary(ary, i);
	//		exit(0);
	//	}

	//	printf("%d번 회원 이름 입력 : ", i + 1);
	//	scanf_s("%s", name, sizeof(name));
	//	strcat_s(name, sizeof(name), ""); // C6054 오류 방지 
	//	printf("%d번 회원 체중 입력 : ", i + 1);
	//	scanf_s("%lf", &weight);

	//}

	return 0;
}

void total_number(int count) {
	printf("총 회원 수 : %d\n", count);
}

double average_weight(Fitness** pary, int count) { 
	int sum = 0;
	double result;
	for (int i = 0; pary[i] != NULL; i++) {
		sum += pary[i]->weight;
	}
	result = sum / (double)count;
	return printf("평균 체중은 %.2lf\n", result);
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
	printf("체중이 많이 나가는 회원\n");
	printf("회원 번호 : %d\n", ary[index]->num);
	printf("이름 : %s\n", ary[index]->name);
	printf("체중 : %.1lf\n", ary[index]->weight);


}

void free_ary(Fitness** pary, int count) {
	for (int i = 0; pary[i] != NULL; i++) {
		free(pary[i]);
		pary[i] = NULL;
	}
}

