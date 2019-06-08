#pragma once
#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <cassert>
#include "globalVariables.h"


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
	: mCurrentTest(funcToRegister)
	, mNumberOfTestCases(testCases)
	, mCurrentScore(0)
	, mCurrentTestNum(0)
	, mTesterDescription((char*)description)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	global::TotalTestNumber += testCases;
	printf("\n\n====Test : %s  START====\n\n", description);

	//file 출력  
	global::ReportFileStream.open("./ReportFile.txt");
	global::ReportFileStream.seekg(0, std::ios::end);
	global::ReportFileStream << "===" << description << "started...===" << std::endl;
	global::ReportFileStream.seekg(0, std::ios::end);
}


template <typename... Args>
Tester<Args...>::~Tester()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (mCurrentScore >= mNumberOfTestCases)
	{
		std::cout << std::setw(40) << std::setfill('=') << "통과" << std::endl;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	std::cout << "Test Over, Your Score of " << mTesterDescription << " " << mCurrentScore << "/" << mNumberOfTestCases << " " << std::setfill('=') << std::endl;

	//파일 출력 
	global::ReportFileStream.open("./ReportFile.txt", std::ios::out);
	global::ReportFileStream.seekg(0, std::ios_base::end);
	global::ReportFileStream << "===" << mTesterDescription << " over...===\n\n" << std::endl;

}

template<typename... Args>
void Tester<Args...>::TestRegisteredFunc(int evaluateValue, Args... args)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (evaluateValue == mCurrentTest(args...))
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_INTENSITY + 2);
		std::cout << "함수반환값 체크" << std::setw(40) << std::setfill('=') << std::right << std::left << std::endl;
		printf("case Success, current score : %d/%d \n\n\n", ++mCurrentScore, mNumberOfTestCases);
		
		global::TotalScore++;
		//파일 출력
		
		global::ReportFileStream << "successed... " << ++global::CurrentTestNumber << " test OK" << std::endl;
		global::ReportFileStream.seekg(0, std::ios_base::end);
		
	}
	else
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "Test Fail...not sure" << std::endl;
		global::ReportFileStream << "failed... " << ++global::CurrentTestNumber << std::endl;
		global::ReportFileStream.seekg(0, std::ios_base::end);
	}
}


template <typename... Args>
inline void Tester<Args...>::TestRegisteredFunc(int evaluateValue, Args... args, const char* description)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (evaluateValue == mCurrentTest(args...))
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_INTENSITY +2);
		std::cout << std::left << "함수반환값 체크 : (" << description << ")" << std::endl;


		printf("case Success, current score : %d out of  %d\n\n", ++mCurrentScore, mNumberOfTestCases);
		
		//파일 출력
		global::ReportFileStream << "successed... " << ++global::CurrentTestNumber << " test OK\n" << std::endl;
		global::ReportFileStream.seekg(0, std::ios_base::end);

	}
	else
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "Test Fail...not sure" << std::endl;
		global::ReportFileStream << "failed... " << ++global::CurrentTestNumber << std::endl;
		global::ReportFileStream.seekg(0, std::ios_base::end);
	}
}


template<typename... Args>
bool Tester<Args...>::DataChecker(int evaluateValue, int data, const char* description)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (evaluateValue == data)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		std::cout << std::setw(20) << std::setfill('=');
		std::cout << description;
		std::cout << std::setw(20) << std::setfill('=') << std::endl;

		global::TotalScore++;
		printf("case Success, current score : %d out of  %d\n", ++mCurrentScore, mNumberOfTestCases);
		return true;
	}
	else
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		printf("case Success, current score : %d out of  %d\n", mCurrentScore, mNumberOfTestCases);
		return false;
	}

	return true;
}

template<typename... Args>
bool Tester<Args...>::MemoryLeakChecker()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (_CrtDumpMemoryLeaks())
	{
		SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
		std::cout << std::setw(20) << std::setfill('=');
		std::cout << mTesterDescription << "에서 Memory 누수 감지됨";
		std::cout << std::setw(20) << std::setfill('=') << std::endl;
		return true;
	}
	return false;
}