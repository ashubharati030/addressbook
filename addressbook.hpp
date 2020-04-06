#ifndef _ADDRESSBOOK_
#define _ADDRESSBOOK_
#include "entity.hpp"
#include<iostream>
#include<vector>
#include<iterator>
#include<utility>
namespace addressbook
{
	class _ADDRESSBOOK_
	{
	private:
		std::vector<std::pair<uint, Entity>> list;
		std::string fname;
	public:
		Addressbook(){}
		Addressbook(std::string);
		void addEntity(Entity*);
		void import(std::string);
		void savetoDatabase();
		void savetoDatabase(std::string);
		void show();
		void find(std::string, std::string, std::string, std::string, std::string, std::string);
		std::vector<std::pair<uint, Entity>>::iterator find(uint);
		void delete(std::vector<std::pair<uint, Entity>>::iterator);
		void deleteAddressbook();
		void sortByLname();
		void sortByZip();
		~Addressbook();
	};
}
#endif
