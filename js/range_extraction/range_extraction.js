function getRangeStr(rangeArr) {
    if (rangeArr === []) return "";
    if (rangeArr.length < 3)
        return rangeArr.join(",");

    return "" + rangeArr[0] + "-" + rangeArr[rangeArr.length - 1];
}

function solution(list) {
    let result = [];
    let tmpRangeArr = [];

    for (let i = 0; i < list.length; i++) {
        if (list[i + 1] !== list[i] + 1) {
            if (tmpRangeArr.length !== 0) {
                tmpRangeArr.push(list[i]);
                result.push(getRangeStr(tmpRangeArr));
                tmpRangeArr = [];
            } else result.push(list[i]);
        } else tmpRangeArr.push(list[i]);
    }
    return result.toString();
}