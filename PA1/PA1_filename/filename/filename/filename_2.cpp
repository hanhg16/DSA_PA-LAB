# include<cstdio>

//����������Сֵ�ĺ���
int min(int x, int y)
{
	return (x < y) ? x : y;
}


int main()
{
	int lena, lenb, k, swapsign = 0;
	scanf("%d%d%d", &lena, &lenb, &k);

	//��֤aΪ�̴�,bΪ����������������㣬�����������򽻻���־��1��
	if (lena > lenb)
	{
		int temp = lena;
		lena = lenb;
		lenb = temp;
		swapsign = 1;
	}

	//�����ַ������Ȳ�ֵ����k���򲻿�����k�β�������ɣ���ֱ�ӷ���-1��
	if (k < lenb - lena)
	{
		printf("%d", min(lena, lenb));
		printf("%d", -1);
		return 0;
	}


	char* stra = new char[lena + 1]; //�����ַ�������ֻ��lena�����������len+1���ڴ�ռ䣬����deleteʱ�������Ҳ����ַ�����β�������ڴ�Խ�磻
	char* strb = new char[lenb + 1];

	int* first = new int[2*k+1];//ֻ������2k*1��int���鼴�ɣ�һ�����ڴ����һ�εĽ����һ��������һ�μ��㣻
	int* last=new int[2*k+1]; 


	//������������˵��������ǰ�����Ƚ���������b��
	if (swapsign == 1) { scanf("%s%s", strb, stra); }
	else { scanf("%s%s", stra, strb); }

	//�Ƚ��洢�ռ����ƽ�������lena/lenb = 0 ʱ����ʼ����
	for (int i = 0; i < k + 1; i++)
	{
		first[i] = i;
	}

	/*������̣�i�����ά�������������stra�е��ַ���Ӧ������ÿ��ֻ����2k+1��������ɣ���ѧ���ɷ�֤������
	���Ը��ݣ��Խ���ǰԪ�ز���k���Խ������඼��k��Ԫ�أ��Խ��ߺ�Ԫ�ز���k����Ϊ3������ֱ���㣬��Ҫע��
	�����������j��ֵԶС��strb�ж�ӦԪ�ص��ȣ���Ҫ�����Ӧ��ϵ��
	����˼·�ο��༭������⣺https://www.jianshu.com/p/a617d20162cf
	ÿ�μ���ʱ���������last[]�У�1�м�����󽫽�����Ƶ�first[]��������һ�μ����������
	*/

	for (int i = 1; i < lena + 1; i++)
	{
		//�Խ���ǰԪ�ز���k
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
					if (stra[i-1] == strb[j-1]) { last[j] = first[j - 1]; }//ע����������[0]��ŵ���ƽ�����������ʵ����ÿ���ַ������ά�����[i-1][j-1]��Ӧ������[i][j]��Ӧ����ͼ������������һ�㣻
					else { last[j] = min(first[j - 1] + 2, last[j - 1] + 1); }
				}
				else
				{
					if (stra[i-1] == strb[j-1]) { last[j] = first[j - 1]; }
					else { last[j] = min(first[j] + 1, last[j - 1] + 1); }
				}

			}
		}
		
		//�Խ������඼��k��Ԫ�أ�ע����2*k+1>lenbʱ������ڸ������
		else if ((k < i)&&(i < lenb + 1 - k))//����ֱ��д�ɣ�k < i < lenb + 1 - k������
		{
			for (int j = 0; j < 2 * k + 1; j++)
			{
				if (j == 0)
				{
					if (stra[i-1] == strb[i - k -1]) { last[j] = first[j]; } //ע���������j���ַ���b��J������ȣ���Ҫ�ҳ����Ӧ��ϵ,ΪJ=j+i-k��
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
		
		//�Խ��ߺ�Ԫ�ز���k
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

		//��������Ƶ�first[]��
		for (int j = 0; j < 2 * k + 1; j++)
		{
			first[j] = last[j];
		}
	}


	if (first[k + lenb - lena] > k) { printf("%d", -1); } //final�汾�ǵ�ɾ���ڶ������
	else { printf("%d", first[k + lenb - lena]); }

	delete[] stra;
	delete[] strb;
	delete[] first;
	delete[] last;

	return 0;

}


/*

�Ľ�˼·��
1.�ڶ���forѭ���ĵ�һ��ѭ���м�����matix[i][]>k,��ֱ��return,���-1���жϴ��룬ĳЩ����¿��Խ�ʡʱ�䣻

*/