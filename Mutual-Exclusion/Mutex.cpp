#include <thread>
#include <chrono>
#include <cstdio>
#include <mutex>

unsigned int garlic_count = 0;
std::mutex mtx;

void shopper(){
    mtx.lock();
    for(int i =0; i<5; i++){
        printf("Shooper %d is thinking.. \n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        garlic_count++;
    }
    mtx.unlock();
}

int main(){
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We shoud buy %u garlic", garlic_count);
    system("PAUSE");
    return 0;
}