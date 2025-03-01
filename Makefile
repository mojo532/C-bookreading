# 컴파일러 설정
CC = gcc
CFLAGS = -Wall

# 최종 실행 파일 이름
TARGET = book_manager

# 오브젝트 파일 목록
OBJS = main.o book.o

# 기본 실행 파일 생성
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 개별 파일 컴파일
main.o: main.c book.h
	$(CC) $(CFLAGS) -c main.c

book.o: book.c book.h
	$(CC) $(CFLAGS) -c book.c

# 불필요한 파일 정리 (빌드 후 필요 없는 파일 삭제)
clean:
	rm -f *.o $(TARGET)
