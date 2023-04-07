#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* Note: Configuration File should never have an empty line at the bottom!!! */
#define FILE_SIZE 6000
#define JSON_FILE_EXTENSION ".json"

typedef struct json_handle_tag
{
	char *filename;
	char *conf_data;
}json_handle;

void json_read_conf_file(json_handle *file);
void json_parser(json_handle *file);

#endif

