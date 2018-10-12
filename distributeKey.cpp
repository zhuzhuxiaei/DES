/*
*函数名:distributeKey
*作用  :将原来的秘钥分为左右两部分
*/
#include "struct.h"
extern bdata56 realkey;
extern int keytable3[];
//times 告诉函数这是第几次,从而从keytable3中取出合适的移位步数
int distributeKey(bdata28* c0, bdata28* d0,int times)
{
	char table[] = {0,1,3};
	//赋值三个char,以及四个位
	for (int i = 0; i < 3; i++)
	{
		c0->bit[i] = realkey.bit[i];
		d0->bit[3 - i] = realkey.bit[6 - i];
	}
	char temp = realkey.bit[3];
	c0->bit[3] = temp & 0xf0;
	d0->bit[0] = temp & 0x0f;
	
	int step = keytable3[times];
	char buf = c0->bit[0];
	char buf2 = d0->bit[0];
	for (int i = 0; i < 3; i++)
	{
		//theshift是要补入的一位或两位
		char theshift = c0->bit[i + 1];
		theshift = theshift >> (8-step);
		theshift = theshift & table[step];
		c0->bit[i] = c0->bit[i] << step;
		c0->bit[i] = c0->bit[i] & (~table[step]);//需要移入的位先置位0
		c0->bit[i] = c0->bit[i] | theshift;
		//d0
		theshift = d0->bit[i + 1];
		theshift = theshift >> (8 - step);
		theshift = theshift & table[step];
		d0->bit[i] = d0->bit[i] << step;
		d0->bit[i] = d0->bit[i] & (~table[step]);
		d0->bit[i] = d0->bit[i] | theshift;

	}
	buf = buf >> (4 - step);
	buf = buf & (table[step] << 4);
	c0->bit[3] = c0->bit[3] << step;
	c0->bit[3] = c0->bit[3] & (~(table[step]<<4));
	c0->bit[3] = c0->bit[3] | buf;

	buf2 = buf2 >> (4 - step);
	buf2 = buf2 & (table[step]);
	d0->bit[3] = d0->bit[3] << step;
	d0->bit[3] = d0->bit[3] & (~table[step]);
	d0->bit[3] = d0->bit[3] | buf2;

	d0->bit[0] = d0->bit[0] & 0x0f;

	return 0;
}
