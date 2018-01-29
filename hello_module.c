#include <stdio.h>
#include <string.h>
#include <stdint.h>


#define NAME_LENGTH 20
#define NUM_OF_FUNC 5

////////////////////////////////SUPPORT//////////////////////////////////////
void info() //visual fieedback for developer not required
{
	printf("info\nget_infolist\nhello\nprint_arglist\n");
};

int get_sizes(int dimension){
	if(dimension){
		return NUM_OF_FUNC;
	}else{
		return	NAME_LENGTH;
	}
}


int get_infolist(uint8_t extern_list[NUM_OF_FUNC][NAME_LENGTH])
{
	int i;
	uint8_t fgv_list[NUM_OF_FUNC][NAME_LENGTH] = {"info\0","get_sizes\0","get_infolist\0","hello\0","print_arglist\0"};
	for(i=0;i<NUM_OF_FUNC;i++){
		memset(extern_list[i],0,sizeof(extern_list[i]));
		strcpy((char*)extern_list[i],(char*)fgv_list[i]);	
	}
	return 0;
};

void print_arglist()
{
//TODO IT'S ONLY TEST 
	printf("void info(void)\nvoid hello()\nchar** get_infolist()\nprint_arglist()");
};


///////////////////////////////////REAL CONTENT/////////////////////////////////
void hello()
{
	printf("Hello\n");
};
