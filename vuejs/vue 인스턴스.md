
# Vue 인스턴스

## Vue 인스턴스 만들기

```javascript
var vm = new Vue({
	// 옵션
})
```

## 속성과 메소드

각 Vue 인스턴스는 data 객체에 있는 모든 속성을 프록시(대리) 처리 합니다.

```javascript
// 데이터 객체
var data = { a: 1 }

// Vue 인스턴스에 데이터 객체를 추가합니다.
var vm = new Vue({
	data: data
})

// 같은 객체를 참조합니다!
vm.a ===  data.a

// 속성 설정은 원본 데이터에도 영향을 미칩니다.
vm.a = 2
data.a // => 2

// ... 당연하게도
data.a = 3
vm.a // => 3
```

data에 있는 속성들은 인스턴스가 생성될 때 존재한 것들만 '반응형'이라는 것입니다.

```javascript
vm.b = 'hi'
```
b 가 변경되어도 화면이 갱신되지 않습니다.
<br>

미리 나중에 속성이 필요하다고 판단되면
```javascript
data: {
	newTodoText: '',
	visitCount: 0,
	hideCompletedTodos: false,
	todos: [],
	error: null
}
```

<br>
Object.freeze() : 기존 속성이 변경되는 것을 막아 반응성 시스템이 추적할 수 없게 합니다.

```pug
#app  
  p {{ foo }}  
  button(v-on:click="foo = 'baz'") Change it
  // 버튼 눌러도 변경안되고, 콘솔에 에러뜹니다.
```
```javascript
const obj = {  
    foo: 'bar'  
};  
  
Object.freeze(obj);  
  
new Vue({  
    el: '#app',  
  data: obj  
});
```

<br>
Vue 인스턴스는 데이터 속성 이외에도 유용한 속성 및 메소드를 제공합니다.($접두어를 붙임)

```javascript
var data = { a : 1 }
var vm = new Vue({
	el: '#example',
	data: data
});

vm.$data === data // => true
vm.$el === document.getElementById('example') // => true

// $watch 는 인스턴스 메소드 입니다.
vm.$watch('a', function (newVal, oldVal) {
	// 'vm.a'가 변경되면 호출 됩니다.
});
```

## 인스턴스 라이프사이클 훅

created 훅은 인스턴스가 생성된 후에 호출됩니다.
```javascript
new Vue({
	data: {
		a: 1
	},
	created: function () {
		// 'this'는 vm 인스턴스를 가리킵니다.
		console.log('a is: ' + this.a);
	}
});
// => "a is: 1"
```
다른 라이프사이클 훅 : mounted, updated, destroyed 가 있습니다.





