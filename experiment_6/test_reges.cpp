// test regex

#include <iostream>
#include <regex>
#include <string>


int main() {

    std::string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    /* \ shold replace with \\*/
    
    // style 1
    std::regex txt_regex("[a-z]+\\.txt");
    for (const auto &fname : fnames) {
        std::cout<<fname<<"  : "<<std::regex_match(fname, txt_regex)<<std::endl;
    }
   
    // style 2
    std::regex base_regex("([a-z]+)\\.txt");
    std::smatch base_match;
    for (const auto &fname : fnames) {
       if (std::regex_match(fname, base_match, base_regex)) {
           // base_match [0] entire string
           // base_match [1] sub string specific [a-z]
           if (base_match.size() == 2) {
                std::string base = base_match[1].str();
                std::cout<<" sub-match[0]: "<<base_match[0].str()<<std::endl;
                std::cout<<" sub-match[1]: "<<base_match[1].str()<<std::endl;
            }
       }
    }
  return 1;
}
    
