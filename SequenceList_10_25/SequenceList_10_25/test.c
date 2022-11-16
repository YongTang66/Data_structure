#define _CRT_SECURE_NO_WARNINGS 1


#include "SeqList.h"


void TestSeqList1()
{
	SeqList sl;
	SeqListInit(&sl);


	//SeqListCheckCapacity(&sl);
	SeqListDestroy(&sl);
}
void TestSeqList2()
{
	SeqList sl;
	SeqListInit(&sl);


	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);


	SeqListPopBack(&sl);
	SeqListPopBack(&sl);


	SeqListPrint(&sl);
	SeqListDestroy(&sl);
}
void TestSeqList3()
{
	SeqList sl;
	SeqListInit(&sl);


	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 1);


	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);

	SeqListPrint(&sl);
	SeqListDestroy(&sl);
}
void TestSeqList4()
{
	SeqList sl;
	SeqListInit(&sl);


	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);




	/*SeqListErase(&sl, 0);
	SeqListErase(&sl, 3);*/


	int i = SeqListFind(&sl, 7);
	if (i != -1)
	{
		SeqListErase(&sl, i);
	}


	SeqListPrint(&sl);
	SeqListDestroy(&sl);
}


int main()
{
	TestSeqList4();


	return 0;
}