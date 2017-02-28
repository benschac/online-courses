document.getElementById('analyseButton').addEventListener('click', analyze);

function analyze() {
  let img = document.createElement('img');
  img.src = document.getElementById('input').value;


  let url = "https://westus.api.cognitive.microsoft.com/face/v1.0/detect?returnFaceAttributes=age,gender,headPose,smile,facialHair,glasses";
  let reqBody = {
        "language": "en",
        "id": 1,
        "url": document.getElementById("input").value
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
    console.log(res[0].faceAttributes.gender);
    document.querySelector('.image').append(img);
    document.getElementById("output").innerHTML =
    res[0].faceAttributes.gender + "<br/>" +
    res[0].faceAttributes.age;
  })
  .catch((err) => {
    alert(err);
    document.getElementById("output").innerHTML = "";
  });
}
