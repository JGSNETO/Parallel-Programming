#include<thread>
#include<mutex>
#include<cstdio>
#include<array>

int sushi_count = 5000;

void philosopher(std::mutex &chopstick){
    int sushi_eaten = 0;
    while(sushi_count > 0){
        std::scoped_lock lock(chopstick);
        if(sushi_count){
            sushi_count--;
            sushi_eaten++;
        }
    }
}

int main(){

    std::mutex chopsticks;
    std::array<std::thread, 200> philosophers;
    for(unsigned int i = 0; i<philosophers.size(); i++){
        philosophers[i] = std::thread(philosopher, std::ref(chopsticks));
    }
    for(unsigned int  i = 0; i<philosophers.size(); i++){
        philosophers[i].join();
    }
    system("PAUSE");
    return 0;
}