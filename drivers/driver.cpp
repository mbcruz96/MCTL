#include "MCvector.h"
#include "MClist.h"
#include "MCstack.h"
#include <iostream>
#include <string>

using namespace mctl;
using namespace std;

int main(){
	/*cout << "starting function execution\n";
	mctl::MCvector<int> vec;
	vec.push_back(12);
	cout << "Current size is " << vec.getSize() << endl;
	vec.print();	
	cout << endl;
	
	vec.pop_back();
	cout << "Current size is " << vec.getSize() << endl;
	vec.print();
	cout << endl;
	
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 10);
		
	cout << "Current size is " << vec.getSize() << endl;
	vec.print();
	cout << endl;
	cout << "\nstarting begin()";
	auto beginptr = vec.begin();
	cout << "\nfinished execution...\n\n" << "starting end()";
	auto endptr = vec.end();
	cout << "\nfinished execution...\n\n";
	
	//cout << "\nfirst value: " << *beginptr;
	cout << "\nlast value: " << *endptr << endl;
	
	cout << "\nstarting insert\n";
	auto insptr = vec.insert(beginptr, 22);
	cout << "finsished... The new iterator is :" << *insptr << endl;
	vec.print();*/
	mctl::MCstack<int> stack;
	stack.push(1);
	for (int i = 0; i < 10; i++)
		stack.push(i * 10);
	stack.print();
	return 0;
}
