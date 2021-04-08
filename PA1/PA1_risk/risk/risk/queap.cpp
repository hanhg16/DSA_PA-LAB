#include"queap.h"


/*
private
*/

//队列扩容函数，每个增加元素的函数都应该进行扩容判断
void queap::q_expand()
{
	if (q_size < q_capacity) { return; }
	int* old = queue;
	q_capacity = 2 * q_capacity;
	queue = new int[q_capacity];
	for (int i = 0;i < q_size;i++)
	{
		queue[i] = old[i];
	}
	delete[] old;
}

//deque扩容函数，每个增加元素的函数都应该进行扩容判断
void queap::d_expand()
{
	if (d_size < d_capacity) { return; }
	deque_point* old = deque;
	d_capacity = 2 * d_capacity;
	deque = new deque_point[d_capacity];
	for (int i = 0;i < d_size;i++)
	{
		deque[i] = old[i];
	}
	delete[] old;
}


/*
public
*/

//构造函数
queap::queap(int c)
{
	q_capacity = c;
	d_capacity = c;
	queue = new int[c];
	deque = new deque_point[c];
	q_size = 0;
	d_size = 0;
}

//析构函数
queap::~queap()
{
	delete[] queue;
	delete[] deque;
}

//接口函数
//插入元素
void queap::enqueap(const int& e)
{
	q_expand();
	queue[q_size] = e;
	q_size++;

	d_expand();
	if (d_size == 0)
	{
		deque[d_size].val = e;
		deque[d_size].cnt = 1;//注意，在每次d_size++时把deque[d_size].cnt置为1而不是+1！！这样相当于在使用时再初始化，不然下一次用到deque[i]的时候直接cnt+1会在原来残留的值上+1而出错；
		d_size++;
	}
	else if (e < deque[d_size - 1].val)
	{
		deque[d_size].val = e;
		deque[d_size].cnt = 1;
		d_size++;
	}
	else //往前吞并deque队列直到遇到比e大的数或到头停止
	{
		deque[d_size - 1].val = e;
		deque[d_size - 1].cnt++;

		for (int i = d_size - 2;(0 <= i) && (deque[i].val <= e);i--)
		{
			deque[i].val = e;
			deque[i].cnt = deque[i].cnt + deque[d_size - 1].cnt;
			d_size--;//或者也可以在每次d_size--前把里面的数值清理干净，回到初始化状态
		}


	}
}

//释放元素
void queap::dequeap()
{
	if (q_size == 0) { return; }
	for (int i = 1;i < q_size;i++)
	{
		queue[i - 1] = queue[i];
	}
	q_size--;

	deque[0].cnt--;
	if (deque[0].cnt == 0)
	{
		for (int i = 1;i < d_size;i++)
		{
			deque[i - 1] = deque[i];
		}
		d_size--;//或者也可以在每次d_size--前把里面的数值清理干净，回到初始化状态
	}
}

//求最大值
int queap::getmax()
{
	return deque[0].val;
}

//查看q_size
int queap::getq_size() 
{
	return q_size;
}


//测试接口
void queap::q_info()
{
	printf("q_capacity=%d\n", q_capacity);
	printf("q_size=%d\n", q_size);
	printf("queue:\n");
	for (int i = 0;i < q_size;i++)
	{
		printf("%d ", queue[i]);
	}
	printf("\n\n");
}

void queap::d_info()
{
	printf("d_size=%d\n", d_size);
	printf("deque:\n");
	for (int i = 0;i < d_size;i++)
	{
		printf("val:%d cnt:%d\n", deque[i].val, deque[i].cnt);
	}
	printf("\n\n");
}

void queap::info()
{
	q_info();
	d_info();
}