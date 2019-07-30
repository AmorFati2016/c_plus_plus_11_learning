// test nullptr

#include <iostream>


int func(char *);
int func(int );

int main() {

 if (NULL == (void *)0) {
    std::cout<<" NULL == 0"<<std::endl;
 }  else {
    std::cout<<" NULL !=0 "<<std::endl;
 }

 func(0);
 func(nullptr); 
 return 1;

}

int func(char *ch) {
  std::cout<<"  this is func (char *)"<<std::endl;
}

int func(int n) {
  std::cout<<" this is func (int)" <<std::endl;
}
