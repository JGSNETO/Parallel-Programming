/*
When the thread is releasing the locker to benefit the other lock.
The final bit.

Multiple thread or processes are actively responding to each other to resolve conflict, but that prevents
them to making progress.
*/
#include <thread>
#include <mutex>
#include <cstdio>

int sushi_count = 5000;

void phi(std::mutex &first_chop, std::mutex &second_chop){
    while(sushi_count >0){
        first_chop.lock();
        if(!second_chop.try_lock()){ // If second chop was already taken by another thread, try_lock will return false.
            first_chop.unlock();
            std::this_thread::yield(); /*To solve the livelock, they will use yield function which will reschedule its 
            execution to allow other threads to run*/
        }else{
            if(sushi_count){
                sushi_count--;
            }
            second_chop.unlock();
            first_chop.unlock();
        }
    }
}

int main(){

    std::mutex chop_a, chop_b;
    std::thread barron(phi, std::ref(chop_a), std::ref(chop_b));
    std::thread olivia(phi, std::ref(chop_b), std::ref(chop_a));
    std::thread steve(phi, std::ref(chop_a), std::ref(chop_b));
    std::thread nick(phi, std::ref(chop_b), std::ref(chop_a));
    barron.join();
    olivia.join();
    steve.join();
    nick.join();
    printf("End\n");
    system("PAUSE");
    return 0;
}