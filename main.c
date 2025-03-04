#include "book.h"


int main() {
    // 동적 메모리 할당 초기화
    initLibrary();

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
                printf("\n🚀 프로그램을 종료합니다. 안녕히 가세요!\n");
                freeMemory();  // ✅ 메모리 해제
                exit(0);
            default:
                printf("\n❌ 잘못된 입력입니다. 다시 선택하세요.\n");
        }
    }
}

