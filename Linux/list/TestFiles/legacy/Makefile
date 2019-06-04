
# gcc 컴파일러
CC = gcc
CFLAGS = -W -Wall # 컴파일단 오류도 같이 출력

# WINDOWS 컴파일러 
MSVC = cl
MSVC_CFLAGS = /EHsc /W4 /D_DEBUG /MDd

# 타겟 파일 ( 실행파일 )
TARGET = List.exe
TEST =  ListTest.exe

# 소스및 오브젝트 파일 (커스텀 컴파일 )
SRCS = list.c  main.c
OBJS = $(SRCS:.c=.o)

# 소스및 오브젝트 파일 (테스트 전용 파일과 구현한 자료구조 파일을 추가해주세요)
TSRCS =   Tester.c TestList.c ../list.c # ex) TestList, list.c
TOBJS = $(TSRCS:.c=.o)

# 인자없이 넘겼을때 기본 명령어
all : $(TARGET) $(TEST)

# 오브젝트 파일(.o 확장자 붙은 파일) 을 make 하면 해당 파일의 .c 를 의존성파일로 넣는다 $@ $< 는  내부 메크로 로써 
# $@ <- 현재의 목표 파일(Target)
# $< <- 현재의 목표 파일(Target)보다 더 최근에 갱신된 파일 이름
%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET) : $(OBJS)
	cl $(MSVC_CFLAGS) /Fe:$(TARGET) $(OBJS)
	$(TARGET)

$(TEST) :$(TOBJS)
	# $(CC) $(CFLAGS) -I$(MEMORY_LEAK_CHECKER_PATH) -o $(TEST) $(TOBJS)
	cl $(MSVC_CFLAGS) /Fe:$(TEST) $(TSRCS)
	chcp 65001
	$(TEST)

clean :
	rm *.o *.exe *.obj
