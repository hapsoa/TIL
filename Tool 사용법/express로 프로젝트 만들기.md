# express로 프로젝트 만들기
CMD접속---

1) mkdir로 erase라는 파일을 생성
2) cd erase로 파일 안으로 접속
3) express -v pug -c sass 로 파일?들 다운.
   -v [VIEW MODE]
    -c [STYLE MODE]
4) npm install
5) WebStorm 열기
6) File 에서 Open들어가서 내가 방금 만든 abc 파일 찾아서 열기.

----------------
7) app.js에 있는
   app.use('/', indexRouter); 를 이용해서 주소 경로를 알아 볼 것이다.

8) '/'부분을 내가 원하는 경로 이름으로 바꿔 준다.
   -> '/test'라고 했다.

9) 여기서 7)의 indexRouter는 위의
   var IndexRouter = require('./routes/index');
   을 보아 routes파일에 있는 index파일에 접근할 것으로 보인다.

10) 따라서, routes파일에 index.js 에서
   router.get('/juwon', function(req, res, next) {
       res.send('HELLO!!!!!!!!!');
   });

   이렇게 추가 한다.

11) 왼쪽 밑에 있는 npm으로 start를 하고 chrome 주소창에
   http://127.0.0.1:3000/test/juwon
   하면 화면에 'HELLO!!!!!!!!!' 가 나온다.

12) 끝!