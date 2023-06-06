#ifndef HOTEL_H
#define HOTEL_H

#include "room.h"

class Hotel
{
	static Hotel hotel;	//	静态对象
	int level_cnt;		//	 层数
	int* room_cnt;		//	 每层房间数
	Room*** rooms;		//   房间类指针
	
	Hotel(void){}		//	私有化构造函数
	Hotel(const Hotel& that){}

public:
	static Hotel& get_hotel(void)	//	获取单例接口函数
	{
		return hotel;
	}
	
	bool load_hotel(const char* path);	//	加载酒店信息
	int menu_hotel(void);		//	菜单
	void start_hotel(void);		//	酒店运行
	Room* find_room_hotel(int room_id);	//	找房间
	bool check_in_hotel(void);	//	入住
	bool check_out_hotel(void);	//	退房
	void list_empty_hotel(void);//	查看空房
	void query_hotel(void);		//	查询房间信息
};

#endif//HOTEL_H



