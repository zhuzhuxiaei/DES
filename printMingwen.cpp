#include "struct.h"
#include <stdio.h>
extern bdata64 mingwen;
int printMingwen()
{
	char table[] = { -128,64,32,16,8,4,2,1 };
	for (int i = 0; i < 64; i++)
	{
		char buf = mingwen.bit[i / 8] & table[i % 8];
		printf("%d ",(buf>0)?1:0);
		if (i % 8 == 7)
			printf("\n");
	}
	return 0;
}
