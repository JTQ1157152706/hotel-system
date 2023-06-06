#ifndef ROOM_H
#define ROOM_H

#include "guest.h"

class Room
{
	int id;			//	房号
	int type;		//	房型
	double price;	//	房价
	int guest_cnt;	//	入住数
	Guest** guests;	//	房客指针
public:
	Room(int id,int type,double price):id(id),type(type),price(price),guest_cnt(0)	
	{
		guests = new Guest*[type];
	}
	
	bool cmp_id_room(int id)
	{
		return this->id == id;
	}
	
	bool is_empty_room(void)
	{
		return 0 == guest_cnt;
	}
	
	bool check_in_room(Guest* guest)
	{
		if(guest_cnt >= type) return false;
		guests[guest_cnt++] = guest;
		return true;
	}
	
	bool check_out_room(void)
	{
		if(0 == guest_cnt) return false;
		for(int i=0; i<guest_cnt; i++)
		{
			delete guests[i];
			guests[i] = NULL;
		}
		guest_cnt = 0;
		return true;
	}
	
	void show(void)
	{
		cout << id << " " << type << " " << price << endl;
		for(int i=0; i<guest_cnt; i++)
		{
			cout << "    旅客" << i+1 << ":";
			guests[i]->show();
		}
	}
};

#endif//ROOM_H

