#include <stdio.h>
#include <stdlib.h>

// 先写一个交换函数
void Swap(int array[], int a, int b){
	int t = array[a];
	array[a] = array[b];
	array[b] = t;
}
// 再写一个打印函数
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

// 1.插入排序 --- 有序放到前面，拿无序中第一个数跟有序中的数比较大小，找到合适位置插入；
void InsertSort(int array[], int size){
    for(int i = 1; i < size; ++i){
        int save = array[i];
        int j;
        for(j = i - 1; j >= 0; --j){
            if(array[j] < save){
                break;
            }
            array[j + 1] = array[j];
        }
        array[j + 1] = save;
    }
}
// 2.希尔排序 --- （分组插排、缩小增量排序），当分组的个数为1时就排好了；
void InsertSortWithGap(int array[], int size, int gap) {
	for (int i = gap; i < size; ++i) {
		int save = array[i];
		int j;
		for (j = i - gap; j >= 0; j -= gap) {
			if (array[j] <= save) {
				break;
			}
			array[j + gap] = array[j];
		}
		array[j + gap] = save;
	}
}
void ShellSort(int array[], int size) {
	for(int gap = size / 2; gap > 0; gap /= 2){
		InsertSortWithGap(array, size, gap);
	}
}
// 3.选择排序 --- 有序放到前面，临时变量记录无序中最小数的下标，将其值与无序中第一个数交换（最小的记录下，比完交换）；
void SelectSort(int array[], int size){
	for(int i = 0; i < size - 1; ++i){
		int save = i;
		for(int j = i + 1; j < size; ++j){
			if(array[j] < array[save]){
				save = j;
			}
		}
		Swap(array, i, save);
	}
}
// 4.堆排序 --- 排升序要建大堆，排降序建小堆；
void AdjustDown(int array[], int size, int rootIdx) {
	int leftIdx = 2 * rootIdx + 1;
	int rightIdx = 2 * rootIdx + 2;
	if (leftIdx >= size) {
		return;
	}
	int maxIdx = leftIdx;
	if (rightIdx < size && array[rightIdx] > array[leftIdx]) {
		maxIdx = rightIdx;
	}
	if (array[rootIdx] >= array[maxIdx]) {
		return;
	}
	Swap(array, maxIdx, rootIdx);
	AdjustDown(array, size, maxIdx);
}
void HeapSort(int array[], int size){
	for(int i = (size - 2) / 2; i >= 0; --i){
		AdjustDown(array, size - 1, i);
	}
	for (int i = 0; i < size; ++i) {
		Swap(array, 0, size - 1 - i);
		AdjustDown(array, size - 1 - i, 0);
	}
}
// 5.冒泡排序 --- 有序放到后面,搬西瓜原理，将无序中最大的往后放（有大的就交换，往后冒泡）；
void BubbleSort(int array[], int size){
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size - 1 - i; ++j){
			if(array[j] > array[j + 1]){
				Swap(array, j, j + 1);
			}
		}
	}
}
// 6.快速排序 --- 三大步：选基准值，做分割，分治算法；
int Partition(int array[], int low, int high){
	int pivot = array[low];
	while(low < high){
		while(low < high && array[high] >= pivot){
			--high;
		}
		array[low] = array[high];
		while(low < high && array[low] <= pivot){
			++low;
		}
		array[high] = array[low];
	}
	array[low] = pivot;
	return low;
}
void QuickSort(int array[], int low, int high){
	if(low < high){
		int pivotIdx = Partition(array, low, high);
		QuickSort(array, low, pivotIdx - 1);
		QuickSort(array, pivotIdx + 1, high);
	}
}
// 7.归并排序 --- 


// 写个测试函数
void Test() {
    int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 6};
	int size = sizeof(array) / sizeof(array[0]);
	printf("排序前数组：\n");
	PrintArray(array, size);
	//printf("\n排序过程：\n");

	//InsertSort(array, size);
    //ShellSort(array, size);
	//SelectSort(array, size);
	//HeapSort(array, size);
	//BubbleSort(array, size);
	QuickSort(array, 0, size - 1);

	printf("排序后数组：\n");
	PrintArray(array, size);
}
// 测试
int main(){
	Test();
	return 0;
}
