#pragma once
int ipExchange();
int keyMake();
int getMingWen();
int getKey();
int extendRdata(bdata32 rdata, bdata48 *edata);
int distributeKey(bdata28* c0, bdata28* d0, int times);
int exKey(bdata28 c0, bdata28 d0, bdata48* exkey);
int mergeKey(bdata28 c0, bdata28 d0);
int xorEdata(bdata48* edata, bdata48 exkey);
int sBox(bdata48 edata,bdata32*);
int pExchange(bdata32* SOUT);
int unipExchange();
int printMingwen();
