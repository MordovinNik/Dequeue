#include <iostream>
#include <deque>
#include <random>
#include "Dequeue.h"

void printQ(My::Dequeue<int> q1, My::Dequeue<int> q2)
{
  std::cout << "MyQ:" << std::endl;
  while (q1.size() != 0)
    std::cout << q1.poll_first() << std::endl;

  std::cout << "NewQ:" << std::endl;
  while (q2.size() != 0)
    std::cout << q2.poll_first() << std::endl;
  std::cout<<std::endl;
}

int main(void)
{
  My::Dequeue<int> MyQ;
 
  MyQ.push_back(12);
  MyQ.push_front(10);
  MyQ.push_back(14);
  MyQ.push_back(16);

  My::Dequeue<int> NewQ = std::move(MyQ);
  printQ(MyQ, NewQ);
  MyQ = NewQ;
  printQ(MyQ, NewQ);
  NewQ.clear();
  printQ(MyQ, NewQ);

  return 0;
  }



