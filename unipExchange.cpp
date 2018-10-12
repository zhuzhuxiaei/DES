/*逆初始置换*/
#include "struct.h"
extern bdata64 mingwen;
extern int iviptable[];
int unipExchange()
{
	bdata64 oldmingwen = mingwen;
	char table[] = { -128,64,32,16,8,4,2,1 };
	for (int i = 0; i < 64; i++)
	{
		int position = iviptable[i] - 1;
		int row = position / 8;
		int offset = position % 8;
		int answer = oldmingwen.bit[row] & table[offset];
		if (answer)//该位置1
		{
			row = i / 8;
			offset = i % 8;
			mingwen.bit[row] = mingwen.bit[row] | table[offset];
		}
		else//该位置0
		{
			row = i / 8;
			offset = i % 8;
			mingwen.bit[row] = mingwen.bit[row] & (~table[offset]);
		}
	}
	return 0;
}
