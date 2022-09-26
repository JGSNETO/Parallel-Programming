/*
Deadlock: Both acquire one lock and both stuck waiting on the other thread to release the other lock. 
Lock ordering:
- Ensurelocks are always taken in the same order by any thread.

Scoped lock: When you create a scoped_lock object, it takes ownership of one or more mutexes and holds
onto them for the scope in which that object was created. The scope_lock has a built-in deadlock avoidance algorithm
when it's used to acquire multiple mutexes at once.
*/
#include<cstdio>
#include<thread>
#include<chrono>
#include<mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick){ // Order that the philosopher will lock the two mutex
    while(sushi_count > 0){
        std::scoped_lock lock(first_chopstick, second_chopstick);
        if(sushi_count){
            sushi_count--;
        }
    }
}

int main(){

std::mutex chopstick_a, chopstick_b;
std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
barron.join();
olivia.join();
printf("The philosophers are done eating\n");
system("PAUSE");
return 0;
}