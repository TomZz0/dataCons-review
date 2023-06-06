#include"sort.h"

void insertSort(int* arr, int length) {
	for (int i = 1; i < length; i++) {
		int val = arr[i];//���汾��Ҫ�����Ԫ��
		int j = i-1;
		while (j >= 0 && arr[j] > val) {
			arr[j+1] = arr[j];
			j--;
		}
		//j������һλ j+1 ΪҪ�����λ��
		arr[j + 1] = val;
	}
}

void insertSortWithSB(int* arr, int length) {
	//����±���Ϊ�ڱ� ������1���±��Ժ�Ϊ��������
	for (int i = 2; i < length; i++) {
		arr[0] = arr[i];//���汾��Ҫ�����Ԫ��
		int j = i - 1;
		while (j >= 0 && arr[j] > arr[0]) {
			arr[j + 1] = arr[j];
			j--;
		}
		//j������һλ j+1 ΪҪ�����λ��
		arr[j + 1] = arr[0];
	}
}

void insertSortBin(int* arr, int length) {
	for (int i = 1; i < length; i++) {
		int val = arr[i];//���汾��Ҫ�����Ԫ��
		int left = 0;
		int right = i-1;
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] < val) left = mid + 1; //���� ��Ҫ����ֻ���С�ںŸĳɴ��ں�s
			else right = mid - 1;
		}
		//���left ���� i ˵���������� �������ƶ�
		if (left == i) continue;
		//���ҽ����� left ��ΪҪ������±� ��left+1��ʼ��Ԫ�غ���һλ		
		for (int j = i; j > left; j--) arr[j] = arr[j - 1];
		arr[left] = val;
	}
}

void shellSort(int* arr, int length) {
	int step = length / 2;
	while (step > 0) {
		for (int i = step; i < length; i++) {
			int val = arr[i];//���汾��Ҫ�����Ԫ��
			int j = i - step;
			while (j >= 0 && arr[j] > val) {
				arr[j + step] = arr[j];
				j -= step;
			}
			//j������һλ j+1 ΪҪ�����λ��
			arr[j + step] = val;
		}
		step /= 2;
	}
	
}

void selectSort(int* arr, int length){
	//ѡ������
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
	//��ĳ������ת�ɴ����
	int bigSon = pos * 2 + 1;
	int temp = arr[pos];
	while (bigSon < length) {
		//������Һ��� ���Һ��Ӵ� �����Ӷ�λ���Һ��� ����Ϊ����
		if (bigSon + 1 < length && arr[bigSon + 1] > arr[bigSon]) bigSon++;
		//������ת�����ڵ� ʵ��Ϊ�³� ����Ҫÿһ�ζ���ֵ����
		//ֻ��Ҫ��bigSon���Ǹ��ڵ� Ȼ��Ƚ�ʱ��ԭ�����ڵ��ֵ�ȼ��� ��temp
		//������ڵ�С ��һ�����³������ӽ�� ���������ÿ�θ��ڵ�ֵ��Ϊtemp
		//�����ڵ���� ��ֹͣѭ�� 
		if (temp < arr[bigSon]) {
			arr[pos] = arr[bigSon];
			pos = bigSon;
			bigSon = bigSon * 2 + 1;
		}
		else break;
	}
	//��temp��������posλ��
	arr[pos] = temp;
}

void heapSort(int* arr, int length) {
	//�����һ��������ʼ��һ�������Ӧ�Ķ�����ת�ɴ����
	for (int i = length/2 - 1; i >= 0; i--) {
		shift(arr, length, i);
	}
	//ÿ�ν����������һ��Ԫ�ؽ��� Ȼ��ǰ������ת�ɴ����
	for (int i = length-1; i >0 ; i--) { //ִ��n-1�μ���
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
	//�ݹ����
	if (end <= start) return;
	int lp = start; int rp = end;
	int val = arr[lp];
	while (lp != rp) {
		//���ظ��� �������� �ٲ����ʼ��ֵval
		//��ָ��ָ����С��val��ֵ ����ָ��ָ���ֵҲΪ���ֵ Ȼ����ָ���һ
		//��ָ��ָ���˴���val��ֵ ����ָ��ָ���ֵҲΪ���ֵ Ȼ����ָ���һ
		//�������ָ��ָ��ͬһ��λ�� ���ֵһ�����ظ�ֵ �޸�Ϊval
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