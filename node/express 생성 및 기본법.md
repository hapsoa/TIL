# node.js express 프로젝트 생성법

```
mkdir <프로젝트 명>
cd <프로젝트 명>

express

warning: the default view engine will not be jade in future releases
warning: use `--view=jade' or `--help' for additional options


  create : public/
  create : public/javascripts/
  create : public/images/
  create : public/stylesheets/
  create : public/stylesheets/style.css
  create : routes/
  create : routes/index.js
  create : routes/users.js
  create : views/
  create : views/error.jade
  create : views/index.jade
  create : views/layout.jade
  create : app.js
  create : package.json
  create : bin/
  create : bin/www

  install dependencies:
    $ npm install

  run the app:
    $ DEBUG=server-preset:* npm start

```

그리고 npm cors 를 설치해 주면 좋다.
https://www.npmjs.com/package/cors

<br>

# 기본 사용법

./routs/index.js 에

```
[GET] 의 경우 req.query 에 정보가 담기고
[POST] 의 경우 req.body 에 정보가 담긴다.

res.send(result); 로 응답을 보낸다.
// === res.json();
```

```javascript
/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/summarize', function(req, res, next) {
  // [GET]
  // req.query

  console.log(req.query);

  res.send(req.query);
  // === res.json();
  // [POST]
  // req.body
});

router.post('/summarize', function(req, res, next) {
  // req.body.text -> string;
  // TODO
  // SEND RESULT
  // res.send(req.body);
});
```
