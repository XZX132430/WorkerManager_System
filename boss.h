//�ϰ���
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;


class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void ShowInformation();

	//��ȡ��λ����
	virtual string getDeptName();
};
