#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void bubble_sort(int arr[], int sz)//(int* arr,int sz)
//arr本身是指针，但是一旦后面加上 [],则arr[]则为地址中的某个元素，因此前面为类型为：int
{
	int flag = 1;//假设这一趟要排序的数据已经有序
	//确定冒泡排序的趟数
	for (int i = 0; i < sz-1; i++)
	{
		//每一趟冒泡排序
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])//若顺序已排好，则一直进行此循环判断，直至所有数据均判断完毕后，结束循环。
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				falg = 0;//本趟排序的数据其实不完全有序
			}
		}

		if (flag == 1)//设立falg==1，则不用在往下进行排序
			break;
	}
}

int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//对arr进行升序，排成升序
	//arr是数组，我们对数组arr进行传参，实际上传过去的是arr首元素的地址 &arr[0]
	bubble_sort(arr,sz);//冒泡排序函数
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}