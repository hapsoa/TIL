# Vue-Cli

에반 유가 공식적으로 관리하는 커맨드라인 인터페이스 기반의 스캐폴딩(Scaffolding) 도구입니다.
<br>

scaffolding: 원래 '공사장 등에서 사용하는 임시 가설물'이라는 뜻입니다. 애플리케이션을 개발할 때 처음부터 개발하는 것이 아니라 기본적인 인터페이스와 틀을 제공해 줍니다.

```
npm install -g vue-cli (windows)
sudo npm install -g vue-cli (macOs)
```
<br>

```
vue list
```
프로젝트 템플릿을 살펴볼 수 있습니다.
<br>

```
vue init [템플릿명] [프로젝트명]
```
프로젝트 만들기 기능
ex)
```
vue init simple hellovuejs
```

이렇게 하면 html 파일 하나 있는 프로젝트가 생성이 된다.

```html
<!DOCTYPE html>  
<html>  
<head>  
 <meta charset="utf-8">  
 <title>hello vue.js</title>  
 <script src="https://unpkg.com/vue"></script>  
</head>  
<body>  
 <div id="simple">  
  {{ message }}  
  </div>  
 <script type="text/javascript">  
  const model = {  
        message: '첫 번째 Vue.js 앱입니다.'  
  };  
  
  const simple = new Vue({  
        el: '#simple',  
  data: model  
    })  
  </script>  
</body>  
</html>
```

model 객체는 변수명 그대로 '모델(Model) 객체'입니다.
simple 객체는 'Vue 객체'이자 '뷰모델(VieModel) 객체' 입니다.
<br>
'Vue 객체'의 'el 속성'은 HTML 요소(Element)를 나타냅니다.
'data 속성'은 모델 객체를 참조합니다.

<br>
Vue 객체가 html 요소와 데이터를 참조하고 있습니다.
이제 데이터(모델)가 변경되면 뷰모델 객체는 즉시 HTML 요소(뷰)에 반영시킵니다.
