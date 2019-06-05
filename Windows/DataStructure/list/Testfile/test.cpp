#include "Tester.h"
#include <iostream>
#include "TestInitialization.h"
#include "TestInsertion.h"
#include "Test.h"


void TestAll()
{
	
	TestInitialization();
	TestInsertion();

	global::ReportFileStream.close();
}