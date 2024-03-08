// A solution to FizzBuzz without all those pesky modulus operators and if statements. Does that make it more efficient? Who knows?!
#include <iostream>
#include <unordered_map>
#include <chrono>

// Define hashmap and function pointer type
using FunctionPtr = void (*)(int);
std::unordered_map<int, FunctionPtr> fizzMap;

int count = 1;

// Hashmap functions
void num(int i)
{
  std::cout << i
            << std::endl;
  count++;
}

void fizz(int i)
{
  std::cout << "Fizz"
            << std::endl;
  count++;
}

void buzz(int i)
{
  std::cout << "Buzz"
            << std::endl;
  count++;
}

void fizzbuzz(int i)
{
  std::cout << "Fizz Buzz"
            << std::endl;
  count = 1;
}

int main()
{
  // Set runs
  int runs = 3000;

  // Add functions
  fizzMap[1] = num;
  fizzMap[2] = num;
  fizzMap[3] = fizz;
  fizzMap[4] = num;
  fizzMap[5] = buzz;
  fizzMap[6] = fizz;
  fizzMap[7] = num;
  fizzMap[8] = num;
  fizzMap[9] = fizz;
  fizzMap[10] = buzz;
  fizzMap[11] = num;
  fizzMap[12] = fizz;
  fizzMap[13] = num;
  fizzMap[14] = num;
  fizzMap[15] = fizzbuzz;

  // Start timer
  auto start = std::chrono::steady_clock::now();

  // Run FizzBuzz
  for (int i = 1; i <= runs; i++)
  {
    (fizzMap.find(count)->second)(i);
  }

  // End timer
  auto end = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Elapsed time: " << duration.count() << " milliseconds" << std::endl;

  return 0;
}