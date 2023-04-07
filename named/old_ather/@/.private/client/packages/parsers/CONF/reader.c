#include "config_reader.h"

int main(int argc, char **argv)
{
    if (!(argc >= 3)){return 0;}
    
    // Configuration File handle
    file_t file = {0};
    
    // Determine the "I/O operation" used in command line (CONFRD | CONFCHG | CONFDEL)
    if(!get_operation(&file, argv, argc)){return 0;}
    
    // Determine the "Options" used in command line such as [-n or -p]
    get_options(&file, argv, argc);
    
    // Execute I/O operation
    IO_executor(&file, argv);

    return 0;
}

