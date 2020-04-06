#include "entity.hpp"
#include<iostream>
#include<string>
#include<iterator>
using namespace addressbook;
Entity::Entity(std::string fname, std::string lname, std::string addr, std::string zip, std::string phone, std::string email)
{
	this->fname = fname;
	this->lname = lname;
	this->addr = addr;
	this->zip = zip;
	this->phone = phone;
	this->email = email;
}
Entity* Entity::createEntity()
{
	Entity* p = new Entity();
	return p;
}
Entity* Entity::createEntity(std::string fname, std::string lname, std::string addr, std::string zip, std::string phone, std::string email)
{
	if(!(fname.empty() || lname.empty() || addr.empty() || zip.empty() || phone.empty() || email.empty()))
	{
		if(check_dig(zip) && check_dig(phone))
		{
			if(zip.length()==6 && phone.length()==10)
			{
				if(check_mail(email))
				{
					Entity* p = new Entity(fname, lname, addr, zip, phone, email);
					return p;
				}
			}
		}
	}
	std::cerr<<"Entity couldn't be created\n";
	return nullptr;
}
void Entity::getfname(std::string s)
{
	if(!s.empty())
	{
		fname = s;
	}
	std::cerr<<"Firstname cannot be empty\n";
}
void Entity::getlname(std::string s)
{
	if(!s.empty())
	{
		lname = s;
	}
	std::cerr<<"Lastname cannot be empty\n";
}
void Entity::getaddr(std::string s)
{
	if(!s.empty())
	{
		addr = s;
	}
	std::cerr<<"Address cannot be empty\n";
}
void Entity::getzip(std::string s)
{
	if(check_dig(s))
	{
		if(s.length()==6)
		{
			zip = s;
		}
	}
	std::cerr<<"Zip must be in proper format\n";
}
void Entity::getphone(std::string s)
{
	if(check_dig(s))
	{
		if(s.length()==10)
		{
			phone = s;
		}
	}
	std::cerr<<"Phone number must be in proper format\n";
}
void Entity::getemail(std::string s)
{
	if(check_mail(s))
	{
		email = s;
	}
	std::cerr<<"Email must be in proper format\n";
}
void Entity::getdetails()
{
	std::string s1, s2;
	std::cout<<"Enter your name:\n";
	getline(std::cin, s1, ' ');
	std::cin>>std::ws;
	getline(std::cin, s2);
	if(!(s1.empty() || s2.empty()))
	{
		fname = s1;
		lname = s2;
	}
	else
	{
		std::cerr<<"Name must be in proper format\n";
	}
	std::cout<<"Enter your address:\n";
	getline(std::cin, s1);
	if(!s1.empty())
	{
		addr = s1;
	}
	else
	{
		std::cerr<<"Address must be in proper format\n";
	}
	std::cout<<"Enter your zip:\n";
	getline(std::cin, s1);
	if(check_dig(s1))
	{
		if(s1.length()==6)
		{
			zip = s1;
		}
		else
		{
			std::cerr<<"Zip must be in proper format\n";
		}
	}
	std::cout<<"Enter your phone number:\n";
	getline(std::cin, s1);
	if(check_dig(s1))
	{
		if(s1.length()==10)
		{
			phone = s1;
		}
		else
		{
			std::cerr<<"Phone number must be in proper format\n";
		}
	}
	std::cout<<"Enter your email address:\n";
	getline(std::cin, s1);
	if(check_mail(s1))
	{
		email = s1;
	}
	else
	{
		std::cerr<<"Email must be in proper format\n";
	}
}
bool Entity::check_dig(std::string s)
{
	bool dig = true;
	for(auto it=s.begin(); it!=s.end(); ++it)
	{
		if((*it<'0') || (*it>'9'))
		{
			dig = false;
		}
	}
	return dig;
}
bool Entity::check_mail(std::string s)
{
	bool mail = false;
	for(auto it=s.begin(); it!=s.end(); ++it)
	{
		if(*it == '@')
		{
			mail = true;
		}
	}
	return mail;
}
void Entity::show()
{
	std::cout<<fname<<" "<<lname<<"\n"<<addr<<"\n"<<zip<<"\n"<<phone<<"\n"<<email<<"\n";
}
