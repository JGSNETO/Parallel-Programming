#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdio>

bool chopping = true;

void vegetable_chopper(const char* name){
    unsigned int vegetable_count = 0;
    while(chopping){
        vegetable_count++;
    }
    printf("\n%s choped %u vegetables.\n", name, vegetable_count);
}

int main(){

    std::thread olivia(vegetable_chopper, "Olivia");
    std::thread barron(vegetable_chopper, "Barron");

    printf("Barron and Olivia are chopping vegetables");

    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping = false;
    //The c++ thread join is used to blocks the threads until the first thread execution process is completed on
    // which particular join() method is called to avoid the misconceptions or erros in the code. If suppose we 
    // are not using any join() method in the c++ code.
    barron.join();
    olivia.join();

    system("PAUSE");
    return 0;
}