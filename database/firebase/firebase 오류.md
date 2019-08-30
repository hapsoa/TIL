# firebase 오류

## cors 에러가 날 시

프로젝트 루트 디렉토리에 cors.json을 만든다.

아래 origin이 * 이므로 모든 url에 cors를 해제한다는 뜻이다.
```json
[
  {
    "origin": ["*"],
    "method": ["GET"],
    "maxAgeSeconds": 3600
  }
]
```

그리고 터미널에 아래 명령어를 입력한다.
```
gsutil cors set cors.json gs://<your-cloud-storage-bucket>
```
(gs://"~~~" 는 내 firebase storage 주소)
