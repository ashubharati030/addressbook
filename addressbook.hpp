#ifndef _ADDRESSBOOK_
#define _ADDRESSBOOK_
#include "entity.hpp"
#include<iostream>
#include<vector>
#include<iterator>
#include<utility>
namespace addressbook
{
	class Addressbook
	{
	private:
		std::vector<Entity*> list;
		std::string filename;
		const std::string database = "database/";
	public:
		Addressbook(){}
		Addressbook(std::string);
		void addEntity(Entity*);
		void import(std::string);
		void savetoDatabase();
		void savetoDatabase(std::string);
		void show();
		std::vector<Entity*>::iterator find(std::string, std::string, std::string, std::string, std::string, std::string);
		void deleteEntry(std::vector<Entity*>::iterator);
		void deleteAddressbook();
		void sortByLname();
		void sortByZip();
		static bool comparelname(Entity*, Entity*);
		static bool comparezip(Entity*, Entity*);
	};
}
#endif
