#ifndef GUEST_H
#define GUEST_H

#include "tools.h"

class Guest
{
	string name;	
	char sex;
	string id;
public:
	Guest(const string& name="",char sex='\0',const string& id=""):name(name),sex(sex),id(id){}
	
	void show(void)
	{
		cout << name << " " << sex << " " << id << endl;
	}
};

#endif//GUEST_H
