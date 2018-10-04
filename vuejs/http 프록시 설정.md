# 10.2.1 http 프록시 설정

브라우저에 기본 설정된 보안 정책 중에 SOP(Same Origin Policy) 라는 것이 있습니다.
<br>

Browser 에서 origin이 있고, Consumer Server 의 컨슈머 페이지(index.html) 요청 / 응답 을 합니다.

<br>
그렇게 되면 browser 에서 origin 지정을 하게 되고,

<br>
Service Provider 에 요청하고 요청 수신이 되고,
응답 전송은 되지만,

<br>
수신 후 로딩은 작동되지 않는다.

그런 문제를 해결하기 위해

```
- 컨슈머 서버(Consumer Server) 측에 프록시 요소 생성
- 서비스 제공자(Service Provider) 측에서 CORS(Cross Origin Resource Sharing) 기능을 제공
- 서비스 제공자(Service Provider) 측에서 JSONP(JSON Padding) 기능을 제공
```

컨슈머 서버에 프록시 요소를 생성해서 컨슈머를 거쳐 요청이 전달되도록 할 수 있습니다.

<br>
vue.config.js

```javascript
module.exports = {
    devServer: {
        proxy: {
            '/api': {
                target: 'http://localhost:3000',
                changeOrigin: true,
                pathRewrite: {
                    '^/api': ''
                }
            }
        }
    }
};

```

