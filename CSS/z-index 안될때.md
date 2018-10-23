# z-index 안될 때

z-index 를 설정하면서 안된다면,

그 위의 부모들의 z-index를 건드리면 된다.

부모가 z-index: 100 이고,
자식이 z-index: 1 이라도

자식이 위에 있다.

자식은 z-index가 100 + 1 = 101이 되는듯하다.
