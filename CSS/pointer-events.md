# pointer-events
```css
pointer-events: all | none
```
all : 클릭이나 호버되게
none: 클릭이나 호버 안되게

pointer-event: none 하더라도 이벤트 버블링을 막을 수는 없다.

이벤트 버블링은 event.stopPropagation() 을 호출해줘야 한다.