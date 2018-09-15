# Vue 인스턴스

## 1. el, data, computed 옵션


```html
<body>
  <div id="test">
    {{ name }}
  </div>

  <script type="text/javascript">
    const model = {
        name : "홍길동"
    };
    const vm = new Vue({
        el: '#test',
        data: model
    })

  </script>
</body>
```

vm.name
"홍길동"

model.name
"홍길동"

vm.$data.name
"홍길동"

<br>
모두 같다

## 2. 메서드

메서드와 계산된 속성을 사용했을 때 최종적인 결과물은 같아 보이지만 내부 작동 방식에는 차이가 있습니다.

계산된 속성은 종속된 값에 의해 결괏값이 캐싱된다는 점입니다. 하지만 메서드는 매번 실행됩니다.

<br>
캐싱 여부에 따라 computed 를 할지 methods 를 할지 결정한다.

<br>
또한 화살표 함수는 쓰면 안된다. this가 전역 객체로 바뀌기 때문이다.
<br>

## 3. 관찰 속성
computed Property 가 있습니다만 주로 긴 처리 시간이 필요한 비동기 처리에 적합한 watch 옵션이 있습니다.

## v-cloak 디렉티브
화면이 오래 뜰 때 {{}} 안보이게
