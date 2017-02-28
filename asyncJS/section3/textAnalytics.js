document.getElementById('analyseButton').addEventListener('click', analyze);

function analyze() {
  let url = "https://westus.api.cognitive.microsoft.com/text/analytics/v2.0/keyPhrases";
  let reqBody = {
    'documents': [
      {
        "language": "en",
        "id": 1,
        "text": document.getElementById("input").value
      }
    ]
  }

  let myHeaders = new Headers({
    'Content-Type': 'application/json',
    'Ocp-Apim-Subscription-Key': config.MY_KEY
  });

  let initObj = {
    headers: myHeaders,
    body: JSON.stringify(reqBody),
    method: 'POST'
  }

  let request = new Request(url, initObj);

  fetch(request).then((res) => {
    if(res.ok) {
      return res.json();
    }

    else {
      return Promise.reject(new Error(res.statusText));
    }
  }).then((res) => {
    document.getElementById("output").innerHTML = "Total Key Phrases: " +
    res.documents[0].keyPhrases.length + "</br>" +
    res.documents[0].keyPhrases;
  })
  .catch((err) => {
    alert(err);
    document.getElementById("output").innerHTML = "";
  });
}
