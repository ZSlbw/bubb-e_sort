#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void bubble_sort(int arr[], int sz)//(int* arr,int sz)
//arr������ָ�룬����һ��������� [],��arr[]��Ϊ��ַ�е�ĳ��Ԫ�أ����ǰ��Ϊ����Ϊ��int
{
	int flag = 1;//������һ��Ҫ����������Ѿ�����
	//ȷ��ð�����������
	for (int i = 0; i < sz-1; i++)
	{
		//ÿһ��ð������
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])//��˳�����źã���һֱ���д�ѭ���жϣ�ֱ���������ݾ��ж���Ϻ󣬽���ѭ����
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				falg = 0;//���������������ʵ����ȫ����
			}
		}

		if (flag == 1)//����falg==1�����������½�������
			break;
	}
}

int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//��arr���������ų�����
	//arr�����飬���Ƕ�����arr���д��Σ�ʵ���ϴ���ȥ����arr��Ԫ�صĵ�ַ &arr[0]
	bubble_sort(arr,sz);//ð��������
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}