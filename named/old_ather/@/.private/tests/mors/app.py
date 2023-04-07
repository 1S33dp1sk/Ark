#!/usr/bin/python3

import flask

app = flask.Flask( __name__ )


@app.route( '/' , methods=['GET'] )
def __home__():
	return 'Hello From Flask',200


@app.route( '/submit_req' , methods=['POST'])
def submit_request():
	return "submit request",200

if __name__ == '__main__':
	app.run(host="0.0.0.0")