#include <iostream>


int main() 
{ 
    // If I only knew! 
    // See reference:  Dan Saks: const T vs. T const (http://www.dansaks.com/articles/1999-02%20const%20T%20vs%20T%20const.pdf) 
    int const  t = 1; 
    // and by the way: you can do: int const static t_ = 1; 
    std::cout << t << std::endl; 
    
    
    int const &t1 = t;              // reference to a constant integer. 
    std::cout << t1 << std::endl; 
    
    
    
    int const *t2 = &t; 
    std::cout << *t2 << std::endl; 
    
    int const * const t3 = &t;          // const pointer to a cont integer. It can be seen as [int const] [* const t3]. 
    // int * const t4 = &t;                // fails.  t4 is a const pointer to integer. t is a const integer. 
    std::cout << *t3 << std::endl; 
     
    // int const & const t5 = t;           // this is wrong for a different reason: 'const' qualifiers cannot be applied to 'const int&
}
