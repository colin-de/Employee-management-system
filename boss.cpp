#include"boss.h"
#include<iostream>
using namespace std;

Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "Worker ID: " << this->m_Id
		<< "\tWorker Name: " << this->m_Name
		<< "\tPosition: " << this->getDeptName()
		<< "\tResponsibility: Finish all things" << endl;
}

string Boss::getDeptName() {
	return string("XBoss ");
}



