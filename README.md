 # WONS

 우리의 프로그램은 snow친구로서 사진에 이벤트 효과를 주는 프로그램입니다.

 ## 역할 분담
  - GUI - 안지수★

  - core - 박주현
  얼굴 윤곽 및 눈, 코, 입 좌표 구하기
  - event
  core을 이용하여 얼굴 좌표를 얻은 뒤, 효과를 입힘
    >효과
    > - 그림 입히기 - 이설희
    > - 모자이크 - 장예솔
    > - 점 (자동) 없애기 - 허정우
    > - 얼굴 바꾸기 - 조민규

  - 발표 - 장예솔
  - PPT - 박주현
  - 보고서 - 허정우

 ## Coding rule
  - 브렌치 설정
  master - 무조건 실행되는 브렌치
  develop - 개발되는 중간에 합쳐지게 되는 브랜치
  feature - develop에서 브랜치를 따서 개발을 함(개인이 따는 브랜치)
<참고 http://amazingguni.github.io/blog/2016/03/git-branch-%EA%B7%9C%EC%B9%99>

 ## 엄청 쉬운 깃 사용법
 git-bash 프로그램을 사용합니다.
 ```bash
 git add 파일명
 >  파일을 add 합니다.
 git commit -m "커밋 메시지"
 >  add 한 파일을 commit 합니다. 커밋이란 버전에 대한 이력을 남기는 것이라고 생각하면 편합니다.
 git diff
 > 현재 추적하고 있는 파일들의 변화를 보여줍니다.
 git diff --cached
 > git add한 프로그램의 변화 내용을 보여줍니다.
 git checkout -b "브랜치명"
 > 새로운 브랜치를 브랜치명으로 따주면서 그 브랜치로 이동합니다.
 git checkout "브랜치명"
 > 브랜치를 이동합니다.
 git merge "브랜치명"
 > 브랜치를 합칩니다.
 git log
 > 깃 로그를 봅니다.
 git status
 > 현재 추적하고 있는 파일, 추적하지 않는 파일, 수정된 파일들등의 상태들을 보여줍니다.

 ```
