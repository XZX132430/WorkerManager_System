#include<iostream>
using namespace std;
#include"workerManager.h"

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"


int main()
{
	////���Դ���
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->ShowInformation();
	//delete worker;//#���������ֶ������ڴ�
	//worker =NULL;


	//ʵ���������߶���
	WorkerManager wm;

	int choice = 0;//�洢ʹ���ߵ�ѡ��

	while (true)
	{
		//���ò˵�
		wm.Show_Menu();

		cout << "���������ѡ��" << endl;
		if (cin >> choice)
		{
			switch (choice)
			{
			case 0:  //�˳�ϵͳ
				wm.ExitSystem();
				break;
			case 1:  //����ְ��
				wm.Add_Emp();
				break;
			case 2:  //��ʾְ��
				wm.Show_Emp();
				break;
			case 3:  //ɾ��ְ��
				wm.Del_Emp();
				break;
			case 4:  //�޸�ְ��
				wm.Mod_Emp();
				break;
			case 5:  //����ְ��
				wm.Find_Emp();
				break;
			case 6:  //����ְ��
				wm.Sort_Emp();
				break;
			case 7:  //����ĵ�
				wm.Claen_File();
				break;
			default:
			{
				cout << "����������������Ҫʹ�õĹ���ǰ����������" << endl;
				system("pause");
				system("cls");//��������
				break;
			}
			}
		}
		else
		{
			cout << "��������#�����빦��ǰ�������#" << endl << endl;


			cin.clear(); // �������״̬��־
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����

			system("pause");
			system("cls");//��������

		}
	}

	system("pause");

	return 0;
}

//*************************************************************************************************************************************************************************************
//�������*��,��*:.��(������)/$:*.���* ��