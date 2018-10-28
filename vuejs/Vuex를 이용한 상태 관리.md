# Vuex를 이용한 상태 관리

부모 컴포넌트에서 자식 컴포넌트로 정보를 전달하기 위해 props를 이용했고, 자식 컴포넌트에서 부모 컴포넌트로 정보를 전달하기 위해서 event를 이용했습니다.

<br>

부모-자식 관계가 아니거나 계층 구조가 복잡해지면 어쩔 수 없이 이벤트 버스(Event Bus) 객체를 사용해야 합니다.

<br>

이벤트 버스 객체를 사용하는 방식도 대규모 애플리케이션을 개발하는 경우에는 복잡도를 증가시킬 수 밖에 없습니다. 이때문에 대규모 애플리케이션의 상태를 관리할 수 있는 상태 관리 라이브러리가 필요하다.

<br>

Vuex는 이벤트 버스 객체를 사용하여 코드가 복잡해지는 문제점과 공유 객체의 변경 추적이 힘들다는 문제점을 해결할 수 있는 좋은 패턴을 제공합니다.

## 1. 왜 Vuex를 사용하는가?
- 중앙 집중화된 상태 정보 관리가 필요하다.
- 상태 정보가 변경되는 상황과 시간을 추적하고 싶다.
- 컴포넌트에서 상태 정보를 안전하게 접근하고 싶다.

간단한 구조의 애플리케이션이라면 EventBus 객체의 사용 정도로도 충분히 해결될 수 있습니다.

## 2. Vuex란?

Vue.js 애플리케이션에서 상태관리 패턴을 지원하는 라이브러리.

Vue 컴포넌트가 나타내는 UI는 저장소(Store)의 상태(State)를 반영하고, Vue 컴포넌트의 UI에서 발생하는 행위는 액션(Action)을 통해 외부 API(예: 서비스에 대한 AJAX 요청)를 호출합니다. API 실행결과는 변이를 통해서 다시 상태를 변화시킵니다. 이렇듯 단방향 흐름으로 관리되기 때문에 상태 변화의 추적이 용이하며 예측할 수 있는 방법으로 상태를 변경할 수 있습니다.

## 3. 상태와 변이

```
상태 : 애플리케이션에서 관리해야 할 중요한 데이터
변이 : 상태를 변경하는 함수들을 보유하고 있는 객체
```

```javascript
import Vue from 'vue';
import Vuex from 'vuex';
import Constant from '../Constant';
Vue.use(Vuex);

const store = new Vuex.Store({
  state: {
    todolist : [
      { id:1, todo : "영화보기", done:false },
      { id:2, todo : "주말 산책", done:true },
      { id:3, todo : "ES6 학습", done:false },
      { id:4, todo : "잠실 야구장", done:false },
    ]
  },
  mutations: {
    [Constant.ADD_TODO] : (state, payload) => {
      if (payload.todo !== "") {
        state.todolist.push(
          { id:new Date().getTime(), todo: payload.todo, done:false });
      }
    },
    [Constant.DONE_TOGGLE] : (state, payload) => {
      var index = state.todolist.findIndex((item)=>item.id === payload.id);
      state.todolist[index].done = !state.todolist[index].done;
    },
    [Constant.DELETE_TODO] : (state, payload) => {
      var index = state.todolist.findIndex((item)=>item.id === payload.id);
      state.todolist.splice(index,1);
    }
  }
});

export default store;

```

```javascript
import Constant from '../Constant'

  export default {
    name: 'List',
    computed : {
      todolist() {
        return this.$store.state.todolist;
      }
    },
    methods : {
      checked : function(done) {
        if(done) return { checked:true };
        else return { checked:false };
      },
      doneToggle(id) {
        this.$store.commit(Constant.DONE_TOGGLE, {id: id})
      },
      deleteTodo(id) {
        this.$store.commit(Constant.DELETE_TODO, {id: id})
      }
    }
  }
```

변이(mutation)는 상태를 변경하기 위해 존재하고, 동기적인 처리만 가능합니다.

<br>

## 5. 액션

비동기적으로 처리

<br>

store 폴더의 index.js

```javascript
actions : {
    [Constant.ADD_TODO] : (store, payload) => {
      console.log("###addTodo!!!", payload);
      store.commit(Constant.ADD_TODO, payload);
    },
    [Constant.DELETE_TODO] : (store, payload) => {
      console.log("###deleteTodo!!!", payload);
      store.commit(Constant.DELETE_TODO, payload);
    },
    [Constant.DONE_TOGGLE] : (store, payload) => {
      console.log("###doneToggle!!!", payload);
      store.commit(Constant.DONE_TOGGLE, payload);
    }
  }
```

<br>

InputTodo.vue
```javascript
methods: {
      addTodo: function() {
        this.$store.dispatch(Constant.ADD_TODO, { todo: this.todo});
        this.todo = "";
      }
    }
```

<br>

### Store 객체의 속성

| 속성명 | 설명 |
|--|--|
| commit |변이를 일으키기 위한 메서드 입니다 |
| dispatch | 액션을 호출하기 위한 메서드입니다. 한 액션에서 다른 액션을 호출할 수 있습니다 |
| getters | 모듈 자기 자신의 게터입니다 |
| rootGetters | 루트 저장소의 게터입니다 |
| state | 모듈 자기 자신의 상태 데이터입니다 |
| rootState | 루트 저장소의 상태 데이터입니다 |

