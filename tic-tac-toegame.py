def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def check_winner(board):
    
    for row in board:
        if row[0] == row[1] == row[2] and row[0] != " ":
            return row[0]
    for col in range(3):
        if board[0][col] == board[1][col] == board[2][col] and board[0][col] != " ":
            return board[0][col]
    if board[0][0] == board[1][1] == board[2][2] and board[0][0] != " ":
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] and board[0][2] != " ":
        return board[0][2]
    return None

def is_draw(board):
    for row in board:
        if " " in row:
            return False
    return True

def main():
    board = [[" " for _ in range(3)] for _ in range(3)]
    print("Welcome to Tic-Tac-Toe!")
    print_board(board)

    players = ["X", "O"]
    turn = 0

    while True:
        current_player = players[turn % 2]
        print(f"Player {turn % 2 + 1}'s turn ({current_player}):")

        try:
            row, col = map(int, input("Enter row and column (0-2, space-separated): ").split())
            if board[row][col] != " ":
                print("Cell already taken. Try again.")
                continue
        except (ValueError, IndexError):
            print("Invalid input. Please enter row and column as two numbers between 0 and 2.")
            continue

        
        board[row][col] = current_player
        print_board(board)

        
        winner = check_winner(board)
        if winner:
            print(f"Player {turn % 2 + 1} ({winner}) wins!")
            break
        if is_draw(board):
            print("It's a draw!")
            break

        turn += 1

if __name__ == "__main__":
    main()
