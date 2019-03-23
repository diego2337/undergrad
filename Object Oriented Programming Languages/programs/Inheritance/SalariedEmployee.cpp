#ifndef SALARIED_H
#include "SalariedEmployee.h"
#endif

#include <iostream>
using namespace std;

                       

void SalariedEmployee::setWeeklySalary( double weeklySalary)
{
	this->weeklySalary = weeklySalary;
}
double SalariedEmployee::getWeeklySalary () const
{
	return this->weeklySalary;
} 
double SalariedEmployee::earnings () const
{
	return getWeeklySalary();
}
void SalariedEmployee::print () const
{
	
	Employee::print();
	cout << "\nSalario semanal: " << getWeeklySalary();

}
