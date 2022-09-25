/*Create a new thread that spins in a while loop forever*/

#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdio>

// Wastes CPU cycles forever
void cpu_waster(){
    printf("CPU waster process ID: %d\n", getpid()); 
    printf("CPU waster thread ID: %d\n", std::this_thread::get_id());
    while(true) continue;
}

int main(){

    printf("Main process ID: %d\n", getpid());
    printf("Main thread ID: %d\n", std::this_thread::get_id());
    //Creating threads and addressing actions
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster);
    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    system("PAUSE");
    return 0;
}