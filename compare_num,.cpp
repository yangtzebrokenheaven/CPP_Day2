#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
	int a;
	int b;
	int c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a > b) {
		if (a > c) {
			cout << a <<endl;
		}
		else cout << c << endl;
	}
	else if (b > c)
		cout << b << endl;
			else 			cout << c << endl;;
}
//#define InitSize 10
//typedef struct {
//	int data[InitSize];
//	int length;
//}SqList;
//bool ListInsert(SqList& L, int i, int a) {
//	if (i<1 || i>L.length + 1)
//		return false;
//	if (L.length >= InitSize)
//		return false;
//	for (int s = L.length; s >= i; s--) 
//		L.data[s] = L.data[s - 1];
//	L.data[i - 1] = a;
//	L.length++;
//}
//bool ListDelete(SqList& L, int i, int& e) {
//	if (i<1 || i>L.length + 1)
//		return false;
//	e = L.data[i - 1];
//	for (int i = i; i < L.length; i++)
//		L.data[j - 1] = L.data[j];
//	L.length--;
//	return true;
//}
//
