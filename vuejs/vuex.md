# vuex

vuex 폴더의 store.js

```javascript
/* eslint-disable import/prefer-default-export */
import Vuex from 'vuex';
import Vue from 'vue';

Vue.use(Vuex);
const store = new Vuex.Store({
  state: { // 상태, 직접적으로 접근 x, mutation으로 접근한다.
    name: '',
    age: 0
  },
  /** 반드시 동기여야 한다.
   * method 이름이 문자열 이므로 상수로 빼둘 필요가 있다.
   * call by : store.commit('method', arg)
   */
  mutations: {
    changeName(state, name) {
      state.name = name;
    },
    changeAge(state, age) {
      state.age = age;
    },
    increment(state, data) {
      state.count += data.inc;
    }
  },

  /** 비동기가 포함 될 수 있다
   * method 이름이 문자열 이므로 상수로 빼둘 필요가 있다.
   * call by : store.dispatch('method', arg)
   */
  actions: {
    increment(context, data) {
      // async await
      context.commit('increment', data);
    }
  },
  getters: {
    getCount: state => state.count,
    name: state => state.name,
    age: state => state.age
  }
});

export { store };

```

ooo.vue 파일에서

```html
<template lang="pug">
  .hello
    h1 HELLO
    h3 {{$store.getters.name}}
    h3 {{$store.getters.age}}
    hr
    button(@click="increaseAge") increaseAge
    button(@click="decreaseAge") decreaseAge
    hr
    router-link(to="/store") GO TO STORE
</template>

<script>

import { store } from '../vuex/store';

export default {
  name: 'HelloWorld',
  store, // vue 에서 store를 쓰겠다는 뜻
  methods: {
    increaseAge() {
      this.$store.commit('changeAge',
        this.$store.getters.age + 1);
    },
    decreaseAge() {
      this.$store.commit('changeAge',
        this.$store.getters.age - 1);
    }
  }
```