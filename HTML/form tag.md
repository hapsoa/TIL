# form tag

type="submit" 인 input tag를 누르면

method 속성에서 http 메소드를 정해주고

action 에서 url 을 요청패스를 지정해준다.

그리고 서버단에서 name 속성값인 req.body.id, req.body.password 에 들어가게 된다. 그리고 해당 값은 input창에 입력한 값이 전달된다.

```html
<form method="post" action="/process/login">
		<table>
			<tr>
				<td><label>아이디</label></td>
				<td><input type="text" name="id" /></td>
			</tr>
			<tr>
				<td><label>비밀번호</label></td>
				<td><input type="password" name="password" /></td>
			</tr>
		</table>
		<input type="submit" value="전송" name=""/>
	</form>
```