#include"boss.h"

//���캯��
Boss::Boss(int id, string name, int did)
{
	this->m_DepartmentId = did;
	this->m_id = id;
	this->m_Name = name;
}

//��ʾ������Ϣ
void Boss::ShowInformation()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ��" << "ͳ��ȫ��" << endl;
}

//��ȡ��λ����
string Boss::getDeptName()
{
	return "�ܲ�";
}