#include "Tester.h"
#include <iostream>
#include "TestInitialization.h"
#include "TestSearch.h"
#include "TestInsertion.h"
#include "Test.h"
#include "TestDelete.h"


void TestAll()
{
	remove("./ReportFile.txt");// ���۽� ����Ʈ ���� ���� 
	TestInitialization();
	TestInsertion();
	TestSearch();
	TestDelete();

	global::ReportFileStream.close();
}