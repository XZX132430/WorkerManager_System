#include"workerManager.h"
#include<iostream>
using namespace std;


//构造函数 
WorkerManager::WorkerManager()
{
	//this->m_EmpArray = NULL;
	//this->m_EmpNum = 0;

	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open())
	{
		cout << "目前文件没创建!" << endl;
		//初始化
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->is_FileEmpty = true;

		ifs.close();
		return;
	}

	//2.文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())//判断存在但没有记录
	{
		cout << "目前文件为空!" << endl;
		//初始化
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->is_FileEmpty = true;

		ifs.close();
		return;
	}

	//3.文件存在并记录着数据
	int num = this->get_EmpNum();
	cout << "目前记录了 " << num << " 位员工!" << endl;
	this->m_EmpNum = num;

	//开辟新空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中即初始化职工
	init_Emp();

	//下面是测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_id
			<< "\t职工姓名" << this->m_EmpArray[i]->m_Name
			<< "\t职工岗位" << this->m_EmpArray[i]->m_DepartmentId<< endl;
	}*/
}

void WorkerManager::Show_Menu()
{
	cout << "********************  欢迎使用职工管理系统  ********************" << endl;
	cout << "***********************  0.退出管理程序  ***********************" << endl;
	cout << "***********************  1.增加职工信息  ***********************" << endl;
	cout << "***********************  2.显示职工信息  ***********************" << endl;
	cout << "***********************  3.删除职工信息  ***********************" << endl;
	cout << "***********************  4.修改职工信息  ***********************" << endl;
	cout << "***********************  5.查找职工信息  ***********************" << endl;
	cout << "***********************  6.按照编号排序  ***********************" << endl;
	cout << "***********************  7.清空所有文档  ***********************" << endl;
	cout << "****************************************************************" << endl;
	cout << endl;
}
//退出系统的函数实现**********************************************************************************
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用Master!" << endl;
	system("pause");
	exit(0);//退出程序
}


//添加员工的函数实现**********************************************************************************
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;

	int addNum = 0;//保存输入数量
	if (cin >> addNum)
	{
		if (addNum > 0)
		{
			//计算空间大小
			int  newSize = this->m_EmpNum + addNum;//新空间人数=原来人数加新增人数

			//开辟新空间
			Worker** newSpace = new Worker * [newSize];

			//将原来空间下数据，拷贝到新空间下
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}


			//批量添加新数据
			for (int i = 0; i < addNum; i++)
			{
				int id;//编号
				string name;//职工姓名
				int dSelect;//部门选择

				cout << "请输入第" << i + 1 << "个新员工的编号：" << endl;
				if (cin >> id)
				{
					////判断员工编号是否重复*************************************有问题不写了
				//for (int t = 0; t < this->m_EmpNum + i; t++)
				//{
				//	if (id == this->m_EmpArray[t]->m_id)
				//	{
				//		cout << "该职工编号已经被占用，请重新开始" << endl;
				//		system("pause");
				//		system("cls");
				//		return;
				//	}
				//}
				//接着输入



					cout << "请输入第" << i + 1 << "个新员工的姓名：" << endl;
					cin >> name;

					cout << "请输入该员工的岗位,输入前面编号即可" << endl;
					cout << "1.普通员工" << endl;
					cout << "2.经理" << endl;
					cout << "3.老板" << endl;
					if (cin >> dSelect)
					{
						Worker* worker = NULL;
						switch (dSelect)
						{
						case 1://普通员工
							worker = new Employee(id, name, 1);
							break;
						case 2://经理
							worker = new Manager(id, name, 2);
							break;
						case 3://老板
							worker = new Boss(id, name, 3);
							break;
						default:
							cout << "输入有误！" << endl;
							system("pause");
							system("cls");
							return;
						}
						//将创建的指针放入数组
						newSpace[this->m_EmpNum + i] = worker;

						//分割线 美观清晰
						cout << "******************************************************************************************" << endl;
					}
					else
					{
						cout << "输入格式有误，请输入为整数的编号" << endl;

						cin.clear(); // 清除错误状态标志
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区

						system("pause");
						system("cls");
						return;
					}
				}
				else
				{
					cout << "输入格式有误，请输入为整数的编号" << endl;

					cin.clear(); // 清除错误状态标志
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区

					system("pause");
					system("cls");
					return;
				}
			}

			// 释放原有空间
			delete[]this->m_EmpArray;

			//更改新空间指向
			this->m_EmpArray = newSpace;

			//更新职工人数
			this->m_EmpNum = newSize;

			//更新文件是否为空的标志
			if (newSize > 0)
			{
				this->is_FileEmpty = false;
			}
			//提示添加成功
			cout << "成功添加" << addNum << "名新员工" << endl;

			//保存数据到指定文件
			this->Save();
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入格式有误，请输入为整数的编号" << endl;

		cin.clear(); // 清除错误状态标志
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
		system("pause");
		system("cls");
		return;
	}
	
}

//保存文件函数实现***********************************************************************
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出方式打开文件即写文件

	//将每个人数据写入文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DepartmentId << endl;
	}

	//关闭文件
	ofs.close();
}

//统计文件中人数的函数实现
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//统计人数
		num++;
	}
	ifs.close();

	return num;
}

//初始化成员************************************************************************
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;


	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;

		if (did == 1)//普通员工
		{
			worker = new Employee(id, name, 1);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, 2);
		}
		else if (did == 3)
		{
			worker = new Boss(id, name, 3);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}

//显示职工函数实现*********************************************************************************************
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->is_FileEmpty)
	{
		cout << "文件记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->ShowInformation();
		}
	}
	//任意键清屏
	system("pause");
	system("cls");
}

//判断职工是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_id)
		{
			index = i;

			break;
		}
	}
	return index;
}

//删除职工函数************************************************************************************************************
void WorkerManager::Del_Emp()
{
	if (this->is_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除的职工的编号" << endl;
		int id = 0;
		if (cin >> id)
		{
			int index = this->IsExist(id);
			if (index != -1)//职工存在
			{
				//数据前移
				for (int i = index; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;
				//同步更新到文件中
				this->Save();

				//更新文件状态
				if (this->m_EmpNum == 0)
				{
					this->is_FileEmpty = true;
				}

				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "删除失败，未找到该职工" << endl;
			}
		}
		else
		{
			cout << "输入格式有误，请输入为整数的编号" << endl;

			cin.clear(); // 清除错误状态标志
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
		}
		system("pause");
		system("cls");
	}
}

//修改职工**************************************************************************************************
void WorkerManager::Mod_Emp()
{
	if (this->is_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想要修改的职工的编号" << endl;

		int id = 0;
		if (cin >> id)
		{
			int x = this->IsExist(id);
			if (x != -1)
			{
				//存在该职工
				delete this->m_EmpArray[x];

				int newid = 0;//编号
				string newname = "";//职工姓名
				int newdSelect = 0;//部门选择

				cout << "查到" << id << "号职工,请输入它的新职工号" << endl;
				if (cin >> newid)
				{
					cout << "请输入新姓名" << endl;
					cin >> newname;

					cout << "请输入新岗位" << endl;
					cout << "1.普通员工" << endl;
					cout << "2.经理" << endl;
					cout << "3.老板" << endl;
					if (cin >> newdSelect)
					{
						Worker* worker = NULL;
						switch (newdSelect)
						{
						case 1://普通员工
							worker = new Employee(newid, newname, 1);
							break;
						case 2://经理
							worker = new Manager(newid, newname, 2);
							break;
						case 3://老板
							worker = new Boss(newid, newname, 3);
							break;
						default:
							cout << "输入有误！" << endl;
							break;
						}
						//跟新到数组中数组
						this->m_EmpArray[x] = worker;
						cout << "修改成功！" << endl;

						//保存到文件中
						this->Save();
					}
					else
					{
						cout << "输入格式有误，请输入为整数的编号" << endl;

						cin.clear(); // 清除错误状态标志
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
					}
				}
				else
				{
					cout << "输入格式有误，请输入为整数的编号" << endl;

					cin.clear(); // 清除错误状态标志
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
				}
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入格式有误，请输入为整数的编号" << endl;

			cin.clear(); // 清除错误状态标志
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
		}
	}
	system("pause");
	system("cls");
}

//查找职工***********************************************************************************************
void WorkerManager::Find_Emp()
{
	if (this->is_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;

		int select = 0;
		if (cin >> select)
		{
			if (select == 1)
			{
				//按照编号查找
				int id;
				cout << "请输入要查找的职工编号" << endl;
				if (cin >> id)
				{
					int x = this->IsExist(id);
					if (x != -1)
					{
						//找到职工
						cout << "该职工的信息如下：" << endl;
						this->m_EmpArray[x]->ShowInformation();
					}
					else
					{
						cout << "查无此人" << endl;
					}
				}
				else
				{
					cout << "输入格式有误，请输入为整数的编号" << endl;

					cin.clear(); // 清除错误状态标志
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
				}
			}
			else if (select == 2)
			{
				//按照姓名查找
				bool flag = false;
				string name;
				cout << "请输入查找的姓名" << endl;
				cin >> name;

				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]->m_Name == name)
					{
						flag = true;
						cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_id << "号"
							<< "职工信息如下:" << endl;
						this->m_EmpArray[i]->ShowInformation();//调用显示信息接口
					}
				}
				if (!flag)
				{
					cout << "查无此人" << endl;
				}
			}
			else
			{
				cout << "输入选项有误，请重新输入" << endl;
			}
		}
		else
		{
			cout << "输入格式有误，请输入为整数的编号" << endl;

			cin.clear(); // 清除错误状态标志
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
		}
	}
	system("pause");
	system("cls");
}

//排序员工*************************************************************************************************
void WorkerManager::Sort_Emp()
{
	if (this->is_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、按照员工编号升序排列" << endl;
		cout << "2、按照员工编号降序排列" << endl;

		int select = 0;
		if (cin >> select)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				int minORmax = i;//声明最小值或最大值下标
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (select == 1)//升序
					{
						if (this->m_EmpArray[minORmax]->m_id > this->m_EmpArray[j]->m_id)
						{
							minORmax = j;
						}
					}
					else
					{
						if (this->m_EmpArray[minORmax]->m_id < this->m_EmpArray[j]->m_id)
						{
							minORmax = j;
						}
					}
				}

				//判断一开的maxORmin是否为遍历得出的最小值 如不为 交换
				if (i != minORmax)
				{
					Worker* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[minORmax];
					this->m_EmpArray[minORmax] = temp;
				}

			}
			cout << "排序成功，排序后的结果为：" << endl;
			this->Save();//保存文件
			this->Show_Emp();
		}
		else
		{
			cout << "输入格式有误，请输入为整数的编号" << endl;

			cin.clear(); // 清除错误状态标志
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区
		}
	}
}

//清空文件******************************************************************************************
void WorkerManager::Claen_File()
{
	cout << "确定要清空文件吗？" << endl;
	cout << "如果要清空文件请输入‘清空文件’来确认" << endl;
	string temp = "";
	cin >> temp;

	if (temp == "清空文件")
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每一个对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区的数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;

			//人数记录归零
			this->m_EmpNum = 0;

			//更新是否为空的标记
			this->is_FileEmpty = true;
		}
		cout << "文件已清空！" << endl;
	}
	else
	{
		cout << "清空失败!" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
	}
}