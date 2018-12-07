# jquery template string 유의사항

template string을 jquery로 묶어서 사용한다.

```javascript
_.forEach(keywords, (keywordUnit) => {
    const template = `
        <div class="keyword-unit">
            <div class="keyword">${keywordUnit.keword}</div>
            <div class="bar-graph-zone">
                <div class="bar-graph"></div>
            </div>
            <div class="count">${keywordUnit.count}회</div>
        </div>
        `;

    const $template = $(template);
    $template.find('.bar-graph').css('width', 60);
    $('.group-keyword').append($template);
});
```