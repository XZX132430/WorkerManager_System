#include"workerManager.h"
#include<iostream>
using namespace std;


//���캯�� 
WorkerManager::WorkerManager()
{
	//this->m_EmpArray = NULL;
	//this->m_EmpNum = 0;

	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	if (!ifs.is_open())
	{
		cout << "Ŀǰ�ļ�û����!" << endl;
		//��ʼ��
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->is_FileEmpty = true;

		ifs.close();
		return;
	}

	//2.�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())//�жϴ��ڵ�û�м�¼
	{
		cout << "Ŀǰ�ļ�Ϊ��!" << endl;
		//��ʼ��
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->is_FileEmpty = true;

		ifs.close();
		return;
	}

	//3.�ļ����ڲ���¼������
	int num = this->get_EmpNum();
	cout << "Ŀǰ��¼�� " << num << " λԱ��!" << endl;
	this->m_EmpNum = num;

	//�����¿ռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽�����м���ʼ��ְ��
	init_Emp();

	//�����ǲ��Դ���
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_id
			<< "\tְ������" << this->m_EmpArray[i]->m_Name
			<< "\tְ����λ" << this->m_EmpArray[i]->m_DepartmentId<< endl;
	}*/
}

void WorkerManager::Show_Menu()
{
	cout << "********************  ��ӭʹ��ְ������ϵͳ  ********************" << endl;
	cout << "***********************  0.�˳��������  ***********************" << endl;
	cout << "***********************  1.����ְ����Ϣ  ***********************" << endl;
	cout << "***********************  2.��ʾְ����Ϣ  ***********************" << endl;
	cout << "***********************  3.ɾ��ְ����Ϣ  ***********************" << endl;
	cout << "***********************  4.�޸�ְ����Ϣ  ***********************" << endl;
	cout << "***********************  5.����ְ����Ϣ  ***********************" << endl;
	cout << "***********************  6.���ձ������  ***********************" << endl;
	cout << "***********************  7.��������ĵ�  ***********************" << endl;
	cout << "****************************************************************" << endl;
	cout << endl;
}
//�˳�ϵͳ�ĺ���ʵ��**********************************************************************************
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��Master!" << endl;
	system("pause");
	exit(0);//�˳�����
}


//���Ա���ĺ���ʵ��**********************************************************************************
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;

	int addNum = 0;//������������
	if (cin >> addNum)
	{
		if (addNum > 0)
		{
			//����ռ��С
			int  newSize = this->m_EmpNum + addNum;//�¿ռ�����=ԭ����������������

			//�����¿ռ�
			Worker** newSpace = new Worker * [newSize];

			//��ԭ���ռ������ݣ��������¿ռ���
			if (this->m_EmpArray != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					newSpace[i] = this->m_EmpArray[i];
				}
			}


			//�������������
			for (int i = 0; i < addNum; i++)
			{
				int id;//���
				string name;//ְ������
				int dSelect;//����ѡ��

				cout << "�������" << i + 1 << "����Ա���ı�ţ�" << endl;
				if (cin >> id)
				{
					////�ж�Ա������Ƿ��ظ�*************************************�����ⲻд��
				//for (int t = 0; t < this->m_EmpNum + i; t++)
				//{
				//	if (id == this->m_EmpArray[t]->m_id)
				//	{
				//		cout << "��ְ������Ѿ���ռ�ã������¿�ʼ" << endl;
				//		system("pause");
				//		system("cls");
				//		return;
				//	}
				//}
				//��������



					cout << "�������" << i + 1 << "����Ա����������" << endl;
					cin >> name;

					cout << "�������Ա���ĸ�λ,����ǰ���ż���" << endl;
					cout << "1.��ͨԱ��" << endl;
					cout << "2.����" << endl;
					cout << "3.�ϰ�" << endl;
					if (cin >> dSelect)
					{
						Worker* worker = NULL;
						switch (dSelect)
						{
						case 1://��ͨԱ��
							worker = new Employee(id, name, 1);
							break;
						case 2://����
							worker = new Manager(id, name, 2);
							break;
						case 3://�ϰ�
							worker = new Boss(id, name, 3);
							break;
						default:
							cout << "��������" << endl;
							system("pause");
							system("cls");
							return;
						}
						//��������ָ���������
						newSpace[this->m_EmpNum + i] = worker;

						//�ָ��� ��������
						cout << "******************************************************************************************" << endl;
					}
					else
					{
						cout << "�����ʽ����������Ϊ�����ı��" << endl;

						cin.clear(); // �������״̬��־
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����

						system("pause");
						system("cls");
						return;
					}
				}
				else
				{
					cout << "�����ʽ����������Ϊ�����ı��" << endl;

					cin.clear(); // �������״̬��־
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����

					system("pause");
					system("cls");
					return;
				}
			}

			// �ͷ�ԭ�пռ�
			delete[]this->m_EmpArray;

			//�����¿ռ�ָ��
			this->m_EmpArray = newSpace;

			//����ְ������
			this->m_EmpNum = newSize;

			//�����ļ��Ƿ�Ϊ�յı�־
			if (newSize > 0)
			{
				this->is_FileEmpty = false;
			}
			//��ʾ��ӳɹ�
			cout << "�ɹ����" << addNum << "����Ա��" << endl;

			//�������ݵ�ָ���ļ�
			this->Save();
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�����ʽ����������Ϊ�����ı��" << endl;

		cin.clear(); // �������״̬��־
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����
		system("pause");
		system("cls");
		return;
	}
	
}

//�����ļ�����ʵ��***********************************************************************
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�������ʽ���ļ���д�ļ�

	//��ÿ��������д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DepartmentId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ��������ĺ���ʵ��
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
		//ͳ������
		num++;
	}
	ifs.close();

	return num;
}

//��ʼ����Ա************************************************************************
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

		if (did == 1)//��ͨԱ��
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
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}

//��ʾְ������ʵ��*********************************************************************************************
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->is_FileEmpty)
	{
		cout << "�ļ���¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->ShowInformation();
		}
	}
	//���������
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
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

//ɾ��ְ������************************************************************************************************************
void WorkerManager::Del_Emp()
{
	if (this->is_FileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ���ı��" << endl;
		int id = 0;
		if (cin >> id)
		{
			int index = this->IsExist(id);
			if (index != -1)//ְ������
			{
				//����ǰ��
				for (int i = index; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;
				//ͬ�����µ��ļ���
				this->Save();

				//�����ļ�״̬
				if (this->m_EmpNum == 0)
				{
					this->is_FileEmpty = true;
				}

				cout << "ɾ���ɹ���" << endl;
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
			}
		}
		else
		{
			cout << "�����ʽ����������Ϊ�����ı��" << endl;

			cin.clear(); // �������״̬��־
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����
		}
		system("pause");
		system("cls");
	}
}

//�޸�ְ��**************************************************************************************************
void WorkerManager::Mod_Emp()
{
	if (this->is_FileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ���ı��" << endl;

		int id = 0;
		if (cin >> id)
		{
			int x = this->IsExist(id);
			if (x != -1)
			{
				//���ڸ�ְ��
				delete this->m_EmpArray[x];

				int newid = 0;//���
				string newname = "";//ְ������
				int newdSelect = 0;//����ѡ��

				cout << "�鵽" << id << "��ְ��,������������ְ����" << endl;
				if (cin >> newid)
				{
					cout << "������������" << endl;
					cin >> newname;

					cout << "�������¸�λ" << endl;
					cout << "1.��ͨԱ��" << endl;
					cout << "2.����" << endl;
					cout << "3.�ϰ�" << endl;
					if (cin >> newdSelect)
					{
						Worker* worker = NULL;
						switch (newdSelect)
						{
						case 1://��ͨԱ��
							worker = new Employee(newid, newname, 1);
							break;
						case 2://����
							worker = new Manager(newid, newname, 2);
							break;
						case 3://�ϰ�
							worker = new Boss(newid, newname, 3);
							break;
						default:
							cout << "��������" << endl;
							break;
						}
						//���µ�����������
						this->m_EmpArray[x] = worker;
						cout << "�޸ĳɹ���" << endl;

						//���浽�ļ���
						this->Save();
					}
					else
					{
						cout << "�����ʽ����������Ϊ�����ı��" << endl;

						cin.clear(); // �������״̬��־
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����
					}
				}
				else
				{
					cout << "�����ʽ����������Ϊ�����ı��" << endl;

					cin.clear(); // �������״̬��־
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����
				}
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "�����ʽ����������Ϊ�����ı��" << endl;

			cin.clear(); // �������״̬��־
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����
		}
	}
	system("pause");
	system("cls");
}

//����ְ��***********************************************************************************************
void WorkerManager::Find_Emp()
{
	if (this->is_FileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;

		int select = 0;
		if (cin >> select)
		{
			if (select == 1)
			{
				//���ձ�Ų���
				int id;
				cout << "������Ҫ���ҵ�ְ�����" << endl;
				if (cin >> id)
				{
					int x = this->IsExist(id);
					if (x != -1)
					{
						//�ҵ�ְ��
						cout << "��ְ������Ϣ���£�" << endl;
						this->m_EmpArray[x]->ShowInformation();
					}
					else
					{
						cout << "���޴���" << endl;
					}
				}
				else
				{
					cout << "�����ʽ����������Ϊ�����ı��" << endl;

					cin.clear(); // �������״̬��־
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����
				}
			}
			else if (select == 2)
			{
				//������������
				bool flag = false;
				string name;
				cout << "��������ҵ�����" << endl;
				cin >> name;

				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]->m_Name == name)
					{
						flag = true;
						cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_id << "��"
							<< "ְ����Ϣ����:" << endl;
						this->m_EmpArray[i]->ShowInformation();//������ʾ��Ϣ�ӿ�
					}
				}
				if (!flag)
				{
					cout << "���޴���" << endl;
				}
			}
			else
			{
				cout << "����ѡ����������������" << endl;
			}
		}
		else
		{
			cout << "�����ʽ����������Ϊ�����ı��" << endl;

			cin.clear(); // �������״̬��־
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����
		}
	}
	system("pause");
	system("cls");
}

//����Ա��*************************************************************************************************
void WorkerManager::Sort_Emp()
{
	if (this->is_FileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1������Ա�������������" << endl;
		cout << "2������Ա����Ž�������" << endl;

		int select = 0;
		if (cin >> select)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				int minORmax = i;//������Сֵ�����ֵ�±�
				for (int j = i + 1; j < this->m_EmpNum; j++)
				{
					if (select == 1)//����
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

				//�ж�һ����maxORmin�Ƿ�Ϊ�����ó�����Сֵ �粻Ϊ ����
				if (i != minORmax)
				{
					Worker* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[minORmax];
					this->m_EmpArray[minORmax] = temp;
				}

			}
			cout << "����ɹ��������Ľ��Ϊ��" << endl;
			this->Save();//�����ļ�
			this->Show_Emp();
		}
		else
		{
			cout << "�����ʽ����������Ϊ�����ı��" << endl;

			cin.clear(); // �������״̬��־
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������뻺����
		}
	}
}

//����ļ�******************************************************************************************
void WorkerManager::Claen_File()
{
	cout << "ȷ��Ҫ����ļ���" << endl;
	cout << "���Ҫ����ļ������롮����ļ�����ȷ��" << endl;
	string temp = "";
	cin >> temp;

	if (temp == "����ļ�")
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿһ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//ɾ������������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;

			//������¼����
			this->m_EmpNum = 0;

			//�����Ƿ�Ϊ�յı��
			this->is_FileEmpty = true;
		}
		cout << "�ļ�����գ�" << endl;
	}
	else
	{
		cout << "���ʧ��!" << endl;
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