# <slot>

슬롯(slot)은 컴포넌트의 재사용성을 높여주는 기능

한 컴포넌트에 등록된 하위 컴포넌트의 마크업을 확장하거나 재정의할 수 있다.

<br>

ex)

하위 컴포넌트

```html
<!-- ButtonTab.vue -->
<template>
  <div class="tab panel">
    <!-- 탭 헤더 -->
    <slot></slot>
    <!-- 탭 본문 -->
    <div class="content">
      Tab Contents
    </div>
  </div>
</template>
```

상위 컴포넌트

```html
<!-- TabContainer.vue -->
<template>
  <button-tab>
    <!-- slot 영역 -->
    <h1>First Header</h1>
  </button-tab>
  <button-tab>
    <!-- slot 영역 -->
    <h1>Second Header</h1>
  </button-tab>
  <button-tab>
    <!-- slot 영역 -->
    <h1>Third Header</h1>
  </button-tab>
</template>

<script>
  export default {
    components: {
      ButtonTab,
    },
  };
</script>
```

<br>

slot에 이름을 붙여 여러개의 슬롯을 사용할 수 있다.

ex)

하위 컴포넌트

```html
<!-- ButtonTab.vue -->
<template>
  <div class="tab panel">
    <!-- 탭 헤더 -->
    <slot name="header"></slot>
    <!-- 탭 본문 -->
    <slot name="content"></slot>
  </div>
</template>
```

상위 컴포넌트

```html
<!-- TabContainer.vue -->
<template>
  <button-tab>
    <!-- slot 영역 -->
    <h1 slot="header">First Header</h1>
    <div slot="content" class="content">Tab Contents #1</div>
  </button-tab>
  <button-tab>
    <!-- slot 영역 -->
    <h1 slot="header">Second Header</h1>
    <div slot="content" class="content">Tab Contents #2</div>
  </button-tab>
  <button-tab>
    <!-- slot 영역 -->
    <h1 slot="header">Third Header</h1>
    <div slot="content" class="content">Tab Contents #3</div>
  </button-tab>
</template>
..
```

<br>

template 태그를 이용하면 부모 컴포넌트에서 slot 안에
다양한 컨텐츠를 넣을 수 있는 듯 하다.

```html
<button-tab>
  <!-- slot 영역 -->
  <template slot="header">
    <h1>First Header</h1>
  </template>
  <template slot="content">
    <div class="content">Tab Contents #1</div>
  </template>
</button-tab>
```

# slot-scope
부모 컴포넌트에서 자식 컴포넌트의 slot태그 속성값을 사용할 수 있게하는 것인듯

자식 컴포넌트 :
```html
<div class="child">
  <slot text="hello from child"></slot>
</div>
```

부모 컴포넌트 :
```html
<div class="parent">
  <child>
    <template slot-scope="props">
      <span>hello from parent</span>
      <span>{{ props.text }}</span>
    </template>
  </child>
</div>
```

렌더링하면 :
```html
<div class="parent">
  <div class="child">
    <span>hello from parent</span>
    <span>hello from child</span>
  </div>
</div>
```











<br><br><br><br><br><br><br>
```



















출처 : https://joshua1988.github.io/web-development/vuejs/slots/
```
