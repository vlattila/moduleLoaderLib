#include "modules.h"
#include <stdio.h>



int main()
{
	int i=0;
	char **fgv_list;
	void *handle;
	printf("Alpha test start!!!!!\n");
	handle = open_module("/home/murdock/Develop/C/modules/libhello.so",NORMAL);
 	char func_list[get_sizes(handle,NUM_OF_FUNC)][get_sizes(handle,LENGTH_FUNC_NAME)];
	func fun;
	get_funclist(func_list, handle);
	fun =  get_fgvptr(func_list[1],handle);
	for(i=0;i<get_sizes(handle,NUM_OF_FUNC);i++)
	{
		printf("%d %s\n",i,func_list[i]);
	}
 	fun();
	return 0;
}
