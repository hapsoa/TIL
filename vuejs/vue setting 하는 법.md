현재 위치
pwd

mkdir '파일 이름'
1. cd '폴더이름'에 들어간다.
2. 한번만 하면 된다.
npm install -g vue-cli

3. 
vue init hyunwoo/vue-template


? Generate project in current directory? Yes
? Project name vue-router-test
? Project description A Vue.js project
? Author SharingWorld <hapsoa@gmail.com>
? Vue build standalone
? Install vue-router? Yes
? Use ESLint to lint your code? Yes
? Pick an ESLint preset Airbnb
? Pick an template language pug
? Pick an style language sass
? Set up unit tests Yes
? Pick a test runner karma
? Setup e2e tests with Nightwatch? Yes
? Pick a documentation tool documentationjs
? Do you want to deploy on the github page? Yes
? Branch name gh-pages
? What is the GitHub Project Name? 
* Important: If this project is a user-wide github page, leave it blank. If not, please enter the n
ame of the project.
1) {USERNAME}.github.io => BLANK,
2) {USERNAME}.github.io/{PROJECTNAME} => PROJECTNAME 
 :  vue-router-test
? Should we run `npm install` for you after the project has been created? (recommended) npm


-- npm --
dev 리프레시 까지 해주는, 8080 포트번호.
start 위와 (비슷)같다
unit : 유닛 테스트(src -> page -> Hello.vue)
e2e : end to end 테스트
test : unit + e2e 둘다 테스트
lint :  는 실행할 필요가 없습니다.
generate-doc : document(API 설명서)를 만듬. dist -> documentation -> index.html
    docma.json jsdoc.json 을 참조하여, 브라우저를 만드는 듯 함.
serve-docs : 도큐먼트 실행
build :  index.html 과 static 폴더로 모두 묶어준다. 난독화
github-deploy : github 페이지 만들어 주는 것
publish : 배포할 때 쓰는 것


preference에 code style 입력하고 Scheme 에 톱니바퀴버튼 누르면
-> import scheme -> intelliJ code style xml 누르고 
-> thethelab......xml 을 선택하고 -> THETHELAB 을 친다.


index.html 을 바탕으로 모든게 구성이 된다. 외부에 넣어줄 것만.
