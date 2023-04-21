import asyncio

async def my_coroutine():
    print('Coroutine started')
    await asyncio.sleep(1)
    print('Coroutine ended')
    
async def main():
    task1 = asyncio.create_task(my_coroutine())
    task2 = asyncio.create_task(my_coroutine())
    await task1
    await task2
    
asyncio.run(main())