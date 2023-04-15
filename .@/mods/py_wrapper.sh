#!/usr/bin/bash

# define colors for a cool ux
NC='\033[0m'
VIOLET='\033[1;94m'
GREY='\033[1;37m'
RED='\033[0;31m'
GREEN='\033[1;32m'

# execute the script with 
# generality and output the exit
# status code
python3 $@ << 'EOF'
from sys import exit
#exit codes from the exec and the bash script
#acts as a kind of mutex(mutual exclusion object)
exit(0x0A)

EOF

EXIT_STATUS=$?

if [ ${EXIT_STATUS} -ne 0 ]; then
    printf  "${VIOLET}Aether${NC} :: ${RED}ERROR${NC} : __CLIENT__ EXIT STATUS NOT 0 -> ${GREY}0xAether client cannot execute non-zero exit codes${NC}\n"
    exit ${EXIT_STATUS}  # exit the bash script with the same status
fi
SCRPT_NAME=$1
BASE_NAME=$(basename $SCRPT_NAME)
EXEC_NAME=${BASE_NAME%%.*}
printf "${VIOLET}Aether${NC} :: ${GREEN}COMPLETED${NC} -> ${GREY}Executed ${EXEC_NAME} gracefully${NC}.\n"
