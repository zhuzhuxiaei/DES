#include "struct.h"
extern int extendtable[];
int extendRdata(bdata32 rdata,bdata48 *edata)
{
	char table[] = { -128,64,32,16,8,4,2,1 };
	for (int i = 0; i < 48; i++)
	{
		int position = extendtable[i] - 1;
		int row = position / 8;
		int offset = position % 8;
		int answer = rdata.bit[row] & table[offset];
		if (answer)
		{
			row = i / 8;
			offset = i % 8;
			edata->bit[row] = edata->bit[row] | table[offset];
		}
		else
		{
			row = i / 8;
			offset = i % 8;
			edata->bit[row] = edata->bit[row] & (~table[offset]);
		}
	}
	return 0;
}
