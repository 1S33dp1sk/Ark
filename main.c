#include "aether.h"

/**
 * aether is a two choice system, with a current default value.
 * choice 1 :
 *      mor ( mirror or reply )
 * choice 2 :
 *      les ( listen evaluate send )
 * current : 
 *      .aether 
 * 
 * There's no need for security configurations as the system is isolated
 * with it's own user, sockets, listeners, repliers, etc... . 
 * 
 * 
 * the .aether file found here is the default value that the instance starts with,
 * that is the current `les`.
 * 
 * the mor instance will evaluate any request incoming.
 * 
 * mor -> les <- .aether = les -> aether
 * 
 * 
 * any type of socket ( server-types ) can relay .aether requests to the local socket.
 * the request is simple :
 * 
 *      PATH:=
 *      CONNC:=
 *      CALL:=
 *      ENTRY { }
 * 
 * entry can contain any executable, script, function, command, etc... .
 * an entry can be 
 * 
 *      ENTRY {
 *          ##!/bin/bash
 *          echo pretty cool
 *          #python3 test.py 
 *      }
 * 
 * the aether is a system-wide user than can only execute in it's own directory.
 * 
 * to gain shell access, a signed message must be provided, based on the entry requirements
 * of that node.
 * 
 * 
 */


int main(int argc, char *argv[]) {
    int __ = argc > 1 ? super_fast_hash( argv[1] , strlen( argv[1] ) ) : 0;

    switch( __ ) {
        case 0:
            break;
        case 0x9eefc5c9:
            mor( argc , argv );
            break;
        case 0x350647ed:
            les( argc , argv );
            break;
        default:
            break;
    }

    // les( argc , argv );
    // mor( argc , argv );
    return 0;
}




