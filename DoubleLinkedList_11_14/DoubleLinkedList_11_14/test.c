#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

void TestDList1()
{
	ListNode* phead = ListCreate();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);


	//ListPopBack(phead);

	ListPrint(phead);

	/*ListPushFront(phead, 6);
	ListPushFront(phead, 7);
	ListPushFront(phead, 8);
	ListPushFront(phead, 9);

	ListPopFront(phead);
	ListPrint(phead);*/

	ListNode* pos = ListFind(phead, 4);
	if (pos)
	{
		pos->data *= 10;
	}
	ListPrint(phead);
	pos = ListFind(phead, 2);
	ListInsert(pos, 10);
	ListPrint(phead);
	pos = ListFind(phead, 10);
	ListErase(pos);
	ListPrint(phead);

	ListDestory(phead);
	phead = NULL;
}

int main()
{
	TestDList1();
	return 0;
}