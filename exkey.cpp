/*
*函数名:exKey
*作用  :将c0,和d0映射为exkey
*/
#include "struct.h"
extern int exkeytable[];
int exKey(bdata28 c0,bdata28 d0,bdata48* exkey)
{
	char buf;//buf用于暂存当前bit位所在的字节
	char table[] = { -128,64,32,16,8,4,2,1 };
	for (int i = 0; i < 48; i++)
	{
		int position = exkeytable[i] - 1;
		int row = position / 8;
		int offset = position % 8;
		if (row >= 3 && offset > 3)
		{
			buf = d0.bit[row - 3];
		}
		else
		{
			buf = c0.bit[row];
		}
		int answer = buf & table[offset];
		if (answer)
		{
			row = i / 8;
			offset = i % 8;
			exkey->bit[row] = exkey->bit[row] | table[offset];
		}
		else
		{
			row = i / 8;
			offset = i % 8;
			exkey->bit[row] = exkey->bit[row] & (~table[offset]);
		}
	}
	return 0;
}
