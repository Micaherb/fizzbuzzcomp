// A solution to FizzBuzz without all those pesky modulus operators and conditionals. Does that make it more efficient? Who knows?!
#include <iostream>
#include <unordered_map>
#include <chrono>

struct Node
{
  void (*functionPointer)(int);
  Node *next;
};

class CircularLinkedList
{
private:
  Node *head;

public:
  // Constructor
  CircularLinkedList() : head(nullptr) {}

  // Add function pointer to the end of list
  void addFunction(void (*function)(int))
  {
    Node *newNode = new Node;
    newNode->functionPointer = function;
    if (head == nullptr) // Point to self
    {
      head = newNode;
      head->next = head;
    }
    else // Loop to head
    {
      Node *temp = head;
      while (temp->next != head)
      {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
    }
  }

  // Execute current function and set head to next node
  void execute(int val)
  {
    head->functionPointer(val);
    head = head->next;
  }
};

// Hashmap functions
void num(int i)
{
  std::cout << i
            << std::endl;
}

void fizz(int i)
{
  std::cout << "Fizz"
            << std::endl;
}

void buzz(int i)
{
  std::cout << "Buzz"
            << std::endl;
}

void fizzbuzz(int i)
{
  std::cout << "Fizz Buzz"
            << std::endl;
}

int main()
{
  // Set runs
  int runs = 1000;

  // Create Function Loop
  CircularLinkedList funcs;
  funcs.addFunction(num);
  funcs.addFunction(num);
  funcs.addFunction(fizz);
  funcs.addFunction(num);
  funcs.addFunction(buzz);
  funcs.addFunction(fizz);
  funcs.addFunction(num);
  funcs.addFunction(num);
  funcs.addFunction(fizz);
  funcs.addFunction(buzz);
  funcs.addFunction(num);
  funcs.addFunction(fizz);
  funcs.addFunction(num);
  funcs.addFunction(num);
  funcs.addFunction(fizzbuzz);

  // Start timer
  auto start = std::chrono::steady_clock::now();

  // Run FizzBuzz
  for (int i = 1; i <= runs; i++)
  {
    funcs.execute(i);
  }

  // End timer
  auto end = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Elapsed time: " << duration.count() << " milliseconds" << std::endl;

  return 0;
}