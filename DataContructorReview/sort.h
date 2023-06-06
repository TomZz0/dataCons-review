#include<iostream>
using namespace std;


void insertSort(int* arr, int length);//选择排序

void insertSortWithSB(int* arr, int length);//选择排序 哨兵版

void insertSortBin(int* arr, int length);//选择排序 二分查找位置

void shellSort(int* arr, int length);//希尔排序

void selectSort(int* arr, int length);//选择排序

void heapSort(int* arr, int length);//堆排序 建造大根堆

void shift(int* arr, int length,int pos);// 将pos位置为根的子树转成大根堆

void bubbleSort(int* arr,int length);//冒泡排序

void quickSort(int* arr, int start,int end);//快速排序

void showArr(int arr[], int length);//打印数组