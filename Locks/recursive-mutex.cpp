#include<thread>
#include<mutex>
#include<cstdio>

unsigned int garlic_count = 0;
unsigned int potaro_count = 0;
std::recursive_mutex pencil;

void add_garlic(){
    pencil.lock();
    garlic_count++;
    pencil.unlock();
}

void add_potato(){
    pencil.lock();
    potaro_count++;
    add_garlic();
    pencil.unlock();
}

void shopper(){
    for(int i=0; i<1000; i++){
        add_garlic();
        add_potato();
    }
}

int main(){
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We shoud buy %u garlic\n", garlic_count);
    printf("We shoudl buy %u potato\n", potaro_count);
    system("PAUSE");
    return 0;
}