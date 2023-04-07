from termcolor import colored
from flask import request 

################################ ERRORS #######################################


def page_not_found(x):
    try:
        print("\nIP OF REQUEST : "+ colored(x.remote_addr, 'green') +" and it is "+colored('DENIED', 'red')+"\n")
    finally:
        return "<h1>404</h1><p>The resource could not be found.</p>", 404


def internal_error(x):
    try:
        print("\nIP OF REQUEST : "+ colored(x.remote_addr, 'green') +" and it is "+colored('DENIED', 'red')+"\n")
    finally:
        return "<h1>404</h1><p>This is our mistake, we have some issues we need to work on, maybe email us at admin@djoure.com</p>", 500    


def forbbid_any(x):
    try:
        print("\nIP OF REQUEST : "+ colored(x.remote_addr, 'green') +" and it is "+colored('DENIED', 'red')+"\n")
    finally:
        return "<h1>403</h1><p>Kinda, Not supposed to be here.</p>", 403       


###############################################################################
