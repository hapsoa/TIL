# express

express 모듈로 'http 모듈로 서버 만드는 것'을 간단하고 좋은 기능을 활용해 만들 수 있다.

## 미들웨어

클라이언트 요청이 들어오면 라우터 전에 미들웨어가 독립된 함수로 필요한 처리를 할 수 있도록 한다.

```javascript
// Express 기본 모듈 불러오기
var express = require('express')
  , http = require('http');

// 익스프레스 객체 생성
var app = express();

// 미들웨어에서 응답 전송할 때 send 메소드 사용하여 JSON 데이터 전송
app.use(function(req, res, next) {
	console.log('첫번째 미들웨어에서 요청을 처리함.');
	
	res.send({name:'소녀시대', age:20});
});


// Express 서버 시작
http.createServer(app).listen(3000, function(){
  console.log('Express 서버가 3000번 포트에서 시작됨.');
});
```

res.send()에 javascript object를 넣어 보내면, 자동으로 json(string으로 이루어져 있음) 형식으로 보내준다.

<br>

쿼리를 req.query에서 받아올 수 있다.

| 추가한 정보 | 설명 |
|--|--|
| query | 클라이언트에서 GET 방식으로 전송한 요청 파라미터를 확인합니다. 예) req.query.name |
| body | 클라이언트에서 POST 방식으로 전송한 요청 파라미터를 확인합니다. 단, body-parser와 같은 외장 모듈을 사용해야 합니다. 예) req.body.name |
| header(name) | 헤더를 확인합니다. |

```javascript
// Express 기본 모듈 불러오기
var express = require('express')
  , http = require('http');

// 익스프레스 객체 생성
var app = express();

// 미들웨어에서 헤더와 파라미터 확인
// 아래 코드에서 파라미터는 GET 요청에 대해서만 처리 가능함 (POST는 req.body 객체 참조)
app.use(function(req, res, next) {
	console.log('첫번째 미들웨어에서 요청을 처리함.');
	
	var userAgent = req.header('User-Agent');
	var paramName = req.query.name;
	
	res.writeHead('200', {'Content-Type':'text/html;charset=utf8'});
	res.write('<h1>Express 서버에서 응답한 결과입니다.</h1>');
	res.write('<div><p>User-Agent : ' + userAgent + '</p></div>');
	res.write('<div><p>Param name : ' + paramName + '</p></div>');
	res.end();
});


// Express 서버 시작
http.createServer(app).listen(3000, function(){
  console.log('Express 서버가 3000번 포트에서 시작됨.');
});
```


## static 과 body-parser

```javascript
var express = require('express')
  , http = require('http')
  , path = require('path');

// Express의 미들웨어 불러오기
var bodyParser = require('body-parser')
  , static = require('serve-static');

// 익스프레스 객체 생성
var app = express();

// 기본 속성 설정
app.set('port', process.env.PORT || 3000);

// body-parser를 이용해 application/x-www-form-urlencoded 파싱
// post 요청을 처리할 수 있다.
app.use(bodyParser.urlencoded({ extended: false }));

// body-parser를 이용해 application/json 파싱
app.use(bodyParser.json());

// public 폴더를 기본 폴더로 둘 수 있다.
app.use(static(path.join(__dirname, 'public')));

// 미들웨어에서 파라미터 확인
app.use(function(req, res, next) {
	 console.log('첫번째 미들웨어에서 요청을 처리함.');

	var paramId = req.body.id || req.query.id;
	var paramPassword = req.body.password || req.query.password;

	res.writeHead('200', {'Content-Type':'text/html;charset=utf8'});
	res.write('<h1>Express 서버에서 응답한 결과입니다.</h1>');
	res.write('<div><p>Param id : ' + paramId + '</p></div>');
	res.write('<div><p>Param password : ' + paramPassword + '</p></div>');
	res.end();
});


// Express 서버 시작
http.createServer(app).listen(app.get('port'), function(){
  console.log('Express server listening on port ' + app.get('port'));
});
```