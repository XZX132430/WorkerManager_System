#include<iostream>
using namespace std;
#include"workerManager.h"

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"


int main()
{
	////测试代码
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->ShowInformation();
	//delete worker;//#不能忘记手动回收内存
	//worker =NULL;


	//实例化管理者对象
	WorkerManager wm;

	int choice = 0;//存储使用者的选择

	while (true)
	{
		//调用菜单
		wm.Show_Menu();

		cout << "请输入你的选择！" << endl;
		if (cin >> choice)
		{
			switch (choice)
			{
			case 0:  //退出系统
				wm.ExitSystem();
				break;
			case 1:  //增加职工
				wm.Add_Emp();
				break;
			case 2:  //显示职工
				wm.Show_Emp();
				break;
			case 3:  //删除职工
				wm.Del_Emp();
				break;
			case 4:  //修改职工
				wm.Mod_Emp();
				break;
			case 5:  //查找职工
				wm.Find_Emp();
				break;
			case 6:  //排序职工
				wm.Sort_Emp();
				break;
			case 7:  //清空文档
				wm.Claen_File();
				break;
			default:
			{
				cout << "输入有误，请输入想要使用的功能前面的数字序号" << endl;
				system("pause");
				system("cls");//清屏操作
				break;
			}
			}
		}
		else
		{
			cout << "输入有误，#请输入功能前面的数字#" << endl << endl;


			cin.clear(); // 清除错误状态标志
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除输入缓冲区

			system("pause");
			system("cls");//清屏操作

		}
	}

	system("pause");

	return 0;
}

//*************************************************************************************************************************************************************************************
//完结撒花*★,°*:.☆(￣▽￣)/$:*.°★* 。