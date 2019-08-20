# firebase hosting

firebase 에서 호스팅을 할 수 있다.

문서에 호스팅 시작하기를 읽으면서

하라고 하는 가이드대로 따라가면 된다.

---

//firebase cli 인스톨
npm install -g firebase-tools

firebase login

// firebase 동작함
// 사용할 계정
firebase init (계정, 로그인 창이 뜨고 로그인)

firestore, hosting, storage
프로젝트 당 하기 때문에,

npm run build

npm build

firebase deploy 배포

hosting에 가보면 배포가 된거야.

domain
gaesory.com 치면,

aws route53
에서 TXT코드 추가하기
A레코드도 추가

www도 해준다.

map파일은 원본 파일을 가리켜 주는 파일인데,
이것을 빼고 deploy하는게 좋다. 용량이 꽤 크기 때문이다.
그리고 map파일이 없으면 해독하기 불가능할거다.

registerWorker를 잠시 빼둬.

## 주의사항

firebase 호스팅 할 때, 도메인 연결을 할 수 있다.

도메인 인증을 하라고 하는데, 도메인 인증시

가비아 같은 호스팅업체에서 TXT 코드 입력할때

호스트를 @ 로 둔다.
