# GET 방식과 POST 방식의 차이점
웹 서버에 요청을 보내는 방식은 GET, POST, PUT, DELETE 등 여러 가지가 있습니다. 인터넷 표준으로 정해 둔 이러한 요청 방식을 메소드(Method)라고도 부릅니다. HTTP 요청 포맷을 보면 크게 헤더(Header)와 본문(Body) 부분으로 나뉘는데 GET 방식은 헤더 부분에 요청 정보들을 넣어 보내고 POST 방식은본문 부분에 요청 정보를 넣어 보냅니다. 이 두 가지 방식은 기능상으로는 요청 정보를 보낸다는 점에서 같지만 보안 등의 이슈가 있을 때나 파일을 요청 정보로 넣어 보내야 하는 경우(파일 업로드)에는 POST 방식을 주로 사용합니다.