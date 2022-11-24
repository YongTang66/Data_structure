#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void TestHeap1()
{
	int arr[] = { 10,20,31,34,60,29,40,53,56,46 };
	Heap hp;
	HeapCreate(&hp, arr, sizeof(arr) / sizeof(int));
}

void HeapSort(int* a, int n)
{
	//向上调整 N*logN
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a,i);
	}*/
	//向下调整 O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//升序 建大堆
	int i = n - 1;
	while (i > 0)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
		--i;
	}
	//降序 建小堆
}

void TestHeap2()
{
	int arr[] = { 50,20,31,34,60,29,40,10,56,46 };
	HeapSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void TestHeap5()
{
	int n = 10000;
	int k = 5;
	srand(time(0));
	FILE* fin = fopen("Data1.txt", "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int val = rand()%n;
		fprintf(fin, "%d\n", val);
	}
	fclose(fin);

	FILE* fout = fopen("Data1.txt", "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("malloc fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d ", &minHeap[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, k, i);
	}

	int val = 0;
	while (fscanf(fout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	fclose(fout);
}

void TestTopk()
{
	int n = 100;
	int k = 10;
	int* a = (int*)malloc(sizeof(int) * n);
	if (a == NULL)
	{
		perror("malloc fail");
		return;
	}
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000;
	}
	PrintTopK(a, n, k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	TestTopk();
	return 0;
}