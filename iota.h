typedef 
    enum {
        NO_SPEC = '\0',
        _0_ather = '@',
        _1_ather = '.',
        _2_ather = '/',
        _3_ather = '0'
} __k ;

#define K_LEVEL __k;


/**
 * first version
 * should be dynamic and k-dependent solution as in func( k , apath** , ... )
 * however, it's 4:26am and i really do not want to deal with permissions
 * because path_k dependenecy allow for manipulation
 * i.e: if we name the paths they are only accessible 
 * via their reference name after being compiled, however
 * if we create a `**` , it's cumbersome to assume that
 * we can protect the integerity of viewership at **&x->next
 */
#ifndef IApath
    #define IApath "i@path"

//first thing is first
// we need a name for iota
#define NAME_LIMIT 512
typedef 
    struct {
        char ia_name[NAME_LIMIT];
        uint32_t ia_pid;
} _ia_p0;


// second we need to get
// the current sys path
#define PATH_LIMIT_MAX 4096
typedef 
    struct {
        _ia_p0 __path;
        char ia_path[PATH_LIMIT_MAX];
        char ia_shell[PATH_LIMIT_MAX];
} _ia_p1;

// #if !defined( INET6_ADDRSTRLEN )
//     #include <arpa/inet.h>
// #endif
// //third lets get the ip as a str
// // so we can use sockets and whatnot
// typedef 
//     struct {
//         _ia_p1 __path;
// #define ia_name __path.ia_name
// #define ia_path __path.ia_path
//         char ia_ip[INET6_ADDRSTRLEN];
//         uint32_t ia_request;
// } _ia_p2;

// #define ADDR_CID_MAX 128
// #define ENTRY_MAX 8196
// //fourth -for now, let's get the
// // blockchain address so we can sign
// typedef 
//     struct {
//         _ia_p2 __path;
// #define ia_name __path.ia_name
// #define ia_path __path.ia_path
// #define ia_ip __path.ia_ip
//        char ia_addr[ADDR_CID_MAX];
//         uint32_t ia_submit;
// } _ia_p3;

// #endif

#include <aio.h>
typedef 
    union {
       _ia_p0 __0;
       _ia_p1 __1;
       // _ia_p2 __2;
       // _ia_p3 __3;
    } 
iota;



#include <stdarg.h>
// The IOTA
/**
<<<<<<< HEAD
 * such as with the physical universe & max planks constant; 
 * we can in any K-system define a certain limit to what is the most
 * infatistimaly small default ( IOTA )
 * In order to define the default , one should define the IOTA completely 
=======
 * such as with max planks constant, we can in any
 * system define a certain limit to what is the most
 * infatistimaly small amount ( IOTA )
 * But, we have to define the IOTA completely 
>>>>>>> 52885d5 (c.*ather*)
 * which is defined under ( Input Output Transfer Ather )
 * which is whats the wrapper holding the IOTA in question 
 **/
uint32_t the_t( uint32_t __fd , unsigned char *__ ) {
    uint32_t _size = 0;
    *__++ = _0_ather;
    _size += 1;
    return write( __fd , __ , _size );
}
unsigned char the_u( uint32_t __fd , char *__ ) {
    if ( read( __fd , __ , 1 ) > 0 ) {
        switch ( *__++ ) {
            case _0_ather:
                printf( "0@ather\n" );
                break; 
            case _1_ather:
                printf( "1.ather\n" );
                break; 
            case _2_ather:
                printf( "2/ather\n" );   
                break; 
            case _3_ather:
                printf( "0xather\n" );
                break;
        }
        return _0_ather;
    }
    return NO_SPEC;
}
uint32_t the_r( uint32_t __fd , unsigned char *__ , ... ) {
    va_list __vars;
    uint32_t read_size = read( __fd , __ , 1 );
    return read_size;
}




// // binary interface 
// // invoke , ABI , pack , etx..
// // adaptive based on the system 
// #define i16( __ , _ ) __I( __ , _ , 0 ) // 16-bit comms
// #define i32( __ , _ ) __I( __ , _ , 2 ) // 32-bit comms
// #define i64( __ , _ ) __I( __ , _ , 6 ) // 64-bit comms
// // binary mirror
// // reply , ABM , unpack , etx..
// #define r16( __ , _ ) __R( __ , _ , 0 ) // 16-bit comms
// #define r32( __ , _ ) __R( __ , _ , 2 ) // 32-bit comms
// #define r64( __ , _ ) __R( __ , _ , 6 ) // 64-bit comms
// void __I( unsigned char *__ , uint64_t _ , uint32_t b );
// uint32_t __R( unsigned char *__ , uint8_t *_ , uint32_t b ); 
// uint32_t pack( unsigned char *__ , uint64_t x );


// void __I( unsigned char *__ , uint64_t _ , uint32_t b ) {
//     while ( b > 0 ) {
//         *__++ = _>>( b + 1 )*8;
//         b--;
//     }
//     *__++ = _>>8; *__++ = _;
// }
// // `_` flag for signed/unsigned. `_` = 0 == unsigned
// uint32_t __R( unsigned char *__ , uint8_t *_ , uint32_t b ) {
//     uint32_t b__ = b;
//     if ( !b ) {
//         #if defined( xType )
//             #undef xType
//         #endif
//         #define xType uint8_t
//         #if defined( cType )
//             #undef cType
//         #endif
//         #define cType ( uint8_t )
//         #if defined( mVal )
//             #undef mVal
//         #endif
//         #define mVal 0x7fffu
//         #if defined( fVal )
//             #undef fVal
//         #endif
//         #define fVal 0xffffu
//         #if defined( sType )
//             #undef sType
//         #endif
//         #define sType uint8_t
//         #if defined( sCType )
//             #undef sCType
//         #endif
//         #define sCType ( uint8_t )
//         #if defined( DEBUG )
//             printf( "16-bit :: %04lx :: %04lx\n" , mVal , fVal );
//         #endif
//     }
//     else if ( b == 2 ) {
//         #if defined( xType )
//             #undef xType
//         #endif
//         #define xType uint32_t 
//         #if defined( cType )
//             #undef cType
//         #endif
//         #define cType ( uint32_t )
//         #if defined( mVal )
//             #undef mVal
//         #endif
//         #define mVal 0x7fffffffu
//         #if defined( fVal )
//             #undef fVal
//         #endif
//         #define fVal 0xffffffffu
//         #if defined( sType )
//             #undef sType
//         #endif
//         #define sType int32_t
//         #if defined( sCType )
//             #undef sCType
//         #endif
//         #define sCType ( int32_t )
//         #if defined( DEBUG )
//            printf( "32-bit :: %08lx :: %08lx\n" , mVal , fVal );
//         #endif
//     }
//     else if ( b == 6 ) {
//         #if defined( xType )
//             #undef xType
//         #endif
//         #define xType uint64_t
//         #if defined( cType )
//             #undef cType
//         #endif
//         #define cType ( uint64_t )
//         #if defined( mVal )
//             #undef mVal
//         #endif
//         #define mVal 0x7fffffffffffffffu
//         #if defined( fVal )
//             #undef fVal
//         #endif
//         #define fVal 0xffffffffffffffffu
//         #if defined( sType )
//             #undef sType
//         #endif
//         #define sType int64_t
//         #if defined( sCType )
//             #undef sCType
//         #endif
//         #define sCType ( int64_t )
//         #if defined( DEBUG )
//             printf( "64-bit :: %016lx :: %016lx \n" , mVal , fVal );
//         #endif
//     }

//     xType temp = ( xType ) __[0]<<( b + 1 )* 8 , last = ( xType ) __[( b + 1 )];
//     if ( b == 0 ) {
//         return temp | last;
//     }
//     while ( b > 0 ) {
//         b--;
//         temp |= ( ( xType )__[ b__ - b ] <<( b + 1 )* 8 );
//     }
//     temp |= last;
//     if ( !_ ) {
//         return temp; 
//     }

//     sType final;
//     if ( temp <= mVal ) {
//         final = temp;
//     } 
//     else {
//         final = - 1 - sCType ( fVal - temp );;
//     }
//     return final;
// }

// uint32_t pack( unsigned char *__ , uint64_t x ) {

// 	__I( __ , x , 6 );
// }



/*

*//* lower_case & `.` delim (kp max) <- PATH:=*.compact(/.)node 
    { less than 100 bytes } :: `web_r`xa-Path

*//* 100 chars or less <- CALL( # )

*//* serv_name , serv_port , etc.. <- CONNC:=max( web_n )

*//* * ( kx max ) <- Entry{#}

*/

// uint8_t __write( uint32_t __fd  , unsigned char *__ , uint32_t _len , ... ) {

//     uint32_t __len = strlen( __ ); 
//     uint32_t _size = 0;
//     char buf[1024] = {0};
//     uint8_t result_ = 0;

//     i16( buf , __len );
//     _size += 2;
    
//     result_ = write( __fd , buf , _size );

//     return result_;
// }

// #include <stdarg.h>
// uint32_t __read( uint32_t __fd , unsigned char *__ , uint32_t __min , ... ) {
//     va_list __vars;
//     uint32_t read_size = read( __fd , __ , 2 );
//     uint32_t x = r16( __ , 0 );

//     printf( "%x\n\n" , x );

//     return read_size;
// }

#endif