# 09 11

\<router-link to=""> 와 \<a> 차이
<br>

\<router-link to=""> 는 SPA(Single Page Application) 방식으로 작동한다.

```html
<router-link to="/user">누르면 유저페이지로 간다</router-link>
<a href="/user">누르면 유저페이지로 간다</a>
```

실제로 주소는 변경이 되었지만, 웹 서버로 url 변경으로 인한 요청이 없어 화면의 전환이 일어나는 경우 browser의 history를 client-js단에서 조작하여 뒤로가기, 앞으로가기 등의 기능을 지원한다.
<br>

## computed

데이터 값이 변경되면 자동으로 계산한 값을 적용한다.

```javascript
computed: {
  getButtonStyle() {
    return {
      background: this.background,
	  color: this.color
    };
  }
}
```

this.color 와 this.background 가 변경되면 getButtonStyle() 이 DOM에 새로 적용이 된다.

<br>

## props

외부에서 데이터를 넣을 수 있도록 한다.

```javascript
props: {
  size: {
    type: String,
    default: 'small'
  },
  text: {
    type: String,
    required: true
  },
  icon: {
    type: String,
    required: true
  },
  background: {
    type: String,
    default: '#fa0'
  },
  color: {
    type: String,
    default: '#fff'
  }
}
```

## this.\$emit()

```javascript
methods: {
  click() {
    this.$emit('click', 'wtwt?');
  }
}
```

click 이라는 메소드를 밖으로 내보낸다.
그럼으로 해서 밖에서 click 메소드를 정의할 수 있도록 한다.
<br>

'click'으로 나가고, 두번째 argument 부터 바깥에서 함수의 parameter 로 활용된다.

```javascript
export default {
  methods: {
    clickButton0(arg) {
      console.log('00000 button!!', arg);
    }
  }
```

## props 와 이벤트 받을 때

```javascript
button-simple(:text="'배고파'"
:icon="'fa-user'"
:background="'#000'"
:size="'large'" @click="clickButton1")
```

html에서 ':'으로 props를 받아들일 수 있도록 하고,
@으로 함수를 받아들일 수 있도록 한다.

## import

```javascript
import * as _ from "lodash";
```

lodash 의 모든(\*) 퍼블릭메소드와 퍼블릭변수 들을 '\_' 에 담는다는 뜻.

## util 폴더

util 폴더에는 000,000, , 쉼표 찍는다는 함수 처럼 그런 유틸 함수를 넣을 수 있도록 한다.

ex)

```javascript
const File = {
  readFile() {},
  writeFile() {}
};

const Date = {
  getDateToString() {}
};

export { File, Date };
```

File 과 Date 객체를 밖으로 내보낸다.

## App.vue

component를 넣을 때는 App.vue 에다가 넣을 수 있도록 한다.
하지만 이렇게 하면 전역으로 import 하는 꼴이 되기 때문에 별로 좋은 선택은 아닌듯 하다.

```javascript
import Vue from "vue";
import Button from "./components/button-simple";
import { store } from "./vuex/store";

Vue.component(Button.name, Button);
```

그리고
main.js 에서 new Vue()를 하고

```javascript
import Vue from "vue";
import App from "./App";
import router from "./router";

Vue.config.productionTip = false;

/* eslint-disable no-new */

new Vue({
  el: "#app",
  router,
  components: { App },
  template: "<App/>"
});
```
