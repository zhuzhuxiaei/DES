/*
*函数名:getKey
*作用  :从键盘获取秘钥
*/
#include "struct.h"
#include <stdio.h>
#include <string.h>
extern bdata64 rawkey;
int getKey()
{
	char a[9];
	printf("input key:\n");
	scanf_s("%s", a, 9);//scanf_s,最后一个参数需要包括\0在内
	for (int i = 0; i < strlen(a); i++)
	{
		rawkey.bit[i] = a[i];
	}
	return 0;
}
