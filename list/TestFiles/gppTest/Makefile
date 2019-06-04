
all : Test.exe User.exe


User.exe :
	g++ -std=c++11 *.cpp -o User.exe
	

Test.exe :
	g++ -std=c++14 test.cpp -o Test.exe
	Test.exe
	rm Test.exe

clean :
	rm ./*.o ./*.exe