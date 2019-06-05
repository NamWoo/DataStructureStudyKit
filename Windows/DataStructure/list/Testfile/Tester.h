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

template <typename T, typename... Args>
class Tester
{
private:
	int mNumberOfTestCases;
	int mCurrentScore;
	char* mTestDescription;
	VaFunc_t mCurrentTest;

public:
	Tester() = default;
	Tester(T funcToRegister, const char* description, int testCases);
	~Tester();
	void TestRegisteredFunc(int evaluateValue, Args... args);
	void VariableChecker(T evaluateValue, T data);

	static void TestFunc(T funcToRegister, int evaluateValue, Args... args);
};

template <typename T, typename... Args>
Tester<T, Args...>::Tester(T funcToRegister, const char* description, int testCases)
	: mCurrentTest((T)funcToRegister)
	, mNumberOfTestCases(testCases)
	, mCurrentScore(0)
	, mTestDescription((char*)description)
{

	printf("====Test : %s  START====\n", description);

	//file Ãâ·Â  
	global::ReportFileStream.open("./ReportFile.txt");
	global::ReportFileStream.seekg(0, std::ios::end);
	std::cout << "test start file output cursor: " << global::ReportFileStream.tellg() << std::endl;
	global::ReportFileStream << "===" << description << "started...===" << std::endl;
	
	global::ReportFileStream.seekg(0, std::ios::end);
	std::cout <<mTestDescription<< " Tester init (after): "<< global::ReportFileStream.tellg() << std::endl;

}

template <typename T, typename... Args>
Tester<T, Args...>::~Tester()
{
	global::ReportFileStream.open("./ReportFile.txt", std::ios::out);
	global::ReportFileStream.seekg(0, std::ios_base::end);
	global::ReportFileStream << "===" << mTestDescription << " over...===\n\n" << std::endl;

	printf("====Test Over====");
}

template <typename T, typename... Args>
inline void Tester<T, Args...>::TestRegisteredFunc(int evaluateValue, Args... args)
{


	std::cout << global::ReportFileStream.tellg() << std::endl;
	if (evaluateValue == mCurrentTest(args...))
	{
		printf("case Success, current score : %d out of  %d\n", mCurrentScore++, mNumberOfTestCases);
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
