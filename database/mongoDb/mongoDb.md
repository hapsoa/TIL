# mongo db

NoSQL(Not Only SQL)

클라우드 서비스로 서버를 구성하는 경우가 많아지면서 많은 사용자를 수용하거나 시스템 자원을 적게 소모하는 NoSQL 데이터베이스에 점점 더 관심을 갖게 됨

```
데이터베이스 == 컬렉션의 집합
컬렉션 == 테이블
Document == 한 줄의 데이터인 레코드(Record)
```

```
<실행방법>
mongod --dbpath /Users/Jaejong/database/local

실행상태로 계속 둬야 데이터베이스를 사용할 수 있다.
```

```
<셸 상태로 몽고디비 접근법>

몽고디비 실행상태에서
mongo를 치고

db.users.insert({name:'소녀시대',age:20})

db.users.find().pretty()


데이터 추가 : insert() 메소드
데이터 조회 : find() 메소드
```



