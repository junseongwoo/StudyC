#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void inrto() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

class Student : public Human
{
protected:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void intro() {
		printf("%d학번 %s입니다.\n", stunum, name);
	}
	void study() {
		printf("구구단 쉽다\n");
	}
};

int main()
{
	Human h("김사람", 10);
	Student s("이학생", 15, 1234567);
	Human* pH;
	Student* pS;

	pH = &h;
	pS = &s;
	pH = &s;

	pS = (Student*)&h;
	pS->intro();
}