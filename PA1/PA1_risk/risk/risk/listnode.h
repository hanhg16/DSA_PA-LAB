#ifndef LISTNODE_H
#define LISTNODE_H


struct listnode
{
	int data;
	int cnt;//仅用在deque里
	listnode* pred;
	listnode* succ;
	listnode() :data(0),cnt(0), pred(0), succ(0) {};//针对head和trailer的构造
	listnode(int e, listnode* p = 0, listnode* s=0):data(e), cnt(1),pred(p),succ(s){}//针对其他所有点的构造；
	listnode* insertassucc(const int& e)//将e作为后继插入，返回新插入节点的位指针/位置，本题用不到
	{
		listnode* x = new listnode(e, this, succ);
		succ->pred = x;
		succ = x;
		return x;
	}

	listnode* insertaspred(const int& e) //将e作为前驱插入，返回新插入节点的位指针/位置
	{
		listnode* x = new listnode(e, pred, this);
		pred->succ = x;
		pred = x;
		return x;
	}
};





#endif

