#include <algorithm> 
#include <vector> 
#include <iostream> 

template <class T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) 
{ 
  for (const auto& vi: v) { os << vi << " " ; } 
  return os;   
} 


template <class Iterator> 
Iterator set_difference_unsorted_v1(Iterator first, Iterator last, Iterator b_first, Iterator b_last) 
{ 
  auto d = first; 
  for (auto it = first; it != last; ++it) 
  { 
    if (std::find(b_first, b_last, *it) == b_last)     // does not exists
    { 
      *d = *it; 
      d++; 
    } 
  } 
  return d; 
} 

template <class Iterator> 
Iterator set_difference_sorted_v1(Iterator first, Iterator last, Iterator b_first, Iterator b_last) 
{ 
  auto d = first; 
  auto new_b_first = b_first; 
  for (auto it = first; it != last; it++) 
  { 
    
    auto search_it = std::find(new_b_first, b_last, *it); 
    if (search_it == b_last)     // does not exists
    { 
      *d = *it; 
      d++; 
    } 
    else { new_b_first = search_it; }
  } 
  return d; 
}

int main() 
{ 
  std::vector<int> a {1,2,3}; 
  std::vector<int> b {2,3,4,5,6}; 
  std::vector<int> c; 
  // std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c)); 
  auto res_it = std::set_difference(a.begin(), a.end(), b.begin(), b.end(), a.begin()); 
  a.erase(res_it, a.end()); 
  c = a;  
  std::cout << a << std::endl; 
  std::cout << b << std::endl; 
  std::cout << c << std::endl;  

  std::vector<std::vector<int>> all_sets {a,b,c};
  // How to remove the dependency on std::vector<int> with a nice way? 
  auto max_it = std::max_element(all_sets.begin(), all_sets.end(), 
          [](const std::vector<int>& a_, const std::vector<int>& b_) {return a_.size() < b_.size(); }); 

   std::cout << "max set: " << *max_it << std::endl; 

  // what if we know that: 
  // 1. elements within a set (vector) are unique. 
  // 2. all elements are within a finite universe set. 
  
  // Let's try to write std::set_difference using std::remove_if 
  // PS: we are actually trying to do: T = T - U 
 
  enum class FindMethod { FIND = 0, BINARY_SEARCH = 1, NONE=2}; 
  auto method = FindMethod::NONE; 
  switch (method) 
  { 
    case FindMethod::FIND: 
    { 
      a.erase(std::remove_if(a.begin(), a.end(), 
        [b](const int& ai){return std::find(b.begin(), b.end(), ai) != b.end(); })); 
  
      break; 
    }
    case FindMethod::BINARY_SEARCH: 
    { 
      a.erase(std::remove_if(a.begin(), a.end(), 
        [b](const int& ai){return std::binary_search(b.begin(), b.end(), ai); })); 
      break; 
    } 
    default : break;  
  } 

  std::cout << a << std::endl; 
 

  /* 
  std::cout << "Testing lambda with range" << std::endl;  
  int n = 1; 
  std::for_each(a.begin(), a.end(), [&n](int& ai) { ai=ai+n++; }); 
  std::cout << a << std::endl;   
  */  // This is just for testing .
  std::cout << "before set difference " << std::endl; 
  std::cout << a << " - " << b << " = ";  
  auto out_it = set_difference_sorted_v1(a.begin(), a.end(), b.begin(), b.end()); 
  // a.erase(out_it, a.end());  
  a.resize(std::distance(a.begin(), out_it));  // An optimization for the case of vector.
  std::cout << a << std::endl;  
}

 
