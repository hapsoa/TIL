# axios 응답 형식

```javascript
axios.get('/api/contacts/'+this.no)
                    .then((response)=> {
                        console.log(response);
                        this.result = response.data;
                    })
```
의 response 객체
```
- config : 요청 시에 사용된 config 옵션 정보입니다.
- headers: 응답 헤더 정보입니다.
- request: 서버와 통신 시에 사용된 XMLHttpRequest 객체 정보입니다.
- status: HTTP 상태 코드(HTTP Status Code)
- statusText: 서버 상태를 나타내는 문자열 정보입니다.
```

HTTP 상태 코드(status)
```
2XX: 성공
3XX: 리다이렉션
4XX: 요청 오류(클라이언트 측 오류)
5XX: 서버 오류
```

