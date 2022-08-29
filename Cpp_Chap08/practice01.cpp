#include <iostream>

template <typename T, int sz>
class CTest
{
private:
	T ary[sz];
public:
	T& operator[] (int idx) {
		if (idx < 0 || idx >= sz) {
			cout << "error" << endl;
			exit(1);
		}
		return arr[idx]
	}
	void getData() {
		for (int i = 0; i < sz; i++) {
			cout << ary[i] << endl;
		}
	}
};


int main()
{
	CTest<int, 3> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr.getData();
	return 0;
}