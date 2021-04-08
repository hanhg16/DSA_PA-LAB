#include<cstdio>
#include"queap_list.h"


void merge(int* M, int lo, int mid, int hi) 
{
	int* A = M + lo;
	int* B = new int[mid - lo];
	int* C = M + mid;
	for (int i = 0;i < mid - lo;i++){ B[i] = A[i]; }
	for (int i = 0, j = 0; i < mid - lo;) 
	{
		if ((C[j] < B[i])&&(j < hi - mid)) { A[i + j] = C[j]; j++; }
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

int binsearch(int p,int* A,int lo,int hi)//二分查找，返回小于p的A中元素秩最大者；
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
	scanf("%d", &n);

	//用于存放每天确诊人数，i代表天数，ccs[0]为第0天，确诊为0,因此开n+1个空间，初始化为0，从xi[1]开始读取数据；
	int* ccs = new int[n + 1]();//confirmed case number
	int* maxccs = new int[n];//存放每次对前几天观察的结果
	for (int i = 1;i < n + 1;i++) { scanf("%d",ccs+i); } //从xi[1]开始读取数据；

	queap myqueap;
	//通过队列模拟滑动窗口求出每一次观察的确诊最大值并存储
	for (int i = 0;i < n;i++)
	{
		int days;
		scanf("%d",&days);
		myqueap.enqueap(ccs[i]);//无论观察前面的多少天，每新的一天总要加入对前一天的观察
		while (days < myqueap.getq_size()){ myqueap.dequeap(); }//一直减少队列窗口里的观察天数直到与需求相等


		maxccs[i] = myqueap.getmax();//此时队列窗口中的最大值即为前m天确诊的最大值
	}


	//对观察结果进行归并排序，以便之后的查找
	mergesort(maxccs,0,n);


	//依次读入p,q并通过二分查找确定每一对p,q对应的天数
	int m;
	scanf("%d", &m);
	for (int i = 0;i < m;i++)
	{
		int p,q,lowdays,middays;
		scanf("%d%d", &p,&q);
		lowdays = binsearch(p,maxccs,0,n);
		middays = binsearch(q, maxccs, lowdays+1, n);
		printf("%d %d\n", lowdays + 1, middays - lowdays);
	}

	delete[] ccs;
	delete[] maxccs;

	return 0;
}

