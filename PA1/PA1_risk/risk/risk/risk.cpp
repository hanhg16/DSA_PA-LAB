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

int binsearch(int p,int* A,int lo,int hi)//���ֲ��ң�����С��p��A��Ԫ��������ߣ�
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

	//���ڴ��ÿ��ȷ��������i����������ccs[0]Ϊ��0�죬ȷ��Ϊ0,��˿�n+1���ռ䣬��ʼ��Ϊ0����xi[1]��ʼ��ȡ���ݣ�
	int* ccs = new int[n + 1]();//confirmed case number
	int* maxccs = new int[n];//���ÿ�ζ�ǰ����۲�Ľ��
	for (int i = 1;i < n + 1;i++) { scanf("%d",ccs+i); } //��xi[1]��ʼ��ȡ���ݣ�

	queap myqueap;
	//ͨ������ģ�⻬���������ÿһ�ι۲��ȷ�����ֵ���洢
	for (int i = 0;i < n;i++)
	{
		int days;
		scanf("%d",&days);
		myqueap.enqueap(ccs[i]);//���۹۲�ǰ��Ķ����죬ÿ�µ�һ����Ҫ�����ǰһ��Ĺ۲�
		while (days < myqueap.getq_size()){ myqueap.dequeap(); }//һֱ���ٶ��д�����Ĺ۲�����ֱ�����������


		maxccs[i] = myqueap.getmax();//��ʱ���д����е����ֵ��Ϊǰm��ȷ������ֵ
	}


	//�Թ۲������й鲢�����Ա�֮��Ĳ���
	mergesort(maxccs,0,n);


	//���ζ���p,q��ͨ�����ֲ���ȷ��ÿһ��p,q��Ӧ������
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

