/*
*函数名:getMingWen
*作用  :从键盘获取明文
*/
#include "struct.h"
#include <stdio.h>
#include <string.h>
extern bdata64 mingwen;
int getMingWen()
{
	char a[9];
	printf("input data:\n");
	scanf_s("%s",a,9);//scanf_s,最后一个参数需要包括\0在内
	for (int i = 0; i < strlen(a); i++)
	{
		//明文是全局变量,他的其他字节全部为0
		mingwen.bit[i] = a[i];
	}
	return 0;
}
