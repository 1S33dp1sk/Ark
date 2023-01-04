#include "json_parser.h"

static int i = 0; 
static int len = 0;

static int bool_len = 0;
static int bool_value = 0;

static void json_executor(FILE *f_ptr, char *temp);

void json_read_conf_file(json_handle *file)
{
  FILE* file_;
  static char buffer[FILE_SIZE] = {0};
  file_ = fopen(file->filename, "r");
  if (file_ == NULL){return;}
  while (!feof(file_))
  {
    fread(buffer, sizeof(buffer), 1, file_);
  }
  fclose(file_);
  file->conf_data = &buffer[0];
}

void json_parser(json_handle *file)
{
	FILE *f_ptr;
	strcat(file->filename, JSON_FILE_EXTENSION);
    	f_ptr = fopen(file->filename, "w+");
    	if (f_ptr == NULL){return;}
	
	char *temp = file->conf_data;
	
	// Search for the 1st key
	temp = strtok(temp, ":");
	// Prints the First key
	fprintf(f_ptr, "{\n\t");
	fprintf(f_ptr, "\"%s\" : ", temp);
	
	// Finds the First value
	temp = strtok(NULL, "\n");
	json_executor(f_ptr, temp);
	
	while(1)
	{
		// Find the next KEY
		temp = strtok(NULL, ":");
		if(temp == NULL){break;}
		// Prints the next KEY
		fprintf(f_ptr, "\n\t\"%s\" : ", temp);
		// Find the next VALUE
		temp = strtok(NULL, "\n");
		if(temp == NULL){break;}
		json_executor(f_ptr, temp);
	}
	fprintf(f_ptr, "\n}\n");	
	fclose(f_ptr);
}

static void json_executor(FILE *f_ptr, char *temp)
{
	// NE check 
	if( ((*temp++) == '=') & ( (*temp == ' ') | (*temp == '\0') ) )
	{
		fprintf(f_ptr, "\"NE\",");	
	}
	// Numbers & Boolean check
	else if( (!strchr(temp, ',')) & (isdigit(*temp) > 0) )
	{
		bool_len = strlen(temp);
		bool_value = atoi(temp);
		// Boolean
		if( (bool_len == 1) & ((bool_value == 0) | ( bool_value == 1)) )
		{
			bool_value?fprintf(f_ptr, "True,"): fprintf(f_ptr,"False,");
		}
		// Numbers or Strings
		else
		{
			bool status = true;
			int counter = 0;
			int digit_checking = 0;
			while(counter < bool_len)
			{
				digit_checking = isdigit(*temp);
				if(digit_checking == 0)
				{
					status = false;
					break;
				}
				temp++;
				counter++;
			}
			// Revert to correct location
			for(int i = 0; i < counter; i++)
			{
				temp--;
			}
			
			// Print as numbers 
			if(status)
			{
				fprintf(f_ptr, " %s,", temp);
			}
			
			// Print as a string
			else if(!status)
			{
				if(*temp == '"')
				{
					fprintf(f_ptr, "%s,", temp);
				}
		
				else
				{
					fprintf(f_ptr, "\"%s\",", temp);
				}
			
			}

		}	
	}
	// Arrays check
	else if(strchr(temp, ','))
	{
		len = strlen(temp);
		i = 0;
		fprintf(f_ptr, "[\"");
		while(i < len)
		{
			if(*temp == ',')
			{
				fprintf(f_ptr, "\",\"");
			}
			else
			{
				fprintf(f_ptr, "%c", *temp);
			}
			temp++;
			i++;
		}
		fprintf(f_ptr,"\"");
		fprintf(f_ptr,"],");
	}
	// Strings check
	else if(!strchr(temp, ',')  ) 
	{
		if(*temp == '"')
		{
			fprintf(f_ptr, "%s,", temp);
		}
		
		else
		{
			fprintf(f_ptr, "\"%s\",", temp);
		}
	}
}
