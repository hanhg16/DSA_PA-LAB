#include<cstdio>

/*
//����A��B��˺���������A,B��λ�Ӹߵ��͹��ɵ�char���飬����˽����λ�ӵ͵��������int����c��,ͬʱ������˽�����λ��λ����
int ABmulti(char* A, int lenA, char* B,int lenB, int* C)
{
	int temp = 0, x = 0, y = 0, a = 0, b = 0, max = 0;
	for (int m = 0, i = lenA - 1; m < lenA; i--, m++) //�ӵ͵��߰�λ��ȡAÿһλ��ֵ��
	{
		a = A[i] - '0';	//��char�͵�����ת��Ϊint�ͣ�
		if (a == 0) { continue; }	//�����λΪ0��ֱ�������������ĳ˷���
		for (int n = 0, j = lenB - 1; n < lenB; j--, n++) //�ӵ͵��߰�λ��ȡBÿһλ��ֵ,ͬʱ��¼��ʱ��λ��ֵ��
		{
			b = B[j] - '0';
			if (b == 0) { continue; }

			temp = a * b;
			x = temp % 10;  //ȡ����λ��˵ĸ�λֵ��
			y = temp / 10;	//ȡ����λ��˵�ʮλֵ����Ȼ����λ�������ൽʮλ��

			//��λ�жϣ���10��1��ͬʱ��¼�´�ʱ��λ������Ȼ���һ�μ�¼�ļ��ǽ�������λ��
			y = (C[m+n] + x) / 10 + y;
			C[m+n] = (C[m+n] + x) % 10;
			if (y == 0){max = m+n;}
			else{max = m+n+1;}
			if (C[m+n+1] + y < 10) { C[m+n+1] += y; }
			else
			{
				C[m+n+1] = (C[m+n+1] + y) % 10;
				int k = m + n + 2;
				for (; C[k] == 9; C[k] = 0, k++);
				C[k] += 1;
			}
		}
	}
	return max;
}

int main()
{
	int n = 0, max = 0;
	char* stra = new char[5000];	//���붯̬�ڴ�ռ��Ŷ����A��B����Ϊchar���飻
	char* strb = new char[5000];
	int* strc = new int[10000]();	//���붯̬�ڴ�ռ���AB��˵Ľ�����������Ϊint���飻

	//����n��ֵ������n�ּ���,ͬʱ���뻻�з���ֹ��Ӱ������Ķ��룻
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{	
		//��a,b��ȡΪchar���鲢�������ó�a,b��λ����
		scanf("%s%s",stra,strb);
		int lengtha=0,lengthb=0;
		while(stra[lengtha]!='\0'){lengtha++;}
		while(strb[lengthb]!='\0'){lengthb++;}

		max = ABmulti(stra,lengtha, strb,lengthb, strc); //������˺������м��㲢��¼��������λ��ֵ�����������
		for (int i = max; 0 <= i; i--) { printf("%d", strc[i]); strc[i] = 0; } //�����������ע��洢�ǰ��ӵ͵��ߴ�ģ��������ʱҪ������������λ����ʼ��ͬʱ�������Ĵ洢��������һ�μ���
		printf("\n");

	}




	delete[] stra;
	delete[] strb;
	delete[] strc;


	return 0;
}


/*bug:
1.ÿ����˺���������û��ʮλ�������10λ�ж�������max��ʵ�ʴ�1������Ϊ04��
2.��˺����ǴӸߵ��Ͷ�A��B������max��Խ��ԽС��
3.�˷�������ԣ�ͬ�������ں����ǴӸߵ��Ͷ�A��B���µģ�

		//��λ����A,B��ֵ��ע���ǴӸߵ���λ���еģ�A[0]Ϊ���λ��
		int lengtha = 0,lengthb = 0;
		do
		{
			scanf("%c", &stra[lengtha]);
			lengtha++;
		} while ((stra[lengtha-1] != ' ') && (stra[lengtha-1] != '\n'));	//�����ո���м�ֹͣ���룬ע��������do...while�����������Ϊ�ǿո���з�����ʵ�����鳤��Ϊlength-1��
		do
		{
			scanf("%c", &strb[lengthb]);
			lengthb++;
		} while ((strb[lengthb - 1] != ' ') && (strb[lengthb - 1] != '\n'));

*/