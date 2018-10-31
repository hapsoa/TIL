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