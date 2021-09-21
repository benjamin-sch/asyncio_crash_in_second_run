import threading
import asyncio

async def asyncFunc():
    await asyncio.sleep(3)

def thread_function():
    print("started thread")
    asyncio.run(asyncFunc())
    print("finishing thread")

x = threading.Thread(target=thread_function, args=())
x.start()
    
