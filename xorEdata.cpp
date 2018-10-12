/*
*函数名:xorEdata
*作用  :将edata和exkey进行xor
*/
#include "struct.h"
int xorEdata(bdata48* edata,bdata48 exkey)
{
	for (int i = 0; i <= 6; i++)
	{
		edata->bit[i] = edata->bit[i] ^ exkey.bit[i];
	}
	return 0;
}
