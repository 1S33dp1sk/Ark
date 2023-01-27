#include "../helpers/helpers.h"

// Get key value used in CONFCHG operation
static void get_key_value(file_t *file, char **argv, int argc);
int get_operation(file_t *file, char **argv, int argc);
// Read Operation 
static void read_action(file_t *file, char **argv);
// Change Operation
static void change_action(file_t *file, char **argv);
// Delete Operation
static void delete_action(file_t *file, char **argv);

static void read_action(file_t *file, char **argv) {
    if (!get_file_data(file)){return;}
    if (!key_exist(file)){return;}
    printf("%s\n", get_value(file->data));
}
static void change_action(file_t *file, char **argv) {
    if (!get_file_data(file)){return;}
    if (!key_exist(file)){return;}
    if (!change_key_value(file)){return;}
}
static void delete_action(file_t *file, char **argv) {
    if (!get_file_data(file)){return;}
    if (!key_exist(file)){return;}
    if (!delete_key_value(file)){return;}
}
static void get_key_value(file_t *file, char **argv, int argc) {
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


static int get_operation(file_t *file, char **argv, int argc) {
    int status = 0; 
    file->_file->_name = AETHER_MAIN;
    if (!strcmp(argv[1], "RD") || !strcmp(argv[1], "rd")) {
        file->operation = READ;   
        
    }
    else if (!strcmp(argv[1], "CHG") || !strcmp(argv[1], "chg")) {
       file->operation = CHANGE;
       get_key_value(file, argv, argc);
    }
    else if (!strcmp(argv[1], "DEL") || !strcmp(argv[1], "del")) {
        file->operation = DELETE; 
    }
    else {
        status = 2;
    }
    file->key = (char*)argv[2];
    return status;
}
void get_options(file_t *file, char **argv, int argc) {
    int options = -1;
    opterr = 0; // Stop 'getopt' print error
    while ((options = getopt(argc, argv, "n:p:")) != -1) 
    {
        if ( !(optind >= argc) ){break;}
        switch (options) 
        {
            case 'n':
                strcat(optarg, FILENAME_EXTENSION);
                file->_file->_name = optarg;
                break;
            case 'p':
                strcat(optarg, FILENAME_EXTENSION);
                file->_file->_name = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s [-n, -p] [file...]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
}
void IO_executor(file_t *file, char **argv) {
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
