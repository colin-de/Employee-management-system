#pragma once
using namespace std;
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "empFile.txt"


class WorkerManager {
public:

	WorkerManager();

	void Show_Menu();

	void ExitSystem();

	int m_EmpNum;//number of employee

	Worker** m_EmpArray;//employee array pointer

	void Add_Emp();//add employee

	void save();

	bool m_FileIsEmpty;//if the file is empty

	int get_EmpNum();//check the number

	void init_Emp();//initialize worker

	void Show_Emp();//show the worker

	void Del_Emp();//delete worker

	int IsExist(int id);//if exist then return the position in array / when not -1

	void Mod_Emp();//modify 

	void Find_Emp();//find

	void Sort_Emp();//sorting

	void Clean_File();//clear all

	~WorkerManager();


};