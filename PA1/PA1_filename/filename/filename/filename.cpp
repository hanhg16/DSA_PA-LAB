# include<cstdio>

/*
int min(int x, int y)
{
	return (x<y)?x:y;
}
int main()
{
	int lena, lenb,k,swapsign=0;
	scanf("%d%d%d", &lena, &lenb, &k);

	//保证a为短串,b为长串，方便后续计算，若发生交换则交换标志置1；
	if(lena > lenb)
	{
		int temp = lena;
		lena = lenb;
		lenb = temp;
		swapsign = 1;
	}

	//若两字符串长度差值大于k，则不可能在k次操作类完成，故直接返回-1；
	if(k < lenb - lena)
	{
		printf("%d",min(lena,lenb));
		printf("%d",-1);
		return 0;
	}


	char* stra = new char[lena+1]; //尽管字符串长度只有lena，但必须分配len+1个内存空间，否则delete时会由于找不到字符串结尾而发生内存越界；
	char* strb = new char[lenb+1];
	int** matrix = new int* [lena+1];
	for (int i = 0; i<lena+1; i++)
	{
		matrix[i] = new int[2*k + 1];
	}
	
	//若发生交换则将说明长串在前，则先将长串赋给b；
	if(swapsign == 1){scanf("%s%s",strb,stra);}
	else{scanf("%s%s",stra,strb);}

	//先将存储空间根据平凡情况（lena/lenb = 0 时）初始化；
	for (int i = 0; i < k+1 ; i++)
	{
		matrix[0][i] = i;
		matrix[i][0] = i;
	}
		
	
	for (int i = 1; i < k+1 ; i++)
	{
		for(int j = 1;j < k+1+i;j++)
		{
			if(j == k+i)
			{
				if(stra[i-1] == strb [j-1]){matrix[i][j] = matrix[i-1][j-1];}
				else{matrix[i][j] = min(matrix[i-1][j-1]+2,matrix[i][j-1]+1);}
			}
			else
			{
				if(stra[i-1] == strb [j-1]){matrix[i][j] = matrix[i-1][j-1];}
				else{matrix[i][j] = min(matrix[i-1][j]+1,matrix[i][j-1]+1);}
			}

		}
	} 

	for(int i = k+1; i < lenb+1-k; i++)
	{
		for (int j = 0; j <2*k+1;j++ )
		{
			if(j == 0 )
			{
				if(stra[i-1] == strb [i-k-1]){{matrix[i][j] = matrix[i-1][j];}}//注意结果矩阵的j与字符串b的J并不相等，需要找出其对应关系,为J=j+i-k；
				else{matrix[i][j] = min(matrix[i-1][j]+2,matrix[i-1][j+1]+1);}
			}
			else if(j == 2*k)
			{
				if(stra[i-1] == strb [i+k-1]){{matrix[i][j] = matrix[i-1][j];}}
				else{matrix[i][j] = min(matrix[i-1][j]+2,matrix[i][j-1]+1);}
			}
			else
			{
				if(stra[i-1] == strb [j+i-k-1]){matrix[i][j] = matrix[i-1][j];}
				else{matrix[i][j] = min(matrix[i-1][j+1]+1,matrix[i][j-1]+1);}
			}
		}
	}
	
	for(int i = lenb+1-k; i < lena+1; i++)
	{
		for (int j = 0; j <k+1+lenb-i;j++ )
		{
			if(j == 0 )
			{
				if(stra[i-1] == strb [i-k-1]){{matrix[i][j] = matrix[i-1][j];}}
				else{matrix[i][j] = min(matrix[i-1][j]+2,matrix[i-1][j+1]+1);}
			}
			else
			{
				if(stra[i-1] == strb [j+i-k-1]){{matrix[i][j] = matrix[i-1][j];}}
				else{matrix[i][j] = min(matrix[i-1][j+1]+1,matrix[i][j-1]+1);}
			}
		}
	}

	if(matrix[lena][k+lenb-lena] > k){printf("%d %d",-1,matrix[lena][k+lenb-lena]);}
	else{printf("%d",matrix[lena][k+lenb-lena]);}

	delete []stra;
	delete []strb;
	delete[] matrix;

	return 0;

}



/*
Bug:
1.k>lenb/2的情况没有进行处理（尽管这种情况实际上应该是不合法的，因为k<=100而lenb<=500000，但任有可能存在这种情况）
这种情况的bug在于尽管运行时代码不会进入第二个for循环（因为lenb+1-k < k+1）,但进入第三个for循环时也会由于lenb+1-k < k+1导致
该区间之内的几行结果会被重复计算一次，从而出错；解决方案是在第三个for循环加一个i<max(lenb+1-k,k+1),同时在第一个for循环中
j的取值上界加上（j<min(2*k+1,lenb+1)）的判断语句，防止第一个for循环的计算越界；（第3个for循环可能也要改，因为j的上届同样涉及k）；

改进思路：
1.第二个for循环的第一重循环中加入若matix[i][]>k,则直接return,输出-1的判断代码，某些情况下可以节省时间；

*/
