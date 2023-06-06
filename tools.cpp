#include "tools.h"

int get_cmd(char start,char end)
{
	printf("请输入指令:");
	while(1)
	{
		char cmd = getch();
		if(cmd >= start && cmd <= end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}
