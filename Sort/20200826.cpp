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

// 5.冒泡排序 --- 有序放到后面,搬西瓜原理，将无序中最大的往后放（有大的就交换，往后冒泡）;

// 写个测试函数
void Test() {
    int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 6};
	int size = sizeof(array) / sizeof(array[0]);
	printf("排序前数组：\n");
	PrintArray(array, size);
	//printf("\n排序过程：\n");

	//InsertSort(array, size);
    ShellSort(array, size);
	//SelectSort(array, size);
	//BubbleSort(array, size);

	printf("排序后数组：\n");
	PrintArray(array, size);
}
// 测试
int main(){
	Test();
	return 0;
}
