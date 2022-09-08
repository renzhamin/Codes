
async function paste(input) {
  input = await navigator.clipboard.readText();
}

var txt;

async function code() {
    document.getElementById("sourceCodeTextarea").value= await navigator.clipboard.readText();
}

navigator.clipboard.readText().then(
  clipText => document.getElementById("sourceCodeTextarea").value=clipText);
