//test keyword auto decltype

#include <iostream>
#include <vector>

using namespace std;

int main() {
  
  // init vector
  std::vector<int> vec;
  for (int i=0; i< 10; ++i) {
    vec.push_back(i);
  }

  // visit element by cuntom method.
  std::cout<< " visit element by custom method."<<std::endl;
  for (std::vector<int>::const_iterator itr = vec.cbegin(); itr != vec.cend();++itr) {
    std::cout<<*itr;
  }
  std::cout<<std::endl;


  //  visist elemtn by c++ 11 standard
  std::cout<< " visit element by c++ 11"<<std::endl;
  for (auto itr = vec.cbegin(); itr !=vec.cend(); ++itr) {
     std::cout<<*itr;
  }
  std::cout<<std::endl;
  
  
  // auto type
  auto x = 5;
  auto y = 10;
  decltype(x + y) z;

  // for loop using c++11
  //init 
  int arry[] = {1,2,3,4,5};
  
  std::cout<<" visit element arry using custom"<<std::endl;
  int length = sizeof(arry)/sizeof(int);
  for (int i=0; i< length; ++i ) {
     std::cout<<arry[i];
  }
  std::cout<<std::endl;

  std::cout<<" visit element arry using c++11"<<std::endl;
  for (auto &x : arry) {
     std::cout<<x;
  }
  std::cout<<std::endl;
  

  // 
  std::cout<<"  visit vector element using c++11"<<std::endl;
  for (auto &i : vec) {
    std::cout<<i;
  }
  std::cout<<std::endl;




  return 1;


}
