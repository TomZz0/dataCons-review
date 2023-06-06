#include"sort.h"

void insertSort(int* arr, int length) {
	for (int i = 1; i < length; i++) {
		int val = arr[i];//保存本次要插入的元素
		int j = i-1;
		while (j >= 0 && arr[j] > val) {
			arr[j+1] = arr[j];
			j--;
		}
		//j后移了一位 j+1 为要插入的位置
		arr[j + 1] = val;
	}
}

void insertSortWithSB(int* arr, int length) {
	//零号下标作为哨兵 排序后从1号下标以后为递增序列
	for (int i = 2; i < length; i++) {
		arr[0] = arr[i];//保存本次要插入的元素
		int j = i - 1;
		while (j >= 0 && arr[j] > arr[0]) {
			arr[j + 1] = arr[j];
			j--;
		}
		//j后移了一位 j+1 为要插入的位置
		arr[j + 1] = arr[0];
	}
}

void insertSortBin(int* arr, int length) {
	for (int i = 1; i < length; i++) {
		int val = arr[i];//保存本次要插入的元素
		int left = 0;
		int right = i-1;
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] < val) left = mid + 1; //升序 若要降序只需把小于号改成大于号s
			else right = mid - 1;
		}
		//如果left 就是 i 说明本就有序 不必再移动
		if (left == i) continue;
		//查找结束后 left 即为要插入的下标 将left+1开始的元素后移一位		
		for (int j = i; j > left; j--) arr[j] = arr[j - 1];
		arr[left] = val;
	}
}

void shellSort(int* arr, int length) {
	int step = length / 2;
	while (step > 0) {
		for (int i = step; i < length; i++) {
			int val = arr[i];//保存本次要插入的元素
			int j = i - step;
			while (j >= 0 && arr[j] > val) {
				arr[j + step] = arr[j];
				j -= step;
			}
			//j后移了一位 j+1 为要插入的位置
			arr[j + step] = val;
		}
		step /= 2;
	}
	
}

void selectSort(int* arr, int length){
	//选择排序
	for (int i = 0; i < length; i++) {
		int min = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min]) min = j;
		}
		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void shift(int* arr, int length, int pos) {
	//将某个子树转成大根堆
	int bigSon = pos * 2 + 1;
	int temp = arr[pos];
	while (bigSon < length) {
		//如果有右孩子 且右孩子大 将大孩子定位到右孩子 否则为左孩子
		if (bigSon + 1 < length && arr[bigSon + 1] > arr[bigSon]) bigSon++;
		//将大孩子转到根节点 实际为下沉 不需要每一次都将值互换
		//只需要将bigSon覆盖根节点 然后比较时用原来根节点的值比即可 即temp
		//如果根节点小 则一定会下沉到孩子结点 程序继续则每次根节点值都为temp
		//若根节点最大 则停止循环 
		if (temp < arr[bigSon]) {
			arr[pos] = arr[bigSon];
			pos = bigSon;
			bigSon = bigSon * 2 + 1;
		}
		else break;
	}
	//将temp补到最后的pos位置
	arr[pos] = temp;
}

void heapSort(int* arr, int length) {
	//从最后一个子树开始将一个数组对应的二叉树转成大根堆
	for (int i = length/2 - 1; i >= 0; i--) {
		shift(arr, length, i);
	}
	//每次将树根和最后一个元素交换 然后将前边重新转成大根堆
	for (int i = length-1; i >0 ; i--) { //执行n-1次即可
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		shift(arr, i, 0);
	}
}

void bubbleSort(int* arr, int length) {
	for (int i = 0; i < length-1; i++)  {
		bool ifSen = true;
		for (int j = 0; j < length - i -1 ; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				ifSen = false;
			}
		}
		if (ifSen) break;
	}
}

void quickSort(int* arr, int start,int end) {
	//递归出口
	if (end <= start) return;
	int lp = start; int rp = end;
	int val = arr[lp];
	while (lp != rp) {
		//来回覆盖 到最后结束 再补上最开始的值val
		//右指针指向了小于val的值 让左指针指向的值也为这个值 然后左指针加一
		//左指针指向了大于val的值 让右指针指向的值也为这个值 然后右指针减一
		//最后左右指针指向同一个位置 这个值一定是重复值 修改为val
		while (lp < rp && arr[rp] >= val) rp--;
		if (lp < rp) arr[lp++] = arr[rp];
		while (lp < rp && arr[lp] <= val) lp++;
		if (lp < rp) arr[rp--] = arr[lp];
	}
	arr[lp] = val;
	quickSort(arr, start, lp-1);
	quickSort(arr, lp + 1, end);
}

void showArr(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}