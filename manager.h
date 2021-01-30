#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
#include<fstream>


class Manager:public Worker {
public:
	
	Manager(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDeptName();
};