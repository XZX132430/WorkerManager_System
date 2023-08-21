#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "职工信息在此文件夹.txt"

class WorkerManager
{
public:

	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//职工数组指针
	Worker** m_EmpArray;

	//记录职工人数
	int m_EmpNum;

	//添加职工的函数
	void Add_Emp();

	//保存文件
	void Save();

	//判断文件是否为空 标志
	bool is_FileEmpty;

	//统计文件中的人数
	int get_EmpNum();

	//初始化职工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//判断职工是否存在
	int IsExist(int id);

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Claen_File();

	//析构函数
	~WorkerManager();

};