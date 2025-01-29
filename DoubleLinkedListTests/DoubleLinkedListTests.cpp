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
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
			Assert::AreEqual(0, list.getLength());
		}

		TEST_METHOD(InitializeListConstructor)
		{
			List<int> list = { 9, 8, 7, 6, 5 };

			Iterator<int> iter = list.begin();
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
			//Assert::AreEqual(*(list.begin()++), 2);
			Assert::AreEqual(2, (*(list.begin()++)));
			Assert::AreEqual(1, list.last());
			Assert::AreEqual(3, list.getLength());
		}

		TEST_METHOD(PushBack)
		{
			List<int> list;
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
			/*list.popFront();
			Assert::AreEqual(4, list.first());*/
		}

		TEST_METHOD(PopBack)
		{

		}

		TEST_METHOD(Insert)
		{
			List<int> list{ 5, 4, 10 };
			/*list.insert(4, 2);
			Assert::AreEqual(2, list.first());*/
		}

		TEST_METHOD(Remove)
		{
			List<int> list{ 2, 4, 5, 7 };
			list.remove(2);
			Assert::AreEqual(4, list.first());
		}

		TEST_METHOD(First)
		{
			List<int> list{ 5, 10, 25, 33, 42 };
			Assert::AreEqual(list.first(), 5);
		}

		TEST_METHOD(Last)
		{
			List<int> list{ 0, 2, 3 };
			Assert::AreEqual(3, list.last());
		}

		TEST_METHOD(Begin)
		{

		}

		TEST_METHOD(End)
		{

		}

		TEST_METHOD(Destroy)
		{

		}

		TEST_METHOD(GetLength)
		{
			List<int> list{ 0 };
			Assert::AreEqual(1, list.getLength());
		}
	};
}
