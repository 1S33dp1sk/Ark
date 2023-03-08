#ifndef __Karch_512__
#include "2c/_h512.h"
#include "2c/lbb.h"
#include "2c/ixr.h"
#define OUTPUT 1
#define LOG_ERR 1
#endif

extern char **environ;



int main(int argc, char **argv) {
	http_content *hc=crt_http_content("This is some cool text for the http header\n", __hct_text);
	log_content(hc);
};





