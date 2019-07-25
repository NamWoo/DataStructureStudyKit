#include "Tester.h"
#include <iostream>
#include "TestInitialization.h"
#include "TestSearch.h"
#include "TestInsertion.h"
#include "Test.h"
#include "TestDelete.h"

void PrintCrash()
{
	std::cout <<"\n looks like crash at test : "<< global::CurrentTestNumber << '/' << global::TotalTestNumber<<std::endl;
}


void TestAll()
{
	remove("./ReportFile.txt");// ���۽� ����Ʈ ���� ���� 
	TestInitialization();
	TestInsertion();
	TestSearch();
	TestDelete();
	std::cout << '\n' << global::CurrentTestNumber << '/' << global::TotalTestNumber << " \n\n\n " << std::endl;
	
	if (global::CurrentTestNumber < global::TotalTestNumber)
	{
		atexit(PrintCrash);
	}
	global::ReportFileStream.close();
	
	

	std::cout << "\n\n\n �׽�Ʈ ����   ������ : "<<global::TotalScore<<'/'<<global::TotalTestNumber<<  " \n\n\n " << std::endl;



}