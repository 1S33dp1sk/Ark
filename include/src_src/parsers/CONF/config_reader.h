#ifndef CONFIGURATION_READER
#define CONFIGURATION_READER

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_FILENAME "default.conf"
#define FILENAME_EXTENSION ""
#define FILE_SIZE_BUFFER 6000

typedef enum
{
    READ = 1,
    CHANGE,
    DELETE,
}file_operation;

typedef struct file_tag
{
    char *filename;
    file_operation operation;
    int key_line_location;
    int file_size;
    char *key;
    char *value;
    char *data;
}file_t;


/*********************************************** 
 *          Static Helper Functions 
************************************************/
// Read Operation 
static void read_action(file_t *file, char **argv);
// Change Operation
static void change_action(file_t *file, char **argv);
// Delete Operation
static void delete_action(file_t *file, char **argv);
// Get key value used in CONFCHG operation
static void get_key_value(file_t *file, char **argv, int argc);
// Validates if the key exists
static bool key_exist(file_t *file);
// Gets the value of the key
static char *get_value(char *contents);
// Reads and stores the conf file data
static bool get_file_data(file_t *file);
// Changes the contents of a file
static bool change_key_value(file_t *file);
// Deletes the contents of a file
static bool delete_key_value(file_t *file);
// Determine the "I/O operation" used in command line (e.g., CONFRD | CONFCHG | CONFDEL)
bool get_operation(file_t *file, char **argv, int argc);
// Determine the "Options" used in command line such as [-n or -p]
// -n : <filename> in current directory
// -p : <filepath/filename> in any directory
void get_options(file_t *file, char **argv, int argc);
// Executes the I/O operation
void IO_executor(file_t *file, char **argv);


bool get_operation(file_t *file, char **argv, int argc)
{
    bool status = false;
    file->filename = DEFAULT_FILENAME;
    if (!strcmp(argv[1], "CONFRD"))
    {
        file->operation = READ;   
        status = true; 
    }
    else if (!strcmp(argv[1], "CONFCHG"))
    {
       file->operation = CHANGE;
       get_key_value(file, argv, argc);
       status = true;
    }
    else if (!strcmp(argv[1], "CONFDEL"))
    {
        file->operation = DELETE; 
        status = true;
    }
    file->key = (char*)argv[2];
    return status;
}

void get_options(file_t *file, char **argv, int argc)
{
    int options = -1;
    opterr = 0; // Stop 'getopt' print error
    while ((options = getopt(argc, argv, "n:p:")) != -1) 
    {
        if ( !(optind >= argc) ){break;}
        switch (options) 
        {
            case 'n':
                strcat(optarg, FILENAME_EXTENSION);
                file->filename = optarg;
                break;
            case 'p':
                strcat(optarg, FILENAME_EXTENSION);
                file->filename = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s [-n, -p] [file...]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
}

void IO_executor(file_t *file, char **argv)
{
    switch(file->operation)
    {
        case READ:
            read_action(file, argv);
            break;
        case CHANGE:
            change_action(file, argv);  
            break;
        case DELETE:
            delete_action(file, argv);
            break;    
    }

}

static void read_action(file_t *file, char **argv)
{
    if (!get_file_data(file)){return;}
    if (!key_exist(file)){return;}
    printf("%s\n", get_value(file->data));
}

static void change_action(file_t *file, char **argv)
{
    if (!get_file_data(file)){return;}
    if (!key_exist(file)){return;}
    if (!change_key_value(file)){return;}
}
static void delete_action(file_t *file, char **argv)
{
    if (!get_file_data(file)){return;}
    if (!key_exist(file)){return;}
    if (!delete_key_value(file)){return;}
}

static void get_key_value(file_t *file, char **argv, int argc)
{
    if (argc >= 4)
    {
        int len = strlen(argv[3]);
        char *temp = argv[3];
        int space_number = 1;
        // Determines if no option(-n, -p, etc) is present at the KEY position
        if (strchr(argv[3], '-') == NULL)
        {
            // Removes all the spacing inside the key
            while( temp[len-space_number] == ' ')
            {
                temp[len - space_number] = '\0';
                space_number++;
            } 
            file->value = argv[3];
        }
    }
}

static bool key_exist(file_t *file)
{ 
    int count_line = 1;
    char *key = strtok(file->data, ":");
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

static char *get_value(char *contents)
{
    char *value = strtok(NULL, "\n");
    value++;
    return value;
}

static bool get_file_data(file_t *file)
{
    bool status = false;
    FILE *f_ptr;
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

static bool change_key_value(file_t *file)
{
    bool status = false;
    
    // Store the desired key(e.g KEY_3) in the command line [e.g CONFCHG KEY_3]
    // else it will be lost with the next read
    char *key = file->key;
    
    // Read the file again
    get_file_data(file);

    int count = 0; // number of characters per line
    int line = 1;  // Number of lines
    int before_count = 0;
    int desired_line_count = 0;
        
    // Operation to obtain the total number of characters before the desired key is reached.
    while(line != file->key_line_location)
    {
        while(file->data[count] != '\n')
        {
            count++;
        }
        line++;  // Increment based on the number of lines        
        count++; // To skip over '\n' to read the next line of characters
    }
    // Stores the total number of characters before the desired key is reached. 
    before_count = count;
    
    while(file->data[before_count] != '\n')
    {
            before_count++;
    }
    // The total number of characters in the line of the desired key
    desired_line_count = before_count - count;
    // Write before and new data only

    // Deletes the file
    if ( !remove(file->filename) == 0)
    {
        printf("deletion not successful.\n");
    }

    // Creates the new file
    FILE *f_ptr;
    f_ptr = fopen(file->filename, "w+");
    if (f_ptr == NULL){return status;}
    int i = 0;
    // Write before new data
    while(i < count)
    {
        fprintf(f_ptr, "%c", file->data[i]);
        i++;
    }
    // New data
    int after = fprintf(f_ptr, "%s:=%s",key, file->value);
    // After new data
    i = after + count;
    i -= (after - desired_line_count);
    while(i < file->file_size)
    {
        fprintf(f_ptr, "%c", file->data[i]);
        i++;
    }
    fclose(f_ptr);
    status = true;
    return status;
}
static bool delete_key_value(file_t *file)
{
    bool status = false;
    char *key = file->key;
    get_file_data(file);
    int count = 0; // number of characters per line
    int line = 1;  // Number of lines
    while(line != file->key_line_location)
    {
        while(file->data[count] != '\n')
        {
            count++;
        }
        line++; // Increment based on the number of lines        
        count++; // To skip over '\n' to read the next line of characters
    }
    int before_count = count;
    while(file->data[before_count] != '\n')
    {
            before_count++;
    }
    int desired_line_count = before_count - count;
    // Deletes the file
    if ( !remove(file->filename) == 0)
    {
        printf("Deletion not successful.\n");
    }
    // Creates the new file
    FILE *f_ptr;
    f_ptr = fopen(file->filename, "w+");
    if (f_ptr == NULL){return status;}
    int i = 0;
    // Write before new data
    while(i < count)
    {
        fprintf(f_ptr, "%c", file->data[i]);
        i++;
    }
    // New data
    int after = fprintf(f_ptr, "%s:=\"NE\"",key);
    // After new data
    i = after + count;
    i -= (after - desired_line_count);
    while(i < file->file_size)
    {
        fprintf(f_ptr, "%c", file->data[i]);
        i++;
    }
    fclose(f_ptr);
    status = true;
    return status;
}



#endif
