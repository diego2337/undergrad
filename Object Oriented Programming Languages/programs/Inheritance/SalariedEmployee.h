#ifndef SALARIED_H
#define SALARIED_H

#include "Employee.h"

using namespace std;

class SalariedEmployee : public Employee
{
	public:
	   SalariedEmployee( const string &first, const string &last, const string &cpf, double weeklySalary) : Employee(first, last, cpf)
		{
			cout << endl << "Construindo um SalariedEmployee";
			setWeeklySalary(weeklySalary);

		}    
       ~SalariedEmployee()
	   {
	       cout << "\nDestruindo um objeto SalariedEmployee." ;
	       // print();
	   }
	   void setWeeklySalary( double ); 
	   double getWeeklySalary () const; 

	   
	   virtual double earnings() const; 
	   virtual void print() const; 

	private:
	   double weeklySalary; // salario semana
	   
}; // fim da classe CommissionEmployee

#endif

