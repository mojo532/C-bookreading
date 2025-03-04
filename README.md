# 📚독서 기록장+커뮤니티 만들기

## ⭐️목표:
사용자가 읽은 책을 기록하고, 독서 모임 정보를 관리할 수 있는 간단한 시스템을 만든다.📚<br>
책을 검색, 추천할 수 있는 기능 포함<br>
기본적인 시스템은 C언어로 만들되, 이후 추천 기능 알고리즘은 파이썬으로 연결할 것.<br>
파이썬, 웹개발은 5주차 이후 시작

## 🎯주 단위 목표

- **목표:** 4주 동안 독서 기록 시스템(책 관리 + 독서 모임 + 추천 기능) 핵심 기능을 완성
- **개발 방식:** 기능별로 우선순위를 정하고 단계적으로 완성
- **진행 방식:** 매일 2시간 집중 개발, 주말에는 기능 테스트 및 개선

- `1주차` : **책 관리 시스템 구축 (기본 기능)**
    
    📌 **목표:** 책 추가, 목록 출력, 검색 기능을 구현하고, 파일 저장을 통해 데이터가 유지되도록 설정    
    ✅ **1주차 결과물:** 책을 추가하고, 목록을 출력하며, 검색과 파일 저장이 가능한 기본 기능
    
- `2주차` : 추천 시스템 및 예외 처리 추가
    
    📌 **목표:** 책 추천 기능을 구현하고, 검색과 저장 기능의 안정성을 높이기<br>
    ✅ **2주차 결과물:** 사용자의 평점/키워드 기반 추천 기능이 추가되고, 검색 기능이 개선됨
    
- `3주차` : 독서 모임 + 담벼락 코멘트 기능
    
    📌 **목표:** 독서 모임을 생성하고, 참여할 수 있는 기능을 구현하며, 담벼락 코멘트 작성 기능 추가<br>
    ✅ **3주차 결과물:** 독서 모임을 생성하고, 참여하며, 모임 내에서 코멘트를 남길 수 있는 기능 추가
    
- `4주차` : 통합, 테스트, 최종 다듬기
    
    📌 **목표:** 전체 기능을 통합하고, 오류를 수정하며, 코드 정리 후 문서화를 진행<br>
    ✅ **4주차 결과물:** 완전한 독서 기록 시스템 완성 + 프로젝트 문서화
    
- `5주차 이후` : 파이썬 연결 및 웹개발

### 데이터 구조 설계

1. 책 정보: 제목, 저자, 읽은 날짜, 평점, 메모, 추천책 설정
2. 독서 모임 정보: 모임 이름, 읽는 책, 참여자 목록, 코멘트
3. 검색: ISBN으로 책 추가
4. 알고리즘: 추천책 Top 30
5. 계정 만들기, 탈퇴, 로그인, 로그아웃, 프로필 설정 등 개인정보

### 기능 목록

- 책 추가, 수정, 삭제
- 책 목록 출력
- 책 검색
- 책 추천
- 독서 모임 관리
- 독서 모임 모집
- 독서 모임 코멘트 작성

### 메뉴 형태

- 나의 책
    1. 추가된 책 목록
    2. 추천책 북마크 기능
    3. 코멘트 기능 (메모) 
- 검색
    1. 나의 책 추가하기
    2. 나의 책 삭제하기
- 많은 추천을 받은 책 Top 30
    1. 나이대/성별로 정렬하기
    2. 분야별 정렬하기
- 독서 모임
    1. 모임 검색
    2. 모임 가입, 탈퇴
    3. 모임원들끼리 이달의 책 선정
    4. 추천책 태그
    5. 독서기록장 코멘트 나누는 기능
- 개인정보
    1. 로그인/로그아웃
    2. 프로필 설정
    3. 가입한 독서모임
    4. 회원 탈퇴
