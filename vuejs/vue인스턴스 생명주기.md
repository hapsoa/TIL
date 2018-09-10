# vue 인스턴스 생명주기 (life cycle)

생명주기(life-cycle) : 인스턴스의 상태에 따라서 호출할수 있는 속성
<br>

라이프 사이클 훅(life cyle hook) : 그 속성마다 개발자가 추가한 커스텀 로직
<br>

속성의 종류 : beforeCreate, beforeMount, mounted, beforeUpdate, beforeDestroy, destroyed 로 총 8개
<br>

## 1. beforeCreate
인스턴스가 생성되고 나서 가장 처음으로 실행되는 라이플 사이클 단계. 이 때는 뷰 인스턴스의 data와 methods 속성이 정의되어 있지 않고 화면 요소(dom) 에도 접근할 수 없음.

## 2. created
data 속성과 methods 속성이 정의되어있기 때문에 두 속성값에 접근하는 로직을 구현할 수 있다. 하지만 아직 화면 요소에 인스턴스가 부착되기 전이기 때문에 template 속성에 정의된 DOM 요소에 접근하는 코드를 구현할 수 없다.

## 3. beforeMount
render() 함수가 호출되기 직전의 단계. created 이후에 template 속성에 지정한 마크업 속성을 render() 함수로 변환한 후 el 속성에 지정한 화면 요소에 인스턴스를 부착하기 직전 호출되기 때문에 화면에 붙이기 전 실행해야할 코드를 구현한다.

## 4. mounted
el 속성에서 지정한 화면 요소에 인스턴스가 부착되고 난 후 호출되는 단계. template 속성에 정의한 화면 요소에 접근할 수 있기 때문에 화면 요소를 제어하는 코드를 구현하면 된다.

## 5. beforeUpdate
el 속성에서 지정한 화면 요소에 인스턴스가 부착되고 난 후에 인스턴스 속성들이 화면에 치환됩니다. 이 치환된 값을 $watch 속성으로 감시한다(이러한 작업을 데이터 관찰이라고 함).
<br>

이렇게 관찰하고 있는 데이터들이 변경되면 가상 돔을 이용해 화면에 다시 그려야 합니다. 이 때, 그리기 직전 호출되는 단계가 beforeUpdate 입니다. 따라서 변경 예정인 데이터 값을 이용해 작업을 해야할 때 그 로직을 이 단계에서 구현하면 된다.

## 6. updated
beforeUpdate 가 끝나고 화면에 다시 그리고 나면 실행되는 단계. 데이터가 변경되고 화면 요소를 제어하는 것을 구현하고 싶을 때 이 단계에서 작업하면 된다.
<br>
하지만 이 단계에서 그 값을 또 변경하면 무한 루프에 빠질 수 있습니다.
<br>
따라서 데이터 값을 갱신하는 로직은 beforeUpdate에서 처리해줘야 한다.

## 7. beforeDestroy

뷰 인스턴스가 destroy 되기 직전에 호출되는 단계. 이 단계에서는 아직 인스턴스가 없어지지 않았기 때문에 접근 가능하며 뷰 인스턴스의 데이터를 삭제하거나 인스턴스가 사라지지 직전 해야하는 작업들을 구현.

## 8. destroyed
뷰 인스턴스가 destroy 되고 난 후 호출되는 단계. 뷰 인스턴스에 정의한 모든 속성이 제거되고 하위에 선언했던 인스턴스들 역시 모두  destroy 됩니다.

<br>

ex)
```html
<template>
	<div id="app">
		{{ message }}
	</div>
</template>

<script>
	new Vue({
		el: '#app'
		data: {
			message: 'Hello Vue.js!'
		},
		beforeCreate: function () {
			console.log('beforeCreate');
		}
		cretaed: function () {
			console.log('cretaed');
		},
		mounted: function () {
			console.log('mounted');
		},
		updated: function () {
			console.log('updated');
		}
	})
</script>

```







