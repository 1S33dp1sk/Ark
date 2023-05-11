#!/usr/bin/python3


import json
import requests

# Define the URL of the RPC server
url = "http://localhost:3000"

# Create a sample JSON request
data = {
    "message": "Hello from Ark!",
    "timestamp": "2023-05-04T00:00:00Z"
}

# Send the JSON request to the RPC server and get the response
response = requests.post(url, json=data)

# Print the response
print("Response from RPC server:")
print(response.json())