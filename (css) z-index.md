# z-index 속성 - 요소 쌓는 순서 정하기

한 요소 위에 다른 요소를 쌓을 수 있습니다.

요소 위에 요소를 쌓을 때 쌓는 순서를 지정할 수 있음

값이 작을수록 아래에 쌓이고, 값이 클수록 위에 쌓입니다.

```html
#b1 {              
  z-index:1;  
}  
#b2 {             
  z-index:3;  
}  
#b3 {  
  z-index:1;  
}

<body>  
 <div id="wrapper">  
	 <div class="box" id="b1">1</div>  
	 <div class="box" id="b2">2</div>  
	 <div class="box" id="b3">3</div>  
</div>
</body>
```

