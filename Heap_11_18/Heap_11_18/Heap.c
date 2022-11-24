#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (hp->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	memcpy(hp->a,a,sizeof(HPDataType)*n);
	hp->size = hp->capacity = n;
	
	for(int i = (n - 1 - 1) / 2; i >= 0; i++)
	{
		AdjustDown(hp->a, n, i);
	}
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);

	free(hp->a);
	hp->a = NULL;
	hp->capacity = hp->size = 0;
}

void Swap(HPDataType* H1, HPDataType* H2)
{
	HPDataType tmp = *H1;
	*H1 = *H2;
	*H2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newcapacity;
	}

	hp->a[hp->size] = x;
	hp->size++;

	AdjustUp(hp->a,hp->size-1);
}

void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}

// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->a, hp->size, 0);
}


// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));

	return hp->a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}

// 堆的判空
bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}


void PrintTopK(int* a, int n, int k)
{
	assert(a);
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, k, i);
	}
	
	for (int i = k; i < n; i++)
	{
		if (a[0] < a[i])
		{
			a[0] = a[i];
			AdjustDown(a, k, 0);
		}
	}
}