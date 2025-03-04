#include "book.h"

Book *books = NULL;    // 동적으로 할당할 배열
int book_count = 0;    // 현재 저장된 책 개수
int book_capacity = 10; // 초기 크기 설정

// 책 추가 기능
void addBook() {
    // 처음 실행될 때 초기 할당
    if (books == NULL) {
        books = (Book*)malloc(book_capacity * sizeof(Book));
        if (books == NULL) {
            printf("메모리 할당 실패!\n");
            exit(1);
        }
    }

    // 책 개수가 저장 공간을 초과하면 크기 2배 증가 (가변 크기)
    if (book_count >= book_capacity) {
        book_capacity *= 2;
        Book *temp = (Book*)realloc(books, book_capacity * sizeof(Book));
        if (temp == NULL) {
            printf("메모리 재할당 실패!\n");
            exit(1);
        }
        books = temp;
    }

    printf("\n책 제목: ");
    getchar();
    fgets(books[book_count].title, 100, stdin);
    books[book_count].title[strcspn(books[book_count].title, "\n")] = '\0';

    printf("저자: ");
    fgets(books[book_count].author, 100, stdin);
    books[book_count].author[strcspn(books[book_count].author, "\n")] = '\0';

    printf("읽은 날짜 (YYYY-MM-DD): ");
    scanf("%s", books[book_count].date);

    printf("평점 (1.0 ~ 5.0): ");
    scanf("%f", &books[book_count].rating);

    printf("메모: ");
    getchar();
    fgets(books[book_count].memo, 200, stdin);
    books[book_count].memo[strcspn(books[book_count].memo, "\n")] = '\0';

    book_count++;
    printf("\n✅ 책이 추가되었습니다!\n");
}

// 책 목록 출력 기능
void listBooks() {
    if (book_count == 0) {
        printf("\n📖 저장된 책이 없습니다.\n");
        return;
    }

    printf("\n📚 내 책 목록 📚\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. %s - %s (%s)\n", i + 1, books[i].title, books[i].author, books[i].date);
        printf("   평점: %.1f/5.0\n", books[i].rating);
        printf("   메모: %s\n\n", books[i].memo);
    }
}

//책 수정
#include "book.h"

void editBook() {
    if (book_count == 0) {
        printf("\n📖 저장된 책이 없습니다. 먼저 책을 추가하세요.\n");
        return;
    }

    int bookIndex;
    listBooks(); // 책 목록 출력

    // 사용자로부터 수정할 책 번호 입력
    while (1) {
        printf("\n수정할 책 번호를 입력하세요 (1~%d, 취소하려면 0 입력): ", book_count);
        scanf("%d", &bookIndex);
        getchar(); // 입력 버퍼 정리

        if (bookIndex == 0) {
            printf("\n🛑 수정 취소.\n");
            return;
        }

        bookIndex--; // 배열 인덱스 조정

        if (bookIndex >= 0 && bookIndex < book_count) break;
        printf("\n❌ 잘못된 번호입니다! 다시 입력하세요.\n");
    }

    // 사용자가 0을 입력할 때까지 계속 수정 가능
    while (1) {
        int fieldChoice;
        printf("\n수정할 항목을 선택하세요:\n");
        printf("1. 제목\n");
        printf("2. 저자\n");
        printf("3. 읽은 날짜\n");
        printf("4. 평점\n");
        printf("5. 메모\n");
        printf("0. 수정 완료\n");
        printf("선택: ");
        scanf("%d", &fieldChoice);
        getchar(); // 입력 버퍼 정리

        if (fieldChoice == 0) {
            printf("\n✅ 모든 수정이 완료되었습니다!\n");
            break;
        }

        switch (fieldChoice) {
            case 1:
                printf("새로운 제목: ");
                fgets(books[bookIndex].title, 100, stdin);
                books[bookIndex].title[strcspn(books[bookIndex].title, "\n")] = '\0';
                break;
            case 2:
                printf("새로운 저자: ");
                fgets(books[bookIndex].author, 100, stdin);
                books[bookIndex].author[strcspn(books[bookIndex].author, "\n")] = '\0';
                break;
            case 3:
                printf("새로운 읽은 날짜 (YYYY-MM-DD): ");
                scanf("%s", books[bookIndex].date);
                getchar(); // 입력 버퍼 정리
                break;
            case 4:
                while (1) {
                    printf("새로운 평점 (1.0 ~ 5.0): ");
                    scanf("%f", &books[bookIndex].rating);
                    getchar();
                    if (books[bookIndex].rating >= 1.0 && books[bookIndex].rating <= 5.0) break;
                    printf("\n❌ 평점은 1.0에서 5.0 사이여야 합니다. 다시 입력하세요.\n");
                }
                break;
            case 5:
                printf("새로운 메모: ");
                fgets(books[bookIndex].memo, 200, stdin);
                books[bookIndex].memo[strcspn(books[bookIndex].memo, "\n")] = '\0';
                break;
            default:
                printf("\n❌ 잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }
}



// 책 삭제 기능
void deleteBook() {
    if (book_count == 0) {
        printf("\n📖 저장된 책이 없습니다.\n");
        return;
    }

    int bookIndex;
    listBooks();
    printf("\n삭제할 책 번호를 입력하세요 (1~%d): ", book_count);
    scanf("%d", &bookIndex);
    getchar();

    if (bookIndex == 0) {
        printf("\n🛑 삭제 취소.\n");
        return;
    }

    bookIndex--;
    if (bookIndex < 0 || bookIndex >= book_count) {
        printf("\n❌ 잘못된 번호입니다!\n");
        return;
    }

    printf("\n📕 책 '%s' 삭제 완료!\n", books[bookIndex].title);
    //책 목록을 앞으로 이동
    for (int i = bookIndex; i < book_count - 1; i++) {
        books[i] = books[i + 1];
    }

    book_count--;

    // 메모리 크기 줄이기 (최소 크기 보장)
    if (book_count > 0 && book_count < book_capacity / 2) {
        book_capacity /= 2;
        Book *temp = (Book*)realloc(books, book_capacity * sizeof(Book));
        if (temp != NULL) { 
            books = temp;
        }
    }

    printf("\n✅ 책 목록이 업데이트되었습니다!\n");
}

Book* searchBook() {
    if (book_count == 0) {
        printf("\n📖 저장된 책이 없습니다. 먼저 책을 추가하세요.\n");
        return NULL;
    }

    char keyword[100];
    printf("\n🔍 검색할 책 제목 또는 저자를 입력하세요: ");
    getchar();
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int found = 0;
    Book *firstMatch = NULL;  // 첫 번째 검색된 책의 포인터 저장

    printf("\n🔎 검색 결과:\n");
    for (int i = 0; i < book_count; i++) {
        if (strstr(books[i].title, keyword) || strstr(books[i].author, keyword)) {
            printf("\n📖 [%d] %s - %s (%s)\n", i + 1, books[i].title, books[i].author, books[i].date);
            printf("   ⭐ 평점: %.1f/5.0\n", books[i].rating);
            printf("   📝 메모: %s\n", books[i].memo);
            printf("---------------------------------------------\n");

            if (firstMatch == NULL) {  // 첫 번째 검색된 책 저장
                firstMatch = &books[i];
            }
            found = 1;
        }
    }

    if (!found) {
        printf("\n❌ 검색 결과가 없습니다.\n");
        return NULL;
    }

    return firstMatch;  // 첫 번째 검색된 책 반환
}


// 도서 목록 초기화 함수
void initLibrary() {
    books = (Book*)malloc(book_capacity * sizeof(Book));
    if (books == NULL) {
        printf("메모리 할당 실패!\n");
        exit(1);
    }
}

// 메모리 해제
void freeMemory() {
    if (books != NULL) {
        free(books);
        books = NULL; // 🔹 메모리 해제 후 NULL 처리
    }
}