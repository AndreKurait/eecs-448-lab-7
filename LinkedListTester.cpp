#include "LinkedListTester.h"

LinkedListTester::LinkedListTester(int largeSize)
{
	m_largeSize = largeSize;
}

void LinkedListTester::testAll()
{
	bool passed = true;
	int testNumber = 1;

	std::cout << "\n\n%%%%%%%%%%%%%%SIZE TESTS%%%%%%%%%%%%%%\n";
	passed = printResult(test01(), testNumber, "size of empty list is zero") && passed;

	passed = printResult(test02(), testNumber, "size returns correct value after addFront of empty list") && passed;
	passed = printResult(test03(), testNumber, "size returns correct value after addBack of empty list") && passed;

	passed = printResult(test04(), testNumber, "size returns correct value after addFront and removeFront of empty list") && passed;
	passed = printResult(test05(), testNumber, "size returns correct value after addFront and removeBack of empty list") && passed;

	passed = printResult(test06(), testNumber, "size returns correct value after addBack and removeFront of empty list") && passed;
	passed = printResult(test07(), testNumber, "size returns correct value after addBack and removeBack of empty list") && passed;

	passed = printResult(test08(), testNumber, "size returns correct value of large list") && passed;
	passed = printResult(test09(), testNumber, "size returns correct value after addBack of large list") && passed;
	passed = printResult(test10(), testNumber, "size returns correct value after removeFront of large list") && passed;
	passed = printResult(test11(), testNumber, "size returns correct value after removeBack of large list") && passed;
	std::cout << "%%%%%%%%%%%%%%SIZE TESTS%%%%%%%%%%%%%%\n\n\n";


	std::cout << "\n%%%%%%%%%%%%%%ADD_FRONT TESTS%%%%%%%%%%%%%%\n";
	passed = printResult(test12(), testNumber, "addFront works in creating list of size 1 to 100") && passed;
	std::cout << "%%%%%%%%%%%%%%ADD_FRONT TESTS%%%%%%%%%%%%%%\n";



	std::cout << "\n%%%%%%%%%%%%%%ADD_BACK TESTS%%%%%%%%%%%%%%\n";
	passed = printResult(test13(), testNumber, "addBack works in creating list of size 1 to 100") && passed;
	std::cout << "%%%%%%%%%%%%%%ADD_BACK TESTS%%%%%%%%%%%%%%\n";


	std::cout << "\n%%%%%%%%%%%%%%IS_EMPTY TESTS%%%%%%%%%%%%%%\n";
	passed = printResult(test14(), testNumber, "isEmpty works in list of size 0") && passed;
	passed = printResult(test15(), testNumber, "isEmpty works in list of size 1 to 100") && passed;
	std::cout << "%%%%%%%%%%%%%%IS_EMPTY TESTS%%%%%%%%%%%%%%\n";


	std::cout << "\n%%%%%%%%%%%%%%SEARCH TESTS%%%%%%%%%%%%%%\n";
	passed = printResult(test16(), testNumber, "search works in list of size 0") && passed;
	passed = printResult(test17(), testNumber, "search returns true for values in list of size 1 to 100") && passed;
	passed = printResult(test18(), testNumber, "search returns false for values not in list of size 1 to 100") && passed;
	std::cout << "%%%%%%%%%%%%%%SEARCH TESTS%%%%%%%%%%%%%%\n";

	std::cout << "\n%%%%%%%%%%%%%%REMOVE_FRONT TESTS%%%%%%%%%%%%%%\n";
	passed = printResult(test19(), testNumber, "removeFront works in list of size 0") && passed;
	passed = printResult(test20(), testNumber, "removeFront returns works in list of size 1") && passed;
	passed = printResult(test21(), testNumber, "removeFront returns works in list of size 2 to 100") && passed;
	std::cout << "%%%%%%%%%%%%%%REMOVE_FRONT TESTS%%%%%%%%%%%%%%\n";


	std::cout << "\n%%%%%%%%%%%%%%REMOVE_BACK TESTS%%%%%%%%%%%%%%\n";
	passed = printResult(test22(), testNumber, "removeBack works in list of size 0") && passed;
	passed = printResult(test23(), testNumber, "removeBack returns works in list of size 1") && passed;
	passed = printResult(test24(), testNumber, "removeBack returns works in list of size 2 to 100") && passed;
	std::cout << "%%%%%%%%%%%%%%REMOVE_BACK TESTS%%%%%%%%%%%%%%\n";
	finalResult(passed);
}

void LinkedListTester::finalResult(bool passed)
{
	if(passed) {
			std::cout << "\nCongratulations! Your Linked List Passed!\n";
	}
	else {
			std::cout << "\nUnfortunately your Linked List failed as one or more tests failed.\n";
	}

}
int* LinkedListTester::createRandomArray(int size)
{
	int* array = new int[size];
	for(int i = 0; i < size; i++) {
		array[i] = rand() % 50 - 25;
	}
	return array;
}

bool LinkedListTester::printResult(bool passed, int& testNumber, std::string testMessage)
{
	if(passed) {
			std::cout << "Test " << testNumber << " has passed (" << testMessage << ")\n";
	}
	else {
			std::cout << "Test " << testNumber << " has failed (" << testMessage << ")\n";
		}
	testNumber++;
	return passed;
}

int LinkedListTester::createRandomint()
{
			return (int) rand()*RAND_MAX % 50;
}

LinkedListOfInts* LinkedListTester::createList(int* array, int size)
{
	LinkedListOfInts* linkedList = new LinkedListOfInts();
	for(int i = size - 1; i >= 0; i--) {
		 linkedList->addFront(array[i]);
	}
	return linkedList;
}

bool LinkedListTester::compareListArray(const LinkedListOfInts& list1, int* array, unsigned arrSize) const
{
	std::vector<int> listVector = list1.toVector();
	if(listVector.size() != arrSize) {
		std::cout << "Comparesize" << listVector.size() << " to " << arrSize << std::endl;
		return false;
	}
	for(unsigned int i = 0; i < listVector.size(); i++)
	{
		if(listVector[i] != array[i]) {
			return false;
		}
 	}
	return true;
}

//size of empty list is zero
bool LinkedListTester::test01()
{
	bool passed = false;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	if(LinkedListOfInts->size() == 0)
	{
		passed = true;
	}
	delete LinkedListOfInts;
	return passed;
}

//size returns correct value after addFront of empty list
bool LinkedListTester::test02()
{
	bool passed = false;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	LinkedListOfInts->addFront(createRandomint());
	if(LinkedListOfInts->size() ==  1)
	{
		passed = true;
	}

	delete LinkedListOfInts;
	return passed;
}

//size returns correct value after addBack of empty list
bool LinkedListTester::test03()
{
	bool passed = false;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	LinkedListOfInts->addBack(createRandomint());
	if(LinkedListOfInts->size() ==  1)
	{
		passed = true;
	}

	delete LinkedListOfInts;
	return passed;
}


//size returns correct value after addFront and removeFront of empty list
bool LinkedListTester::test04()
{
	bool passed = false;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	LinkedListOfInts->addFront(createRandomint());
	LinkedListOfInts->removeFront();
	if(LinkedListOfInts->size() ==  0)
	{
		passed = true;
	}

	delete LinkedListOfInts;
	return passed;
}

//size returns correct value after addFront and removeBack of empty list
bool LinkedListTester::test05()
{
	bool passed = false;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	LinkedListOfInts->addFront(createRandomint());
	LinkedListOfInts->removeBack();
	if(LinkedListOfInts->size() ==  0)
	{
		passed = true;
	}

	delete LinkedListOfInts;
	return passed;
}

//size returns correct value after addBack and removeFront of empty list
bool LinkedListTester::test06()
{
	bool passed = false;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	LinkedListOfInts->addBack(createRandomint());
	LinkedListOfInts->removeFront();
	if(LinkedListOfInts->size() ==  0)
	{
		passed = true;
	}

	delete LinkedListOfInts;
	return passed;
}

//size returns correct value after addBack and removeBack of empty list
bool LinkedListTester::test07()
{
	bool passed = false;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	LinkedListOfInts->addBack(createRandomint());
	LinkedListOfInts->removeBack();
	if(LinkedListOfInts->size() ==  0)
	{
		passed = true;
	}

	delete LinkedListOfInts;
	return passed;
}

//size returns correct value of large list
bool LinkedListTester::test08()
{
	bool passed = false;
	int* array = createRandomArray(m_largeSize);
	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
	if(LinkedListOfInts->size() == m_largeSize)
	{
		passed = true;
	}
	delete[] array;
	delete LinkedListOfInts;
	return passed;
}

//size returns correct value after addBack of large list
bool LinkedListTester::test09()
{
	bool passed = false;
	int* array = createRandomArray(m_largeSize);
	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
	LinkedListOfInts->addBack(createRandomint());
	if(LinkedListOfInts->size() == m_largeSize + 1)
	{
		passed = true;
	}
	delete[] array;
	delete LinkedListOfInts;
	return passed;
}

//size returns correct value after removeFront of large list
bool LinkedListTester::test10()
{
	bool passed = false;
	int* array = createRandomArray(m_largeSize);
	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
	LinkedListOfInts ->removeFront();
	if(LinkedListOfInts->size() == m_largeSize - 1)
	{
		passed = true;
	}
	delete[] array;
	delete LinkedListOfInts;
	return passed;
}

//size returns correct value after removeBack of large list
bool LinkedListTester::test11()
{
	bool passed = false;
	int* array = createRandomArray(m_largeSize);
	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
	LinkedListOfInts ->removeBack();
	if(LinkedListOfInts->size() == m_largeSize - 1)
	{
		passed = true;
	}
	delete[] array;
	delete LinkedListOfInts;
	return passed;
}



bool LinkedListTester::test12()
{
	bool passed = true;
	for(int i = 1; i <= 100; i++)
	{
		int* array = createRandomArray(i);
		LinkedListOfInts* LinkedListOfInts = createList(array, i);
		try {
			passed = passed && compareListArray((*LinkedListOfInts), array, i);
		}
		catch (std::runtime_error& rte) {
			passed = false;
		}
		delete[] array;
		delete LinkedListOfInts;
	}
	return passed;
}


bool LinkedListTester::test13()
{
	bool passed = true;
	for(int i = 1; i <= 100; i++)
	{
		int* array = createRandomArray(i);
		LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
		try {
			for(int j = i-1; j >= 0; j--) {
				LinkedListOfInts->addBack(array[j]);
			}
			passed = passed && compareListArray((*LinkedListOfInts), array, i);
		}
		catch (std::runtime_error& rte) {
			passed = false;
		}
		delete[] array;
		delete LinkedListOfInts;
	}
	return passed;
}

bool LinkedListTester::test14()
{
	bool passed = true;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	try {
		passed = passed && (LinkedListOfInts->isEmpty()) ;
	}
	catch (std::runtime_error& rte) {
		passed = false;
	}
	delete LinkedListOfInts;
	return passed;
}

bool LinkedListTester::test15()
{
	bool passed = true;
	for(int i = 1; i <= 100; i++)
	{
		int* array = createRandomArray(i);
		LinkedListOfInts* LinkedListOfInts = createList(array, i);
		try {
			passed = passed && (!LinkedListOfInts->isEmpty()) ;
		}
		catch (std::runtime_error& rte) {
			passed = false;
		}
		delete[] array;
		delete LinkedListOfInts;
	}
	return passed;
}



bool LinkedListTester::test16()
{
	bool passed = true;
	for(int i = -1*m_largeSize; i <= m_largeSize; i++)
	{
		int* array = nullptr;
		LinkedListOfInts* LinkedListOfInts = createList(array, 0);
		try {
			passed = passed && !LinkedListOfInts->search(i);
		}
		catch (std::runtime_error& rte) {
			passed = false;
		}
		delete LinkedListOfInts;
	}
	return passed;
}

bool LinkedListTester::test17()
{
	bool passed = true;
	for(int i = 1; i <= 100; i++)
	{
		int* array = createRandomArray(i);
		LinkedListOfInts* LinkedListOfInts = createList(array, i);
		try {
			for (int j = 0; j < i; j++) {
				passed = passed && (LinkedListOfInts->search(array[j]));
			}
		}
		catch (std::runtime_error& rte) {
			passed = false;
		}
		delete[] array;
		delete LinkedListOfInts;
	}
	return passed;
}

bool LinkedListTester::test18()
{
	bool passed = true;
	for(int i = 1; i <= 100; i++)
	{
		int* array = createRandomArray(i);
		LinkedListOfInts* LinkedListOfInts = createList(array, i);
		try {
			for(int repeat = 0; repeat < 100; repeat++) {
				bool randInArray = false;
				int randInt = 0;
				do {
					randInArray = false;
					randInt = rand() % 200 - 100;
					for (int j = 0; j < i; j++) {
						if(randInt == array[j]) {
							randInArray = true;
						}
					}
				}while(randInArray);
				passed = passed && !LinkedListOfInts->search(randInt);
			}
		}
		catch (std::runtime_error& rte) {
			passed = false;
		}
		delete[] array;
		delete LinkedListOfInts;
	}
	return passed;
}

bool LinkedListTester::test19()
{
	bool passed = true;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	try {
		passed = passed && !LinkedListOfInts->removeFront();
	}
	catch (std::runtime_error& rte) {
		passed = false;
	}
	delete LinkedListOfInts;
	return passed;
}


bool LinkedListTester::test20()
{
	bool passed = true;
	int* array = createRandomArray(1);
	LinkedListOfInts* LinkedListOfInts = createList(array, 1);
	try {
		passed = passed && LinkedListOfInts->removeFront();
		passed = passed && (LinkedListOfInts->toVector().size() == 0);
	}
	catch (std::runtime_error& rte) {
		passed = false;
	}
	delete LinkedListOfInts;
	return passed;
}

bool LinkedListTester::test21()
{
	bool passed = true;
	for(int i = 2; i < m_largeSize; i++) {
		int* array = createRandomArray(i);
		LinkedListOfInts* LinkedListOfInts = createList(array, i);
		try {
			passed = passed && LinkedListOfInts->removeFront();
			passed = passed && compareListArray((*LinkedListOfInts), array + 1, i - 1);
		}
		catch (std::runtime_error& rte) {
			passed = false;
		}
		delete LinkedListOfInts;
	}
	return passed;
}

bool LinkedListTester::test22()
{
	bool passed = true;
	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
	try {
		passed = passed && !LinkedListOfInts->removeBack();
	}
	catch (std::runtime_error& rte) {
		passed = false;
	}
	delete LinkedListOfInts;
	return passed;
}


bool LinkedListTester::test23()
{
	bool passed = true;
	int* array = createRandomArray(1);
	LinkedListOfInts* LinkedListOfInts = createList(array, 1);
	try {
		passed = passed && LinkedListOfInts->removeBack();
		passed = passed && (LinkedListOfInts->toVector().size() == 0);
	}
	catch (std::runtime_error& rte) {
		passed = false;
	}
	delete LinkedListOfInts;
	return passed;
}

bool LinkedListTester::test24()
{
	bool passed = true;
	for(int i = 2; i < m_largeSize; i++) {
		int* array = createRandomArray(i);
		LinkedListOfInts* LinkedListOfInts = createList(array, i);
		try {
			passed = passed && LinkedListOfInts->removeBack();
			passed = passed && compareListArray((*LinkedListOfInts), array, i - 1);
		}
		catch (std::runtime_error& rte) {
			passed = false;
		}
		delete LinkedListOfInts;
	}
	return passed;
}

// //insert throws execption if given an invalid position too high in list of size 1
// bool LinkedListTester::test13()
// {
// 	bool passed = false;
// 	int* array = createRandomArray(1);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, 1);
// 	try {
// 		LinkedListOfInts->insert(3, createRandomint());
// 	}
// 	catch (std::runtime_error& rte) {
// 		passed = true;
// 	}
// 	delete[] array;
// 	delete LinkedListOfInts;
// 	return passed;
// 	return true;
// }
//
//
// //insert throws execption if given an invalid position too low in list of large size
// bool LinkedListTester::test14()
// {
// 	bool passed = false;
// 	int* array = createRandomArray(m_largeSize);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
// 	try {
// 		LinkedListOfInts->insert(0, createRandomint());
// 	}
// 	catch (std::runtime_error& rte) {
// 		passed = true;
// 	}
// 	delete[] array;
// 	delete LinkedListOfInts;
// 	return passed;
// }
//
//
// //insert works if given a valid position in list of large size
// bool LinkedListTester::test15()
// {
// 	bool passed = true;
// 	for(int i = 1; i <= m_largeSize + 1; i++)
// 	{
// 		int* array = createRandomArray(m_largeSize);
// 		LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
// 		try {
// 			LinkedListOfInts->insert(i, createRandomint());
// 		}
// 		catch (std::runtime_error& rte) {
// 			passed = false;
// 		}
// 		delete[] array;
// 		delete LinkedListOfInts;
// 	}
// 	return passed;
// }
//
//
// //insert throws execption if given an invalid position too high in list of large size
// bool LinkedListTester::test16()
// {
// 	bool passed = false;
// 	int* array = createRandomArray(m_largeSize);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
// 	try {
// 		LinkedListOfInts->insert(m_largeSize + 2, createRandomint());
// 	}
// 	catch (std::runtime_error& rte) {
// 		passed = true;
// 	}
// 	delete[] array;
// 	delete LinkedListOfInts;
// 	return passed;
// }
//
//
// //insert at begining adds the correct value and does not affect other nodes in the list
// bool LinkedListTester::test17()
// {
// 	bool passed = true;
// 	int* array = createRandomArray(m_largeSize);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
// 	int random = createRandomint();
// 	try {
// 		LinkedListOfInts->addFront(random);
// 		if(LinkedListOfInts->getEntry(1) != random)
// 			passed = false;
// 		for(int i = 1; i <= m_largeSize; i++)
// 			if(LinkedListOfInts->getEntry(i+1) != array[i-1])
// 				passed = false;
// 	}
// 	catch (std::runtime_error& rte) {
// 		passed = false;
// 	}
// 	delete[] array;
// 	delete LinkedListOfInts;
// 	return passed;
// }
//
//
// //insert in middle adds the correct value and does not affect other nodes in the list
// bool LinkedListTester::test18()
// {
// 	bool passed = true;
// 	int* array = createRandomArray(m_largeSize);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
// 	int random = createRandomint();
// 	try {
// 		LinkedListOfInts->insert(m_largeSize/2, random);
// 		if(LinkedListOfInts->getEntry(m_largeSize/2) != random)
// 			passed = false;
// 		for(int i = 1; i < m_largeSize/2; i++)
// 			if(LinkedListOfInts->getEntry(i) != array[i-1])
// 				passed = false;
// 		for(int i = m_largeSize/2 + 1; i <= m_largeSize + 1; i++)
// 				if(LinkedListOfInts->getEntry(i) != array[i-2])
// 					passed = false;
// 	}
// 	catch (std::runtime_error& rte) {
// 		passed = false;
// 	}
// 	delete[] array;
// 	delete LinkedListOfInts;
// 	return passed;
// }
//
//
// //insert in end adds the correct value and does not affect other nodes in the list
// bool LinkedListTester::test19()
// {
// 	bool passed = true;
// 	int* array = createRandomArray(m_largeSize);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
// 	int random = createRandomint();
// 	try {
// 		LinkedListOfInts->insert(m_largeSize + 1, random);
// 		if(LinkedListOfInts->getEntry(m_largeSize + 1) != random)
// 			passed = false;
// 		for(int i = 1; i <= m_largeSize; i++)
// 			if(LinkedListOfInts->getEntry(i) != array[i-1])
// 				passed = false;
// 	}
// 	catch (std::runtime_error& rte) {
// 		passed = false;
// 	}
// 	delete[] array;
// 	delete LinkedListOfInts;
// 	return passed;
// }

// /******************************************
// replace tests*/
//
// //@brief replace throws in empty list
// bool LinkedListTester::test20()
// {
// 	bool passed = true;
// 	for(int i = -1*m_largeSize; i <= m_largeSize; i++)
// 	{
// 		int* array = nullptr;
// 		LinkedListOfInts* LinkedListOfInts = createList(array, 0);
// 		try {
// 			LinkedListOfInts->replace(i, createRandomint());
// 			passed = false;
// 		}
// 		catch (std::runtime_error& rte) {
// 		}
// 		delete LinkedListOfInts;
// 	}
// 	return passed;
// }
//
// //@brief replace only works with replace 1 in list of size 1;
// bool LinkedListTester::test49()
// {
// 	bool passed = true;
// 	for(int i = -1*m_largeSize; i <= m_largeSize; i++)
// 	{
// 		int* array = createRandomArray(1);
// 		LinkedListOfInts* LinkedListOfInts = createList(array, 1);
// 		try {
// 			LinkedListOfInts->replace(i, createRandomint());
// 			if(i != 1)
// 				passed = false;
// 		}
// 		catch (std::runtime_error& rte) {
// 			if(i != 1)
// 				passed = true;
// 		}
// 		delete[] array;
// 		delete LinkedListOfInts;
// 	}
// 	return passed;
// }
//
// //@brief replace works with list of large size;
// bool LinkedListTester::test24()
// {
// 	bool passed = true;
// 	for(int i = -1*m_largeSize; i <= m_largeSize; i++)
// 	{
// 		int* array = createRandomArray(m_largeSize);
// 		int random = createRandomint();
// 		LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
// 		try {
// 			LinkedListOfInts->replace(i, random);
// 			array[i-1] =  random;
// 				passed = compareListArray((*LinkedListOfInts), array, i);
// 		}
// 		catch (std::runtime_error& rte) {
// 			if(i < 1 && i >= m_largeSize)
// 				passed = false;
// 		}
// 		delete[] array;
// 		delete LinkedListOfInts;
// 	}
// 	return passed;
// }
//
//
//
// /******************************************
// Copy Constructor tests*/
//
//
// //copy constructor works with empty list
// bool LinkedListTester::test21()
// {
// 	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
// 	bool passed = copyConstructorTest((*LinkedListOfInts), nullptr);
// 	delete LinkedListOfInts;
// 	return passed;
// }
//
//
// //copy constructor works with list of size 1
// bool LinkedListTester::test22()
// {
// 	int* array = createRandomArray(1);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, 1);
// 	bool passed = copyConstructorTest((*LinkedListOfInts), array);
// 	delete LinkedListOfInts;
// 	delete[] array;
// 	return passed;
// }
//
//
// //copy constructor works with list of large size
// bool LinkedListTester::test23()
// {
// 	int* array = createRandomArray(1);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, 1);
// 	bool passed = copyConstructorTest((*LinkedListOfInts), array);
// 	delete LinkedListOfInts;
// 	delete[] array;
// 	return passed;
// }
//
//
// /******************************************
// Assignment operator tests*/
//
// //Assignment operator works with empty list
// bool LinkedListTester::test25()
// {
// 	LinkedListOfInts* LinkedListOfIntsptr = createList(nullptr, 0);
// 	LinkedListOfInts* LinkedListOfInts2ptr = createList(nullptr, 0);
// 	LinkedListOfInts LinkedListOfInts = (*LinkedListOfIntsptr);
// 	LinkedListOfInts LinkedListOfInts2 = (*LinkedListOfInts2ptr);
// 	delete LinkedListOfIntsptr;
// 	delete LinkedListOfInts2ptr;
// 	bool passed = true;
// 	try {
// 		LinkedListOfInts = LinkedListOfInts2;
// 	}
// 	catch (std::runtime_error& rte){
// 		passed = false;
// 	}
// 	return passed;
// }
//
//
// //Assignment operator works with list of size 1
// bool LinkedListTester::test26()
// {
// 	int* array = createRandomArray(1);
// 	int* array2 = createRandomArray(1);
// 	LinkedListOfInts* LinkedListOfIntsptr = createList(array, 1);
// 	LinkedListOfInts* LinkedListOfInts2ptr = createList(array2, 1);
// 	LinkedListOfInts LinkedListOfInts = (*LinkedListOfIntsptr);
// 	LinkedListOfInts LinkedListOfInts2 = (*LinkedListOfInts2ptr);
// 	delete LinkedListOfIntsptr;
// 	delete LinkedListOfInts2ptr;
// 	bool passed = true;
// 	try {
// 		LinkedListOfInts = LinkedListOfInts2;
// 	}
// 	catch (std::runtime_error& rte){
// 		passed = false;
// 	}
// 	passed = compareListArray(LinkedListOfInts, array2);
// 	delete[] array;
// 	delete[] array2;
// 	return passed;
// }
//
//
// //Assignment operator works with list of large size
// bool LinkedListTester::test27()
// {
// 	int* array = createRandomArray(m_largeSize);
// 	int* array2 = createRandomArray(m_largeSize);
// 	LinkedListOfInts* LinkedListOfIntsptr = createList(array, m_largeSize);
// 	LinkedListOfInts* LinkedListOfInts2ptr = createList(array2, m_largeSize);
// 	LinkedListOfInts LinkedListOfInts = (*LinkedListOfIntsptr);
// 	LinkedListOfInts LinkedListOfInts2 = (*LinkedListOfInts2ptr);
// 	delete LinkedListOfIntsptr;
// 	delete LinkedListOfInts2ptr;
// 	bool passed = true;
// 	try {
// 		LinkedListOfInts = LinkedListOfInts2;
// 	}
// 	catch (std::runtime_error& rte){
// 		passed = false;
// 	}
// 	passed = compareListArray(LinkedListOfInts, array2);
// 	delete[] array;
// 	delete[] array2;
// 	return passed;
// }
//
//
// /******************************************
// Empty method tests*/
//
// //isEmpty() returns true for empty list
// bool LinkedListTester::test28()
// {
// 	LinkedListOfInts LinkedListOfInts;
// 	return LinkedListOfInts.isEmpty();
// }
//
//
// //isEmpty() returns false for list of size 1
// bool LinkedListTester::test29()
// {
// 	int* array = createRandomArray(1);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, 1);
// 	bool passed = (!LinkedListOfInts->isEmpty());
// 	delete LinkedListOfInts;
// 	delete[] array;
// 	return passed;
// }
//
//
// //isEmpty() returns false for list of large size
// bool LinkedListTester::test30()
// {
// 	int* array = createRandomArray(m_largeSize);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
// 	bool passed = (!LinkedListOfInts->isEmpty());
// 	delete LinkedListOfInts;
// 	delete[] array;
// 	return passed;
// }
//
//
// /******************************************
// remove method tests*/
//
// //@brief remove throws in empty list
// bool LinkedListTester::test31()
// {
// 	bool passed = true;
// 	for(int i = -1*m_largeSize; i <= m_largeSize; i++)
// 	{
// 		int* array = nullptr;
// 		LinkedListOfInts* LinkedListOfInts = createList(array, 0);
// 		try {
// 			LinkedListOfInts->remove(i);
// 			passed = false;
// 		}
// 		catch (std::runtime_error& rte) {
// 		}
// 		delete LinkedListOfInts;
// 	}
// 	return passed;
// }
//
// //@brief remove only works with remove 1 in list of size 1;
// bool LinkedListTester::test32()
// {
// 	bool passed = true;
// 	for(int i = -1*m_largeSize; i <= m_largeSize; i++)
// 	{
// 		int* array = createRandomArray(1);
// 		LinkedListOfInts* LinkedListOfInts = createList(array, 1);
// 		try {
// 			LinkedListOfInts->remove(i);
// 			if(i != 1)
// 			{
// 				passed = false;
// 			}
// 			else
// 			{
// 				passed = passed & LinkedListOfInts->isEmpty();
// 			}
// 		}
// 		catch (std::runtime_error& rte) {
// 			if(i == 1)
// 				passed = false;
// 		}
// 		delete[] array;
// 		delete LinkedListOfInts;
// 	}
// 	return passed;
// }
//
// //@brief remove works with list of large size;
// bool LinkedListTester::test33()
// {
// 	bool passed = true;
// 	for(int i = -1*m_largeSize; i <= m_largeSize; i++)
// 	{
// 		int* array = createRandomArray(m_largeSize);
// 		LinkedListOfInts* LinkedListOfInts = createList(array, m_largeSize);
// 		try {
// 		LinkedListOfInts->remove(i);
// 		int counter = 0;
// 		for(int j = 0; j < m_largeSize; j++)
// 		{
// 			if(j != i-1)
// 			{
// 				array[counter] = array[j];
// 				counter ++;
// 			}
// 		}
// 		passed = (LinkedListOfInts->size() == m_largeSize - 1);
// 		passed = compareListArray((*LinkedListOfInts),array);
// 		}
// 		catch (std::runtime_error& rte) {
// 			if(i >= 1 && i <= m_largeSize)
// 			{
// 				passed = false;
// 			}
// 		}
// 		delete[] array;
// 		delete LinkedListOfInts;
// 	}
// 	return passed;
// }
//
//
// /******************************************
// clear method tests*/
//
// //clear works correctly in empty list
// bool LinkedListTester::test39()
// {
// 	LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
// 	LinkedListOfInts->clear();
// 	bool passed = LinkedListOfInts->isEmpty();
// 	delete LinkedListOfInts;
// 	return passed;
// }
//
//
// //clear works correctly in list of size 1
// bool LinkedListTester::test40()
// {
// 	int* array = createRandomArray(1);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, 1);
// 	LinkedListOfInts->clear();
// 	delete[] array;
// 	bool passed = LinkedListOfInts->isEmpty();
// 	delete LinkedListOfInts;
// 	return passed;
// }
//
//
// //clear works correctly in list of large size
// bool LinkedListTester::test41()
// {
// 	int* array = createRandomArray(m_largeSize);
// 	LinkedListOfInts* LinkedListOfInts = createList(array, 1);
// 	LinkedListOfInts->clear();
// 	delete[] array;
// 	bool passed = LinkedListOfInts->isEmpty();
// 	delete LinkedListOfInts;
// 	return passed;
// }
//
//
// /******************************************
// getEntry method tests*/
//
// //getEntry throws exception if given any position in empty list
// bool LinkedListTester::test42()
// {
// 	bool passed = true;
// 	for(int i = -1*m_largeSize; i <= m_largeSize; i++)
// 	{
// 		LinkedListOfInts* LinkedListOfInts = createList(nullptr, 0);
// 		try {
// 		LinkedListOfInts->getEntry(i);
// 		passed = false;
// 		}
// 		catch (std::runtime_error& rte) {
// 		}
// 		delete LinkedListOfInts;
// 	}
// 	return passed;
// }
//
//
// //getEntry operates with correct behavior with size at and above 1
// bool LinkedListTester::test43()
// {
// 	bool passed = true;
// 	for(int size = 1; size <= m_largeSize; size++)
// 	{
// 		for(int i = -1*size; i <= size*2; i++)
// 		{
// 			int* array = createRandomArray(size);
// 			LinkedListOfInts* LinkedListOfInts = createList(array, size);
// 			try {
// 				LinkedListOfInts->getEntry(i);
// 				if(i < 1 || i > size)
// 				{
// 					passed = false;
// 				}
// 				else
// 				{
// 					passed = passed && compareListArray((*LinkedListOfInts), array, i);
// 				}
// 			}
// 			catch (std::runtime_error& rte) {
// 			}
// 			delete[] array;
// 			delete LinkedListOfInts;
// 		}
// 	}
// 	return passed;
// }
