#!/usr/bin/python3

import asyncio
import websockets

async def echo(websocket):
    async for message in websocket:
        print(message);
        await websocket.send(message)

async def main():
    print("running on 0.0.0.0:9999")
    async with websockets.serve(echo, "0.0.0.0", 9999):
        await asyncio.Future()  # run forever

asyncio.run(main())