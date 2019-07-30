//test_thread


#include <iostream>
#include <thread>


void foo() {
    std::cout<<" hell thread foo"<<std::endl;
}


int main() {

    std::thread t(foo);
    t.join();
    return 1;
}
