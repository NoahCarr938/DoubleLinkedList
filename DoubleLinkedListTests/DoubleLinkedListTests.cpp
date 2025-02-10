#include "pch.h"
#include "CppUnitTest.h"
#include "List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoubleLinkedListTests
{
	TEST_CLASS(DoubleLinkedListTests)
	{
	public:
		
		TEST_METHOD(DefaultConstructor)
		{
			List<int> list;
			Assert::IsNotNull(&list);
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());
		}

		TEST_METHOD(InitializeListConstructor)
		{
			List<int> list = { 9, 8, 7, 6, 5 };

			Iterator<int> iter = list.begin();
			Assert::IsNotNull(&list);
			Assert::AreEqual(9, *iter);
			iter++;
			Assert::AreEqual(8, *iter);
			iter++;
			Assert::AreEqual(7, *iter);
			iter++;
			Assert::AreEqual(6, *iter);
			iter++;
			Assert::AreEqual(5, *iter);
			Assert::AreEqual(5, list.getLength());
		}

		TEST_METHOD(PushFront)
		{
			List<int> list;
			Assert::IsNotNull(&list);
			list.pushFront(1);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.pushFront(2);
			Assert::AreEqual(2, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(2, list.getLength());

			list.pushFront(3);
			Assert::AreEqual(3, list.first());
			// list.begin returns an iterator
			Assert::AreEqual(2, (*(list.begin()++)));
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PushBack)
		{
			List<int> list;
			Assert::IsNotNull(&list);
			list.pushBack(1);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(1, list.getLength());

			list.pushBack(2);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, list.last());
			Assert::AreEqual(2, list.getLength());

			list.pushBack(3);
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, (*(list.begin()++)));
			Assert::AreEqual(3, list.last());
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PopFront)
		{
			List<int> list{ 2, 4, 8 };
			Assert::IsNotNull(&list);
			list.popFront();
			Assert::AreEqual(2, list.getLength());
			list.popFront();
			Assert::AreEqual(8, list.first());
			list.insert(4, 0);
			Assert::AreEqual(4, list.first());
			list.insert(5, 2);
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PopBack)
		{
			List<int> list{ 3, 5, 7, 8, 12 };
			Assert::IsNotNull(&list);
			list.popBack();
			Assert::AreEqual(8, list.last());
			list.popBack();
			Assert::AreEqual(3, list.getLength());
			Assert::AreEqual(7, list.last());
			//list.remove(7);
			list.popBack();
			Assert::AreEqual(3, list.first());
			Assert::AreEqual(2, list.getLength());
		}

		TEST_METHOD(Insert)
		{
			List<int> list{ 5, 4, 10 };
			Assert::IsNotNull(&list);
			list.insert(4, 0);
			Assert::AreEqual(4, list.getLength());
			Assert::AreEqual(4, list.first());
			Assert::AreEqual(10, list.last());
			list.insert(5, 3);
			Assert::AreEqual(5, list.getLength());
			Assert::AreEqual(4, list.first());
			Assert::AreEqual(10, list.last());
			for (size_t i = 0; i < 1000; i++)
			{
				list.insert(10, 0);
			}
			Assert::AreEqual(1005, list.getLength());
			Assert::AreEqual(10, list.first());
			Assert::AreEqual(10, list.last());
			for (size_t i = 0; i < 6; i++)
			{
				list.insert(5, 0);
				list.insert(3, 1006);
			}
			Assert::AreEqual(1017, list.getLength());
			Assert::AreEqual(5, list.first());
			Assert::AreEqual(3, list.last());
		}

		TEST_METHOD(Remove)
		{
			List<int> list{};
			Assert::IsNotNull(&list);

			list.pushBack(1);
			list.pushBack(0);
			list.pushBack(1);
			list.pushBack(2);
			list.pushBack(1);
			list.pushBack(3);
			list.pushBack(1);
			Assert::AreEqual(7, list.getLength());
			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(1, *iter);

			// Normal remove, removes head and tail
			int count = list.remove(1);
			Assert::AreEqual(4, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(*iter, list.first());
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::IsTrue(iter == nullptr);

			// Removing value not present in the list
			count = list.remove(5);
			Assert::AreEqual(0, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);

			// Test for the entire list being the same value
			list = List<int>();
			Assert::IsNotNull(&list);
			list.pushBack(3);
			list.pushBack(3);
			list.pushBack(3);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			list.remove(3);
			count = list.remove(3);
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
		}

		TEST_METHOD(First)
		{
			List<int> list{ 5, 10, 25, 33, 42 };
			Assert::IsNotNull(&list);
			Assert::AreEqual(5, list.first());
			list.remove(5);
			Assert::AreEqual(10, list.first());
			list.remove(10);
			list.remove(25);
			Assert::AreEqual(33, list.first());
			list.insert(3, 0);
			Assert::AreEqual(3, list.first());
		}

		TEST_METHOD(Last)
		{
			List<int> list{ 0, 2, 3 };
			Assert::IsNotNull(&list);
			Assert::AreEqual(3, list.last());
			list.remove(3);
			Assert::AreEqual(2, list.last());
			list.remove(2);
			Assert::AreEqual(0, list.last());
			list.insert(17, 1);
			Assert::AreEqual(17, list.last());
		}

		TEST_METHOD(Begin)
		{
			List<int> list{ 5, 12, 2, 34, 43, 1, 23, 4 };
			Assert::IsNotNull(&list);
			Iterator<int> iter = list.begin();
			Assert::AreEqual(5, (*(list.begin())));
			Assert::AreEqual(12, (*(list.begin()++)));
			list.remove(5);
			Assert::AreEqual(12, (*(list.begin())));
			list.insert(1, 0);
			Assert::AreEqual(1, (*list.begin()));
		}

		TEST_METHOD(End)
		{
			List<int> list = { 5, 79, 35, 2, 0 };
			Assert::IsNotNull(&list);
			Iterator<int> iter = list.end();
			Assert::IsTrue(iter == nullptr);
			Iterator<int> iter2 = list.begin();
			Assert::AreEqual(5, *iter2);
			iter2++;
			Assert::AreEqual(79, *iter2);
			iter2++;
			Assert::AreEqual(35, *iter2);
			iter2++;
			Assert::AreEqual(2, *iter2);
			iter2++;
			Assert::AreEqual(0, *iter2);
			iter2++;
			Assert::IsTrue(iter2 == nullptr);
		}

		TEST_METHOD(Destroy)
		{
			List<int> list{ 4, 2, 10 };
			Assert::IsNotNull(&list);
			Iterator<int> iter = list.end();
			list.destroy();
			Assert::AreEqual(0, list.getLength());
			list.insert(1, 0);
			Assert::AreEqual(1, list.getLength());
			list.insert(2, 1);
			list.destroy();
			Assert::AreEqual(0, list.getLength());
			Assert::IsTrue(iter == nullptr);
		}

		TEST_METHOD(GetLength)
		{
			List<int> list{ 0 };
			Assert::IsNotNull(&list);
			list.remove(0);
			Assert::AreEqual(0, list.getLength());
			list.insert(1, 0);
			Assert::AreEqual(1, list.getLength());
			list.insert(1, 0);
			Assert::AreEqual(2, list.getLength());
			list.insert(3, 2);
			Assert::AreEqual(3, list.getLength());
			list.remove(3);
			Assert::AreEqual(2, list.getLength());
			list.destroy();
			Assert::AreEqual(0, list.getLength());
			list.remove(0);
			Assert::AreEqual(0, list.getLength());
		}

		// Usage for List
		// Main point of usage tests are to try stupid stuff to break it.
		// Make a seperate class to test iterators
		// Make a seperate class for node (will be a short and simple class)

		// A Linked List Usage Test for ints
		TEST_METHOD(LinkedListUsageTest1)
		{
			List<int> list{ 0 };
			Assert::AreEqual(1, list.getLength());
			for (size_t i = 0; i < 1000; i++)
			{
				list.insert(1, 0);
			}
			Assert::AreEqual(1001, list.getLength());
			for (int i = 0; i < 1000; i++)
			{
				list.remove(1);
			}
			Assert::AreEqual(1, list.getLength());
		}

		// A second Linked List Usage Test for ints
		TEST_METHOD(LinkedListUsageTest2)
		{
			List<int> list{0, 1, 10};
			Assert::AreEqual(3, list.getLength());
			for (size_t i = 0; i < 500; i++)
			{
				list.remove(0);
			}
			Assert::AreEqual(2, list.getLength());
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(10, list.last());
		}

		// A Linked List Usage Test for floats
		TEST_METHOD(LinkedListUsageTest3)
		{
			List<float> list{ 4.79, 12.2, 9.9 };
			Assert::IsNotNull(&list);
			Iterator<float> iter = list.end();
			for (size_t i = 0; i < 500; i++)
			{
				list.insert(45.2, 0);
				list.insert(34.7, 1);
			}
			Assert::AreEqual(1003, list.getLength());
			for (size_t i = 0; i < 5000; i++)
			{
				list.insert(45.22, 2);
			}
			Assert::AreEqual(6003, list.getLength());
			for (size_t i = 0; i < 6001; i++)
			{
				list.popFront();
			}
			Assert::AreEqual(2, list.getLength());
			list.popBack();
			Assert::AreEqual(1, list.getLength());
			list.popBack();
			Assert::AreEqual(0, list.getLength());
			list.destroy();
			Assert::IsTrue(iter == nullptr);
		}

		// A Linked List Usage Test for const char*
		TEST_METHOD(LinkedListUsageTest4)
		{
			List<const char*> list{ "Pam", "Jim", "Michael", "Michael Scotch", "Michael Scarn", "Prison Mike", "Dwight", "Stanley"};
			Assert::IsNotNull(&list);
			Iterator<const char*> iter = list.end();
			Assert::AreEqual(8, list.getLength());
			list.insert("Ryan", 3);
			list.insert("Kevin", 0);
			list.insert("Oscar", 0);
			list.insert("Angela", 0);
			list.insert("Kelly", 0);
			list.insert("Phyllis", 0);
			list.insert("Plop", 0);
			list.insert("Bob Vance, Vance Refrigeration", 0);
			list.insert("Creed", 0);
			Assert::AreEqual(17, list.getLength());
			list.remove("Bob Vance, Vance Refrigeration");
			Assert::AreEqual(16, list.getLength());
			Assert::AreEqual("Creed", list.first());
			Assert::AreEqual("Stanley", list.last());
			list.remove("Michael");
			list.remove("Pam");
			list.remove("Ryan");
			Assert::AreEqual(13, list.getLength());
			List<const char*> list2{};
			Assert::IsNotNull(&list2);
			Iterator<const char*> iter2 = list.end();
			list2.insert("Michael", 0);
			list2.insert("Pam", 0);
			list2.insert("Ryan", 0);
			Assert::AreEqual(3, list2.getLength());
			Assert::AreEqual("Ryan", list2.first());
			Assert::AreEqual("Michael", list2.last());
			list2.popBack();
			list2.popBack();
			list2.popBack();
			list2.destroy();
			Assert::AreEqual(0, list2.getLength());
			Assert::IsTrue(iter2 == nullptr);
			list.insert("Michael", 0);
			list.insert("Ryan", 0);
			list.insert("Pam", 0);
			Assert::AreEqual(16, list.getLength());
			Assert::AreEqual("Pam", list.first());
			Assert::AreEqual("Stanley", list.last());
		}
	};
}
