#include "json_parser.h"

int main(int argc, char const *argv[])
{
	if( !(argc > 1)){return 0;}

	json_handle json = {0};
	json.filename = (char*)argv[1];
	json_read_conf_file(&json);
	json_parser(&json);
			
	return 0;
}

