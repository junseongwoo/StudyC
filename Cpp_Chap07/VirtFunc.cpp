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

	virtual void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}
};

class Student : public Human
{
protected:
	int stunum;

public :
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void intro()
	{
		printf("%d�й� %s�Դϴ�\n", stunum, name);
	}
	
	void study() {
		printf("c��� ��������!\n");
	}

};

//void IntroSomeBody(Human* pH) {
//	pH->intro();
//}

int main()
{
	Human h("����", 10);
	Student s("���л�", 15, 1234567);
	Human* pH;

	/*IntroSomeBody(&h);
	IntroSomeBody(&s);*/

	pH = &h;
	pH->intro();
	pH = &s;
	pH->intro();
}