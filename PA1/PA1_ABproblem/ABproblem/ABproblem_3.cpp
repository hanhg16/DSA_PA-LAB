#include<cstdio>

//����A��B��˺���������A,B��λ�Ӹߵ��͹��ɵ�char���飬����˽����λ�ӵ͵��������int����c��,ͬʱ������˽�����λ��λ����
int ABmulti(int* A, int lenA, int* B,int lenB, int* C)
{
	int  k = 0, max = 0;
	for (int m = 0; m < lenA; m++) //�ӵ͵��߰�λ��ȡAÿһλ��ֵ��
	{
		k = 0;
		if (A[lenA-1-m] == 0) { continue; }	//�����λΪ0��ֱ�������������ĳ˷���
		for (int n = 0; n < lenB; n++) //�ӵ͵��߰�λ��ȡBÿһλ��ֵ,ͬʱ��¼��ʱ��λ��ֵ��
		{
			//��λ�жϣ��κ�ʱ��a,b��λ��˵Ľ�����Ϊ��λ��������ԭ�������Ӧλ�����ɣ�
			C[m+n] = C[m+n] + A[lenA-1-m]*B[lenB-1-n] + k;
			k = C[m+n]/10;
			C[m+n] %= 10;
		}
		C[m+lenB] = k;//���λҪ���м�¼����ֹ��һ��ѭ��ֱ�Ӷ�ʧ��
	}
	max = lenA + lenB -1;//A*B��λ�����Ϊ�������λ֮��+1��
	while(C[max] == 0 && 0 < max){max--;}//���λ��Ϊ�������λ֮�͵������

	return max;
}

int main()
{
	int n = 0, max = 0;
	char* stra = new char[5000];	//���붯̬�ڴ�ռ��Ŷ����A��B����Ϊchar���飻
	char* strb = new char[5000];
	int* A= new int[1250];
	int* B=new int[1250];
	int* C= new int[2500]();	//���붯̬�ڴ�ռ���AB��˵Ľ�����������Ϊint���飻

	//����n��ֵ������n�ּ���,ͬʱ���뻻�з���ֹ��Ӱ������Ķ��룻
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{	
		//��a,b��ȡΪchar���鲢�������ó�a,b��λ����
		scanf("%s%s",stra,strb);
		int lengtha=0,lengthb=0;
		while(stra[lengtha]!='\0')	//��char�͵�����ת��Ϊint�ͣ�
		{
			A[lengtha]=stra[lengtha]-'0';
			lengtha++;
		}
		while(strb[lengthb]!='\0')
		{
			B[lengthb]=strb[lengthb]-'0';
			lengthb++;
		}

		max = ABmulti(A,lengtha, B,lengthb, C); //������˺������м��㲢��¼��������λ��ֵ�����������
		for (int i = max; 0 <= i; i--) { printf("%d", C[i]); C[i] = 0; } //�����������ע��洢�ǰ��ӵ͵��ߴ�ģ��������ʱҪ������������λ����ʼ��ͬʱ�������Ĵ洢��������һ�μ���
		printf("\n");

	}




	delete[] stra;
	delete[] strb;
	delete[] A;
	delete[] B;
	delete[] C;


	return 0;
}


/*

*/