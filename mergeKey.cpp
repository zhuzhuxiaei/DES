/*
*函数名:mergeKey
*作用  :将c0,d0合并为realkey 
*/
#include "struct.h"
extern bdata56 realkey;
int mergeKey(bdata28 c0,bdata28 d0)
{
	for (int i = 0; i < 3; i++)
	{
		realkey.bit[i] = c0.bit[i];
	}
	for (int i = 4; i < 7; i++)
	{
		realkey.bit[i] = d0.bit[i - 3];
	}
	c0.bit[3] = c0.bit[3] & 0xf0;
	d0.bit[0] = d0.bit[0] & 0x0f;
	realkey.bit[3] = c0.bit[3] | d0.bit[0];
	return 0;
}
