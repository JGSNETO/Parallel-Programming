/*
-The shared mutex class has been part c++ since c17. To proive a mutex that can be acquired in a shared mode
in which multiple threads can share ownership of the mutex as well as an exclusive mode in which only one thread
can have a lock.
*/
#include<thread>
#include<mutex>
#include<chrono>
#include<cstdio>
#include<shared_mutex>

char weekdays[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int today = 0;
std::shared_mutex marker;

void calendar_reader(const int id){
    for(int i =0; i<7; i++){
        marker.lock_shared();
        printf("Reader-%d sees today is %s\n", id, weekdays[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        marker.unlock_shared();
    }
}

void calendar_writter(const int id){
    for(int i=0; i<7; i++){
        marker.lock();
        today=(today+1)%7;
        printf("Writter-%d updated date to %s\n", id, weekdays[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        marker.unlock();
    }
}

int main(){

    //Create ten reader threads .. but only two writter threads
    std::array<std::thread, 10> readers;
    for(unsigned int i = 0; i<readers.size(); i++){
        readers[i] = std::thread(calendar_reader, i);
    }
    std::array<std::thread, 2> writters;
    for(unsigned int i=0; i<writters.size(); i++){
        writters[i] = std::thread(calendar_writter, i); 
    }

    //wait for readers and writters to finish
    for(unsigned int i = 0; i<readers.size(); i++){
        readers[i].join();
    }
    for(unsigned int i = 0; i<writters.size(); i++){
        writters[i].join();
    }
    system("PAUSE");
    return 0;
}