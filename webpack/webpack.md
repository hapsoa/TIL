# Webpack

모던 자바스크립트 애플리케이션 개발을 위한 모듈 번들러입니다. 모듈과 모듈이 사용하는 정적 자원(CSS, Image)들을 묶어서 하나의 파일 또는 몇 개의 파일로 번들링 합니다.

## 번들링의 장점

- 초기 로딩 타임을 줄입니다.
- 정적 자원들까지 모듈화가 가능합니다.
- Babel, Typescript 등과 같은 트랜스파일러와 손쉽게 통합됩니다.
- HMR(Hot Module Replacement)를 지원하기 때문에 코드가 수정될 때마다 자동으로 번등링을 수행하고 페이지가 갱신됩니다.
- 다양한 로더(loader)가 제공됩니다.

  로더는 번들링을 하기 전에 수행해야 하는 전처리 기능을 제공합니다. 필요한 전처리 기능에는 정적 자원(CSS, Image 등)의 변환, ES2015에 대한 트랜스파일링 등이 있습니다.

- 다양한 플러그인(Plugin)을 제공합니다.

<br><br>

javascript 는 모듈 시스템이 없다.
그래서 한계를 극복하는 도구가 webpack 이다.

로더 사용, 빠른 컴파일 속도 등 장점이 많다.

webpack은 commonJS 와 AMD 의 명세를 모두 지원하는
javascript 모듈화 도구다.

모듈로 만든 파일은 웹페이지에 넣어 브라우저에서 실행할 수 없다.
webpack으로 컴파일해 브라우저에서 실행할 수 있는 형태로 바꿔야 한다.

webpack은 node.js 가 설치된 환경에서 실행된다.

```
npm install webpack -g
```

```
webpack ./entry.js bundle.js
```

엔트리 파일 : 서로 의존 관계에 있는 다양한 모듈을 사용하는 시작점이 되는 파일
번들 파일 : 브라우저에서 실행할 수 있게 모듈을 컴파일한 파일

javascript를 사용하는 html 코드에서는 컴파일 결과로 만들어진 번들 파일만
포함하면 된다.

--watch 옵션을 사용하면, 모듈 파일 변경될때마다
변경된 모듈을 자동으로 다시 컴파일 한다.

```
webpack --watch ./entry.js bundle.js
```

모듈은 스코프 된다.
함수로 모듈을 감싼다.

매번 옵션이 많고 엔트리 파일이 많고 하면 입력하기 불편하기 때문에,
설정 파일을 만들 수 있다.

```javascript
module.exports = {
  context: __dirname + '/app', // 모듈 파일 폴더
  entry: {
    // 엔트리 파일 목록
    app: './app.js',
  },
  output: {
    path: __dirname + '/dist', // 번들 파일 폴더
    filename: '[name].bundle.js', // 번들 파일 이름 규칙
  },
};
```

webpack.config.js 파일을 작성

webpack 명령어를 입력하면
webpack --watch

## 로더

webpack의 로더는 다양한 리소스를 javascript에서 바로 사용할 수 있는
형태로 로딩하는 기능이다.

```
json-loader(데이터) => 데이터 객체
handlebars-loader(템플릿) => 템플릿 함수
coffescript(개발 언어) => Javascript
```

컴파일 속도도 빠르다. 왜냐하면 비동기 I/O와 다중 캐시 레벨을 사용하기 때문에
컴파일 속도가 매우 빠르다.

<br><br><br>

## Write your code

src/bar.js

```javascript
export default function bar() {
  //
}
```

src/index.js

```javascript
import bar from './bar';

bar();
```

<br>

## Bundle with webpack
