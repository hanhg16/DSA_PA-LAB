#include"queap.h"


/*
private
*/

//�������ݺ�����ÿ������Ԫ�صĺ�����Ӧ�ý��������ж�
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

//deque���ݺ�����ÿ������Ԫ�صĺ�����Ӧ�ý��������ж�
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

//���캯��
queap::queap(int c)
{
	q_capacity = c;
	d_capacity = c;
	queue = new int[c];
	deque = new deque_point[c];
	q_size = 0;
	d_size = 0;
}

//��������
queap::~queap()
{
	delete[] queue;
	delete[] deque;
}

//�ӿں���
//����Ԫ��
void queap::enqueap(const int& e)
{
	q_expand();
	queue[q_size] = e;
	q_size++;

	d_expand();
	if (d_size == 0)
	{
		deque[d_size].val = e;
		deque[d_size].cnt = 1;//ע�⣬��ÿ��d_size++ʱ��deque[d_size].cnt��Ϊ1������+1���������൱����ʹ��ʱ�ٳ�ʼ������Ȼ��һ���õ�deque[i]��ʱ��ֱ��cnt+1����ԭ��������ֵ��+1������
		d_size++;
	}
	else if (e < deque[d_size - 1].val)
	{
		deque[d_size].val = e;
		deque[d_size].cnt = 1;
		d_size++;
	}
	else //��ǰ�̲�deque����ֱ��������e�������ͷֹͣ
	{
		deque[d_size - 1].val = e;
		deque[d_size - 1].cnt++;

		for (int i = d_size - 2;(0 <= i) && (deque[i].val <= e);i--)
		{
			deque[i].val = e;
			deque[i].cnt = deque[i].cnt + deque[d_size - 1].cnt;
			d_size--;//����Ҳ������ÿ��d_size--ǰ���������ֵ����ɾ����ص���ʼ��״̬
		}


	}
}

//�ͷ�Ԫ��
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
		d_size--;//����Ҳ������ÿ��d_size--ǰ���������ֵ����ɾ����ص���ʼ��״̬
	}
}

//�����ֵ
int queap::getmax()
{
	return deque[0].val;
}

//�鿴q_size
int queap::getq_size() 
{
	return q_size;
}


//���Խӿ�
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