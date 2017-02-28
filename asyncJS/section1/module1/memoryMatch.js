let clickedArray = [];
let interval;
let started = false;
let time = 0;
let ready = true;
let numCompleted = 0;


setup();

function randomAnswers() {
  return [1,1,2,2,3,3,4,4,5].sort(() => .5 - Math.random());
}

function startTimer() {
  if(started == false) {
    interval = setInterval(() => {
      time++;
      document.getElementById("timer").innerHTML = "Time Elapsed: " + time;
    }, 1000);
    started = true;
  }
}

// Stateful functions.
function reveal(cell) {
  cell.clicked = true;
  cell.innerHTML = cell.value;
  cell.style.background = 'red';
}

function hide(cell) {
  cell.style.background = 'blue';
  cell.innerHTML = '';
  cell.clicked = false;
}

function complete(cell) {
  cell.style.background = 'purple';
  cell.completed = true;
  numCompleted++;
}
// startTimer();
function setup() {
  let grid = document.getElementsByTagName('td');
  let answers = randomAnswers();

  document.addEventListener('keydown', function(event) {
    if(event.key > 0 && event.key < 10) {
      grid[event.key - 1].click();
    }
  });

  document.getElementById('restart').addEventListener('click', function() {
    location.reload();
  })
  for(var i = 0; i < grid.length; i++) {
    // Loop over all grid items.
    var cell = grid[i];
    cell.completed = false;
    cell.clicked = false;
    cell.value = answers[i];

    // Event Delegation
    cell.addEventListener('mouseenter', function() {
      if(this.completed == false && this.clicked == false) {
        this.style.background = 'orange';
      }
    });

    cell.addEventListener('mouseleave', function() {
      if(this.completed == false && this.clicked == false) {
        this.style.background = 'blue';
      }
    });

    cell.addEventListener('click', function() {
      if(ready == false) {
        return;
      }
      clickedArray.push(this);
      // Using the context of this as the argument while delegating the event.
      startTimer();
      reveal(this);

      if(clickedArray.length == 2) {
        if(clickedArray[0].value == clickedArray[1].value
        && clickedArray[0].id != clickedArray[1].id) {
          console.log(clickedArray);
          complete(clickedArray[0]);
          complete(clickedArray[1]);
          clickedArray = [];

          if(numCompleted == 8) {
            alert('You\'ve won the game!');
            clearInterval(interval);
          }
        } else {
          // Pause so user can see incorrect answer.
          ready = false;
          document.getElementById('gridTable').style.border = '5px solid red';
          setTimeout(() => {
            hide(clickedArray[0]);
            hide(clickedArray[1]);
            clickedArray = [];
            ready = true;
            document.getElementById('gridTable').style.border = '5px solid black';
          }, 500);
        }
      }
    });
  }
}
