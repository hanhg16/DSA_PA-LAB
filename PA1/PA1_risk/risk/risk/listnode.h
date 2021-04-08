#ifndef LISTNODE_H
#define LISTNODE_H


struct listnode
{
	int data;
	int cnt;//������deque��
	listnode* pred;
	listnode* succ;
	listnode() :data(0),cnt(0), pred(0), succ(0) {};//���head��trailer�Ĺ���
	listnode(int e, listnode* p = 0, listnode* s=0):data(e), cnt(1),pred(p),succ(s){}//����������е�Ĺ��죻
	listnode* insertassucc(const int& e)//��e��Ϊ��̲��룬�����²���ڵ��λָ��/λ�ã������ò���
	{
		listnode* x = new listnode(e, this, succ);
		succ->pred = x;
		succ = x;
		return x;
	}

	listnode* insertaspred(const int& e) //��e��Ϊǰ�����룬�����²���ڵ��λָ��/λ��
	{
		listnode* x = new listnode(e, pred, this);
		pred->succ = x;
		pred = x;
		return x;
	}
};





#endif

