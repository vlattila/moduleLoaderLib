#include "modules.h"

#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>



void error_handler(const char* err_text, const char* err_type)
{
	printf("Error: %s %s",err_text,err_type);
	exit(-1);
};

void* open_module(const char* name_of_module,int print_info)
{
	void *handle;
	void (*info)();
	
	if(access(name_of_module,F_OK)== -1)
	{
		error_handler("File dosen;t exist!",name_of_module);
	}	
	
	handle = dlopen(name_of_module, RTLD_LAZY);
	
	if(!handle)
	{
		error_handler("Can't open the", name_of_module);
	}
	printf("=====The opening was succesfully=====\n");
	info = dlsym(handle,"info");
	
	if(print_info)
	{
		if(info)
		{
			info();
		}else{
			error_handler("Didn't found [ info ] function","\n");
		}
	}
	return handle;
};

func get_fgvptr(char* fgv_name, void* handle)
{	
	int i;
	uint8_t fgvNameList[get_sizes(handle,NUM_OF_FUNC)][get_sizes(handle,LENGTH_FUNC_NAME)];
	void (*temp)(void);
	int (*get_list)(uint8_t**) = dlsym(handle,"get_infolist");
	int num_of_function = get_list(fgvNameList);
//	for(i=0;i<num_of_function;i++ ){
//		printf("-> %s\n",fgvNameList[i]);
//	}
	temp = dlsym(handle, fgv_name);
	return temp;
}

int get_funclist(char** extern_list,void* handle)
{
	int (*get_list)(uint8_t**) = dlsym(handle,"get_infolist");
	int num_of_function = get_list(extern_list);                           
	return num_of_function;
}

int get_sizes(void* handle,int dimension)
{
	int (*function)(int) = dlsym(handle,"get_sizes");
	return function(dimension);
}

