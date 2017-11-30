 # WONS

 우리의 프로그램은 snow친구로서 사진에 이벤트 효과를 주는 프로그램입니다.

 ## 역할 분담
  - GUI - 안지수

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

 ## 사용환경 설정
 ```
  운영체제: ubuntu 16.04
  개발 환경: qt 5.9.3, opencv 3.3.0
 ```

 ### 환경 설정 방법
 * qt 설치
 [다운로드 링크](https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=d62710cd-e1db-46aa-8d4d-2f1c1ffdacea&placement_guid=f977210e-de67-475f-a32b-65cec207fd03&portal_id=149513&redirect_url=APefjpFgYs3CLQnyoSXrSq-8FPbwQf5IOfZxi_noHgIT00PdyAR0O9hNBpFUGtHmOZsc5PKOnOVmZDgKUvLeFTrcWJq-4RCZNsyWx6c5x0aDumr_fkkhMhRszvtRfyr1fzfLYa33MlsZm-6qeS3mmP4Y4YiEsH0bwNhoz6HreXzXjm86wMHE84x3Tu-ASEUJL3BtBxfg9L9bzwXqIM_765Ww272bg6cYUbfq3a6YLjn_3kenZH98p5M&hsutk=e74aab30f74e311652d094178d1867c8&canon=https%3A%2F%2Fwww.qt.io%2Fdownload-qt-for-application-development&click=61217d54-046e-44fa-8c91-647ea2a5f149&pageId=4588874906)

 * opencv 설치
 [설치법 링크](https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html?highlight=installation)
 

