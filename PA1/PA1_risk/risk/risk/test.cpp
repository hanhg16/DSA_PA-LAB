#include<cstdio>
#include"queap.h"

/*
void merge(int* M, int lo, int mid, int hi)
{
	int* A = M + lo;
	int* B = new int[mid - lo];
	int* C = M + mid;
	for (int i = 0;i < mid - lo;i++) { B[i] = A[i]; }
	for (int i = 0, j = 0; i < mid - lo;)
	{
		if ((C[j] < B[i]) && (j < hi - mid)) { A[i + j] = C[j]; j++; }
		else { A[i + j] = B[i]; i++; }
	}
	delete[] B;
}

void mergesort(int* M, int lo, int hi)
{
	if (hi - lo < 2) { return; }
	int mid = (lo + hi) >> 1;
	mergesort(M, lo, mid);
	mergesort(M, mid, hi);
	merge(M, lo, mid, hi);
}

int binsearch(int p, int* A, int lo, int hi)//二分查找，返回小于p的A中元素秩最大者；
{
	int mid;
	while (lo < hi)
	{
		mid = (lo + hi) >> 1;
		if (A[mid] < p) { lo = mid + 1; }
		else { hi = mid; }
	}
	return lo - 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int* maxccs = new int[n];
	for (int i = 0;i<n;i++){ scanf("%d", maxccs+i); }


	//test
	for (int i = 0;i < n;i++) { printf("%d ", maxccs[i]); }
	printf("\n");

	//对观察结果进行归并排序，以便之后的查找
	mergesort(maxccs, 0, n);

	//test
	for (int i = 0;i < n;i++) { printf("%d ", maxccs[i]); }
	printf("\n");



	//依次读入p,q并通过二分查找确定每一对p,q对应的天数
	int m, p, q, lowdays, middays;
	scanf("%d", &m);
	for (int i = 0;i < m;i++)
	{
		scanf("%d%d", &p, &q);
		lowdays = binsearch(p, maxccs, 0, n);
		middays = binsearch(q, maxccs, lowdays + 1, n);
		printf("%d %d\n", lowdays + 1, middays - lowdays);
		
		//test
		for (int j = 0;j < lowdays + 1;j++){ printf("%d ", maxccs[j]); }
		printf("\n");

		for (int j = lowdays + 1;j < middays+1;j++) { printf("%d ", maxccs[j]); }
		printf("\n\n");
	}

	delete[] maxccs;

	return 0;
}

*/
