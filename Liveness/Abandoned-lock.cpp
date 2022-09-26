/*
If one thread breaks for some reason, the other thread will forever wait. 
Scoped lock solves that. If one thread goes off, automatically release the lock. 
*/

#include<thread>
#include<mutex>
#include<cstdio>

int sushi_count = 5000;

void philosopher(std::mutex &chopstick){
    while(sushi_count>0){
        std::scoped_lock lock(chopstick);
        if(sushi_count){
            sushi_count--;
        }
        if(sushi_count == 10){
            printf("This philosophers has had enough\n");
            break;
        }
    }
}

int main(){

    std::mutex chopstick;
    std::thread barron(philosopher, std::ref(chopstick));
    std::thread olivia(philosopher, std::ref(chopstick));
    barron.join();
    olivia.join();
    printf("This philosophers are done enough\n");
    system("PAUSE");
    return 0;
}
