#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h"

#include <string> // classe string padrão C++ 
#include <iomanip> 
#include <iostream>

using namespace std;

class CommissionEmployee : public Employee
{
	public:
	   CommissionEmployee(const string &first, const string &last, const string &c, double sales, double rate) : Employee(first, last, c)                                     
		{            
				cout << endl << "Construindo um CommissionEmployee";		
				setGrossSales(sales);
				setCommissionRate(rate);
		}                                          
       ~CommissionEmployee()
	   {
	       cout << "\nDestruindo um objeto ComissionEmployee." ;
	       
	   }
	   void setGrossSales( double ); 
	   double getGrossSales() const; 

	   void setCommissionRate( double ); 
	   double getCommissionRate() const; 

	   virtual double earnings() const; 
	   virtual void print() const; 

	private:
	   double grossSales; // vendas brutas semanais    
	   double commissionRate; // porcentagem da comissão
}; // fim da classe CommissionEmployee

#endif

