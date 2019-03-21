# \_.debounce()

일정 시간(delay) 까지 기다리다가, 해당 함수가 다시 호출이 되지 않을때 함수가 호출된다.

ex)
input 값 0.5초 뒤에

```pug
input(ref="inputImageSearch", v-model="ui.images.search", @keyup="changeImageSearch" @blur="changeImageSearch" placeholder="검색" maxlength="16")
```

```javascript
methods: {
  changeImageSearch: _.debounce(function() {
    this.ui.images.debouncedSearch = this.$refs.inputImageSearch.value;
  }, 500),
}
```

