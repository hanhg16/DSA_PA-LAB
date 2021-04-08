# include<cstdio>

//求两数中最小值的函数
int min(int x, int y)
{
	return (x < y) ? x : y;
}


int main()
{
	int lena, lenb, k, swapsign = 0;
	scanf("%d%d%d", &lena, &lenb, &k);

	//保证a为短串,b为长串，方便后续计算，若发生交换则交换标志置1；
	if (lena > lenb)
	{
		int temp = lena;
		lena = lenb;
		lenb = temp;
		swapsign = 1;
	}

	//若两字符串长度差值大于k，则不可能在k次操作类完成，故直接返回-1；
	if (k < lenb - lena)
	{
		printf("%d", min(lena, lenb));
		printf("%d", -1);
		return 0;
	}


	char* stra = new char[lena + 1]; //尽管字符串长度只有lena，但必须分配len+1个内存空间，否则delete时会由于找不到字符串结尾而发生内存越界；
	char* strb = new char[lenb + 1];

	int* first = new int[2*k+1];//只需两行2k*1的int数组即可，一组用于存放上一次的结果，一组用于下一次计算；
	int* last=new int[2*k+1]; 


	//若发生交换则将说明长串在前，则先将长串赋给b；
	if (swapsign == 1) { scanf("%s%s", strb, stra); }
	else { scanf("%s%s", stra, strb); }

	//先将存储空间根据平凡情况（lena/lenb = 0 时）初始化；
	for (int i = 0; i < k + 1; i++)
	{
		first[i] = i;
	}

	/*计算过程，i代表二维数组的行数，与stra中的字符对应，由于每行只计算2k+1个结果即可（数学归纳法证明），
	所以根据（对角线前元素不满k，对角线两侧都有k个元素，对角线后元素不满k）分为3种情况分别计算，需要注意
	后两种情况中j的值远小于strb中对应元素的秩，需要求出对应关系；
	计算思路参考编辑距离求解：https://www.jianshu.com/p/a617d20162cf
	每次计算时将结果存在last[]中，1行计算完后将结果复制到first[]中用于下一次计算的条件；
	*/

	for (int i = 1; i < lena + 1; i++)
	{
		//对角线前元素不满k
		if (i < k + 1)
		{
			for (int j = 0; j < k + 1 + i; j++)
			{
				if (j == 0)
				{
					last[j] = i;
				}
				else if (j == k + i)
				{
					if (stra[i-1] == strb[j-1]) { last[j] = first[j - 1]; }//注意由于数组[0]存放的是平凡情况，所以实际上每个字符是与二维数组的[i-1][j-1]对应而非与[i][j]对应，画图可清晰看出这一点；
					else { last[j] = min(first[j - 1] + 2, last[j - 1] + 1); }
				}
				else
				{
					if (stra[i-1] == strb[j-1]) { last[j] = first[j - 1]; }
					else { last[j] = min(first[j] + 1, last[j - 1] + 1); }
				}

			}
		}
		
		//对角线两侧都有k个元素，注意在2*k+1>lenb时不会存在该情况；
		else if ((k < i)&&(i < lenb + 1 - k))//不能直接写成（k < i < lenb + 1 - k）！！
		{
			for (int j = 0; j < 2 * k + 1; j++)
			{
				if (j == 0)
				{
					if (stra[i-1] == strb[i - k -1]) { last[j] = first[j]; } //注意结果矩阵的j与字符串b的J并不相等，需要找出其对应关系,为J=j+i-k；
					else { last[j] = min(first[j] + 2, first[j + 1] + 1); }
				}
				else if (j == 2 * k)
				{
					if (stra[i-1] == strb[i + k-1]) { last[j] = first[j]; } 
					else { last[j] = min(first[j] + 2,last[j - 1] + 1); }
				}
				else
				{
					if (stra[i-1] == strb[j + i - k -1]) { last[j] = first[j]; }
					else {last[j] = min(first[j + 1] + 1, last[j - 1] + 1); }
				}
			}
		}
		
		//对角线后元素不满k
		else
		{
			for (int j = 0; j < k + 1 + lenb - i; j++)
			{
				if (j == 0)
				{
					if (stra[i-1] == strb[i - k -1]) { last[j] = first[j]; } 
					else { last[j] = min(first[j] + 2, first[j + 1] + 1); }
				}
				else
				{
					if (stra[i-1] == strb[j + i - k -1]) { last[j] = first[j]; } 
					else { last[j] = min(first[j + 1] + 1, last[j - 1] + 1); }
				}
			}
		}

		//将结果复制到first[]中
		for (int j = 0; j < 2 * k + 1; j++)
		{
			first[j] = last[j];
		}
	}


	if (first[k + lenb - lena] > k) { printf("%d", -1); } //final版本记得删除第二个输出
	else { printf("%d", first[k + lenb - lena]); }

	delete[] stra;
	delete[] strb;
	delete[] first;
	delete[] last;

	return 0;

}


/*

改进思路：
1.第二个for循环的第一重循环中加入若matix[i][]>k,则直接return,输出-1的判断代码，某些情况下可以节省时间；

*/