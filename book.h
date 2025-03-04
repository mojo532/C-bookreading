#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 책 정보 구조체
typedef struct {
    char title[100];
    char author[100];
    char date[20];
    float rating;
    char memo[200];
} Book;

// 전역 변수 선언
extern Book *books;
extern int book_count;
extern int book_capacity;

// 함수 원형 선언
void addBook();
void listBooks();
void editBook();
void deleteBook();
Book* searchBook();
void initLibrary();
void freeMemory();

#endif
