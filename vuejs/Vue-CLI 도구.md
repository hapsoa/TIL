# Vue-CLI 도구

Vue.js 애플리케이션을 빠르게 개발할 수 있는 관련된 기능을 모두 제공하는 Vue.js 개발 도구이자 시스템입니다.

## 1. Vue CLI의 구성요소와 설치

### CLI : @vue/cli

### CLI 서비스: @vue/cli-service

### CLI 플러그인

ex)
router, vuex, babel, eslint, unit-jest, vuetify
<br>

```
-- 설치 방법 --
npm install -g @vue/cli
```

## 2. 프로젝트 생성과 기본 사용법

```
vue create [프로젝트 명]
```

### src
개발자가 작성하는 소스 코드를 배치하는 디렉터리

- assets : 여러 가지 자원 정보들이 저장되는 곳
- components : Vue 컴포넌트를 작성하기 위한 디렉터리

<br>

### public
배포 버전을 빌드할 때 필요한 파일

<br>

### node_modules
앱 개발과 배포에 필요한 npm 패키지들이 저장되는 디렉터리

<br>

### dist
작성한 앱 코드를 빌드하여 만든 배포 버전을 저장하는 디렉터리

## 3. 플러그인

```
vue add [플러그인]
```
ex) vue add router

## 4. vue.config.js

웹팩 설정을 위해 vue.config.js 라는 파일을 프로젝트 내부에 작성합니다.

## 5. Vue CLI GUI 도구

GUI 로 프로젝트를 생성 / 관리 할 수 있다.
