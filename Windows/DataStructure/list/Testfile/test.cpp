#include "Tester.h"
#include <iostream>
#include "TestInitialization.h"
#include "TestSearch.h"
#include "TestInsertion.h"
#include "Test.h"


void TestAll()
{
	remove("./ReportFile.txt");// 시작시 리포트 파일 제거 
	TestInitialization();
	TestInsertion();
	TestSearch();

	global::ReportFileStream.close();
}