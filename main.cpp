#include "addressbook.hpp"
#include<iostream>
#include<string>
using namespace addressbook;
int main()
{
	Entity* p = Entity::createEntity();
	p->getdetails();
	p->show();
	Addressbook hello;
	hello.addEntity(p);
	hello.savetoDatabase("test.txt");
	return 0;
}
