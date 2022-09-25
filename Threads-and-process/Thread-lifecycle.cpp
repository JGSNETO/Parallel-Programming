#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdio>

void chef_olivia(){

    printf("Olivia started & waiting for sausafe to thaw...\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("Olivia is done cutting sausage");
}

int main(){

    printf("Barron requests olivia's help\n");
    std::thread olivia(chef_olivia);
    /*Is an in-built function in c++ std::thread. It is an observer function which means it observes a state
    and then returns the corresponding output and checks wheter the thread object is joinable or not
    
    A thread object is said joinable if it identifies/represent an active thread or execution.
    */
    printf("\nOlivia is joiable ? %s\n", olivia.joinable() ? "true":"fasle"); // waits the thread finish

    printf("Barron continues coocking soup\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf("\nOlivia is joiable ? %s\n", olivia.joinable() ? "true":"fasle"); 
    
    printf("Barron waits for olivia to finish\n");
    olivia.join();
    printf("\nOlivia is joiable ? %s\n", olivia.joinable() ? "true":"fasle"); 
    

    system("PAUSE");
    return 0;
}