#include <iostream>
#include <string>
#include <vector>
#include <array> 
#include <algorithm>
#include <iterator>
#include <numeric> 

template <class Iterator>
constexpr std::size_t size(Iterator first, Iterator last) 
{ 
    return std::distance(first, last); 
} 


template <class T, class Ostream = std::ostream> 
Ostream& log(const T& v, Ostream& os = std::cout)
{ 
   
  for (auto& a : v) { os << a << " "; }
  return os; 
} 




template <class T, class N> 
auto get_insert_iterator(std::array<T,N>& container) 
{ 
	return container.begin(); 
}


template <class T>
auto get_insert_iterator(T& container) 
{ 
	return std::back_inserter(container); 
}  

int main()
{
    
    //using container = std::vector<int>;  
    using container = std::array<int, 3>;
    container a = {1,2,3};
		container r;  
		std::transform(a.begin(), a.end(), a.begin(), get_insert_iterator(r), std::plus<>()); 
	  std::cout << r[0]  <<  std::endl; 
}


