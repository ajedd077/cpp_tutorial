#include <iostream> 
#include <vector>

template <class T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) 
{ 
  for (const auto& vi: v) { os << vi << " " ; } 
  return os;   
} 


template <class Iterator, class Op>
void adjacent_pairs(Iterator first, Iterator last, Op f)
{ 
  auto ip1 = first ; 
  for (auto i = first; ip1 != last; ) 
  { 
    if (i == first) { ip1 ++; }
    f(*i, *ip1); 
    i++; ip1++;  
  }  
} 

int main() 
{ 
  
  std::vector<int> v {1,2,3}; 
  auto pair_logger = [](int a, int b) { std::cout << "( " << a << ", " << b << ") "; };
  adjacent_pairs(v.begin(), v.end(), pair_logger);  
  std::cout << std::endl;  

  std::vector<int> v_diff; 
  auto diff_finder = [&v_diff](int a, int b) {v_diff.push_back(b-a); }; 
  adjacent_pairs(v.begin(), v.end(), diff_finder);
  for (auto vdi : v_diff) { std::cout << vdi ; } std::cout << std::endl;   

}  
