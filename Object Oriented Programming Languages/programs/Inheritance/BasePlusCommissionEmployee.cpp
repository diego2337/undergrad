// Implementação dos métodos da classe BasePlusCommissionEmployee, derivada de ComissionEmployee
#ifndef BASEPLUS_H
#include "BasePlusCommissionEmployee.h"
#endif



#include <iostream>
using std::cout;

// construtor

void BasePlusCommissionEmployee::setBaseSalary( double salary )
{
   baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
}
double BasePlusCommissionEmployee::getBaseSalary() const
{
   return baseSalary;
}
double BasePlusCommissionEmployee::earnings() const
{
	return CommissionEmployee::earnings()+getBaseSalary();

} 
void BasePlusCommissionEmployee::print() const
{
   CommissionEmployee::print();
   cout << "\nSalario-base: " << getBaseSalary();
}




