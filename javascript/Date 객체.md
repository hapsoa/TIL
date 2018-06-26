# Date 객체

날짜와 시간을 표시하는 객체.

```javascript
// 변수를 선언합니다.
var date = new Date();

// 출력합니다.
alert(date);
```
매개 변수를 입력하지 않으면 현재 시각으로 초기화

<br>

```javascript
// 문자열을 사용한 Date 객체 생성
var date = new Date('December 9, 1991');
var date = new Date('December 9, 1991 02:24:23');
```

```javascript
// 숫자를 사용한 Date 객체 생성
var date = new Date(1991, 11, 9);
var date = new Date(1991, 11, 9, 2, 24, 23);
var date = new Date(1991, 11, 9, 2, 24, 23, 1);
```
```javascript
// Unix time을 사용한 Date 객체 생성
var date = new Date(2732741033257);
```

## 메서드

```javascript
// 변수를 선언합니다.
var date = new Date();

// 현재 시각에서 7일을 더합니다.
date.setDate(date.getDate() + 7);

// 출력합니다
alert(date);
```

## 시간 간격 계산

날짜 간격을 구할 때는 getTime() 함수를 사용
<br>
getTime() 함수 : 1970년 1월 1일 자정부터 지난 밀리 초를 구합니다.

```javascript
// 변수를 선언합니다.
var now = new Date();
var before = new Date('December 9, 1991');

// 날짜 간격을 구합니다.
var interval = now.getTime() - before.getTime();
```

<br>
Date 객체의 프로토타입에 날짜 간격을 구하는 메서드 추가
-> 쉽고 편리하게 날짜 간격을 구할수 있음

```javascript
// Date 생성자 함수의 프로토타입에 메서드를 추가합니다.
Date.prototype.getInterval = function(otherDate) {
	// 변수를 선언합니다.
	var interval;

	// 양수로 날짜 간격을 구하려고 조건문을 사용합니다.
	if (this > otherDate) {
		interval = this.getTime() - otherDate.getTime();
	}
	else {
		interval = otherDate.getTime() - this.getTime();		
	}

	// 리턴합니다.
	return Math.floor(interval / (1000 * 60 * 60 * 24));

	// 변수를 선언합니다.
	var now = new Date();
	var before = new Date('December 9, 1991');

	// 출력합니다.
	alert('Interval: ' + now.getInterval(before) + '일');
}
```

