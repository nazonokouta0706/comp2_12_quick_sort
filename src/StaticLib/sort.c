﻿#include "Windows.h"                    // Windows API の機能(NULL)定義
#include <stdbool.h>
#include "../include/libsort.h"


static void swap(node* p1, node* p2)
{
	node tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

static void quick_sort_sub(node* p, int begin, int end)
{
	int pivot, l, r;

	if (begin >= end)
		return;

	pivot = p[begin].key;
	l = begin;
	r = end - 1;

	while (l<r)
	{
		while (p[l].key < pivot)l++;
		while (p[r].key > pivot)r--;

		swap(&p[l], &p[r]);
	}

	quick_sort_sub(p, begin, l - 1);
	quick_sort_sub(p, r + 1, end);

}

// ソート
void quick_sort(array* a)
{
	quick_sort_sub(a->nodes,0, a->num);
}


//
// 配列の初期化
//
array* create(int num)
{
	array* a = (array*)malloc(sizeof(array));
	if (a == NULL) return NULL;

	a->num = num;
	a->nodes = (node*)malloc(sizeof(node) * num);

	return a;
}


//
// 使用メモリの全解放
//
void finalize(array* a)
{
	free(a->nodes);
	free(a);
}
