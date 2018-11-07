# object-fit

img 태그나 video 태그에서 그 상위의 container에 맞게 resize 하는 것이다.

```css
img {
    width: 200px;
    height: 400px;
    object-fit: cover;
}
```

| 속성 값 | 설명 |
|--|--|
| fill | 사이즈에 꽉 채운다 |
| contain | 비율에 맞게 들어간다. |
| cover | 비율에 맞게 꽉 들어가지만, 잘린다 |
| none | resize 되지 않는다. |
| scale-down | 내용물의 크기는 지정되지 않았거나 포함된 것처럼 지정됩니다(콘크리트 객체 크기가 작아질 수 있음). |

<br>

운영체제가 달라지거나 브라우저가 달리지면 object-fit 속성이 맞지 않는 경우가 생긴다.

그럴때 npm object-fit 에 관한 여러 모듈 중 하나를 받아서 사용 설명에 따라서 적용할 수 있도록 한다.