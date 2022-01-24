#include"manager.h"
#include<iostream>
using namespace std;

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "Worker ID: " << this->m_Id
		<< "\tWorker Name: " << this->m_Name
		<< "\tPosition: " << this->getDeptName()
		<< "\tResponsibility: Finish the tasks from Boss" << endl;
}

string Manager::getDeptName() {
	return string("Manager");
}