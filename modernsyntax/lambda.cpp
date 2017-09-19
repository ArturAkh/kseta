/*
g++ -o lambda -std=c++14 -pthread -g -Wall -Wextra -Wpedantic -Werror lambda.cpp
*/
#include <iostream>
#include <thread>

void incrementCounter(int* counter, const unsigned int times){
  for (unsigned int i=0; i<times;++i){
    ++(*counter);
  }
}

int main(){
  int counter(0);
  // launch a thread to increment the counter
  std::thread increment(incrementCounter,&counter,100000);
  increment.join();
  std::cout << counter << std::endl;
  std::cout << "Test lambda" << std::endl;
  int counter2(0);
  const unsigned int times = 200000;
  std::thread increment2([&counter2,times](){for (unsigned int i=0; i<times;++i){++counter2;}});
  increment2.join();
  std::cout << counter2 << std::endl;
  return 0;
}
