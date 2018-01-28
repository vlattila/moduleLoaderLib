#ifndef MODULES_H
#define MODULES_H

#define DEBUG 1
#define NORMAL 0

#define LENGTH_FUNC_NAME 0
#define NUM_OF_FUNC 1

typedef void (*func)(void);

void error_handler(const char*,const char*);
void* open_module(const char* name_of_module, int print_info); 
func get_fgvptr(char* fgv_name,void* handle);
int get_funclist(char**,void*);
int get_sizes(void* handle,int dimension);
#endif
