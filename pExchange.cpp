#include "struct.h"
extern int ptable[];
int pExchange(bdata32* SOUT)
{
	bdata32 backup = *SOUT;
	char table[] = { -128,64,32,16,8,4,2,1 };
	for (int i = 0; i < 32; i++)
	{
		int position = ptable[i] - 1;
		int row = position / 8;
		int offset = position % 8;
		int answer = backup.bit[row] & table[offset];
		if (answer)//该位置1
		{
			row = i / 8;
			offset = i % 8;
			SOUT->bit[row] = backup.bit[row] | table[offset];
		}
		else//该位置0
		{
			row = i / 8;
			offset = i % 8;
			SOUT->bit[row] = backup.bit[row] & (~table[offset]);
		}
	}
	return 0;
}
