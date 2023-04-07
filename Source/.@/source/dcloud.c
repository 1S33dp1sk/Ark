/// The d-cloud \\\
The D-cloud is a Layer-3 network

#include "2c/_h512.h"

#define __PASS_MAX_C 24
#define __PASS_MID_C 16
#define __PASS_MIN_C 8

void __udef_inp() {
	system("@cls||clear");
	printf("\t\t\tWelcome to 'd-cloud'\n\n");
}

int __udef_end() {
	printf("Hope you enjoyed d-cloud, goodbye.\n");
	_exit(0);
	return 0;
}

char const *__conv_addr(char *__pass){

}



int main(int argc,char const*argv[]) {
	ArcBuffer arcbuf;
	memset(&arcbuf,0,sizeof(ArcBuffer));
	arcbuf.level=0;
	__udef_inp();
	printf("enter your dcloud pass(or Y 'create a new account'):\n");
	ulong rd_size=read(0,arcbuf.__,__PASS_MAX_C);
	printf("read :%d\n",rd_size);
	if(rd_size==2){
		if(arcbuf.__[0]=='Y'){
			// printf("Creating account ...\n");
			// printf("Initialzing 'd-cloud' account ::\n\t%016x \n\t\t@%016x \n\t\t\t+%016x\n",0,0,0);
			printf("please enter 8 or more characters as a password:\n");
			rd_size=read(0,arcbuf.__,__PASS_MAX_C);
			if(rd_size>=8){
				printf("passcode :: %s\n",arcbuf.__);
				char const *kgev=__kgev(arcbuf.__);
				printf("Initialzing account { kgev : %s }\n",kgev);


			}
			else {
				printf("passcode must be at-least 8 characters\n");
			}
		}
	}
	else if(rd_size>__PASS_MIN_C) {
		if(rd_size<__PASS_MID_C) {
			printf("less than MID 16bytes :: %s\n",arcbuf.__);
		}
		else if (rd_size<__PASS_MAX_C) {
			printf("less than MAX 24bytes :: %s\n",arcbuf.__);
		}
	}
	return __udef_end();
}