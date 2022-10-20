/* Include the required headers from httpd */
#include "httpd.h"
#include "http_core.h"
#include "http_protocol.h"
#include "http_request.h"

/* Define prototypes of our functions in this module */
static void register_hooks(apr_pool_t *pool);
static int example_handler(request_rec *r);

/* Define our module as an entity and assign a function for registering hooks  */

module AP_MODULE_DECLARE_DATA   ather_module =
{
    STANDARD20_MODULE_STUFF,
    NULL,            // Per-directory configuration handler
    NULL,            // Merge handler for per-directory configurations
    NULL,            // Per-server configuration handler
    NULL,            // Merge handler for per-server configurations
    NULL,            // Any directives we may have for httpd
    register_hooks   // Our hook registering function
};


/* register_hooks: Adds a hook to the httpd process */
static void register_hooks(apr_pool_t *pool) 
{
    
    /* Hook the request handler */
    ap_hook_handler(example_handler, NULL, NULL, APR_HOOK_LAST);
}

/** The handler function for our module.
 * This is where all the fun happens!
 * 
 * r->handler (char*): Contains the name of the handler the server is currently asking to do the handling of this request
 * r->method (char*): Contains the HTTP method being used, f.x. GET or POST
 * r->filename (char*): Contains the translated filename the client is requesting
 * r->args (char*): Contains the query string of the request, if any
 * r->headers_in (apr_table_t*): Contains all the headers sent by the client
 * r->connection (conn_rec*): A record containing information about the current connection
 * r->user (char*): If the URI requires authentication, this is set to the username provided
 * r->useragent_ip (char*): The IP address of the client connecting to us
 * r->pool (apr_pool_t*): The memory pool of this request.
 * 
 */


void log_request( request_rec *r ) {
    printf( "Ather :: Apache<request> :: \n" );
    printf( "\tHandler : %s\n" , r -> handler );
    printf( "\tMethod : %s\n" , r -> method );
    printf( "\tFilename : %s\n", r -> filename );
    printf( "\tArgs : %s\n" , r -> args );
    printf( "\tIp : %s\n" , r -> useragent_ip );
    printf( "\tUser : %s\n" , r -> user );
}

static int example_handler(request_rec *r)
{
    /* Set the appropriate content type */
    ap_set_content_type(r, "text/html");

    /* Print out the IP address of the client connecting to us: */
    ap_rprintf(r, "<h2>Hello, %s!</h2>", r->useragent_ip);
    
    /* If we were reached through a GET or a POST request, be happy, else sad. */
    if ( !strcmp(r->method, "POST") || !strcmp(r->method, "GET") ) {
        ap_rputs("You used a GET or a POST method, that makes us happy!<br/>", r);
    }
    else {
        ap_rputs("You did not use POST or GET, that makes us sad :(<br/>", r);
    }

    /* Lastly, if there was a query string, let's print that too! */
    if (r->args) {
        ap_rprintf(r, "Your query string was: %s", r->args);
    }


    log_request( r );
    return OK;
}