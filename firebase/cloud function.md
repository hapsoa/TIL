# cloud function

서버 측 코드를 cloud function으로 실행하는 듯하다.

클라이언트에서 firebase 관련 메소드를 호출 시에
cloud function이 트리거되서 서버에서 작동되는 형식이랄까

<br>

## 설치 진행

npm i -g firebase-tools

firebase init

```
What language would you like to use to write Cloud Functions? TypeScript
? Do you want to use TSLint to catch probable bugs and enforce style? Yes
✔  Wrote functions/package.json
✔  Wrote functions/tslint.json
✔  Wrote functions/tsconfig.json
✔  Wrote functions/src/index.ts
✔  Wrote functions/.gitignore
? Do you want to install dependencies with npm now? Yes
```

```
### 설명
프로젝트 안 functions 디렉토리가 cloud function 을 관리한다.

functions/src/index.ts 가 cloud function 코드 작성하는 중심인 곳
```

firebase deploy 하면 배포가 된다.
(firebase deploy --only functions)

```
firebase console의 Functions에 가보면 요청사항들이 기록되어 있다.
로그 창을 누르면 console.log() 호출한 내용을 볼 수 있고 이를 통해 디버그 가능
```
