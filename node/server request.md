
# server.on('request', function(req, res){});

```javascript
// 웹서버 객체를 만듭니다.
var server = http.createServer();

// 클라이언트 요청 이벤트 처리
server.on('request', function(req, res) {
	console.log('클라이언트 요청이 들어왔습니다.');
	
	res.writeHead(200, {"Content-Type": "text/html; charset=utf-8"});
	res.write("<!DOCTYPE html>");
	res.write("<html>");
	res.write("  <head>");
	res.write("    <title>응답 페이지</title>");
	res.write("  </head>");
	res.write("  <body>");
	res.write("    <h1>노드제이에스로부터의 응답 페이지</h1>");
	res.write("  </body>");
	res.write("</html>");
	res.end();
	  
});
```

| 메소드 이름 | 설명 |
|--|--|
| writeHead(statusCode[, statusMessage][, headers] | 응답으로 보낼 헤더를 만듭니다. |
| write(chunk[, encoding][, callback]) | 응답 본문(body) 데이터를 만듭니다. 여러 번 호출될 수 있습니다. |
| end([data][, encoding][, callback]) | 클라이언트로 응답을 전송합니다. 파라미터에 데이터가 들어 있다면 이 데이터를 포함시켜 응답을 전송합니다. 클라이언트의 요청이 있을 한 번은 호출되어야 응답을 보내며, 콜백 함수가 지정되면 응답이 전송된 후 콜백 함수가 호출됩니다 |
