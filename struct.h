#pragma once

typedef struct BDATA64
{
	//8*8=64
	char bit[8];
}bdata64;
typedef struct BDATA56 
{
	char bit[7];
}bdata56;
typedef struct BDATA32
{
	char bit[4];
}bdata32;
typedef struct BDATA48
{
	char bit[6];
}bdata48;
typedef struct BDATA28
{
	char bit[4];//28位的bit我们只能用32位的代替,多余的四位用不上.
}bdata28;
