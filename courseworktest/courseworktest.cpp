#include "pch.h"
#include "CppUnitTest.h"
#include "../semestr_project//Calc.h"
#include "../semestr_project/Calc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace courseworktest
{
	TEST_CLASS(courseworktest)
	{
	public:
		calc* c;

		TEST_METHOD_INITIALIZE
		{
			c = new calc();
		}

		TEST_METHOD_CLEANUP{
			delete c;
		}
		
		TEST_METHOD(perform)
		{
		}
	};
}
