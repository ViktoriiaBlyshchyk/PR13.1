#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Student\PR13.1\PR13.1\PR13.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int x = 1, n = 0;
			int t;
			t = (2 * n - 1 * 1.) / ((x * x) * (2 * n + 1));
			Assert::AreEqual(t, -1);
		}
	};
}
