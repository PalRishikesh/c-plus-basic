
let arr=[1,2,1,2,3,3,3,4];

let obj = {};
for (let index = 0; index < arr.length; index++) {
    const element = arr[index];
    obj[element] = obj[element] ? obj[element]+1:1;
    
}
// console.log(obj);
let sortedObj = Object.keys(obj).sort((a,b)=> {
    return obj[b] - obj[a];
})
// console.log(sortedObj);
let highestValueList = [];
for (let index = 0; index < 2; index++) {
    highestValueList.push(sortedObj[index]);
}
console.log(highestValueList);