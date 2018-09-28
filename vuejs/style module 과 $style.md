# style module 과 $style

css 모듈을 css 스타일을 마치 객체처럼 다룰 수 있게 합니다.

```html
<template>
  <div>
    <button :class="$style.hand"> CSS Module을 적용한 버튼</button>
  </div>
</template>

<script>
  export default {
    name: "Module1",
    created() {
      console.log(this.$style);
    }
  }
</script>

<style module>
.hand {
  cursor: pointer;
  background-color: purple;
  color: yellow;
}
</style>
```

적용해야할 css 클래스가 여러개라면 배열 문법을 이용해 한번에 적용할 수 있습니다.

```html
<div v-bind:class="[$style.box, $style.border]">Hello World</div>
```