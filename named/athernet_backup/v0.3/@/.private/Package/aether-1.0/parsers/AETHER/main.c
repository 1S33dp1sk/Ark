#include "aether.h"

static bool get_file_data(); //file_t *file
static bool key_exist(file_t *file);
void pprint(char *contents);
static char *get_value(char *contents);
int aether_path();





int main(int argc, char const *argv[])
{
	// char *ptr = ".aether/230dd42fdc9d1a06ae36f490d512ab9f";
	// printf( "%s\n" , ptr );

	// printf( "%ld\n" , sizeof(ptr) );

	// aether_dir();

	aether_path();

	//uid_t p = geteuid();  // Check for NULL!
	//printf("User name: %d\n", p);

	printf( "End execution\n" );
	return 0;
}


int aether_path() {

	char working_dir[1000];
	// check current link to aether
	if ( getcwd( working_dir , sizeof( working_dir ) ) != NULL ) {
		// .aether dir check
		if ( strstr( working_dir , _AETHER_ ) != NULL ) {
			
		}		
	}

}



int aether_dir() {
	char cwd[43];
	char *ptr = ".aether/230dd42fdc9d1a06ae36f490d512ab9f";

   if (getcwd(cwd, sizeof(cwd)) != NULL) {
   		if (strstr(cwd, _AETHER_) != NULL) {
   			if(access(".aether",F_OK) == 0 ) {
   				file_t file = {0};
   				file.filename = ".aether";
   				file.key = "CONNEC";
   				// printf("hmmm file name is : %s\n", file.filename);
   				if ( get_file_data(&file) ) {
   					// printf("data by yours truly (mr kj ) : \n%s\n", file.data);
   					key_exist(&file);
   					char *value = get_value(file.data);
					// printf("%s\n", value);
					pprint(value);
   				}
   				printf("We are good to go\n");
   			}else{
   				printf("not so good\n");
   			}
   		}
   		else{
   			perror("Not in aether");
   			// exit(1);
   		}
   } else {
       perror("getcwd() error");
       return 1;
   }
   return 0;
}


static bool get_file_data(file_t *file) {
    bool status = false;
    FILE *f_ptr;
    file->filename = AETHER_MAIN;
    char buffer[FILE_SIZE_BUFFER] = {0};
    f_ptr = fopen(file->filename, "r");
    if (f_ptr == NULL){return status;}
    status = true;
    while (!feof(f_ptr))
    {
        fread(buffer, sizeof(buffer), 1, f_ptr);
    }
    file->file_size = ftell(f_ptr);
    fclose(f_ptr);
    file->data = &buffer[0];
    return status;
}


static bool key_exist(file_t *file) { 
    int count_line = 1;
    char *key = strtok(file->data, ":=");
    if (!strcmp(key, file->key))
    {
        file->key_line_location = count_line;
        return true;
    }
    while( (strcmp(key, file->key)) )
    {
        key = strtok(NULL, "\n");
        key = strtok(NULL, ":");
        if (key == NULL)
        {
            return false;
        }
        count_line++;
    }
    file->key_line_location = count_line;
    return true;
}


void pprint(char *contents) {
	char *pch;
	printf ("Splitting string \"%s\" into tokens:\n",contents);
	pch = strtok (contents," ,");
	while (pch != NULL) {
		printf ("%s\n",pch);
		pch = strtok (NULL, " ,");
	}
	return;
}



static char *get_value(char *contents) {
    char *value = strtok(NULL, "\n");
    value++;
    return value;
}

