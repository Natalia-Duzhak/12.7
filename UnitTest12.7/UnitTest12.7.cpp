#include "pch.h"
#include "CppUnitTest.h"
#include "../Project12.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest127
{
	TEST_CLASS(UnitTest127)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;
			int value = 4;
			Add(first, last, value);
			int v = Delete(first, last);
			Assert::AreEqual(v, 4);
		}
	};
}
