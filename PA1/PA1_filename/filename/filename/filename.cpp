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

	//��֤aΪ�̴�,bΪ����������������㣬�����������򽻻���־��1��
	if(lena > lenb)
	{
		int temp = lena;
		lena = lenb;
		lenb = temp;
		swapsign = 1;
	}

	//�����ַ������Ȳ�ֵ����k���򲻿�����k�β�������ɣ���ֱ�ӷ���-1��
	if(k < lenb - lena)
	{
		printf("%d",min(lena,lenb));
		printf("%d",-1);
		return 0;
	}


	char* stra = new char[lena+1]; //�����ַ�������ֻ��lena�����������len+1���ڴ�ռ䣬����deleteʱ�������Ҳ����ַ�����β�������ڴ�Խ�磻
	char* strb = new char[lenb+1];
	int** matrix = new int* [lena+1];
	for (int i = 0; i<lena+1; i++)
	{
		matrix[i] = new int[2*k + 1];
	}
	
	//������������˵��������ǰ�����Ƚ���������b��
	if(swapsign == 1){scanf("%s%s",strb,stra);}
	else{scanf("%s%s",stra,strb);}

	//�Ƚ��洢�ռ����ƽ�������lena/lenb = 0 ʱ����ʼ����
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
				if(stra[i-1] == strb [i-k-1]){{matrix[i][j] = matrix[i-1][j];}}//ע���������j���ַ���b��J������ȣ���Ҫ�ҳ����Ӧ��ϵ,ΪJ=j+i-k��
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
1.k>lenb/2�����û�н��д��������������ʵ����Ӧ���ǲ��Ϸ��ģ���Ϊk<=100��lenb<=500000�������п��ܴ������������
���������bug���ھ�������ʱ���벻�����ڶ���forѭ������Ϊlenb+1-k < k+1��,�����������forѭ��ʱҲ������lenb+1-k < k+1����
������֮�ڵļ��н���ᱻ�ظ�����һ�Σ��Ӷ���������������ڵ�����forѭ����һ��i<max(lenb+1-k,k+1),ͬʱ�ڵ�һ��forѭ����
j��ȡֵ�Ͻ���ϣ�j<min(2*k+1,lenb+1)�����ж���䣬��ֹ��һ��forѭ���ļ���Խ�磻����3��forѭ������ҲҪ�ģ���Ϊj���Ͻ�ͬ���漰k����

�Ľ�˼·��
1.�ڶ���forѭ���ĵ�һ��ѭ���м�����matix[i][]>k,��ֱ��return,���-1���жϴ��룬ĳЩ����¿��Խ�ʡʱ�䣻

*/
