#!/usr/bin/python3
import flask

app=flask.Flask(__name__)

if __name__=="__main__":
	app.run("0.0.0.0","9999")
