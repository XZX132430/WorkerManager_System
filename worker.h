#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���ĳ�����
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void ShowInformation() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;


	//ְ�����
	int m_id;
	//ְ������
	string m_Name;
	//���ű��
	int m_DepartmentId;
};