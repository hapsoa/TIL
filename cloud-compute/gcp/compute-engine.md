# compute engine

cloud computing(가상 컴퓨터 인스턴스)을 띄우는 것인듯 하다.

gcp(google cloud platform)에서 compute

# compute engine을 도메인에 연결하는 법

https://www.youtube.com/watch?v=4iciq0ck8Ns

gabia에 네임서버를 추가하고,
dns 레코드에서
a 레코드로 '35.123.123.123' 외부 ip를 입력한다.
cname 레코드로 'jaejong.xyz.' 을 입력한다.

gcp
네트워크 서비스 => Cloud DNS 에서 레코드 모음 추가

<br>

## vpc 네트워크 => 외부 IP 주소

고정 IP 주소로 바꿀 수 있다.

<br>

## vpc 네트워크 => 방화벽 규칙

송신 수신 2개 만들어서 방화벽을 개방한다.

<br>
