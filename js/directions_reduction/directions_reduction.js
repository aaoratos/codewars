function dirReduc(arr){
  const dirWeights = {"NORTH": 1, "SOUTH": -1, "EAST": 2, "WEST": -2};
  for (let i = 0; i < arr.length; i++) {
    if (dirWeights[arr[i]] + dirWeights[arr[i + 1]] === 0) {
      arr.splice(i, 2);
      dirReduc(arr);
    }
  }
  return arr;
}