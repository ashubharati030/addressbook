#include "addressbook.hpp"
#include<fstream>
using namespace addressbook;
Addressbook::Addressbook(std::string path)
{
	this->fname = path;
	fstream fio;
	fio.open("database" + this->fname);
	std::pair<uint, Entity> p;
	while(fio)
	{
		fio>>p.first;
		getline(fio, p.second.fname);
		getline(fio, p.second.lname);
		getline(fio, p.second.addr);
		getline(fio, p.second.zip);
		getline(fio, p.second.phone);
		getline(fio, p.second.email);
		list.push_back(p);
	}
}
