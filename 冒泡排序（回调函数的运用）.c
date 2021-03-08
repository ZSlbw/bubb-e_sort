#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void Swap(char* buf1, char* buf2, int width)
{                         //widthǡ��Ҳ����Ԫ�غʹ�Ԫ����Ҫ�����Ķ�������Ϊwidth�����ͣ�Ҳ���������� ǿ������ת���� ��char*������һ����λ
	int i = 0;             // ���������Ե�λ������Ҫ������ԵĴ����������Ҫ���� width ���������
	                         //����ֻ���� char* buf1 �� char* buf2 �����޷�ȷ����Ҫ�����Ķ�����
	for (i = 0; i < width; i++)
	{
		char tmp = * buf1;
		* buf1 = * buf2;
		* buf2 = tmp;
		buf1++;
		buf2++;
	}
}


qsort(void* base, size_t num, size_t width, int(*cmp)(const void* e1, const void* e2))
{
	//��һ���������������������Ԫ�ص�ַ
	//�ڶ��������������������Ԫ�ظ���
	//�����������������������ÿ��Ԫ�صĴ�С  - ��λ���ֽ�
	//���ĸ��������Ǻ���ָ�룬�Ƚ�����Ԫ�����ú����ĵ�ַ  - �������ʹ�����Լ�ʵ��  -  ����ָ������������ǣ����Ƚϵ����������ĵ�ַ
}

//ʵ��bubble_sort�����ĳ���Ա�Ƿ�֪��δ��������������� - ��֪��
//��˳���ԱҲ��֪�������Ƚϵ�����Ԫ�ص�����
void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1,const void* e2))
{                                  // �� width ����Ϊ��֪���������������ͣ�void* baseָ����ʼλ�ã���֪���ںδ�ֹͣ
	                               // width �����Ϳ���ʹ��ָ��ָ����һ��Ԫ���ˡ�ԭ������� void* ��ָ���޷����� +- �����Ĳ���
	int i = 0;//widthǡ��Ҳ����Ԫ�غʹ�Ԫ����Ҫ�����Ķ�������Ϊwidth�����ͣ�Ҳ���������� ǿ������ת���� ��char*������һ����λ
	          //���������Ե�λ������Ҫ������ԵĴ����������Ҫ���� width �������������ֻ���� char* buf1 �� char* buf2 �����޷�ȷ����Ҫ�����Ķ�����
	//����
	for (i = 0; i < sz - 1; i++)
	{
		//ÿһ�˱ȽϵĶ���
		for (int j = 0; j < sz - 1 - i; j++)
		{
			//��������Ԫ�صıȽ�
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width) >0)
			{
				//����
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

//������������
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void test1()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//ʹ��bubble_sort�ĳ���Աһ��֪���Լ��������ʲô����
	//��Ӧ��֪����αȽϴ����������е�Ԫ��
	//��Ҫ�Ƚϵ�Ԫ�ص����Ͳ�ȷ����������ʦ��Ԫ�رȽϵķ�ʽ����ʹ�����Լ����
	//�����������Ԫ�رȽϵ��㷨���� cmp
	bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
	printf("��ӡ�������������\n");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//���򸡵�������
int cmp_float(const void* e1, const void*e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}

void test2()
{
	float f[] = { 5.0, 4.0, 3.0, 2.0, 1.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	bubble_sort(f, sz, sizeof(f[0]), cmp_float);
	printf("��ӡ���������������\n");
	for (int i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
	printf("\n");
}

//���нṹ������
struct Stu
{
	char name[20];
	int age;
};


int cmp_Stu_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void cmp_Stu_name(const void* e1, const void* e2)
{
	//�Ƚ����־��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ����><=���Ƚϣ�Ӧ����strcmp���� - #include <string.h> 
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test3()
{
	struct Stu s[] = { {"zhangsan",20}, {"lisi",30}, {"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	//ʹ�õ��Թۿ�
	bubble_sort(s, sz, sizeof(s[0]), cmp_Stu_age);
	bubble_sort(s, sz, sizeof(s[0]), cmp_Stu_name);
}

int main()
{
	test1();
	test2();
	test3();
	return 0;
}
