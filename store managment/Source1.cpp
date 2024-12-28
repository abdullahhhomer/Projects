#include<iostream>
using namespace std;

int* func(int num) {
	num++;
	return &num;
}

int main() {
	int num = 5;
	int* p = &num;
	p = func(num);
	cout << *p;
}