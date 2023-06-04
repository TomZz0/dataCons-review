#include<iostream>
using namespace std;

int BinSearch(int* arr, int length,int val);
void main_¶ş·Ö²éÕÒ() {
	int arr[] = { 1,2,3,6,9,12,56,87,123 };
	int index = BinSearch(arr, 9,1111);
	cout << index;
}

int BinSearch(int* arr, int length,int val) {
	int l = 0;
	int r = length - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] == val) return mid;
		if (arr[mid] < val)l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}