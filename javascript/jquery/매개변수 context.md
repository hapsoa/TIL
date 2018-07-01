# 매개변수 context

jQuery 메서드는 사실 매개변수 두 개 입력할 수도 있습니다.

```
$(selector, context)
```

매개변수 context는 selector가 적용하는 범위를 한정합니다.

<br>
특정 부분에 선택자를 적용하고 싶을 때 사용하는 것 -> 매개변수 context

<br>
ex)

```javascript
$(document).ready(function(){
	// 이벤트를 연결합니다.
	$('div').click(function() {
		var header = $('h1', this).text();
		var paragraph = $('p', this).text();

		//출력합니다.
		alert(header + '\n' + paragraph);
	});
});
```

<br>
다음과 같이 find() 메서드를 사용해도 됩니다.

```javascript
$(document).ready(function(){
	// 이벤트를 연결합니다.
	$('div').click(function() {
		// 변수를 선언합니다.
		var header = $(this).find('h1').text();
		var paragraph = $(this).find('p').text();

		// 출력합니다.
		alert(header + '\n' + paragraph);
	});
});
```
