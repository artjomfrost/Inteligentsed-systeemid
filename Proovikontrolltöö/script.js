// Начальное состояние доски
let algseis = [
    ['B', '.', 'N', '.'],
    ['B', 'B', 'B', 'R'],
    ['.', 'R', 'R', 'R'],
    ['.', 'N', '.', '.']
];

// Определение всех форм фигуры L
const LShapes = [
    [[0, 0], [1, 0], [2, 0], [2, 1]], // Вертикальная L
    [[0, 0], [1, 0], [2, 0], [2, -1]],
    [[0, 0], [0, 1], [0, 2], [1, 2]], // Горизонтальная L
    [[0, 0], [0, 1], [0, 2], [-1, 2]],
    [[0, 0], [-1, 0], [-2, 0], [-2, -1]], // Перевернутая вертикальная L
    [[0, 0], [-1, 0], [-2, 0], [-2, 1]],
    [[0, 0], [0, -1], [0, -2], [1, -2]], // Перевернутая горизонтальная L
    [[0, 0], [0, -1], [0, -2], [-1, -2]],
];

// Проверка допустимости хода
function isValidMove(board, row, col, shape) {
    for (let [dx, dy] of shape) {
        let x = row + dx;
        let y = col + dy;
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) {
            return false; // Выход за границы
        }
        if (board[x][y] !== '.') {
            return false; // Клетка занята
        }
    }
    return true;
}

// Применение хода на доске
function applyMove(board, row, col, shape, mark) {
    for (let [dx, dy] of shape) {
        board[row + dx][col + dy] = mark;
    }
}

// Генерация доступных ходов для игрока
function generateMoves(board, playerMark) {
    let moves = [];
    for (let row = 0; row < board.length; row++) {
        for (let col = 0; col < board[row].length; col++) {
            for (let shape of LShapes) {
                if (isValidMove(board, row, col, shape)) {
                    let newBoard = board.map(row => row.slice()); // Копия доски
                    applyMove(newBoard, row, col, shape, playerMark);
                    moves.push(newBoard);
                }
            }
        }
    }
    return moves;
}

// Отображение доски в HTML
function renderBoardHTML(board) {
    return board.map(row => row.join(' ')).join('\n');
}

// Основная логика
function main() {
    const outputDiv = document.getElementById('output');

    // Вывод исходного состояния
    const initialState = document.createElement('div');
    initialState.innerHTML = `<h3>Исходное состояние:</h3><pre class="board">${renderBoardHTML(algseis)}</pre>`;
    outputDiv.appendChild(initialState);

    // Генерация доступных ходов
    const availableMoves = generateMoves(algseis, 'L');

    if (availableMoves.length === 0) {
        const noMoves = document.createElement('p');
        noMoves.textContent = "Нет доступных ходов для фигуры L.";
        outputDiv.appendChild(noMoves);
    } else {
        const movesHeader = document.createElement('h3');
        movesHeader.textContent = `Найдено ${availableMoves.length} доступных хода(ов) для фигуры L:`;
        outputDiv.appendChild(movesHeader);

        availableMoves.forEach((move, index) => {
            const moveDiv = document.createElement('div');
            moveDiv.innerHTML = `<h4>Ход ${index + 1}:</h4><pre class="board">${renderBoardHTML(move)}</pre>`;
            outputDiv.appendChild(moveDiv);
        });
    }
}

// Запуск программы
main();
