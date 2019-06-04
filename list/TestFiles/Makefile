
all : Test.exe User.exe


User.exe :
# TODO : 나중에 유저 테스트 코드 추가하가... 
	g++ -std=c++11 *.cpp -o User.exe
	

Test.exe :
	g++ -std=c++14 test.cpp Test*.cpp ../list.c -o Test.exe
	chcp 65001
	Test.exe
	rm ./Test.exe

clean :
	rm ./*.o ./*.exe