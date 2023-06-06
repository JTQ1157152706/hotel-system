#include "hotel.h"

int main(int argc,const char* argv[])
{
	Hotel& hotel = Hotel::get_hotel();
	if(2 != argc)
	{
		cout << "User: ./HMS <info_path>" << endl;
		return 0;
	}	
	if(!hotel.load_hotel(argv[1]))
	{
		cout << "info_path wrong!" << endl;
		return 0;
	}
	hotel.start_hotel();
}
