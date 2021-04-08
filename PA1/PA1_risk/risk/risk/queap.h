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

	//�������ݺ�����ÿ������Ԫ�صĺ�����Ӧ�ý��������ж�
	void q_expand();

	//deque���ݺ�����ÿ������Ԫ�صĺ�����Ӧ�ý��������ж�
	void d_expand();

protected:

public:

	//���캯��
	queap(int c = DEFAULT_CAPACITY);

	//��������
	~queap();

	//�ӿں���
	//����Ԫ�أ�
	void enqueap(const int& e);

	//�ͷ�Ԫ��
	void dequeap();
	
	//�����ֵ
	int getmax();

	//�鿴q_size
	int getq_size();

	//���Խӿ�
	void q_info();

	void d_info();

	void info();

};

#endif // ! QUEAP_H



