import asyncio
import time

async def count():
    print("One")
    await asyncio.sleep(1)
    print("Two")

async def main():
    #Asyncio method that allows multiple coroutines to be executed concurrently and collect their results
    #The result of each coroutine is returned as an element in a list in the order n which they were passed to asyncio.gather
    await asyncio.gather(count(),count(),count()) 
    
if __name__ == "__main__":
    asyncio.run(main())
    
