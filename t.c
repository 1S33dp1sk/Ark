#include <unistd.h>
#include <stdio.h>
int main(){
	char *_e[] = { "entry.ath" };
	char *__e[] = {""};
	int _execval = execve( "/usr/bin/python3" , __e , _e );
	printf("execution returns :: %d\n\n");
}
