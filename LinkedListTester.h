#ifndef LINKED_LIST_TESTER_H
#define LINKED_LIST_TESTER_H

#include "LinkedListOfInts.h"
#include <iostream>
#include <string>

class LinkedListTester
{
    public:
        //@brief runs all the tests for linked list tester
        void testAll();

        //@brief initializes m_largeSize for the creation of the LinkedListTester object
        LinkedListTester(int largeSize = 100);

    private:
      int m_largeSize;

      //Helper Functions

      //@brief creates random int array of size size
      int* createRandomArray(int size);

      //@brief return random int
      int createRandomint();

      //@brief creates list equivalent to array
      LinkedListOfInts* createList(int* array, int size);

      //@brief tests the copy constructor by compareing the passed in linked list with passed in boolean and returning whether or not integrity was kept.
      bool copyConstructorTest(LinkedListOfInts LinkedListOfInts, int* array);

      //@brief compares a list to an array
      bool compareListArray(const LinkedListOfInts& list1, int* array, unsigned arrSize) const;

      //@brief prints the message of if a test passes or fails and returns the passed in boolean
      bool printResult(bool passed, int& testNumber, std::string testMessage);

      //@brief prints final message of whether or not the all tests have passed
      void finalResult(bool passed);


      /****************************************
      size Tests*/
      bool test01();
      bool test02();
      bool test03();
      bool test04();
      bool test05();
      bool test06();
      bool test07();
      bool test08();
      bool test09();
      bool test10();
      bool test11();
      /*size Tests
      ****************************************/

      bool test12();

      bool test13();

      bool test14();
      bool test15();

      bool test16();
      bool test17();
      bool test18();


      bool test19();
      bool test20();
      bool test21();

      bool test22();
      bool test23();
      bool test24();
};
#endif
