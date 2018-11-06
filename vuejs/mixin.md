# mixin

mixin Vue 생명주기와 관련하여 todo 가 있는 경우 사용한다.

library, util 기능이 필요한 경우에는 mixin이 아닌 prototype 을 사용한다.


```javascript
// mixin 객체 생성
var myMixin = {
  created: function () {
    this.hello()
  },
  methods: {
    hello: function () {
      console.log('hello from mixin!')
    }
  }
}

// mixin을 사용할 컴포넌트 정의
var Component = Vue.extend({
  mixins: [myMixin]
})

var component = new Component() // => "hello from mixin!"
```

