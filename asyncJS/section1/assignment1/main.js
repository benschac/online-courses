/*
- An application title labeled "Stopwatch Demo" -- complete
- A section with a timer that displays the current elapsed time to the hundredth second
- A button labeled "Start/Stop", "Reset", "Record Times" -- Complete
- A section labeled "Past Times" that keeps a record of previously recorded times

*/
let interval;
let time = 0;
let ready = true;
let lis = document.querySelectorAll('li');

function setId(id) {
  return document.getElementById(id);
}

function startStop() {
  if(ready) {
    ready = false;
    interval = setInterval(function () {
        setId('time').innerHTML = time.toFixed(2);
          time+= .01;
        }, 10);
    }
   else {
    ready = true;
    clearInterval(interval);
  }
}

function record() {
    let li = document.createElement('li');
    li.append(time.toFixed(2));
    setId('times').append(li);
}

function reset() {
  clearInterval(interval);
  time = 0;
  setId('time').innerHTML = time.toFixed(2);
  document.querySelectorAll('li').forEach((li) => li.remove());
  ready = true;
}

function init() {
  setId('time').innerHTML = time.toFixed(2);
  setId('start-stop').addEventListener('click', function() {
    startStop();
  });
  setId('reset').addEventListener('click', function() {
    reset();
  });
  setId('record').addEventListener('click', function() {
    record();
  });

  document.body.addEventListener('keypress', function(event) {
    if(event.key == 's') {
      startStop();
    }

    if(event.key == 't') {
      if(ready) {
        return;
      } else {
        record();
      }

    }

    if(event.key == 'r') {
      reset();
    }
  });
}

init();
