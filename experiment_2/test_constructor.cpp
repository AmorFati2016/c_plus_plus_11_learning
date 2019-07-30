//test the order of constructor


#include <iostream>


class Base {
public:
    Base() {
      std::cout<<" enter the base constructor"<<std::endl;
    }
   virtual  ~Base() {
      std::cout<<" enter the ~ base constructor"<<std::endl;
    }

};

class SubClass : public Base {

public:
//   SubClass() { 
//     std::cout<<" enter subclass constructor"<<std::endl;
//   }

     SubClass():Base() {
       std::cout<<" enter the subclas contructor"<<std::endl;
     } 
     virtual ~SubClass() {
     std::cout<<" enter the subClass ~"<<std::endl;
   }
};

int main() {
   std::cout<<" Test the order of constructor"<<std::endl;
   SubClass b;
   //delete b;
  return 1;
} 
