#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void Swap(char* buf1, char* buf2, int width)
{                         //width恰好也是首元素和次元素需要交换的对数，因为width（类型）也是总数，而 强制类型转换的 （char*）则是一个单位
	int i = 0;             // 用总数除以单位就是需要进行配对的次数，因此需要传递 width 这个参数，
	                         //否则，只传入 char* buf1 和 char* buf2 ，是无法确定需要交换的对数的
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
	//第一个参数：待排序数组的首元素地址
	//第二个参数：待排序数组的元素个数
	//第三个参数：待排序数组的每个元素的大小  - 单位是字节
	//第四个参数：是函数指针，比较两个元素所用函数的地址  - 这个函数使用者自己实现  -  函数指针的两个参数是：带比较的两个函数的地址
}

//实现bubble_sort函数的程序员是否知道未来排序的数据类型 - 不知道
//因此程序员也不知道，带比较的两个元素的类型
void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1,const void* e2))
{                                  // 传 width 是因为不知道操作函数的类型，void* base指向起始位置，不知道在何处停止
	                               // width 传来就可以使用指针指向下一个元素了。原因就在于 void* 的指针无法进行 +- 整数的操作
	int i = 0;//width恰好也是首元素和次元素需要交换的对数，因为width（类型）也是总数，而 强制类型转换的 （char*）则是一个单位
	          //用总数除以单位就是需要进行配对的次数，因此需要传递 width 这个参数，否则，只传入 char* buf1 和 char* buf2 ，是无法确定需要交换的对数的
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//每一趟比较的对数
		for (int j = 0; j < sz - 1 - i; j++)
		{
			//两个相邻元素的比较
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width) >0)
			{
				//交换
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

//排序整型数组
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void test1()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//使用bubble_sort的程序员一定知道自己排序的是什么数据
	//就应该知道如何比较待排序数组中的元素
	//需要比较的元素的类型不确定，因此设计师将元素比较的方式留给使用者自己填充
	//因此引入数组元素比较的算法函数 cmp
	bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
	printf("打印整型数组的排序\n");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//排序浮点型数组
int cmp_float(const void* e1, const void*e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}

void test2()
{
	float f[] = { 5.0, 4.0, 3.0, 2.0, 1.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	bubble_sort(f, sz, sizeof(f[0]), cmp_float);
	printf("打印浮点型数组的排序\n");
	for (int i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
	printf("\n");
}

//排列结构性数组
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
	//比较名字就是比较字符串
	//字符串比较不能直接用><=来比较，应该用strcmp函数 - #include <string.h> 
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test3()
{
	struct Stu s[] = { {"zhangsan",20}, {"lisi",30}, {"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	//使用调试观看
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
