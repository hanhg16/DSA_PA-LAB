#ifndef	QUEAP_LIST_H
#define QUEAP_LIST_H

#include<cstdio>
#include"listnode.h"


class queap
{
private:
	listnode* q_header;
	listnode* q_trailer;
	int q_size;
	listnode* d_header;
	listnode* d_trailer;
	int d_size;

	//列表节点删除函数
	void remove(listnode* p);

protected:

public:

	//构造函数
	queap();

	//析构函数
	~queap();

	//接口函数
	//插入元素；
	void enqueap(const int& e);

	//释放元素
	void dequeap();

	//求最大值
	int getmax();

	//查看q_size
	int getq_size();

	//测试接口
	void q_info();

	void d_info();

	void info();

};

#endif // ! QUEAP_H




