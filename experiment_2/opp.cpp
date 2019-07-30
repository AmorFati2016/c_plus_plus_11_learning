// test c++11 opp

#include <iostream>


class Base {

public:
    int value1;
    int value2;
    Base() {
      value1 = 1;
      std::cout<<" enter copy constructor function"<<std::endl;
    }
    Base(int value) : Base() { // delegating constructor
      value2 = 2;
      std::cout<<" enter delegating constuctor function"<<std::endl;
    }
};

class SubClass : public Base {
public:
     using Base::Base; // inherit constructior
};


class Magic {
public:
    //Magic() = default;  // using compiler's constructor
    Magic() {
      std::cout<<" enter default constructor"<<std::endl;
    }
    Magic& operator = (const Magic&) = delete; //reject the compiler's constructor
    Magic(int magic_num) {
      std::cout<<" constructor by user"<<std::endl;
    }
};

class Base2 {

public:
   virtual int doit() { return 1;}
   virtual int doitagain() final { return 2;}
};

class SubClass2 : public Base2 {
public:
    int doit() override;
};

int SubClass2::doit() {
    return 1;
}

int main() {
    std::cout<<" Test delegating constructor"<<std::endl;
    Base b(2);
    std::cout<<" value1 = "<< b.value1<<std::endl;
    std::cout<<" value2 = "<< b.value2<<std::endl;
    
    std::cout<<" Test inherit constructor"<<std::endl;
    SubClass sub;
    std::cout<<" value1 = "<<sub.value1<<std::endl;
    SubClass sub2(3);
    std::cout<<" value1 = "<<sub2.value1<<std::endl;
    std::cout<<" value2 = "<<sub2.value2<<std::endl;
    
    std::cout<<" Test obvious inherit"<<std::endl; 
    SubClass2 sub3;

    std::cout<<" Test the reject default constructor"<<std::endl;
    Magic magic;  
    return 1;
}
