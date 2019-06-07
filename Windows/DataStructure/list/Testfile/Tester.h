#pragma once
#include <iomanip>
#include <iostream>
#include <cassert>
#include "ReportFileStream.h"


typedef int(*VaFunc_t)(...);

enum ERROR_CODE
{
	SUCCESS = 0,
	FAIL = -1
};

template <typename... Args>
class Tester
{
private:
	int mNumberOfTestCases;
	int mCurrentScore;
	int mCurrentTestNum;
	char* mTesterDescription;
	VaFunc_t mCurrentTest;

public:
	Tester() = default;
	Tester(VaFunc_t funcToRegister, const char* description, int testCases);
	~Tester();
	void TestRegisteredFunc(int evaluateValue, Args... args, const char* description);
	void TestRegisteredFunc(int evaluateValue, Args... args);
	bool DataChecker(int evaluateValue, int data, const char*);
	bool MemoryLeakChecker();
};


template <typename... Args>
Tester<Args...>::Tester(VaFunc_t funcToRegister, const char* description, int testCases)
	: mCurrentTest((VaFunc_t)funcToRegister)
	, mNumberOfTestCases(testCases)
	, mCurrentScore(0)
	, mCurrentTestNum(0)
	, mTesterDescription((char*)description)
{
	global::TotalTestNumber += testCases;
	printf("====Test : %s  START====\n", description);

	//file 출력  
	global::ReportFileStream.open("./ReportFile.txt");
	global::ReportFileStream.seekg(0, std::ios::end);
	std::cout << "test start file output cursor: " << global::ReportFileStream.tellg() << std::endl;
	global::ReportFileStream << "===" << description << "started...===" << std::endl;
	
	global::ReportFileStream.seekg(0, std::ios::end);
	std::cout <<mTesterDescription<< " Tester init (after): "<< global::ReportFileStream.tellg() << std::endl;
}


template <typename... Args>
Tester<Args...>::~Tester()
{
	global::ReportFileStream.open("./ReportFile.txt", std::ios::out);
	global::ReportFileStream.seekg(0, std::ios_base::end);
	global::ReportFileStream << "===" << mTesterDescription << " over...===\n\n" << std::endl;

	if (mCurrentScore >= mNumberOfTestCases)
	{
		std::cout << std::setw(40) << std::setfill('=')<< "통과"<<std::endl;
	}

	std::cout  <<"Test Over, Your Score of "<<mTesterDescription <<" "<< mCurrentScore<<"/"<<mNumberOfTestCases<<" " <<std::setfill('=') <<std::endl;
}

template<typename... Args>
void Tester<Args...>::TestRegisteredFunc(int evaluateValue, Args... args)
{
	if (evaluateValue == mCurrentTest(args...))
	{
		std::cout << "함수반환값 체크" << std::setw(40) << std::setfill('=') << std::right << std::left << std::endl;
		printf("case Success, current score : %d out of  %d \n\n\n", ++mCurrentScore, mNumberOfTestCases);

		//파일 출력
		global::ReportFileStream << "successed... " << ++global::CurrentTestNumber << " test OK" << std::endl;
		global::ReportFileStream.seekg(0, std::ios_base::end);

	}
	else
	{
		std::cout << "Test Fail...not sure" << std::endl;
		global::ReportFileStream << "failed... " << ++global::CurrentTestNumber << std::endl;
		global::ReportFileStream.seekg(0, std::ios_base::end);
	}
}


template <typename... Args>
inline void Tester<Args...>::TestRegisteredFunc(int evaluateValue, Args... args, const char* description)
{

	if (evaluateValue == mCurrentTest(args...))
	{
		std::cout << std::left << "함수반환값 체크 : (" << description << ")" << std::endl;
		
		
		printf("case Success, current score : %d out of  %d\n\n", ++mCurrentScore, mNumberOfTestCases);
		
		//파일 출력
		global::ReportFileStream << "successed... " << ++global::CurrentTestNumber << " test OK\n" << std::endl;
		global::ReportFileStream.seekg(0, std::ios_base::end);

	}
	else
	{
		std::cout << "Test Fail...not sure" << std::endl;
		global::ReportFileStream << "failed... " << ++global::CurrentTestNumber << std::endl;
		global::ReportFileStream.seekg(0, std::ios_base::end);
	}
}


template<typename... Args>
bool Tester<Args...>::DataChecker(int evaluateValue, int data, const char* description)
{
	if (evaluateValue == data)
	{
		std::cout<<std::setw(20) << std::setfill('=');
		std::cout << description;
		std::cout << std::setw(20) << std::setfill('=')<< std::endl;

		printf("case Success, current score : %d out of  %d\n", ++mCurrentScore, mNumberOfTestCases);
		return true;
	}
	else
	{
		printf("case Success, current score : %d out of  %d\n", mCurrentScore, mNumberOfTestCases);
		return false;
	}

	return true;
}

template<typename... Args>
bool Tester<Args...>::MemoryLeakChecker()
{
	if (_CrtDumpMemoryLeaks())
	{
		std::cout << std::setw(20) << std::setfill('=');
		std::cout << mTesterDescription << "에서 Memory 누수 감지됨";
		std::cout << std::setw(20) << std::setfill('=') << std::endl;
		return true;
	}
	return false;
}