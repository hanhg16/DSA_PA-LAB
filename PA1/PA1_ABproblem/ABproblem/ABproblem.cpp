#include<cstdio>

/*
//大数A，B相乘函数，输入A,B按位从高到低构成的char数组，将相乘结果按位从低到高输出到int数组c中,同时返回相乘结果最高位的位数；
int ABmulti(char* A, int lenA, char* B,int lenB, int* C)
{
	int temp = 0, x = 0, y = 0, a = 0, b = 0, max = 0;
	for (int m = 0, i = lenA - 1; m < lenA; i--, m++) //从低到高按位读取A每一位的值；
	{
		a = A[i] - '0';	//将char型的数字转换为int型；
		if (a == 0) { continue; }	//如果该位为0，直接跳过接下来的乘法；
		for (int n = 0, j = lenB - 1; n < lenB; j--, n++) //从低到高按位读取B每一位的值,同时记录此时的位数值；
		{
			b = B[j] - '0';
			if (b == 0) { continue; }

			temp = a * b;
			x = temp % 10;  //取出两位相乘的个位值；
			y = temp / 10;	//取出两位相乘的十位值，显然两个位数相乘最多到十位；

			//进位判断，满10进1，同时记录下此时的位数，显然最后一次记录的即是结果的最高位；
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
	char* stra = new char[5000];	//申请动态内存空间存放读入的A，B，存为char数组；
	char* strb = new char[5000];
	int* strc = new int[10000]();	//申请动态内存空间存放AB相乘的结果用于输出，为int数组；

	//读入n的值并进行n轮计算,同时读入换行符防止其影响后续的读入；
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{	
		//将a,b读取为char数组并遍历，得出a,b的位数；
		scanf("%s%s",stra,strb);
		int lengtha=0,lengthb=0;
		while(stra[lengtha]!='\0'){lengtha++;}
		while(strb[lengthb]!='\0'){lengthb++;}

		max = ABmulti(stra,lengtha, strb,lengthb, strc); //调用相乘函数进行计算并记录结果的最高位的值，用于输出；
		for (int i = max; 0 <= i; i--) { printf("%d", strc[i]); strc[i] = 0; } //输出计算结果，注意存储是按从低到高存的，所以输出时要从数组最后（最高位）开始，同时清空数组的存储，用于下一次计算
		printf("\n");

	}




	delete[] stra;
	delete[] strb;
	delete[] strc;


	return 0;
}


/*bug:
1.每次相乘函数无论有没有十位，都会进10位判定，导致max比实际大1，表现为04；
2.相乘函数是从高到低读A和B，导致max会越来越小；
3.乘法结果不对，同样是由于函数是从高到低读A和B导致的；

		//按位读入A,B的值，注意是从高到低位排列的，A[0]为最高位；
		int lengtha = 0,lengthb = 0;
		do
		{
			scanf("%c", &stra[lengtha]);
			lengtha++;
		} while ((stra[lengtha-1] != ' ') && (stra[lengtha-1] != '\n'));	//遇到空格或换行键停止读入，注意由于是do...while，所以最后以为是空格或换行符，故实际数组长度为length-1；
		do
		{
			scanf("%c", &strb[lengthb]);
			lengthb++;
		} while ((strb[lengthb - 1] != ' ') && (strb[lengthb - 1] != '\n'));

*/