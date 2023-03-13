function alphabetPosition(text) {
  return text.toLowerCase()
             .split("")
             .filter( (ch) => ch.match(/[a-z]/))
             .map( (ch) => ch.charCodeAt() - 96)
             .join(" ");
}