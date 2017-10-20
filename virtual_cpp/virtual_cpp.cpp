#include <iostream> 


struct Base 
{ 
  virtual ~Base() = 0; 
  virtual void foo() { std::cout << "Base::foo" << std::endl; } 
}; 

Base::~Base() = default;

struct Derived : public Base
{ 
 
  // void foo() override; 
  // declaring foo while forgeting to implementing gives a strange error in gcc.  
  // The error does not give any indication that we are missing the implementation of foo. 
  // Instead, the undefined reference is in function the constructor Derived and destructor ~Dervied. 
  // If I only knew!

  // jedda@jedda-Aspire-V3-571:~/Desktop/programming/virtual_cpp$ g++ --std=c++14 virtual_cpp.cpp -g 
  // /tmp/ccWUvbV2.o: In function `Derived::Derived()':
  // /home/jedda/Desktop/programming/virtual_cpp/virtual_cpp.cpp:12: undefined reference to `vtable for Derived'
  // /tmp/ccWUvbV2.o: In function `Derived::~Derived()':
  // /home/jedda/Desktop/programming/virtual_cpp/virtual_cpp.cpp:12: undefined reference to `vtable for Derived'
  //  collect2: error: ld returned 1 exit status
  void bar() { std::cout << "Derived::bar" << std::endl;} 
}; 

int main() 
{ 
  Derived().bar(); 
} 
