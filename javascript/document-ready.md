# $(documnet).ready()

문서가 준비되면 매개변수로 넣은 콜백함수를 실행하라는 의미.

<br/>
한 이벤트로 여러 개의 함수를 연결할 수 있습니다.

```javascript
$(document).ready(function() {
	alert('First READY');
})

$(document).ready(function() {
	alert('Second READY');
})

$(document).ready(function() {
	alert('Third READY');
})
```

간단한 형태
```javascript
$(function() {

});
```

