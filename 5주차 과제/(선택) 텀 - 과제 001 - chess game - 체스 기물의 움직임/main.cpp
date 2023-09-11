#include "chess.h"

bool make_move(ChessBoard board, int from_x, int from_y) {
    ChessPiece piece = board[from_y][from_x];

    std::vector<std::pair<int, int>> legal_moves;

    switch (piece.piece) {
        case EMPTY: break;

        case PAWN:
            legal_moves = find_pawn_moves(board, from_x, from_y, piece.color);
            break;

        case ROOK:
            legal_moves = find_rook_moves(board, from_x, from_y, piece.color);
            break;

        case KNIGHT:
            legal_moves = find_knight_moves(board, from_x, from_y, piece.color);
            break;

        case BISHOP:
            legal_moves = find_bishop_moves(board, from_x, from_y, piece.color);
            break;

        case QUEEN:
            legal_moves = find_queen_moves(board, from_x, from_y, piece.color);
            break;

        case KING:
            legal_moves = find_king_moves(board, from_x, from_y, piece.color);
    }
    return legal_moves.size();
}


int main(){
    ChessBoard board = {
            {{ROOK,   WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE},{KING,  WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK,   WHITE}},
            {{PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,  WHITE}, {PAWN,  WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}},
            {{EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY, BLANK}, {EMPTY, BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}},
            {{EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY, BLANK}, {EMPTY, BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}},
            {{EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY, BLANK}, {EMPTY, BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}},
            {{EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY, BLANK}, {EMPTY, BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}, {EMPTY,  BLANK}},
            {{PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,  BLACK}, {PAWN,  BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}},
            {{ROOK,   BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK}, {KING,  BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK,   BLACK}}
    };

    print_board(board);

    while (true) {
        int from_x, from_y;
        std::cout << "Select your piece (x y): ";
        std::cin >> from_y >> from_x;
        std::cin.ignore();
        if (from_x == -1 && from_y == -1) break;

        if (!make_move(board, from_x, from_y)) {
            std::cout << "Illegal move!\n";
            continue;
        }
        else{
            ChessPiece piece = board[from_y][from_x];

            std::vector<std::pair<int, int>> legal_moves;

            switch (piece.piece) {
                case EMPTY: break;

                case PAWN:
                    legal_moves = find_pawn_moves(board, from_x, from_y, piece.color);
                    break;

                case ROOK:
                    legal_moves = find_rook_moves(board, from_x, from_y, piece.color);
                    break;

                case KNIGHT:
                    legal_moves = find_knight_moves(board, from_x, from_y, piece.color);
                    break;

                case BISHOP:
                    legal_moves = find_bishop_moves(board, from_x, from_y, piece.color);
                    break;

                case QUEEN:
                    legal_moves = find_queen_moves(board, from_x, from_y, piece.color);
                    break;

                case KING:
                    legal_moves = find_king_moves(board, from_x, from_y, piece.color);
            }
            print_moves(legal_moves);//벡터를 어디서 만들징
            select_move(board, legal_moves, from_x, from_y);
        }
        print_board(board);
        if(check_end(board)) break;
    }

    return 0;
}