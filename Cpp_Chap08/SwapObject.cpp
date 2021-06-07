#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

template <typename T>
void swap(T& a, T& b) // 클래스 자료형 
{
	T t;
	t = a; a = b; b = t;
}

class Human
{
private:
	char* name;
	int age;

public:
	Human() {
		name = new char[1];
		name[0] = NULL;
		age = 0;
	}

	Human(const char* aname, int aage) {   // 인수를 두개 받는 생성자
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;
	}

	Human(const Human& other) {  // 복사 생성자 & 변환 생성자
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}

	Human& operator =(const Human& other) {  // 연산자 오버로딩 
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			age = other.age;
		}
		return *this;
	}

	~Human() {
		delete[] name;
	}

	void intro() {    // 멤버 함수
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human lee("이승만", 10);
	Human park("박정희", 20);
	lee.intro();
	park.intro();
	swap(lee, park);
	lee.intro();
	park.intro();
}
