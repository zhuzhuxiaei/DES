#include "struct.h"
extern char stable[8][4][16];
int sBox(bdata48 edata,bdata32* result)
{	
	char S[8] = { 0 };
	char table[] = { -128,64,32,16,8,4,2,1 };
	//取出第一和第六个bit位,
	char temp = edata.bit[0] & table[0];
	char temp2 = edata.bit[0] & table[5];
	temp = temp >> 6;
	temp = temp & table[6];//消解移位头部副作用
	temp2 = temp2 >> 2;
	char temp3 = temp | temp2;
	temp = edata.bit[0] & 120;//其实只要最高位0即可
	temp = temp >> 3;
	S[0] = stable[0][temp3][temp];

	temp = edata.bit[0] & table[6];
	temp2 = edata.bit[1] & table[3];
	temp2 = temp2 >> 4;
	temp3 = temp | temp2;
	temp = edata.bit[0] & table[7];
	temp2 = edata.bit[1] & -32;
	temp2 = temp2 >> 5;
	temp2 = temp2 & 7;
	temp = temp << 3;
	temp = temp | temp2;
	S[1] = stable[1][temp3][temp];

	temp = edata.bit[1] & table[4];
	temp2 = edata.bit[2] & table[1];
	temp = temp >> 2;
	temp2 = temp2 >> 6;
	temp3 = temp | temp2;
	temp = edata.bit[1] & 7;
	temp = temp << 1;
	temp2 = edata.bit[2] & 128;
	temp2 = temp2 >> 7;
	temp2 = temp2 & table[7];//消除移位补位影响
	temp = temp | temp2;
	S[2] = stable[2][temp3][temp];

	temp = edata.bit[2] & table[2];
	temp2 = edata.bit[2] & table[7];
	temp = temp >> 4;
	temp3 = temp | temp2;
	temp = edata.bit[2] & 30;
	temp = temp >> 1;
	S[3] = stable[3][temp3][temp];

	//////////////////////////////////////////

	temp = edata.bit[3] & table[0];
	temp2 = edata.bit[3] & table[5];
	temp = temp >> 6;
	temp = temp & table[6];//消解移位头部副作用
	temp2 = temp2 >> 2;
	temp3 = temp | temp2;
	temp = edata.bit[3] & 120;//其实只要最高位0即可
	temp = temp >> 3;
	S[4] = stable[4][temp3][temp];

	temp = edata.bit[3] & table[6];
	temp2 = edata.bit[4] & table[3];
	temp2 = temp2 >> 4;
	temp3 = temp | temp2;
	temp = edata.bit[3] & table[7];
	temp2 = edata.bit[4] & -32;
	temp2 = temp2 >> 5;
	temp2 = temp2 & 7;
	temp = temp << 3;
	temp = temp | temp2;
	S[5] = stable[5][temp3][temp];

	temp = edata.bit[4] & table[4];
	temp2 = edata.bit[5] & table[1];
	temp = temp >> 2;
	temp2 = temp2 >> 6;
	temp3 = temp | temp2;
	temp = edata.bit[4] & 7;
	temp = temp << 1;
	temp2 = temp2 >> 7;
	temp2 = temp2 & table[7];
	temp = temp | temp2;
	S[6] = stable[6][temp3][temp];

	
	temp = edata.bit[5] & table[2];
	temp2 = edata.bit[5] & table[7];
	temp = temp >> 4;
	temp3 = temp | temp2;
	temp = edata.bit[5] & 30;
	temp = temp >> 1;
	S[7] = stable[7][temp3][temp];

	for (int i = 0;i<=3;i++)
	{
		S[i*2] = S[i*2] << 4;
		result->bit[i] = S[i*2] | S[i*2 + 1];
	}

	return 0;
}
