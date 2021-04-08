#include<cstdio>


/*
����˼·��
1.����x,y���������ݲ����������ۺϿ��Ǹ������򷽷���ʱ�临�ӶȺͿռ临�ӶȺ�
�������ù鲢������Ϊ���ȶ���ʱ�临�Ӷ�����ú������¶���O��nlogn�����ռ临�Ӷ�ΪO��n+logn);
2.��������ÿ��һ������һ�μ��㲢�������m��������ö��ֲ��ҷ�����toleft���ԣ��ҳ�ÿ���������ҵ��߶θ����������
*/

//���㣨px,py�����߶Σ�x,0��(0,y)�����ʱ���޽��㣬����false�����Ҳ���߶���ʱ�н��㣬����true��
bool toright(int x, int y, int px, int py)
{
	return (0 < x * y - x * py - y * px) ? false : true;
}

//�鲢�������������Լ��ź���������������ϲ���
void merge(int* axis, int lo, int mid, int hi)
{
	int* A = axis + lo;
	int* B = new int[mid - lo];
	int* C = axis + mid;
	for (int i = 0; i < mid - lo; i++) { B[i] = A[i]; }
	for (int i = 0, j = 0, k = 0;i < mid - lo; k++)
	{
		if ((C[j] < B[i]) && (j < hi - mid))
		{
			A[k] = C[j];
			j++;
		}
		else
		{
			A[k] = B[i];
			i++;
		}
	}
	delete[] B;
}

//�鲢���������ֶ���֮��
void mergesort(int* axis, int lo, int hi)
{
	if (hi - lo < 2) { return; }
	int mid = (hi + lo) >> 1;
	mergesort(axis, lo, mid);
	mergesort(axis, mid, hi);
	merge(axis, lo, mid, hi);
}

int main()
{
	//��������n��x,y���������ݣ�
	int n;
	scanf("%d", &n);
	int* xaxis = new int[n];
	int* yaxis = new int[n];
	for (int i = 0; i < n; i++) { scanf("%d", xaxis + i); }
	for (int i = 0; i < n; i++) { scanf("%d", yaxis + i); }

	//��x��y�������С�����������
	mergesort(xaxis, 0, n);
	mergesort(yaxis, 0, n);

	//ѭ������m��m��������꣬���ν��ж��ֲ��ҽ���toleft���㣬��������
	int m, px, py, k = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int lo = 0, hi = n;
		scanf("%d%d", &px, &py);
		while (lo < hi)
		{
			int mid = (lo + hi) >> 1;
			if (toright(xaxis[mid], yaxis[mid], px, py)) { lo = mid + 1; }
			else { hi = mid; }
		}
		printf("%d\n", lo);//�������϶��ֲ��ҵ��оݣ�����ѭ��ʱlo = hi,lo-1Ϊ�루px,py���н�������ֵ��������x,y���������Ǵ�0�����ǿ�ʼ���������Խ�����Ϊ[lo-1]+1=lo,�������޽���Ϊ����Ӧ���0������-1,��
	}

	delete[] xaxis;
	delete[] yaxis;

	return 0;
}