#include <iostream>
#include <map>

using namespace std;

class PrinterQueue
{
  // your attributes
  pair<string, int> *queue;
  int capacity;
  int count;

public:
  // your methods
  PrinterQueue()
  {
    this->capacity = 10;
    this->count = 0;
    this->queue = new pair<string, int>[capacity];
  }

  void ensureCapacity(int minCapacity)
  {
    if (minCapacity > capacity)
    {
      pair<string, int> *newQueue = new pair<string, int>[minCapacity];
      for (int i = 0; i < count; i++)
        newQueue[i] = queue[i];
      delete[] queue;
      queue = newQueue;
      capacity = minCapacity;
    }
  }

  void reheapUp(int position)
  {
    int parent = (position - 1) / 2;
    pair<string, int> temp = queue[position];
    while (position > 0 && temp.second > queue[parent].second)
    {
      queue[position] = queue[parent];
      position = parent;
      parent = (position - 1) / 2;
    }
    queue[position] = temp;
  }

  void reheapDown(int position)
  {
    int child = 2 * position + 1;
    pair<string, int> temp = queue[position];
    while (child < count)
    {
      if (child < count - 1 && queue[child].second < queue[child + 1].second)
        child++;
      if (temp.second >= queue[child].second)
        break;
      queue[position] = queue[child];
      position = child;
      child = 2 * position + 1;
    }
    queue[position] = temp;
  }

  void addNewRequest(int priority, string fileName)
  {
    // your code here
    ensureCapacity(count + 1);
    pair<string, int> document(fileName, priority);
    queue[count] = document;
    reheapUp(count);
    count++;
  }

  void print()
  {
    // your code here
    // After some logic code, you have to print fileName with endline
    cout << queue[0].first << endl;
    queue[0] = queue[count - 1];
    count--;
    reheapDown(0);
  }
};

int main()
{
  PrinterQueue *myPrinterQueue = new PrinterQueue();
  myPrinterQueue->addNewRequest(1, "hello.pdf");
  myPrinterQueue->addNewRequest(2, "goodbye.pdf");
  myPrinterQueue->addNewRequest(2, "goodnight.pdf");
  myPrinterQueue->print();
  myPrinterQueue->print();
  myPrinterQueue->print();
}