/*
For simple operations, like increment a var, then the simpler solution, should be c++ atomic types,
which encapsulate a value and synchronize access to it, to prvent data race.
*/

#include<thread>
#include<atomic>
#include<cstdio>

std::atomic<unsigned int> garlic_count(0);

void shopper(){
    for(int i=0; i<1000000; i++){
        garlic_count++;
    }
}

int main(){
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We shoudl buy %u, garlic\n", garlic_count.load());
    system("PAUSE");
    return 0;
}