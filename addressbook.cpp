#include "addressbook.hpp"
#include<fstream>
using namespace addressbook;
Addressbook::Addressbook(std::string path)
{
	this->filename = path;
	std::ifstream fin;
	std::string s;
	fin.open(database + this->filename);
	if(!fin.is_open())
	{
		throw std::runtime_error("Error opening file\n");
	}
	Entity* p = Entity::createEntity();
	while(fin)
	{
		getline(fin, s);
		p->getfname(s);
		getline(fin, s);
		p->getlname(s);
		getline(fin, s);
		p->getaddr(s);
		getline(fin, s);
		p->getzip(s);
		getline(fin, s);
		p->getphone(s);
		getline(fin, s);
		p->getemail(s);
		list.push_back(p);
	}
	fin.close();
}
void Addressbook::addEntity(Entity* en)
{
	list.push_back(en);
}
void Addressbook::import(std::string filename)
{
	this->filename = filename;
	std::ifstream fin;
	std::string s;
	fin.open(database + this->filename);
	if(!fin.is_open())
	{
		throw std::runtime_error("Error opening file\n");
	}
	Entity* p = Entity::createEntity();
	while(fin)
	{
		getline(fin, s);
		p->getfname(s);
		getline(fin, s);
		p->getlname(s);
		getline(fin, s);
		p->getaddr(s);
		getline(fin, s);
		p->getzip(s);
		getline(fin, s);
		p->getphone(s);
		getline(fin, s);
		p->getemail(s);
		list.push_back(p);
	}
	fin.close();
}
void Addressbook::savetoDatabase()
{
	std::ofstream fout;
	fout.open(database+filename, std::ios::trunc);
	for(auto it=list.begin(); it!=list.end(); ++it)
	{
		fout<<(*it)->putfname()<<"\n";
		fout<<(*it)->putlname()<<"\n";
		fout<<(*it)->putaddr()<<"\n";
		fout<<(*it)->putzip()<<"\n";
		fout<<(*it)->putphone()<<"\n";
		fout<<(*it)->putemail()<<"\n";
	}
	fout.close();
}
void Addressbook::savetoDatabase(std::string filename)
{
	this->filename = filename;
	std::ofstream fout;
	fout.open(database+filename, std::ios::trunc);
	for(auto it=list.begin(); it!=list.end(); ++it)
	{
		fout<<(*it)->putfname()<<"\n";
		fout<<(*it)->putlname()<<"\n";
		fout<<(*it)->putaddr()<<"\n";
		fout<<(*it)->putzip()<<"\n";
		fout<<(*it)->putphone()<<"\n";
		fout<<(*it)->putemail()<<"\n";
	}
	fout.close();
}
void Addressbook::show()
{
	for(auto it=list.begin(); it!=list.end(); ++it)
	{
		(*it)->show();
	}
}
std::vector<Entity*>::iterator Addressbook::find(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5, std::string s6)
{
	bool found = false;
	auto it = list.begin();
	for(; it!=list.end(); ++it)
	{
		if((((*it)->putfname())==s1) && (((*it)->putlname())==s2) && (((*it)->putaddr())==s3) && (((*it)->putzip())==s4) && (((*it)->putphone())==s5) && (((*it)->putemail())==s6))
		{
			found = true;
			break;
		}
	}
	if(found)
	{
		return it;
	}
	else
	{
		std::cout<<"No match found\n";
		return it;
	}
}
void Addressbook::deleteEntry(std::vector<Entity*>::iterator it)
{
	bool deleted = false;
	for(auto itr=list.begin(); itr!=list.end(); ++itr)
	{
		if(itr == it)
		{
			list.erase(it);
			deleted = true;
			break;
		}
	}
	if(!deleted)
	{
		std::cerr<<"Couldn't delete the entry\n";
	}
}
