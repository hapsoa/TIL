# \<iframe> 태그
## 외부 문서 삽입하기
웹 문서 안에 다른 웹 문서를 가져와 표시하는 것 (= inline frame)

```html
<iframe src="삽입할 문서 주소" [속성 = "속성 값"]> <iframe>
```

| 속성 | 설명 |
|--|--|
| width | 인라인 프레임의 너비 |
| height| 인라인 프레임의 높이 |
| name | 인라인 프레임의 이름 |
| src | 프레임에 표시할 문서의 주소를 지정 |
| seamless | 프레임의 테두리를 없애 마치 본문의 일부처럼 보이도록 만듬 (속성 값 없이 그냥 쓰면 됨) |


```html
<div class="content">  
 <iframe src="http://www.easyspub.co.kr/" width="95%" height="500"></iframe>  
</div>
```



