#include"manager.h"

//���캯��
Manager::Manager(int id, string name, int did)
{
	this->m_DepartmentId = did;
	this->m_id = id;
	this->m_Name = name;
}

//��ʾ������Ϣ
void Manager::ShowInformation()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ��" << "����ϰ���������͸�Ա���ɷ�����" << endl;
}

//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}