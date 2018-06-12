# extends

layout.pug 파일이 있다면
```pug
doctype html  
html  
 head title= title  
  link(rel='stylesheet', href='/stylesheets/style.css')  
  body  
 block content
```

index.pug 파일
```pug
extends layout  
  
block content  
  h1= title  
  p Welcome to #{title}
```

# include
pug 파일에서 다른파일 안의 코드를 붙여 넣는다.
붙여넣는 코드는 pug 외에 어떤 확장자도 가능하다고 한다

frame.pug
```pug
extends layout //layout.pug

block content
  include login  //login.pug
```
