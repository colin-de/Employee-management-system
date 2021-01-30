#include "workerManager.h"
using namespace std;

WorkerManager::WorkerManager()
{
	//1. File doesn't exist
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//read the file

	if (!ifs.is_open())
	{
		cout << "File doesn't exist" << endl;
		//initialize the num and pointer
		this->m_EmpNum = 0;
	
		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//2. File exists but is empty
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3. when file exists and is not empty
	int num = this->get_EmpNum();
	//cout << "The number of workers: " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "Id: " << this->m_EmpArray[i]->m_Id
	//		<< " Name: " << this->m_EmpArray[i]->m_Name
	//		<< " Department number: " << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}

void WorkerManager::Show_Menu() {

	cout << "*****************************************" << endl;
	cout << "*** Welcome to WorkerManagerSystem£¡*****" << endl;
	cout << "********** 0.Exit Managerment System ****" << endl;
	cout << "********** 1.Add Worker Information *****" << endl;
	cout << "********** 2.Display Worker Information *" << endl;
	cout << "********** 3.Delete Worker **************" << endl;
	cout << "********** 4.Modify Worker Information  *" << endl;
	cout << "********** 5.Search Worker Information **" << endl;
	cout << "********** 6.Sorting with number ********" << endl;
	cout << "********** 7.Clear all data *************" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem() {
	cout << "Welcome to you next time" << endl;

	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "Please input the number to add£º " << endl;

	int addNum = 0; 
	cin >> addNum;

	if (addNum > 0)
	{

		int newSize = this->m_EmpNum + addNum;

		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id; 
			string name; 
			int dSelect; 

			cout << "Please input the " << i + 1 << " th new worker number£º " << endl;
			cin >> id;

			cout << "Please input the " << i + 1 << "  th new worker name£º " << endl;
			cin >> name;

			cout << "Please select the position£º " << endl;
			cout << "1. employee" << endl;
			cout << "2. manager" << endl;
			cout << "3. boss" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;

		}

		//release orignial space
		delete[] this->m_EmpArray;

		//change the pointer
		this->m_EmpArray = newSpace;

		//change the num
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		cout << "successfully adding" << addNum << " new stuff!" << endl;

		this->save();

	}
	else
	{
		cout << "false input" << endl;
	}

	system("pause");
	system("cls");
}


void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); 


	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();

}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}


void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

void WorkerManager::Show_Emp() {
	
	if (this->m_FileIsEmpty)
	{
		cout << "File does not exist or is empty" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();

		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "File does not exist " << endl;
	}
	else
	{
		cout << "Input the number you want to delete" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//means that the worker exist and need to delete
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			delete this->m_EmpArray[this->m_EmpNum - 1];
			this->m_EmpNum--;

			this->save();

			cout << "successfully deleted" << endl;
		}
		else
		{
			cout << "Fail to delete" << endl;
		}

		system("pause");
		system("cls");
 	}
}

int WorkerManager::IsExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id) {
			
			//find the worker
			index = i;

			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "File does not exist " << endl;
	}
	else
	{
		cout << "Please input the number of worker" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//find
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;
			
			cout << "Find the: " << id << " worker, please input new id" << endl;
			cin >> newId;

			cout << "Please input new name: " << endl;
			cin >> newName;

			cout << "Please input new position " << endl;
			cout << "1. Worker" << endl;
			cout << "2. Manager" << endl;
			cout << "3. Boss" << endl;

			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//refresh the data into array
			this->m_EmpArray[ret] = worker;

			cout << "successfully modified" << endl;

			//save
			this->save();
		}
		else
		{
			cout << "fail to modify, cannot find!" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "File does not exist " << endl;
	}
	else
	{
		cout << "Please give the searching method" << endl;
		cout << "1. using Id " << endl;
		cout << "2. using name " << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//Id
			int id;
			cout << "Please input the Id: " << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				//find
				cout << "successfully found! The worker's information: " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "False input!" << endl;
			}
		}
		else if (select == 2)
		{
			//Name
			string name;
			cout << "Please input the name: " << endl;
			cin >> name;

			//detremine whether is found
			bool flag = false;

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name) 
				{
					cout << "successfully found, the Id: "
						<< this->m_EmpArray[i]->m_Id
						<< " worker's information: " << endl;

					flag = true;

					//display function
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "fail to find!" << endl;
			}
		}
		else
		{
			cout << "False input!" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "File does not exist! " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Please select sorting method: " << endl;
		cout << "1. Ascending Sorting with Id " << endl;
		cout << "2. Descending Sorting with Id " << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i; //declare min or max sub index
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1) //ascending
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //descending
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			//determine whether the predetermind min/max is the computational final min/max, when not, swap them
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		}

		cout << "successfully sorting, the result is: " << endl;
		this->save();
		this->Show_Emp();
	}
}

void WorkerManager::Clean_File() {
	cout << "Are you sure to clean all data? " << endl;
	cout << "1. Confirm" << endl;
	cout << "2. Not sure" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//delete file
		ofstream ofs(FILENAME, ios::trunc); //delete and reconstruct
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//delete all object in heap
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//delete all pointer in heap
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}

		cout << "successfully delete all data!" << endl;
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


	}

}