#include"employee.h"

//���캯��
Employee::Employee(int id, string name, int did)
{
	this->m_DepartmentId = did;
	this->m_id = id;
	this->m_Name = name;
}

//��ʾ������Ϣ
void Employee::ShowInformation()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ��" << "��ɾ�����������" << endl;
}

//��ȡ��λ����
string Employee::getDeptName()
{
	return "��ͨԱ��";
}