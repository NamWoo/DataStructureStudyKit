CC = gcc
CFLAGS = -W -Wall # 컴파일단 오류도 같이 출력
TARGET = List.exe
TEST =  ListTest.exe

# MEMORY_LEAK_CHECKER_PATH = ./leak_detector/
# MEMORY_LEAK_CHECKER_SRC = $(MEMORY_LEAK_CHECKER_PATH)mem.c
# MEMORY_LEAK_CHECKER_OBJ = $(MEMORY_LEAK_CHECKER_SRC:.c=.o)

SRCS = list.c  main.c
OBJS = $(SRCS:.c=.o)

TSRCS = list.c  test.c TestMain.c
TOBJS = $(TSRCS:.c=.o)

all : $(TARGET)  $(TEST)


%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	$(TARGET)

$(TEST) :$(TOBJS)
	# $(CC) $(CFLAGS) -I$(MEMORY_LEAK_CHECKER_PATH) -o $(TEST) $(TOBJS)
	cl /EHsc /W4 /D_DEBUG /MDd /Fe:$(TEST) $(TSRCS)
	
	chcp 65001
	$(TEST)



clean :
	rm *.o *.exe *.obj
	rm ./leak_detector/*.o
