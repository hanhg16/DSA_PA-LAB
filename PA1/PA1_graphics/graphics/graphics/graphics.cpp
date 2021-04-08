#include<cstdio>


/*
解题思路：
1.读入x,y轴坐标数据并进行排序；综合考虑各种排序方法的时间复杂度和空间复杂度后，
决定采用归并排序，因为其稳定，时间复杂度在最好和最坏情况下都是O（nlogn），空间复杂度为O（n+logn);
2.挨个（即每读一个进行一次计算并输出）对m个坐标采用二分查找法进行toleft测试，找出每个坐标左右的线段个数并输出；
*/

//当点（px,py）在线段（x,0）(0,y)的左侧时，无交点，返回false，在右侧或线段上时有交点，返回true；
bool toright(int x, int y, int px, int py)
{
	return (0 < x * y - x * py - y * px) ? false : true;
}

//归并函数，将两个以及排好序的数组进行排序合并；
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

//归并排序函数，分而治之；
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
	//读入点个数n及x,y坐标轴数据；
	int n;
	scanf("%d", &n);
	int* xaxis = new int[n];
	int* yaxis = new int[n];
	for (int i = 0; i < n; i++) { scanf("%d", xaxis + i); }
	for (int i = 0; i < n; i++) { scanf("%d", yaxis + i); }

	//对x，y轴坐标从小到大进行排序；
	mergesort(xaxis, 0, n);
	mergesort(yaxis, 0, n);

	//循环读入m及m各点的坐标，依次进行二分查找进行toleft计算，输出结果；
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
		printf("%d\n", lo);//根据以上二分查找的判据，脱离循环时lo = hi,lo-1为与（px,py）有交点的最大值，又由于x,y坐标数组是从0而不是开始计数，所以交点数为[lo-1]+1=lo,这样以无交点为例，应输出0而不是-1,。
	}

	delete[] xaxis;
	delete[] yaxis;

	return 0;
}