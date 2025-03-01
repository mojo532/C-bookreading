#include "book.h"

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
        printf("2. 책 수정\n");
        printf("3. 책 삭제\n");
        printf("4. 책 목록 보기\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: editBook(); break;
            case 3: deleteBook(); break;
            case 4: listBooks(); break;  // ✅ 4번으로 이동
            case 5:
                freeMemory();
                return 0;
            default:
                printf("잘못된 입력입니다.\n");
        }
    }
}

