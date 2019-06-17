#include "utils/commandline.h"

extern CommandLine cmdline;
extern int sinal = 0;


uint16_t cmd_info(uint16_t argc, uint8_t *argv8[]){
	const char **argv=(const char **)argv8;
	uint16_t size=0;
	char* buffer=(char*)argv[0];

	if(argc==1){
		size+=sprintf(buffer+size, "USB_Gentil\r\n");
		sinal = sianl ^ 1;
	} else {
		size+=sprintf(buffer+size, "Syntax: info\r\n");
	}
	return size;
}


CommandLine cmdline({"vai"},
					{cmd_info});
