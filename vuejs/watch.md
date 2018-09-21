# watch 속성

감싲

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>03-07</title>
    <script src="https://unpkg.com/vue"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/underscore.js/1.9.1/underscore.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/fetch/3.0.0/fetch.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/es6-promise/4.1.1/es6-promise.auto.js"></script>

    <style>
        #list {
            width: 400px;
            border: 1px solid black;
            border-collapse: collapse;
        }
        #list td, #list th {
            border: 1px solid black;
            text-align: center;
        }
        #list > thead > tr {
            color: yellow;
            background-color: purple;
        }
    </style>
</head>
<body>
<div id="example">
    <p>
        이름 : <input type="text" v-model="name" placeholder="두자 이상 입력하세요" />
    </p>
    <table id="list">
        <thead>
            <tr>
                <th>번호</th><th>이름</th><th>전화번호</th><th>주소</th>
            </tr>
        </thead>
        <tbody id="contacts">
            <tr v-for="contact in contactlist">
                <td>{{contact.no}}</td>
                <td>{{contact.name}}</td>
                <td>{{contact.tel}}</td>
                <td>{{contact.address}}</td>
            </tr>
        </tbody>
    </table>
    <div v-show="isProcessing === true">조회중</div>
</div>

<script type="text/javascript">
    const vm = new Vue({
        el: '#example',
        data: {
            name: "",
            isProcessing: false,
            contactlist: []
        },
        watch: {
            name: function(val) {
                if (val.length >= 2) {
                    this.fetchContacts();
                } else {
                    this.contactlist = [];
                }
            }
        },
        methods: {
            fetchContacts: _.debounce(function() {
                this.contactlist = [];
                this.isProcessing = true;
                const url = "http://sample.bmaster.kro.kr/contacts_long/search/" + this.name;

                const vm = this;
                fetch(url)
                    .then(function(response) {
                        return response.json();
                    }).then(function(json) {
                        vm.contactlist = json;
                        vm.isProcessing = false;
                }).catch(function(ex) {
                    console.log('parsing failed', ex);
                    vm.contactlist = [];
                    vm.isProcessing = false;
                })
            }, 300)
        }
    })
</script>
</body>
</html>

```