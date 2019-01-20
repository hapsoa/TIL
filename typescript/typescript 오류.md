# typescript 오류

### * import 할 때 에러나는 것은

tsconfig.json 의 compilerOptions의 types에 모듈이름을 입력하면 된다.
(ex. lodash, vuetify)

or
"compilerOptions" 안에
```
Edit your tsconfig.json

"noImplicitAny": false
```
을 한다.

### * 전역변수를 사용하는 방법은

declare를 사용하거나, tsconfig.json의 types에 node를 넣고 설치를 한다.
```
npm install --save-dev @types/node
```

### this.변수 에러 잡는 법
tsconfig.json 의 CompilerOptions에
```
"noImplicitThis": false
```

### console.log 에러 끄는 법
tslint.json에 가서
```
"rules": {
    "no-console": false
}
```