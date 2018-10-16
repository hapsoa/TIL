# vue-router를 이용한 라우팅

# 1. vue-router란?
화면마다 고유의 식별자를 기반으로 화면을 렌더링해야 합니다. 고유 식별자로 사용하기에 가장 적절한 정보가 바로 URI(Uniform Resource Identifier) 입니다.

# 2. vue-router 기초

```html
<template>
  <div>
    <div class="header">
      <h1 class="headerText">(주)OpenSG</h1>
      <nav>
        <ul>
          <li><router-link to="/home">Home</router-link></li>
          <li><router-link to="/about">About</router-link></li>
          <li><router-link to="/contacts">Contacts</router-link></li>
        </ul>
      </nav>
    </div>

    <div class="container">
      <router-view></router-view>
    </div>
  </div>
</template>
<script>
    import Home from './components/Home.vue';
    import About from './components/About.vue';
    import Contacts from './components/Contacts.vue';
    import VueRouter from 'vue-router';

    const router = new VueRouter({
        routes : [
            { path:'/', component: Home },
            { path:'/home', component: Home },
            { path:'/about', component: About },
            { path:'/contacts', component: Contacts }
        ]
    });

    export default {
        name : 'app',
        router
    }

</script>
<style>
  .header { background-color:aqua; padding: 10px 0px 0px 0px; }
  .headerText { padding: 0px 20px 0px 20px; }
  ul { list-style-type: none; margin: 0; padding: 0;
    overflow: hidden; background-color: purple;  }
  li { float: left; }
  li a { display: block; color: yellow; text-align: center;
    padding: 14px 16px; text-decoration: none;  }
  li a:hover { background-color: aqua; color:black; }
</style>

```

## 4. 중첩 라우트
하나의 컴포넌트가 다시 하위 컴포넌트를 포함하는 경우에 라우팅도 중첩이 가능해야 합니다.

