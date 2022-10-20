#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_SIZE_BUFFER 10000

typedef enum 
{
    READ = 1,
    CHANGE,
    DELETE,
}file_operation;

typedef struct file_tag
{
    file_operation operation;
    int key_line_location;
    char *key;
    char *value;
    a_file *_file;
}file_t;


/*********************************************** 
 *          Static Helper Functions 
************************************************/

// Validates if the key exists
static int key_exist(file_t *file);
// Reads and stores the conf file data
static int _file_contents(a_file *file);
// Changes the contents of a file
static int change_key_value(file_t *file);
// Deletes the contents of a file
static int delete_key_value(file_t *file);
// matches&returns chars until `matcher`
static char *append_till_match( char *string_match , char *matcher );
// Gets the value of the key
static char *get_value(char *contents);




static int key_exist(file_t *file) { 
    int count_line = 1;
    char *key = strtok(file->_file->_contents, ":");
    if (!strcmp(key, file->key)) {
        file->key_line_location = count_line;
        return 0;
    }
    while( (strcmp(key, file->key)) ) {
        key = strtok(NULL, "\n");
        key = strtok(NULL, ":");
        if (key == NULL) {
            return 2;
        }
        count_line++;
    }
    file->key_line_location = count_line;
    return 2;
}

static int _file_contents(a_file *file) {
    int status = 2;
    char buffer[FILE_SIZE_BUFFER] = {0};
    FILE *f_ptr = malloc( AETHER_FILE_BUFFER );
    f_ptr = fopen( file->_name , "r");
    
    if (f_ptr == NULL){
        return status;
    }
    else{
        status = 0;
    }
    while (!feof(f_ptr)) {
        fread(buffer, sizeof(buffer), 1, f_ptr);
    }
    file->_size = ftell(f_ptr);
    fclose(f_ptr);
    file->_contents = &buffer[0];
    return status;
}

static int get_file_data( file_t *file ) {
    int status = 2;
    FILE *f_ptr;
    char buffer[FILE_SIZE_BUFFER] = {0};
    f_ptr = fopen( file->_file->_name , "r");
    if (f_ptr == NULL){return status;}
    status = 0;
    while (!feof(f_ptr))
    {
        fread(buffer, sizeof(buffer), 1, f_ptr);
    }
    file->_file->_size = ftell(f_ptr);
    fclose(f_ptr);
    file->_file->_contents = &buffer[0];
    return status;
}

static int change_key_value(file_t *file) {
    int status = 2;
    
    // Store the desired key(e.g KEY_3) in the command line [e.g CONFCHG KEY_3]
    // else it will be lost with the next read
    char *key = file->key;
    
    // Read the file again

    _file_contents(file->_file);

    int count = 0; // number of characters per line
    int line = 1;  // Number of lines
    int before_count = 0;
    int desired_line_count = 0;
        
    // Operation to obtain the total number of characters before the desired key is reached.
    while(line != file->key_line_location)
    {
        while((file->_file)->_contents[count] != '\n')
        {
            count++;
        }
        line++;  // Increment based on the number of lines        
        count++; // To skip over '\n' to read the next line of characters
    }
    // Stores the total number of characters before the desired key is reached. 
    before_count = count;
    
    while(file->_file->_contents[before_count] != '\n')
    {
            before_count++;
    }
    // The total number of characters in the line of the desired key
    desired_line_count = before_count - count;
    // Write before and new data only

    // Deletes the file
    if ( !remove(file->_file->_name) == 0)
    {
        printf("deletion not successful.\n");
    }

    // Creates the new file
    FILE *f_ptr;
    f_ptr = fopen(file->_file->_name, "w+");
    if (f_ptr == NULL){return status;}
    int i = 0;
    // Write before new data
    while(i < count)
    {
        fprintf(f_ptr, "%c", file->_file->_contents[i]);
        i++;
    }
    // New data
    int after = fprintf(f_ptr, "%s:=%s",key, file->value);
    // After new data
    i = after + count;
    i -= (after - desired_line_count);
    while(i < file->_file->_size)
    {
        fprintf(f_ptr, "%c", file->_file->_contents[i]);
        i++;
    }
    fclose(f_ptr);
    status = 0;
    return status;
}

static int delete_key_value(file_t *file) {
    int status = 2;
    char *key = file->key;
    _file_contents(file->_file);
    int count = 0; // number of characters per line
    int line = 1;  // Number of lines
    while(line != file->key_line_location)
    {
        while(file->_file->_contents[count] != '\n')
        {
            count++;
        }
        line++; // Increment based on the number of lines        
        count++; // To skip over '\n' to read the next line of characters
    }
    int before_count = count;
    while(file->_file->_contents[before_count] != '\n')
    {
            before_count++;
    }
    int desired_line_count = before_count - count;
    // Deletes the file
    if ( !remove(file->_file->_name) == 0)
    {
        printf("Deletion not successful.\n");
    }
    // Creates the new file
    FILE *f_ptr;
    f_ptr = fopen(file->_file->_name, "w+");
    if (f_ptr == NULL){return status;}
    int i = 0;
    // Write before new data
    while(i < count)
    {
        fprintf(f_ptr, "%c", file->_file->_contents[i]);
        i++;
    }
    // New data
    int after = fprintf(f_ptr, "%s:=\"NE\"",key);
    // After new data
    i = after + count;
    i -= (after - desired_line_count);
    while(i < file->_file->_size)
    {
        fprintf(f_ptr, "%c", file->_file->_contents[i]);
        i++;
    }
    fclose(f_ptr);
    status = 0;
    return status;
}

static char *append_till_match( char *string_match , char *matcher ) {
    char *ptr;
    for( int i=0; i<strlen( string_match ); i++ ) {
        ptr[i] = string_match[i];
        if ( strstr( ptr , matcher ) ) {
            ptr[i+1] = '\0';
            break;
        }
    }   
    return ptr;
}

static char *get_value(char *contents) {
    char *value = strtok(NULL, "\n");
    value++;
    return value;
}
