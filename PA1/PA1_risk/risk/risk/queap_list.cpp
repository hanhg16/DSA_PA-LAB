#include"queap_list.h"


/*
private
*/


//�б�ڵ�ɾ������
void queap::remove(listnode* p)
{
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
}


/*
public
*/

//���캯��
queap::queap()
{
	//queue�б���еĳ�ʼ��
	q_header = new listnode;
	q_trailer = new listnode;
	q_header->succ = q_trailer;
	q_header->pred = 0;
	q_trailer->pred = q_header;
	q_trailer->succ = 0;
	q_size = 0;

	//deque�б���еĳ�ʼ��
	d_header = new listnode;
	d_trailer = new listnode;
	d_header->succ = d_trailer;
	d_header->pred = 0;
	d_trailer->pred = d_header;
	d_trailer->succ = 0;
	d_size = 0;
}

//��������
queap::~queap()
{
	while (0 < q_size) { remove(q_header->succ);q_size--; }
	delete q_header;
	delete q_trailer;

	while (0 < d_size) { remove(d_header->succ);d_size--; }
	delete d_header;
	delete d_trailer;

}

//�ӿں���
//����Ԫ��
void queap::enqueap(const int& e)
{
	q_trailer->insertaspred(e);
	q_size++;

	if (d_size == 0)
	{
		d_trailer->insertaspred(e);
		d_size++;
	}
	else if (e < d_trailer->pred->data)
	{
		d_trailer->insertaspred(e);
		d_size++;
	}
	else //��ǰ�̲�deque����ֱ��������e�������ͷֹͣ
	{
		listnode* p = d_trailer->pred;
		p->data = e;
		p->cnt++;
		

		while ((p->pred != d_header)&&(p->pred->data < e))
		{
			p = p->pred;
			p->data = e;
			p->cnt = p->cnt + p->succ->cnt;
			remove(p->succ);
			d_size--;//����Ҳ������ÿ��d_size--ǰ���������ֵ����ɾ����ص���ʼ��״̬
		}

	}
}

//�ͷ�Ԫ��
void queap::dequeap()
{
	if (q_header->succ == q_trailer) { return; }
	remove(q_header->succ);
	q_size--;

	d_header->succ->cnt--;
	if (d_header->succ->cnt == 0)
	{
		remove(d_header->succ);
		d_size--;//����Ҳ������ÿ��d_size--ǰ���������ֵ����ɾ����ص���ʼ��״̬
	}
}

//�����ֵ
int queap::getmax()
{
	return d_header->succ->data;
}

//�鿴q_size
int queap::getq_size()
{
	return q_size;
}


//���Խӿ�
void queap::q_info()
{
	printf("q_size=%d\n", q_size);
	printf("queue:\n");
	for (listnode* p = q_header->succ; p != q_trailer; p = p->succ)
	{
		printf("%d ", p->data);
	}
	printf("\n\n");
}

void queap::d_info()
{
	printf("d_size=%d\n", d_size);
	printf("deque:\n");
	for (listnode* p = d_header->succ; p != d_trailer; p = p->succ)
	{
		printf("%d ", p->data);
	}
	printf("\n\n");
}

void queap::info()
{
	q_info();
	d_info();
}
