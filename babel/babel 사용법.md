1. babel 이란 javascript를 인터넷 익스플로러 다양한 브라우저 환경에서
실행되도록 하는 컴파일러라고 볼 수 있다.

babel은 javascript compiler 다. 옛날 버전도 호환시켜주는

1. npm install babel-cli -g를 하고

2. 프로젝트 root에 src 와 dist 폴더를 만든다.

3. npm install babel-preset-env --save 를 하고

4. Project root에 .babelrc를 만들고

{
  "presets": [
    "env"
  ]
}

를 입력한다.

5. babel ./src/babel.example.js -o ./out.js 를 하면
babel 컴파일링 된 파일을 만들어 준다.

<babel로 컴파일링 자동화 과정>

package.json에

"scripts" : {
  "start": "node ./bin/www",
  "build": "babel ./src --out-dir ./dist --watch"
}

-> 여기에 "build" 부분을 추가한다.

6. app.js 에서

app.use(express.static(path.join(__dirname, 'public')));

		|
		V

app.use(express.static(path.join(__dirname, 'public')));
app.use(express.static(path.join(__dirname, 'node_modules')));
// cdn을 사용하지 않고 local에서 라이브러리를 사용하는 것

app.use(express.static(path.join(__dirname, 'dist')));



babel 이용시 regenerateruntime 이 오류가 나는데,
npm install babel-polyfill (옵션 더 있을 듯) 설치하고
script(src="/babel-polyfill/dist/polyfill.js") 를 pug의
head에 추가하면 될 것이다.
