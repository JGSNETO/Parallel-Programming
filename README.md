# Parallel-Programming

- Asynchronous programming is a technique used to improve the performance of programs that rely heavily on I/O operations. The idea is to allow multiple tasks to run concurrently, instead of waiting for each task to complete before starting the next one. 
- Python provides a built-in library called ásyncio´for writing asynchronous code.

- Parallelism: Consists of performing multiple operations at the same time. Multiprocessing is a means to effect parallelism, and it entails spreading tasks over a CPU. Tightky bound for loops and mathematical computations. 
- Concurrency: It suggest that multiple tasks have the ability to run in an overlapping manner. 
- Threading: Is a concurrent execution model whereby multiple threads take turns executing tasks. One process can contain multiple threads. 

### The rules of async IO

- Async: The syntax async def introduces either a native coroutine or an asynchronous generator. The expressions async with and async for are also valid- 
- Await: The keyword await passes function control back to the event loop. If python encounters an await f() expression in the scope of g(), this is how await tells the event loop "Suspend execution of g() until whatever i am working on - the result of f() - is returned. In the mean time, go let something else run.
```
async def g():
    # Pause here and come back to g() when f() is ready
    r = await f()
    return r
```

- A function that you introduce with async def is a coroutine. It may use await, return, or yield, but all of these are optional. Declaring async def noop(): pass is valid
1. Using await and/or return creates a coroutine function. To call a coroutine function, you must await it to get its results.
2. It is less common (and only recently legal in python) to use yield in an async def block. This creates an asynchronous generator, which you iterate over with async for. Forget about async generators for the time being and focus on getting downs the syntax for coroutine functions, which use await and/or return. 