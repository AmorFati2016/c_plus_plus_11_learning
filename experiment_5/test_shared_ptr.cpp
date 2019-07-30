//test shared_ptr

#include <iostream>
#include <memory>


//test weak ptr

class A;
class B;

class A {
public:
    std::shared_ptr<B> pointer;
    std::weak_ptr<B> pointer2;
    ~A() {
        std::cout<<" A is destory"<<std::endl;
    } 
};

class B {
public:
    std::shared_ptr<A> pointer;
    ~B() {
         std::cout<<" B is destroy"<<std::endl;
    }
};



void foo(std::shared_ptr<int> i) {
   (*i)++;
}

int main() {

  // auto
  auto pointer = std::make_shared<int>(10);
  std::cout<<" init number is "<<*pointer<<std::endl;
  foo(pointer);
  std::cout<<" number is "<<*pointer<<std::endl;
  std::cout<<" current use count is "<<pointer.use_count()<<std::endl;
  
  std::cout<<"  add 1"<<std::endl;
  auto point2 = pointer;
  std::cout<<" current use count is "<<point2.use_count()<<std::endl;

  //test weak ptr
  std::cout<<" test weak ptr"<<std::endl;
  auto a = std::make_shared<A>();
  auto b = std::make_shared<B>();

  a->pointer = b;
  b->pointer = a;
  std::cout<<" for shared_ptr a's user_count is "<<a.use_count()<<std::endl;
  std::cout<<" for shared_ptr b's user_coutn is "<<b.use_count()<<std::endl; 
 
  a.reset();
  b.reset();
  a.reset();
  b.reset();
  
  std::cout<<" for reset a's user_count is "<<a.use_count()<<std::endl;
  std::cout<<" for reset b's user_coutn is "<<b.use_count()<<std::endl; 
  
  auto c = std::make_shared<A>();
  auto d = std::make_shared<B>();
  c->pointer2 = d;
  d->pointer = c;
  
  std::cout<<" for weak_ptr a's user_count is "<<c.use_count()<<std::endl;
  std::cout<<" for weak_ptr b's user_coutn is "<<d.use_count()<<std::endl;
  return 0;

}
