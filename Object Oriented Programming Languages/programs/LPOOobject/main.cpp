#include <typeinfo>
#include "intfloat.h"
#include "List.h"
#include "Complex.h"
int main()
{
	List array;
	bool check;
	Int *inteiro = new Int(10);
	Float *flutuante = new Float(11.11);
	Float *flutuante2 = new Float(23.12);
	Float *flutuante3 = new Float(23.12);
	Object *objeto;
	Complex *complexo = new Complex(3.4, 7.5);
	array.add(inteiro);
	array.add(flutuante);	
	array.add(complexo);
	array.add(flutuante2);
	array.print();
	check = array.remove(inteiro);
	if(check)
		cout << "Node successfully removed.\n";
	else
		cout << "Problem removing node.\n";
	array.print();
	if(flutuante2->equals(*flutuante))
		cout << "Equal values\n";
	else
		cout << "Different values\n";
	array.add(flutuante3);
	array.print();
	check = array.remove(complexo);
	array.print();
	objeto = flutuante3->clone();
	if(flutuante2->equals(*objeto))
		cout << "Equal values\n";
	else
		cout << "Different values\n";
	array.clear();
	array.add(inteiro);
	array.add(flutuante);	
	array.add(complexo);
	array.add(flutuante2);
	cout << "Values after clearing the list: ";
	array.print();
	return 0;
}