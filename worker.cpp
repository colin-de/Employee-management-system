#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

void test01() {
	Worker* worker = NULL;
	worker = new Employee(1, "Colin", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "Curry", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "Lebron", 3);
	worker->showInfo();
	delete worker;
}

int main() {
	//test01();


	WorkerManager wm;
	
	int choice = 0;

	while (true)
	{
		wm.Show_Menu();

		cout << "Please input your choice" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //exit
			wm.ExitSystem();
			break; 
		case 1: //add worker
			wm.Add_Emp();
			break; 
		case 2: //display worker
			wm.Show_Emp();
			break; 
		case 3: //delete worker
			wm.Del_Emp();
			break;
		//{	
		//	int ret = wm.IsExist(5);
		//	if (ret != -1)
		//	{
		//		cout << "worker exists" << endl;
		//	}
		//	else
		//	{
		//		cout << "worker does not exist" << endl;
		//	}
		//	break;
		//}
		case 4: //modify worker 
			wm.Mod_Emp();
			break; 
		case 5: //search worker 
			wm.Find_Emp();
			break; 
		case 6: //sort worker 
			wm.Sort_Emp();
			break; 
		case 7: //clear all 
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}

	}
	
	system("pause");
	return 0;

}



