#include "trialbero.h"
#include<iostream>

int main() {
  trialbero<char> t1, t2, t3;
  t1.insert('b');
  t1.insert('a');
  t2.insert('a');
  t3 = t1;
  t3.insert('c');
  std::cout << (t1 == t2) << std::endl; 
  std::cout << t1.search('b') << std::endl; 
  std::cout << "T1:" << t1 << std::endl << "T2:" << t2 << std::endl << "T3:" << t3 << std::endl;
}