#!usr/bin/python

from aspapi import app as application
import logging
import sys


logging.basicConfig(stream=sys.stderr)
# sys.path.insert(0, '/home/kj/Desktop/8200-7443/asp-api/aspapi.py')

if __name__ == "__main__":
	application.run(host='0.0.0.0',port=5000, debug=False, )

