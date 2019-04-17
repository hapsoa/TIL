# nginx

nginx는 웹서버(=http 서버) 이다.

웹서버란 인터넷(web, mail, ftp) 중 웹서비스를 위한 서버를 구동하는 프로그램이라고 볼 수 있는 듯 하다.

기존에는 apache를 많이 사용해왔다. 이제는 nginx를 활용 많이하기 시작한다.

apache는 프로젝트 디렉토리안의 각 파일들의 경로를 웹서버로 제공해주는 프로그램인 것으로 기억한다.
(www.jaejong.xyz/project1/project1-name.html)

라우팅을 해주는 프로그램이 아닌가 한다.

<br>

## ubuntu에 nginx 설치 및 시작 방법

https://twpower.github.io/39-install-nginx-on-ubuntu-by-using-apt-get-and-brief-explanation

```
// 시작
$ sudo service nginx start
$ sudo systemctl start nginx
$ sudo /etc/init.d/nginx start

// 재시작
$ sudo service nginx restart
$ sudo systemctl restart nginx
$ sudo /etc/init.d/nginx restart

// 중지
$ sudo service nginx stop
$ sudo systemctl stop nginx
$ sudo /etc/init.d/nginx stop

// 상태
$ sudo service nginx status
$ sudo systemctl status nginx

// 설정 reload
$ sudo service nginx reload
$ sudo systemctl reload nginx
$ sudo nginx -s reload

// configuration file syntax check
$ sudo nginx -t


$ sudo find / -name nginx.conf
```

## nginx 분기하는 법

```
http {
  server {
    server_name ttt.jaejong.xyz; //도메인 주소
    root /home/hapsoa; //파일을 가리키는 곳(index.html)
  }
}
```
