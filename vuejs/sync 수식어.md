# sync 수식어

자식 컴포넌트가 .sync를 가지는 속성을 변경하면 값의 변경이 부모에 반영됩니다. 

편리하지만 단방향 데이터 흐름이 아니기 때문에 장기적으로 유지보수에 문제가 생깁니다

```html
<comp :foo.sync="bar"></comp>
```

는 아래와 같습니다.

```html
<comp :foo="bar" @update:foo="val => bar = val"></comp>
```

<br>

하위 컴포넌트가 foo를 갱신하려면 속성을 변경하는 대신 명시적으로 이벤트를 보내야합니다.

```javascript
this.$emit('update:foo', newValue)
```