function firstNonRepeatingLetter(s) {
    if (s.length === 1 || s === "") return s;
    let checked = [];
    for (let i = 0; i < s.length; i++) {
      let unique = true;
      if (checked.includes(s[i])) continue;
      for (let j = s.length - 1; j > i; j--) {
        if (s[i].toLowerCase() === s[j].toLowerCase()) {
          unique = false;
          checked.push(s[i]);
          break;
        }
      }
      if (unique) {
        return s[i];
      }
    }
    return "";
  }