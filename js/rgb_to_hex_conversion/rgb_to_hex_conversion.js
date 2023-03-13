function rgb(r, g, b){
  return Array.from([r, g, b], x => (x > 255) ? 255 : (x < 0) ? 0 : x)
              .map((el) => (el.toString(16).length) === 1 ? "0" + el.toString(16) : el.toString(16))
              .join("").toUpperCase();
}