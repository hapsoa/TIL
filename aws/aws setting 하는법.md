
-aws 가입

Gabia -> xyz -> AWS -> Route 53(DNS)

EC2
Compute Engine

Amazon Linux

<6단계> (이전단계는 걍 물흐르듯이하면됨)




[vue]


code style -> scheme -> 그 폴더 ~~scheme.xml 넣어서 apply ok






-----------------------------------

name: <webserver-instance-sg>

SSH -> 오픈할 ip 설정 22포트 / --> 0.0.0.0/0 (모든 거 가능)
HTTP 80 포트 추가
HTTPS 443 포트 추가



<7단계>

키 페어 선택 / 새 키 페어 생성


새 키 페어 생성

webserver-20180908 // 날짜로 관리하면 좋음 -> 나만 갖고 있어야 함!

키페어다운로드(.pem) -> 보관해놓기


===>>> 끝


<Terminal>

-> pem 다운받은 경로로 가기

-> IPv4 퍼블릭 IP (ip) 복사해서 
	
	# ssh -i webserver-20180908.pem ec2-user@(ip)

	-> yes 해도 안 됨

	# ls -l webserver-20180908.pem 해 보면

	-rw-r--r--@		소유자 / 그룹 / 다른 사용자

	pem 키가 다른 사람들 권한을 가지고 있으면 안 됨

	# chmod 400 webserver-20180908.pem 하면 됨
	# ls -l webserver-20180908.pem

	-r--------@		로 바뀜 => 이제 접속 됨 [EC2]


----------------------------------

이제 서버를 띄우자. (vue 라우터 테스트 리포지터리를 가지고 해보자.)

# $sudo yum install git -> 얘 깃 설치하기

문제가 있다. node를 다운 받아야 한다.

node 10을 다운받자 -> 근데 macOS로 돼 있다. Other download 가서

-> 현재 버전 Linux x64 오른쪽버튼 누르고 링크 주소 복사하기 (link)

# wget (link) 

(cd 쳐서 홈에서 다운받자)

/**

얘는 압축파일이다.. (xz 파일(file))

cd 들어가서 받았으면 홈으로 옮겨야 함

# mv (file) ~

**/

압축을 풀자

# tar xvf (file) 

git clone (vue router 주소.git)

# git clone https://github.com/55rgt/vue.git

압축 파일을 지우자

# rm (file)

---

들어가자

# cd (file)

# cd bin

-> 여기 중요한 실행 파일들(node, npm, npx)이 있다.

얘들을 언제 어디서든 실행할 수 있게 path에 추가해야 한다.

ls (node, npm, npx) 있는 곳에서 해야 함)()

# export PATH=$PWD:$PATH
(현재 패스 유지 + 디렉토리에 추가)

# cd

# node
>| 				=> 얘가 나오면 된 거임.

문제가 있다.

exit 하면 node가 없어진다.... 유지를 해야 함

# grep export
=> 우리가 했던 명령이 로그인 할 때마다 자동으로 추가되도록 해야 한다..

# echo $PWD

=> (path)

# export PATH=(path)

# vi ~/.bash_profile => export PATH=(path) 추가

	(i 누르면 삽입 모드) (wq)

			ex) export PATH=~~~/bin:$path <-- 얘를 추가하면 됨
				export PATH=

# ls -al
-> 하면 내장들이 다 보임



=> exit 하고 ssh -i webserver-20180908.pem ec2-user@(ip) 해서 node 쳐서 뭐가 나오면 됨 (ctrl + C 2번 치면 나와짐)

-----------------------------

클론 받은 폴더로 가서 npm install 하기

# npm install

한 다음에,

# npm run dev

------------------------

인터넷 aws로 가서 EC2에 우리 컴퓨터에 IPv4 퍼블릭 IP 주소가 있다. (ipv4)

-> 얘를 복사해서 하려고 했더니 접속이 안 됨. 왜 안되지? <= 포트번호가 없다.

우리는 8080

80포트는 일반적인 사용자가 할 수 없다.. 슈퍼유저만 쓸 수 있음

근데 우리는 사실 슈퍼유저였다.

# sudo npm run dev

-> 오류! 슈퍼유저는 노드가 설치되어 있지 않다.

로드밸런서를 써야 함

# npm run dev 계속 켜 둬라


------------------------

인터넷 aws 가서 aws => EC2 => 왼쪽에 로드밸런서 => 로드밸런서 생성 

=> 왼쪽꺼(첫번째꺼) 생성(application load balancer)

<단계 1>!!!

=> 이름 webserver-elb
=> 리스너 추가
	HTTPS 를 추가해야 하는데 추가할 수 없는 상황이다.
	-> 얘는 꼭 필요함
	-> 크롬에서 안전하지 않음 뜸
	-> 그래서 추가해야 함
	-> 안 하면 서버 권한 제한

	인증서를 받자




---------------------이거는 도메인 전용-------------------

AWS 서비스에서 SSL을 검색하면 Certificate Manager가 추천에 뜬다.

-> 이거 쳐서 인증서 프로비져닝 쳐서 

인증서 요청 -> 공인인증서~~~버튼


<1단계> 
도메인 이름 추가 chesterbe.xyz
			 *.chesterbe.xyz

다음

<2단계>

검증 방법 선택 -> DNS 검증을 쓰자

넘어가기 ... 

<4단계 검증>

Route 53에서 레코드 생성  -> 위에 꺼 밑에 꺼 두 개 중 하나만 하면 됨


-------------------------------------------------------

다시 197라인 부근 !!! 내용 쪽에 가서

=> 도메인 없으면 그냥 쌩 HTTP만 하고

=> 있으면 리스너 추가해서 HTTPS(보안) 넣어서 하면 됨


가용 영역 다 선택하기 2개가 나와야 한다. 한국인이다.


<단계 2> 보안

-인증서 => 도메인 있어야 있음

-보안 정책 => TLS 1-2-EXT-2018-06

<단계 3> 보안그룹 구성
 새 보안그룹 생성: webserver-elb-sg

 TCP 80
 TCP 443 -------------> HTTPS

<단계 4> 라우팅 구성

 대상 그룹

 이름: webserver-http-target
 프로토콜: HTTP
 포트: 8080

 다음

<단계 5> 대상 등록

 타겟 인스턴스 파란색으로 누르고 등록된 항목에 추가 눌러서 위로 올리자

 다음:검토

 생성한다!

생성이 됨.

로드밸런서 누르면 상태가 provisioning 되어 있는데 기다리면 active로 바뀜

설명 보면 ARN 밑에 DNS가 있는데 그 링크(link)를 복사해서 크롬 탭에 복붙하면 서버가 떠야 하는데 안 뜬다는 건 문제가 있다는 거다. (504 Gateway Time-out)
=> 왜 뜨냐면 80하고 443만 열어놔서 그럼

=> sol) 다른 포트를 추가해야 함
	-> 근데 이렇게 하면 서비스 추가할 때마다 다 찾아서 추가해야 하기 때문에 별로임

	alt) 외부에서는 접속 못하게 하지만 안에 있는 컴퓨터끼리는 편하게 테스트 할 수 있게 만들어야 한다..

AWS 홈 가서 VPC 검색하면 VPC 대시보드 나옴

VPCs 눌러서 보면 IPv4 CIDR 보면 172.31.0.0/16으로 되어 있음

=> 16비트라는 거임 => 앞에 있는 2바이트에 대해서 체크하겠다는 거임

=> 얘를 바꿔줘야 한다. 과연 어떤식으로

EC2 - 네트워크 및 보안 - 보안 그룹으로 가서 우리가 만든 그룹 (instance-sg) 체크 후 -> 인바운드를 편집해서 22번만 놔두고 80 닫아버리고 443도 닫아버린다.. 그 다음에 모든 TCP 추가해서 얘 부분의 소스를 172.31.0.0/16으로 추가하면 다 접속할 수 있다.

이제 브라우저에 아까 (link) 로 들어가면 된다. 그만하자.

근데 502가 뜰 수 있다.. 그러면 뭔가를 해야 함

dev 떠 있는걸 Ctrl+C로 중지시키고 ls 치면 라우토쪽

vi config/index.js -> 들어와짐

16째 줄 host: 'localhost' -> 얘를 host: '0.0.0.0' 으로 바꾸면 된다.

npm run dev를 해서 다시 해 보자 그러면 초록색 V가 뜸

도메인 있는 애들을 도메인을 연결하면 된다..

하지만 사실 다 한 게 아니다. 또 문제가 있다.

--------------도메인 애들 전용--------------

Router53으로 가서 hosted zones 

www.chesterbe.xyz 를 type- A~ 레코드로 바꾸고

alias -> yes 로드밸런서를 선택하고 확인하면 된다..

(dualstack?? save 저장하고)

nslookup www.chesterbe.xyz

-> 어떻게 바뀜 canonical name(name)이 바뀔 때가 있다.

-> chesterbe.xyz -> 락이 걸림 (https까지)

-> https://chesterbe.xyz

__________________________________________

로드밸런서 추가하면 돈 든다. 지우자.

또 문제가 있다.

terminal 창을 끄면 502 뜬다.

process를 백그라운드로 옮겨야 한다. (daemonize)

terminal 접속해서 vue-router-sample(프로젝트 말하는 거)로 가서

# npm i pm2 -g 설치

# pm2 start npm -- run dev

-> npm이 뜨고 있다. 테이블이 나옴

# exit 하고(창을 닫고) 도메인으로 접속해도 돌아간다. V

근데 사실 얘도 문제가 있다.

인스턴스 재부팅이 걸리면 pm2가 작업을 안 해준다. 설정을 해 주자.

# ssh 접속 해서

# cd (project) 가서

# pm2 list 하면 안 떠 있다..

# pm2 start npm -- run dev

# pm2 save

# pm2 startup을 실행 하면 sudo ~ 뭐가 나오는데 (something)

얘를 복붙해서 엔터 치면 됨

# (something)

끝!!

크롬에 주소/vue(프로젝트이름) 쳐서 나오면 끝


<지우자>

인스턴스 -> 작업 - 상태 - 종료 (종료됨)
로드밸런서 -> 작업 - 삭제          (얘는 삭제 안 하면 돈 나감.)
route53 가서 도메인 delete record set 
(인증서 ssl - 삭제)
