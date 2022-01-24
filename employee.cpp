#include"employee.h"
#include"worker.h"
#include"workerManager.h"
#include<iostream>
using namespace std;

Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "Worker ID: " << this->m_Id
		<< "\tWorker Name: " << this->m_Name
		<< "\tPosition: " << this->getDeptName()
		<< "\tResponsibility: Finish the tasks from manager" << endl;
}

string Employee::getDeptName() {
	return string("Worker");
}

