#include "Tester.h"
#include <iostream>
#include "TestInitialization.h"
#include "TestSearch.h"
#include "TestInsertion.h"
#include "Test.h"


void TestAll()
{
	remove("./ReportFile.txt");// ���۽� ����Ʈ ���� ���� 
	TestInitialization();
	TestInsertion();
	TestSearch();

	global::ReportFileStream.close();
}