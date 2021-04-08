#include<cstdio>

//大数A，B相乘函数，输入A,B按位从高到低构成的char数组，将相乘结果按位从低到高输出到int数组c中,同时返回相乘结果最高位的位数；
int ABmulti(int* A, int lenA, int* B,int lenB, int* C)
{
	int  k = 0, max = 0;
	for (int m = 0; m < lenA; m++) //从低到高按位读取A每一位的值；
	{
		k = 0;
		if (A[lenA-1-m] == 0) { continue; }	//如果该位为0，直接跳过接下来的乘法；
		for (int n = 0; n < lenB; n++) //从低到高按位读取B每一位的值,同时记录此时的位数值；
		{
			//进位判断，任何时候a,b两位相乘的结果最多为两位数，加在原结果上相应位数即可；
			C[m+n] = C[m+n] + A[lenA-1-m]*B[lenB-1-n] + k;
			k = C[m+n]/10;
			C[m+n] %= 10;
		}
		C[m+lenB] = k;//最高位要进行记录，防止下一轮循环直接丢失；
	}
	max = lenA + lenB -1;//A*B的位数最多为两数最高位之和+1；
	while(C[max] == 0 && 0 < max){max--;}//结果位数为两数最高位之和的情况；

	return max;
}

int main()
{
	int n = 0, max = 0;
	char* stra = new char[5000];	//申请动态内存空间存放读入的A，B，存为char数组；
	char* strb = new char[5000];
	int* A= new int[1250];
	int* B=new int[1250];
	int* C= new int[2500]();	//申请动态内存空间存放AB相乘的结果用于输出，为int数组；

	//读入n的值并进行n轮计算,同时读入换行符防止其影响后续的读入；
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{	
		//将a,b读取为char数组并遍历，得出a,b的位数；
		scanf("%s%s",stra,strb);
		int lengtha=0,lengthb=0;
		while(stra[lengtha]!='\0')	//将char型的数字转换为int型；
		{
			A[lengtha]=stra[lengtha]-'0';
			lengtha++;
		}
		while(strb[lengthb]!='\0')
		{
			B[lengthb]=strb[lengthb]-'0';
			lengthb++;
		}

		max = ABmulti(A,lengtha, B,lengthb, C); //调用相乘函数进行计算并记录结果的最高位的值，用于输出；
		for (int i = max; 0 <= i; i--) { printf("%d", C[i]); C[i] = 0; } //输出计算结果，注意存储是按从低到高存的，所以输出时要从数组最后（最高位）开始，同时清空数组的存储，用于下一次计算
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