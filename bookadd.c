#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 책 정보를 저장하는 구조체
typedef struct {
    char title[100];
    char author[100];
    char date[20];
    float rating;
    char memo[200];
} Book;

// 동적 메모리 관리를 위한 변수
Book *books = NULL;    // 동적으로 할당할 배열
int book_count = 0;    // 현재 저장된 책 개수
int book_capacity = 10; // 초기 크기 설정 (10권부터 시작)

// 함수 원형 선언 (앞에서 미리 선언해줘야 함)
void listBooks();  // ✅ 함수 원형 추가
void addBook();
void editBook();
void deleteBook(); // (추후 추가할 삭제 기능)

// 책 추가 함수
void addBook() {
    // 책 개수가 저장 공간을 초과하면 배열 크기 확장
    if (book_count >= book_capacity) {
        book_capacity *= 2; // 기존 크기의 2배로 확장
        books = realloc(books, book_capacity * sizeof(Book)); // 메모리 재할당
        if (books == NULL) {
            printf("메모리 할당 실패!\n");
            exit(1);
        }
        printf("📚 저장 공간이 %d권으로 확장되었습니다!\n", book_capacity);
    }

    // 책 정보 입력받기
    printf("\n책 제목: ");
    getchar(); 
    fgets(books[book_count].title, 100, stdin); //fgets(배열, 최대 입력 길이, stdin); 여기서 stdin은 표준 입력(키보드)을 의미합니다. fgets()는 개행 문자(\n)를 포함하여 입력을 받습니다.
    books[book_count].title[strcspn(books[book_count].title, "\n")] = '\0'; //개행 문자를 널 문자(\0)로 바꿔 문자열 끝을 지정 (개행 문자를 제거)

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

// 책 수정 함수
void editBook() {
    if (book_count == 0) {
        printf("\n📖 저장된 책이 없습니다. 먼저 책을 추가하세요.\n");
        return;
    }

    // 수정할 책 선택
    int bookIndex;
    listBooks(); // 책 목록 출력
    while (1) {
        printf("\n수정할 책 번호를 입력하세요 (1~%d, 취소하려면 0 입력): ", book_count);
        scanf("%d", &bookIndex);
        getchar(); // 입력 버퍼 정리
        
        if (bookIndex == 0) {
            printf("\n수정을 취소했습니다.\n");
            return;
        }
        
        bookIndex--; // 배열 인덱스에 맞추기

        if (bookIndex >= 0 && bookIndex < book_count) break;
        printf("\n❌ 잘못된 번호입니다. 다시 입력하세요.\n");
    }

    // 수정할 항목 선택
    int fieldChoice;
    while (1) {
        printf("\n수정할 항목을 선택하세요:\n");
        printf("1. 제목\n");
        printf("2. 저자\n");
        printf("3. 읽은 날짜\n");
        printf("4. 평점\n");
        printf("5. 메모\n");
        printf("선택 (취소하려면 0 입력): ");
        scanf("%d", &fieldChoice);
        getchar(); // 입력 버퍼 정리

        if (fieldChoice == 0) {
            printf("\n수정을 취소했습니다.\n");
            return;
        }

        if (fieldChoice >= 1 && fieldChoice <= 5) break;
        printf("\n❌ 잘못된 선택입니다. 다시 입력하세요.\n");
    }

    // 선택한 항목 수정
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
            break;
        case 4:
            while (1) {
                printf("새로운 평점 (1.0 ~ 5.0): ");
                scanf("%f", &books[bookIndex].rating);
                if (books[bookIndex].rating >= 1.0 && books[bookIndex].rating <= 5.0) break;
                printf("\n❌ 평점은 1.0에서 5.0 사이여야 합니다. 다시 입력하세요.\n");
            }
            break;
        case 5:
            printf("새로운 메모: ");
            fgets(books[bookIndex].memo, 200, stdin);
            books[bookIndex].memo[strcspn(books[bookIndex].memo, "\n")] = '\0';
            break;
    }

    printf("\n✅ 수정 완료!\n");
}

void deleteBook() {
    if (book_count == 0) {
        printf("\n📖 저장된 책이 없습니다. 삭제할 수 없습니다.\n");
        return;
    }

    int bookIndex;
    listBooks(); // 현재 책 목록 출력
    printf("\n삭제할 책 번호를 입력하세요 (1~%d, 취소하려면 0 입력): ", book_count);
    scanf("%d", &bookIndex);
    getchar(); // 입력 버퍼 정리

    if (bookIndex == 0) {
        printf("\n🛑 삭제 취소.\n");
        return;
    }

    bookIndex--; // 배열 인덱스 맞추기

    if (bookIndex < 0 || bookIndex >= book_count) {
        printf("\n❌ 잘못된 번호입니다! 다시 시도하세요.\n");
        return;
    }

    printf("\n📕 책 '%s' 삭제 완료!\n", books[bookIndex].title);

    // 삭제된 책 이후의 데이터를 앞으로 이동
    for (int i = bookIndex; i < book_count - 1; i++) {
        books[i] = books[i + 1];
    }

    book_count--; // 책 개수 감소

    printf("\n✅ 책 목록이 업데이트되었습니다!\n");
}

// 책 목록 출력 함수
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

// 프로그램 종료 시 동적 메모리 해제
void freeMemory() {
    free(books);
    printf("\n🛑 프로그램 종료, 메모리 해제 완료.\n");
}

int main() {
    books = malloc(book_capacity * sizeof(Book));
    if (books == NULL) {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    int choice;
    while (1) {
        printf("\n=== 독서 기록 시스템 ===\n");
        printf("1. 책 추가\n");
        printf("2. 책 목록 보기\n");
        printf("3. 책 수정\n");
        printf("4. 책 삭제\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: listBooks(); break;
            case 3: editBook(); break;
            case 4: deleteBook(); break;
            case 5:
                freeMemory();
                return 0;
            default:
                printf("잘못된 입력입니다.\n");
        }
    }
}