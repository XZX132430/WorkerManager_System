#include"boss.h"

//构造函数
Boss::Boss(int id, string name, int did)
{
	this->m_DepartmentId = did;
	this->m_id = id;
	this->m_Name = name;
}

//显示个人信息
void Boss::ShowInformation()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：" << "统筹全局" << endl;
}

//获取岗位名称
string Boss::getDeptName()
{
	return "总裁";
}