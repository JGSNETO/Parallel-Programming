/*Detecting data races:
1. Hard to do
2. Two or more threads accessing the same variable
Prevente data races:
1. Pay attention whenever two or more threads access the same resource

*/
#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdio>

unsigned int garlic_count = 0;

void shopper() {
    for(int i=0; i<10000000; i++){ // higher number to increase the chance of a data race happens 
        garlic_count++;
    }
}

int main(){
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join(); // Wait until their both done
    olivia.join();
    printf("We shoud buy %u garlic\n", garlic_count);
}