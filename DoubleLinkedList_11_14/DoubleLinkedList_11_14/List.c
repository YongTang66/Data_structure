#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

//创建节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = pHead->prev;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = pHead;
	pHead->prev = newnode;

}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* tail = pHead->prev;
	ListNode* first = tail->prev;

	pHead->prev = first;
	first->next = pHead;
	free(tail);
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* newnode = BuyListNode(x);
	ListNode* second = pHead->next;
	pHead->next = newnode;
	newnode->prev = pHead;
	newnode->next = second;
	second->prev = newnode;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* delnode = pHead->next;
	ListNode* node = delnode->next;

	pHead->next = node;
	node->prev = pHead;
	free(delnode);
}


// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);

	prev->next = next;
	next->prev = prev;
}