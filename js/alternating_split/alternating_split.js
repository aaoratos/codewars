function encrypt(text, n) {
  if (text === null || text === "" || n <= 0) return text;

  let charsArr = text.split("");
  let evenChars = "";
  let oddChars = "";
  let encryptedText = "";

  for (let i = 0; i < charsArr.length; i++) {
      if ((i + 1) % 2)
          oddChars += charsArr[i];
      else
          evenChars += charsArr[i];
  }
  encryptedText = evenChars + oddChars;
  return encrypt(encryptedText, n - 1);
}

function decrypt(encryptedText, n) {
  if (encryptedText === null || encryptedText === "" || n <= 0) return encryptedText;
  let decryptedText = "";

  for (let i = 0, j = Math.floor(encryptedText.length / 2); j < encryptedText.length; i++, j++) {
      decryptedText += encryptedText[j];
      decryptedText += encryptedText[i];
  }

  if (encryptedText.length % 2 !== 0)
      decryptedText = decryptedText.slice(0, -1);

  return decrypt(decryptedText, n - 1);
}