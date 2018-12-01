# favicon

favicon이란, url 앞에 있는 아이콘이나 html title 앞의 아이콘을 뜻한다.

설정하는 법은 

```html
<head>
    <link rel="icon" href="<%= BASE_URL %>e-home-favicon.ico">
</head>
```

사용예시 2

```html
<link rel="shortcut icon" href="/favicon.ico" type="image/x-icon">
<link rel="icon" href="/favicon.ico" type="image/x-icon">
```

png 같은 이미지 파일을 ico 확장자로 바꾸려면, favicon-generator 사이트가 있다.

```
https://www.favicon-generator.org/
```

Maintain Image Dimensions (don't resize to be square) 를 체크 해제하면 기존의 png가 배경이 투명하면, 마찬가지로 배경을 투명하게 ico를 만들 수 있다.

