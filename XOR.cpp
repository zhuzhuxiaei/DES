#include "struct.h"
int XOR(bdata32 ldata, bdata32 SOUT, bdata32* rdata)
{
	for (int i = 0; i < 4; i++)
	{
		rdata->bit[i] = ldata.bit[i] ^ SOUT.bit[i];

	}
	return 0;
}
