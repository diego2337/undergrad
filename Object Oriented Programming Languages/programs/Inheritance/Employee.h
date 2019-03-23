#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> // classe string padrão C++ 
#include <iostream>
using namespace std;

class Employee
{
	public:
	   Employee(const string &first, const string &last, const string &cpf)                                      
		{                                  
			cout << endl << "Construindo um Employee";
			setFirstName(first);
			setLastName(last);
			setCpf(cpf);                   
		}                       

       ~Employee()
	   {
	       cout << "\nDestruindo um objeto Employee." ;
	       
	   }
	   void setFirstName( const string & ); 
	   string getFirstName() const; 

	   void setLastName( const string & ); 
	   string getLastName() const; 

	   void setCpf( const string & );
	   string getCpf() const; 

	   virtual double earnings() const = 0; //virtual pura 
	   virtual void print() const; 

	private:
	   string firstName; //nome                     
	   string lastName; // sobrenome           
	   string cpf; // cpf     
	   
}; // fim da classe CommissionEmployee

#endif

