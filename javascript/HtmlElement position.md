# HtmlElement position 관련 정리

## HtmlElement 가로 길이

```
HtmlElement객체.clientWidth
```

## HtmlElement의 위치 찾기

```
HtmlElement객체.scrollTop : 해당 객체의 스크롤된 길이

HtmlElement객체.offsetTop : the number of pixels from the top of the closest relatively positioned parent element. (부모 element에서 상대적 높이 거리)

HtmlElement객체.getBoundingClientRect() : The values returned by element.getBoundingClientRect() are relative to the viewport(현재 보이는 창) (현재 보이는 창 기준으로 element의 위치).
```

## HtmlElement의 스크롤 이동

```
// 아래 둘은 같음
HtmlElement객체.scroll(x, y)
HtmlElement객체.scrollTo(x, y)

HtmlElement객체.scrollBy(x, y)
```

## 최상단으로 스크롤하기

```javascript
window.scrollTo(xCoord, yCoord);
```
