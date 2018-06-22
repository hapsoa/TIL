# window 객체

자바 스크립트의 브라우저 기반 최상위 객체

<br/>
alert(), prompt() 함수 모두 window 객체의 메서드 입니다.

```javascript
window.alert();
```

기본 변수와 window 객체
> var 키워드로 선언한 일반 변수도 모두 window 객체의 속성이 된다.

## 새로운 window 객체 생성

```
window.open(URL, name, features, replace);
```
```javascript
window.open(); // 새로운 웹브라우저 윈도우가 만들어집니다.
```
```javascript
window.open('http://hanbit.co.kr', 'child', 'width=600, height: 300', true);
```

open() 메서드 : 새로운 window 객체를 생성하는 메소드 이면서, 윈도우 객체를 리턴한다.

```javascript
//변수를 선언합니다.
var child = window.open(", ", 'width=300, height= 200');

// 출력합니다.
child.document.write('<h1>From Parent Window</h1>');
```

<br/>

