# v-on 을 이용한 사용자 지정 이벤트

$on(eventName) 을 사용하여 이벤트를 감지 하십시오.
$emit(eventName) 을 사용하여 이벤트를 트리거 하십시오.

```html
<body>
  <div id="counter-event-example">
    <p>{{ total }}</p>
    <button-counter v-on:increment="incrementTotal"></button-counter>
    <button-counter v-on:increment="incrementTotal"></button-counter>
  </div>

  <script type="text/javascript">
    Vue.component('button-counter', {
        template: '<button v-on:click="incrementCounter">{{ counter }}</button>',
        data: function () {
            return {
                counter: 0
            }
        },
        methods: {
            incrementCounter: function () {
                this.counter += 1;
                this.$emit('increment');
            }
        }
    });

    new Vue({
       el: '#counter-event-example',
       data: {
           total: 0
       },
        methods: {
           incrementTotal: function () {
               this.total += 1;
           }
        }
    })

  </script>
</body>
```

Vue 객체 안에서

this.$emit('increment');

라고 하면 바깥에서
```html
<button-counter v-on:increment="incrementTotal"></button-counter>
```

이런 식으로 받아 들일 수 있다.