#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


void SeListCheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDateType* tmp = (SLDateType*)realloc(ps->a, newCapacity * sizeof(SLDateType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}
void SeqListInit(SeqList* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


void SeqListDestroy(SeqList* ps)
{
	assert(ps);


	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->size = ps->capacity = 0;
	}
}


void SeqListPrint(SeqList* ps)
{
	assert(ps);


	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


//尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);


	SeListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}


//尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);


	ps->a[ps->size - 1] = 0;
	ps->size--;
}


//头插
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);

	SeListCheckCapacity(ps);


	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}


//头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}


// 顺序表在pos位置插入x 中间插入
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos <= ps->size);


	SeListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}


// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0);
	assert(pos < ps->size);


	int begin = pos;
	while (begin < ps->size)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}


// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	{
		assert(ps);


		for (int i = 0; i < ps->size; i++)
		{
			if (ps->a[i] == x)
			{
				return i;
			}
		}
		return -1;
	}
}