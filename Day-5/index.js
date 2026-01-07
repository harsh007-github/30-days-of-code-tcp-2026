const grid = document.getElementById('grid');
const status = document.getElementById('status');
const resetBtn = document.getElementById('reset');
const cells = document.querySelectorAll('.cell');

let currentPlayer = 'X';
let board = ["", "", "", "", "", "", "", "", ""];
let active = true;

const winPatterns = [
    [0,1,2], [3,4,5], [6,7,8], 
    [0,3,6], [1,4,7], [2,5,8], 
    [0,4,8], [2,4,6]           
];

function handleClick(e) {
    const index = e.target.dataset.index;

    if (board[index] !== "" || !active) return;

    board[index] = currentPlayer;
    e.target.innerText = currentPlayer;
    
    checkWinner();
}

function checkWinner() {
    let won = false;

    for (let pattern of winPatterns) {
        const [a, b, c] = pattern;
        if (board[a] && board[a] === board[b] && board[a] === board[c]) {
            won = true;
            highlightWinningCells([a, b, c]);
            break;
        }
    }

    if (won) {
        status.innerText = `Player ${currentPlayer} Wins!`;
        active = false;
    } else if (!board.includes("")) {
        status.innerText = "It's a Draw!";
        active = false;
    } else {
        currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
        status.innerText = `Player ${currentPlayer}'s Turn`;
    }
}

function highlightWinningCells(indices) {
    indices.forEach(i => cells[i].classList.add('winner'));
}

function resetGame() {
    board = ["", "", "", "", "", "", "", "", ""];
    currentPlayer = 'X';
    active = true;
    status.innerText = "Player X's Turn";
    cells.forEach(cell => {
        cell.innerText = "";
        cell.classList.remove('winner');
    });
}

cells.forEach(cell => cell.addEventListener('click', handleClick));
resetBtn.addEventListener('click', resetGame);