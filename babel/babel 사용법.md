babel 설정을 했으니,

접속을 해보도록 한다.

pug 파일을
script()를 설정한다.


babel 설정을 복습을 한다.

그리고 Promise.all()을 활용하는 방법에 대해서 더 강구를 할 수 있도록 한다.

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
