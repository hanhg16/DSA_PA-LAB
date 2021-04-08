#ifndef	QUEAP_H
#define QUEAP_H

#include<cstdio>

#define DEFAULT_CAPACITY 100

struct deque_point
{
public:
	int cnt;
	int val;
	deque_point(int count, int value) :cnt(count), val(value) {}
	deque_point() :cnt(0), val(0) {}
};

class queap
{
private:
	int* queue;
	int q_size;
	int q_capacity;
	deque_point* deque;
	int d_size;
	int d_capacity;

	//队列扩容函数，每个增加元素的函数都应该进行扩容判断
	void q_expand();

	//deque扩容函数，每个增加元素的函数都应该进行扩容判断
	void d_expand();

protected:

public:

	//构造函数
	queap(int c = DEFAULT_CAPACITY);

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



