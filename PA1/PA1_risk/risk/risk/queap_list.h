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

	//�б�ڵ�ɾ������
	void remove(listnode* p);

protected:

public:

	//���캯��
	queap();

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




