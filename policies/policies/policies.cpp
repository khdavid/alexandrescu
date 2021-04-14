// policies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <class T>
struct OpNewCreator
{
  static T* Create()
  {
    return new T;
  }
};

template <class T>
struct MallocCreator
{
  static T* Create()
  {
    void* buf = std::malloc{sizeof(T) };
    if (!buf)
    {
      return nullptr;
    }
    return new(buf) T;
  }
};

template <class T>
struct PrototypeCreator
{
  PrototypeCreator(T * pObj = nullptr) : pPrototype_(pObj)
  {

  }
  T* Create()
  {
    return pPrototype_ ? pPrototype_->Clone() : NULL;
  }
  T* GetPrototype()
  {
    return pPrototype_;
  }
  void SetPrototype(T *pObj)
  {
    pPrototype_ = pObj;
  }
private:
  T pPrototype_;
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
