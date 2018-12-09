# iterator 사용하는 이유

```java
public void viewer(Iterator iter){ 
 while(iter.hasNext()){
     System.out.println(iter.next());     
    }
}
```


이 뷰어메서드는 어떤 컬렉션이던 상관하지 않고 모두 동일한 방법으로 요소에 대한 모든 내용을 출력가능합니다.

바로 이걸 위해서 iterator를 쓰는거죠

어떤 요소를 반복적으로 꺼내는 작업을 할때 iterator를 사용하게 된다면

그 요소가 무엇으로 변하건 간에 변경작업 없이 사용 가능할 것입니다.

<br><br><br><br><br><br>




출처: http://invincure.tistory.com/entry/Iterator-에-대해서 [Do you want it? Come get it.]