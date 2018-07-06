# 함수 호출과 this

함수 호출 또한 다른 언어와는 달리 자유롭다.

## arguments 객체

함수를 호추할 때 인수들과 함께 암묵적으로 arguments 객체가 함수 내부로 전달 되기 때문에, 인자를 아무렇게나 넣어도 작동 되고 있다.

<br/>
arguments 객체를 다를 줄 알아야 한다.

<br/>
arguments 객체 : 함수를 호출할 때 넘긴 인자들이 배열 형태로 저장된 객체

<br/>
실제 배열이 아닌 유사 배열 객체

```javascript
// add() 함수
function add(a, b) {
	// arguments 객체 출력
	console.dir(arguments);
	return a + b;
}

console.log(add(1)); // (출력값) NaN
console.log(add(1, 2)); // (출력값) 3
console.log(add(1, 2, 3)); // (출력값) 3
	
}
```

arguments는 객체이지 배열이 아니다. 배열 메서드를 사용할 경우 에러가 발생한다는것에 주의.

<br/>
arguments 객체 -> 매개변수 개수가 정확하게 정해지지 않은 함수를 구현하거나, 

<br/>
전달된 인자의 개수에 따라 서로 다른 처리를 해줘야 하는 함수를 개발하는 데 유용.

```javascript
function sum() {
	var result = 0;
	
	for (var i = 0; i < arguments.length; i++) {
	result += arguments[i];
}

	return result;
}

console.log(sum(1, 2, 3)); //(출력값) 6
console.log(sum(1, 2, 3, 4, 5, 6, 7, 8, 9)); //(출력값) 45

```

## 호출 패턴과  this 바인딩

함수를 호출할 때 기존 매개변수로 전달되는 인자값에 더해, arguments 객체 및 this 인자가 함수 내부로 암묵적으로 전달된다.

<br/>
this가 이해하기 어려운 이유 : 함수가 호출되는 방식(호출 패턴)에 따라 this가 다른 객체를 참조하기(this 바인딩) 때문

<br/>
함수 호출 패턴과 해당 패턴에 따라 this가 어떤 객체에 바인딩 되는지 알아야 한다.

<br/>

### 객체의 메서드 호출할 때 this 바인딩

객체의 프로퍼티가 함수의 경우, 이 함수를 메서드.

<br/>
메서드 내부 코드에서 사용된 this는 해당 메서드를 호출한 객체로 바인딩된다.

```javascript
// my Object 객체 생성
var myObject = {
	name: 'foo',
	sayName: function () {
		console.log(this.name);
	}
}

// otherObject 객체 생성
var otherObject = {
	name: 'bar'
}

// otherOject.sayName() 메서드
otherObject.sayName = myObject.sayName;

// sayName() 메서드 호추
myObject.sayName();
otherObject.sayName();
```
```
[출력결과]
foo
bar
```

<br/>

### 함수를 호출할 때 this 바인딩

해당 함수 내부에서 사용된 this -> 전역 객체에 바인딩 된다.

```
브라우저 환경 - 전역 객체는 window 객체
Node.js 환경 - 전역 객체는 global 객체
```

<br/>

자바스크립트의 모든 전역 변수는 실제로는 전역 객체의 프로퍼티들
```javascript
var test = 'This is test';
console.log(window.test);

//sayFoo() 함수
var sayFoo = function() {
	console.log(this.test); // sayFoo()함수 호출 시 this는 전역 객체에 바인딩된다.
};

sayFoo();
```
```
This is test
This is test
```

<br/>
내부 함수(inner function)를 호출했을 경우에도 그대로 적용. 내부 함수에서 this를 이용할 때는 주의해야 한다.

```javascript
// 전역 변수 value 정의
var value = 100;

// myObject 객체 생성
var myObject = {
	value: 1,
	func1: function() {
		this.value += 1;
		console.log('func1() called. this.value : ' + this.value);

		// func2() 내부 함수
		func2 = function() {
			this.value += 1;
			console.log('func2() called. this.value : ' + this.value);
			
			func3 = function() {
				this.value += 1;
				console.log('func3() called. this.value: ' + this.value);
			}
			
			func3(); //func3() 내부 함수 호출
		}

		func2(); // func2() 내부 함수 호출
	}
};

myObject.func1(); // func1() 메서드 호출 
```
```
[출력결과]
2
101
102
```

내부 함수도 결국 함수이므로 이를 호추할 때는 함수 호출로 취급된다. 

<br/>
함수 호출 패턴 규칙에 따라 내부 함수의 this는 전역 객체 (window)에 바인딩된다.

<br/>
한계 극복 -> 부모 함수의 this를 내부 함수가 접근 가능한 다른 변수에 저장한다.

<br/>
관례상 this 값을 저장하는 변수의 이름 : that

<br/>
that 변수로 부모 함수의 thi가 가리키는 객체에 접근할 수 있다.


```javascript
// 내부 함수 this 바인딩

var value = 100;

var myObject = {
	value : 1,
	func1: function() {
		var that = this;

		this.value += 1;
		console.log('func1() called. this.value : ' + this.value);

		func2 = function() {
			that.value += 1;
			console.log('func2() called. this.value : ' + that.value);

			func3 = function() {
				that.value += 1;
				console.log('func3() called. this.value : ' + that.value);
			}
			func3();
		}
		func2();
	}
};

myObject.func1(); // func1 메서드 호출
```
```
[출력 결과]
2
3
4
```


<br/>

### 생성자 함수를 호출할 때 this 바인딩

기존 함수에 new 연산자를 붙여서 호출하면 해당 함수는 생성자 함수로 동작한다.

<br/>
특정 함수가 생성자 함수로 정의되어 있음을 알리려고 함수 이름의 첫 문자를 대문자로 쓰기를 권하고 있음.

```javascript
// Person() 생성자 함수
var Person = function (name) {
	// 함수 코드 실행 전
	this.name = name;
	// 함수 리턴
};

// foo 객체 생성
var foo = new Person('foo');
console.log(foo.name); // (출력값) foo

```javascript
// 객체 리터럴 방식으로 foo 객체 생성
var foo = {
	name: 'foo',
	age: 35,
	gender: 'man'
};
console.dir(foo);

// 생성자 함수
function Person(name, age, gender, position) {
	this.name = name;
	this.age = age;
	this.gender = gender;
}

// Person 생성자 함수를 이용해 bar 객체, baz 객체 생성
var bar = new Person('bar', 33, 'woman');
console.dir(bar);

var baz = new Person('baz', 25, 'woman');
console.dir(baz);

```

```javascript
var qux = Person('qux', 20, 'man');
console.log(qux); // (출력값) undefined

console.log(window.name); // (출력값) qux
console.log(window.age); // (출력값) 20
console.log(window.gender); // (출력값) man

```


#### 강제로 인스턴스 생성하기
```javascript
function A(arg) {
	if (!this instanceof A))
		return new A(arg);
	this.value = arg ? arg : 0;
}

var a = new A(100);
var b = A(10);

console.log(a.value); //(출력값) 100
console.log(b.value); // 10
console.log(global.value); // undefined

```

this가 A의 인스턴스인지를 확인하는 분기문 
-> this가 A의 인스턴스가 아니라면, new로 호출된 것이 아님을 의미. 그래서 new로 A를 호출하여 반환하게 함.

<br/>

다음과 같이 표현식을 쓰곤 한다.
```javascript
if (!(this instanceof arguments.callee))
... 
```
arguments.callee : 곧 호출된 함수
-> 특정 함수 이름과 상관없이 이 패턴을 공통으로 사용하는 모듈을 작성할 수 있음.

<br/>
어쨌든 이 패턴으로 함수 작성자의 의도와는 다르게 함수를 호출할 때에도 문제가 발생하지 않게 한다.



### call과 apply 메서드를 이용한 명시적인 this 바인딩

```javascript
// 생성자 함수
function Person(name, age, gender) {
	this.name = name;
	this.age = age;
	this.gender = gender;
}

// foo 빈 객체 생성
var foo = {};

// apply)() 메서드 호출
Person.apply(foo, ['foo', 30, 'man']);
console.dir(foo);
```
```
Person.apply(foo, ['foo', 30, 'man']);
```
apply() 메서드를 사용해서, Person() 함수를 호출한 코드다.

<br/>
결국 Person('foo', 30, 'man') 함수를 호출하면서, this를 foo 객체에 명시적으로 바인딩 하는 것을 의미한다.

<br/>
<br/>
call() 메서드 : apply() 와 기능은 같음

```javascript
Person.call(foo, 'foo', 30, 'man');
```

apply()나 call() 메서드는 this를 원하는 값으로 명시적으로 매핑해서 특정 함수나 메서드를 호출할 수 있다는 장점이 있다.


```javascript
function myFunction() {
	console.dir(arguments);

	// arguments.shift(); 에러 발생

	// arguments 객체를 배열로 변환
	var args = Array.prototype.slice.apply(arguments);
	console.dir(args);
}

myFunction(1, 2, 3);
```

<br/>

## 함수 리턴
자바스크립트 함수는 항상 리턴값을 반환한다.

### 규칙 1) 일반 함수나 메서드는 리턴값을 지정하지 않을 경우, undefined 값이 리턴된다.

### 규칙 2) 생성자 함수에서 리턴값을 지정하지 않을 경우 생성된 객체가 리턴된다

생성자 함수의 리턴값으로 넘긴 값이 객체가 아닌 불린, 숫자, 문자열의 경우
-> 이러한 리턴값을 무시하고 this로 바인딩된 객체가 리턴된다.
