# jquery를 vue에서 사용하기

mounted() 에서 jquery를 접근하도록 한다.

```html
<template>
  <div>
    <button id="btn">click me</button>
  </div>
</template>

<script>
  import $ from 'jquery';

  export default {
    mounted() {
      $('#btn').click(function() {
        alert('hi');
      });
    },
  };
</script>
```

```
<template> 안에 HTML 태그가 있으니 제이쿼리로 항상 접근할 수 있을 것 같지만 실제로는 그렇지 않습니다.

왜냐하면 <template>은 실제 돔으로 변환되기 전의 Virtual DOM 상태이기 때문에 적절한 라이프 사이클 훅에서 접근하지 않으면 접근할 수 없기 때문입니다.
```
