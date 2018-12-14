# webpack

## Webpack은 무엇인가?

- 서로 연관 관계가 있는 웹 자원들을 js, css, img와 같은 스태틱한 자원으로 변환해주는 모듈 번들러

## Webpack을 사용하는 이유 & 배경

1. 새로운 형태의 Web Task Manager
- 기존 Web Task Manager (Gulp, Grunt)의 기능 + 모듈 의존성 관리
- 예) minification을 webpack default cli로 실행 가능

2. 자바스크립트 Code based Modules 관리
- 자바스크립트 모듈화의 필요성 : AMD, Common js, ES6(Modules)
- 기존 모듈 로더들과의 차이점 : 모듈 간의 관계를 청크(chunk) 단위로 나눠 필요할 때 로딩
- 현대의 웹에서 JS 역할이 커짐에 따라, Client Side에 들어가는 코드량이 많아지고 복잡해짐
- 복잡한 웹 앱을 관리하기 위해 모듈 단위로 관리하는 Common JS, AMD, ES6 Modules 등이 등장
- 가독성이나 다수 모듈 미병행 처리등의 약점을 보완하기 위해 Webpack이 등장

## Webpack의 철학

1. Everyting is Module

모든 웹 자원(js, css, html)이 모듈 형태로 로딩 가능

```
require('base.css');
require('main.js');
```

2. Load only "what" you need and "when" you need (lazy-load)
초기에 불필요한 것들을 모두 로딩하지 않고, 필요할 때 필요한 것만 로딩하여 사용

## 자바스크립트 모듈화 문제란?

아래는 script 태그로 간단하게 자바스크립트 모듈화를 시도하는 예제

```html
<script src="module1.js"></script>
<script src="module2.js"></script>
<script src="library1.js"></script>
<script src="module3.js"></script>
```

상기 모듈 로딩 방식의 문제점 : 전역변수 충돌, 스크립트 로딩 순서, 복잡도에 따른 관리상의 문제

이를 해결하기 위해 AMD 및 기타 모듈 로더들, Webpack이 등장

<br>

## Basic Setup

```
공식 참조 링크
https://webpack.js.org/guides/getting-started/
```

<br>

```
mkdir webpack-demo && cd webpack-demo
npm init -y
npm install webpack webpack-cli --save-dev
```

src 폴더에 js 파일들을 작성하고

```
npx webpack
```
을 하면 dist 폴더에 main.js 가 만들어 진다.

<br>

## Using a Configuration

webpack.config.js 를 프로젝트에 추가하면 webpack의 configuration file 이 된다.

```javascript
const path = require('path');

module.exports = {
  entry: './src/index.js',
  output: {
    filename: 'main.js',
    path: path.resolve(__dirname, 'dist')
  }
};
```

아래 명령어를 치면 config 설정에 맞춰 bundling 된 파일이 나온다.

(파일 이름이 webpack.config.js 라면 그냥 npx webpack 해도 된다.)

```
npx webpack --config webpack.config.js
```



