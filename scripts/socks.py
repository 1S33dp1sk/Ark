#!/usr/bin/python3

import asyncio
import websockets

async def echo(websocket):
    async for message in websocket:
        await websocket.send(message)

async def main():
    print("running on localhost:9999")
    async with websockets.serve(echo, "localhost", 9999):
        await asyncio.Future()  # run forever

asyncio.run(main())