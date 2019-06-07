#pragma once
#include <fstream>
namespace global
{
	static std::fstream ReportFileStream;
	static int CurrentTestNumber=0;
	static int TotalTestNumber = 0;
}