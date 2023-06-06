#include <cstdlib>
#include "hotel.h"
#include "tools.h"

Hotel Hotel::hotel; //	静态成员变量类外定义

//	加载酒店信息
bool Hotel::load_hotel(const char* path)
{                                        
	FILE* frp = fopen(path,"r");
	if(NULL == frp)
	{
		perror("fopen");
		return false;
	}
	
	//	读取层数
	fscanf(frp,"%d",&level_cnt);
	
	//	申请每层房间数内存
	room_cnt = new int[level_cnt];
	//	申请每层房间指针内存
	rooms = new Room**[level_cnt];
	
	//	读取每层每个房间信息
	for(int i=0; i<level_cnt; i++)
	{
		//	读取第i层房间数
		fscanf(frp,"%d",&room_cnt[i]);
		//	分配第i层房间指针内存
		rooms[i] = new Room*[room_cnt[i]];
		for(int j=0; j<room_cnt[i]; j++)
		{
			int id;
			int type;
			double price;
			fscanf(frp,"%d %d %lf",&id,&type,&price);
			rooms[i][j] = new Room(id,type,price);
			//rooms[i][j]->show();
		}		
	}
	return true;
}

//	菜单
int Hotel::menu_hotel(void)
{
	system("clear");
	cout << "***欢迎使用指针酒店系统***" << endl;
	cout << "1、入住   2、退房" << endl;
	cout << "3、查询   4、查看" << endl;
	cout << "5、退出" << endl;
	return get_cmd('1','5');
}

//	酒店运行	
void Hotel::start_hotel(void)
{
	while(true)
	{
		switch(menu_hotel())
		{
			case '1':	check_in_hotel();	break;
			case '2':	check_out_hotel();	break;
			case '3':	query_hotel();	break;
			case '4':	list_empty_hotel();	break;
			case '5':	return;
		}
	}
}

Room* Hotel::find_room_hotel(int room_id)
{
	for(int i=0; i<level_cnt; i++)
	{
		for(int j=0; j<room_cnt[i]; j++)
		{
			if(rooms[i][j]->cmp_id_room(room_id))
				return rooms[i][j];
		}
	}
	return NULL;
}

//	入住		
bool Hotel::check_in_hotel(void)
{
	cout << "请输入入住房间号:" ;
	int room_id;
	cin >> room_id;
	Room* room = find_room_hotel(room_id);
	if(NULL == room)
	{
		cout << "未找到房间" << room_id << " 请检查!" << endl;
		return false;
	}
	
	cout << "请输入旅客姓名、性别、身份证号:";
	string name,id;
	char sex;
	cin >> name >> sex >> id;
	Guest* guest = new Guest(name,sex,id);
	if(false == room->check_in_room(guest))
	{
		cout << "房间已满，请重试!" << endl;
		delete guest;
		return false;
	}
	cout << "入住成功!" << endl;
	return true;
}

//	退房	
bool Hotel::check_out_hotel(void)
{
	cout << "请输入退房房间号:" ;
	int room_id;
	cin >> room_id;
	Room* room = find_room_hotel(room_id);
	if(NULL == room)
	{
		cout << "未找到房间" << room_id << " 请检查!" << endl;
		return false;
	}
	
	if(!room->check_out_room())
	{
		cout << "该房间为空，请检查!" << endl;
		return false;
	}
	cout << "房间" << room_id << "退房成功！" << endl;
	return true;
}

//	查看空房	
void Hotel::list_empty_hotel(void)
{
	for(int i=0; i<level_cnt; i++)
	{
		for(int j=0; j<room_cnt[i]; j++)
		{
			if(rooms[i][j]->is_empty_room())
			{
				rooms[i][j]->show();
			}
		}
	}
}

//	查询房间信息
void Hotel::query_hotel(void)
{
	for(int i=0; i<level_cnt; i++)
	{
		for(int j=0; j<room_cnt[i]; j++)
		{
			if(!rooms[i][j]->is_empty_room())
			{
				rooms[i][j]->show();
			}
		}
	}
}
		
