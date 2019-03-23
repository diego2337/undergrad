#ifndef HOURLY_H
#define HOURLY_H

#include "Employee.h"

#include <iostream>

using namespace std;

class HourlyEmployee : public Employee
{
	public:
	   HourlyEmployee( const string &first, const string &last, const string &cpf, double hourlyWage, double workedHours ) : Employee(first, last, cpf)
	   {
			cout << endl << "Construindo um HourlyEmployee";
			setWage(hourlyWage);
			setHours(workedHours);
	   }                                  
       ~HourlyEmployee()
	   {
	       cout << "\nDestruindo um objeto HourlyEmployee." ;
	       // print();
	   }
	   void setWage( double ); 
	   double getWage () const;
	   void setHours( double );
	   double getHours () const;
	   
	   virtual double earnings() const; 
	   virtual void print() const; 

	private:
	   double wage; // valor de salario-hora
	   double hours; // horas trabalhadas durante a semana
}; 

#endif

