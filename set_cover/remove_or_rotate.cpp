#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <cassert> 

template <class T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) 
{ 
  for (const auto& vi: v) { os << vi << " " ; } 
  return os;   
} 

template <class Iterator> 
void log(Iterator first, Iterator last) 
{ 
  for (auto it = first; it != last; it++) { std::cout << *it << " "; } 
} 

template <class Iterator> 
void shift_right(Iterator first, Iterator last) 
{ 
  std::rotate(first, first+1, last); 
} 


struct Set 
{ 
  
  using container = std::vector<int>; 
  container           _vec;  
  container::iterator _end_it;
  bool empty() { return _vec.begin() == _end_it; } 
  std::size_t size() { return std::distance(_vec.begin(), _end_it); }

  bool remove_element(container::iterator first) 
  { 
    // it_ must be between _vec.begin() and _end_it; 
    // and _end_it cannot be _vec.end() as well .. 
    if (first  == _vec.end()) { return false ; } 
    shift_right(first, _end_it);
    auto p_end_it = _end_it; 
    _end_it = first + std::distance(first, _end_it) - 1;  
    return (p_end_it != _end_it); 
  } 

  void log(const std::string& msg = {}) 
  { 
    std::cout << msg << " : " ; 
    for (auto it = _vec.begin(); it != _end_it; it++) 
    { 
      std::cout << *it << " "; 
    }
    std::cout << std::endl; 
  }
  void set_end_it()  { _end_it = _vec.end(); } 
}; 


int main() 
{ 
  Set s; 
  s._vec = {1,2,3,4}; 
  s.set_end_it(); 
  std::cout << s._vec << std::endl; 
  auto it = std::find(s._vec.begin(), s._vec.end(), 2); 
  assert(*it == 2);
  s.remove_element(it); 
  s.log("after remove 2"); 

  it = std::find(s._vec.begin(), s._vec.end(), 1); 
  assert(*it == 1);
  s.remove_element(it); 
  s.log("after remove 1"); 



  it = std::find(s._vec.begin(), s._vec.end(), 4); 
  assert(*it == 4);
  s.remove_element(it); 
  s.log("after remove 4"); 

  it = std::find(s._vec.begin(), s._vec.end(), 3); 
  assert(*it == 3);
  s.remove_element(it); 
  s.log("after remove 3"); 



  it = std::find(s._vec.begin(), s._vec.end(), 6); 
  assert(it == s._vec.end());
  s.remove_element(it); 
  s.log("after remove 6"); 


  Set s1; s1._vec = {1,2,3,4}; s1.set_end_it(); 
  std::cout << "inside loop" << std::endl;   
  for (auto it = s1._vec.begin(); !s1.empty(); ) 
  { 
    auto v = *it; 
    auto removed = s1.remove_element(it); 
    std::cout << "after removing " << v ; s1.log();   
    if (!removed) it ++;   
  }
  std::cout << "original vector: " << s1._vec << std::endl;
  std::cout << "original size: "    << s1._vec.size() << std::endl; 
  std::cout << "modified vector size: " << s1.size() << std::endl; 
} 

#if 0
int main() 
{ 
  std::vector<int> v {1,2,3};
  std::cout << "original: " << v << std::endl;  
  
  auto first = v.begin(); 
  auto last  = v.end(); 
  for (;first!=last;) 
  { 
    shift_right(first, last); 
    std::cout << "after rotation: "; log(first, last); std::cout << std::endl;  
    last = first +  std::distance(first, last) - 1; 
    std::cout << *last << std::endl;
    std::cout << "after pseudo-remove: "; log(first, last); std::cout << std::endl;  
  } 
  
  std::cout << "original vector: "; log(v.begin(), v.end());  std::cout << std::endl; 
  std::cout << "with size: " << v.size() << std::endl; 
} 
#endif 
