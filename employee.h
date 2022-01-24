#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
#include"employee.h"

class Employee :public Worker {
public:
	
	Employee(int id, string name, int dId);

	virtual	void showInfo();

	virtual string getDeptName();
};

