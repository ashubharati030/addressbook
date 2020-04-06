#include "entity.hpp"
#include<iostream>
#include<string>
using namespace addressbook;
int main()
{
	Entity* p = Entity::createEntity();
	p->getdetails();
	p->show();
	return 0;
}
