# @mixin

_global.sass 파일 작성 (공통된 스타일 속성 파일)
```sass
$nav-height: 50px  
  
@mixin backgroundImage($url)  
  background: url($url)  
  background-size: cover  
  
@mixin small-button  
  width: 32px  
  height: 32px  
  border-radius: 50%  
  border: solid 1px #f00  
  
@mixin inline-block  
  display: inline-block  
  vertical-align: top  
  
@mixin border-radius($rt, $rb, $lb ,$lt)  
  border-bottom-left-radius: $lb  
  border-bottom-right-radius: $rb  
  border-top-right-radius: $rt  
  border-top-left-radius: $lt
```


style.sass (한 페이지의 스타일 파일)
```sass
@import "global"  
  
아래는 그 페이지 코드 
```



-------

1. 미디어 쿼리 기본 
```sass
@media screen and (max-width: 1280px) and (min-width: 721px)
	.content-field
		background: #f00

@media screen and (max-width: 720px)		
	.content-field
		background: #f0f
```

2. @mixin을 이용한 _global.sass 내용
```sass
@mixin view-mobile
	@media screen and (max-width: 480px)	
		@content

@mixin view-tablet
	@media screen and (max-width: 960px)		
		@content
```

3. style.sass(한 페이지 스타일)에 mixin 적용
```sass
@include view-tablet
	background: #f0f

@include view-mobile
	background: #f00	
```
