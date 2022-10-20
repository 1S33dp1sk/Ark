#ifndef JSON_PARSER_H
#define JSON_PARSER_H


#include "../helpers/helpers.h"

/* Note: Configuration File should never have an empty line at the bottom!!! */
#define JSON_FILE_EXTENSION ".json"

typedef struct
{
	char *filename;
	char *conf_data;
}json_handle;

void json_read_conf_file(json_handle *file);
void json_parser(json_handle *file);

#endif

