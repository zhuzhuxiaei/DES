/*
*函数名: keyMake
*作用  : 将rawkey,映射为realkey
*/
#include "struct.h"
extern int keytable1[];
extern bdata64 rawkey;
extern bdata56 realkey;
int keyMake()
{
	char table[] = {-128,64,32,16,8,4,2,1};
	for (int i = 0; i < 56; i++)
	{
		int position = keytable1[i]-1;
		int row = position / 8;
		int offset = position % 8;
		//我们需要获得他所在的位
		int answer = rawkey.bit[row] & table[offset];
		//answer确定所选位是否使能
		if (answer)
		{
			row = i / 8;
			offset = i % 8;
			realkey.bit[row] = realkey.bit[row] | table[offset];
		}
		else
		{
			row = i / 8;
			offset = i % 8;
			realkey.bit[row] = realkey.bit[row] & (~table[offset]);
		}
	}
	return 0;
}
