#include "chess.h"

using namespace std;

string pieceName[7] = {" ","P", "R", "N", "B", "Q", "K"};
string pieceColor[3] = {" ", "w", "b"};

void print_board(ChessBoard const board){
    cout << "  0  1  2  3  4  5  6  7" << endl;
    for(int i=0; i<BOARD_SIZE; i++){
        cout << i;
        for(int j=0; j<BOARD_SIZE; j++){
            cout << " " << pieceName[board[i][j].piece] << pieceColor[board[i][j].color];
        }
        cout << endl;
    }
}
void trans(vector<pair<int,int>>& a){
    for(auto i=a.begin(); i<a.end(); i++){
        int temp = i->first;
        i->first = i->second;
        i->second = temp;
    }
}

std::vector<std::pair<int, int>> find_pawn_moves(ChessBoard board, int x, int y, Color color){
    vector<pair<int, int>> legal_moves;

    int y_move;
    if(color == WHITE) {y_move = 1;}
    else {y_move = -1;}

    if(0 <= y+y_move && y+y_move <= 7){

        legal_moves.push_back({x, y+y_move});

        if((y==1 && color == WHITE) || (y==6 && color == BLACK)) legal_moves.push_back({x, y+2*y_move});

        //앞으로 전진하는데 기물이 있으면 그 move 제거
        legal_moves.erase(remove_if(legal_moves.begin(), legal_moves.end(),
                                    [board](auto move){return board[move.second][move.first].piece != EMPTY;}),legal_moves.end());

        if(0<x && x<7){
            if(board[y+y_move][x+1].piece != EMPTY && board[y+y_move][x+1].color != color)
                legal_moves.push_back({x+1, y+y_move});
            if(board[y+y_move][x-1].piece != EMPTY && board[y+y_move][x-1].color != color)
                legal_moves.push_back({x-1, y+y_move});
        }
        else if(x==0) {
            if(board[y+y_move][x+1].piece != EMPTY && board[y+y_move][x+1].color != color)
                legal_moves.push_back({x+1, y+y_move});
        }
        else if(x==7) {
            if(board[y+y_move][x-1].piece != EMPTY && board[y+y_move][x-1].color != color)
                legal_moves.push_back({x-1, y+y_move});
        }
    }

    return legal_moves;
}

void add_go_end(ChessBoard board, vector<pair<int,int>>& legal_moves, int x, int y, bool Xon, bool Yon, int x_move, int y_move, Color color){
    int i=1;
    while(board[y+y_move*i*Yon][x+x_move*i*Xon].piece == EMPTY && 0<= x+x_move*i*Xon && x+x_move*i*Xon <= 7
          && 0 <= y+y_move*i*Yon && y+y_move*i*Yon <= 7){
        legal_moves.push_back({x+x_move*i*Xon,y+y_move*i*Yon});
        i++;
    }

    if(board[y+y_move*i*Yon][x+x_move*i*Xon].color != color && 0<= x+x_move*i*Xon && x+x_move*i*Xon <= 7
                                                               && 0 <= y+y_move*i*Yon && y+y_move*i*Yon <= 7)
        legal_moves.push_back({x+x_move*i*Xon, y+y_move*i*Yon});
}

std::vector<std::pair<int, int>> find_rook_moves(ChessBoard board,int x, int y, Color color){
    vector<pair<int, int>> legal_moves;

    add_go_end(board, legal_moves, x, y, true, false, 1, 1, color);
    add_go_end(board, legal_moves, x, y, true, false, -1, 1, color);
    add_go_end(board, legal_moves, x, y, false, true, 1, 1, color);
    add_go_end(board, legal_moves, x, y, false, true, 1, -1, color);

    return legal_moves;
}

std::vector<std::pair<int, int>> find_knight_moves(ChessBoard board, int x, int y, Color color){
    vector<pair<int, int>> legal_moves;
    legal_moves.push_back({x-2, y+1});
    legal_moves.push_back({x-2, y-1});
    legal_moves.push_back({x-1, y+2});
    legal_moves.push_back({x-1, y-2});

    legal_moves.push_back({x+2, y+1});
    legal_moves.push_back({x+2, y-1});
    legal_moves.push_back({x+1, y+2});
    legal_moves.push_back({x+1, y-2});

    legal_moves.erase(remove_if(legal_moves.begin(), legal_moves.end(), [](pair<int, int> move){return (0>move.first)||(move.first>7)||(0>move.second)||(move.second>7);}), legal_moves.end());
    legal_moves.erase(remove_if(legal_moves.begin(), legal_moves.end(), [board, color](pair<int, int> move){return board[move.second][move.first].color == color;}), legal_moves.end());

    return legal_moves;
}

std::vector<std::pair<int, int>> find_bishop_moves(ChessBoard board, int x, int y, Color color){
    vector<pair<int, int>> legal_moves;

    add_go_end(board, legal_moves, x, y, true, true, 1, 1, color);
    add_go_end(board, legal_moves, x, y, true, true, -1, 1, color);
    add_go_end(board, legal_moves, x, y, true, true, -1, -1, color);
    add_go_end(board, legal_moves, x, y, true, true, 1, -1, color);

    return legal_moves;
}

std::vector<std::pair<int, int>> find_queen_moves(ChessBoard board,int x, int y, Color color){
    vector<pair<int, int>> legal_moves;

    add_go_end(board, legal_moves, x, y, true, false, 1, 1, color);
    add_go_end(board, legal_moves, x, y, true, false, -1, 1, color);
    add_go_end(board, legal_moves, x, y, false, true, 1, 1, color);
    add_go_end(board, legal_moves, x, y, false, true, 1, -1, color);
    add_go_end(board, legal_moves, x, y, true, true, 1, 1, color);
    add_go_end(board, legal_moves, x, y, true, true, -1, 1, color);
    add_go_end(board, legal_moves, x, y, true, true, -1, -1, color);
    add_go_end(board, legal_moves, x, y, true, true, 1, -1, color);

    return legal_moves;
}

std::vector<std::pair<int, int>> find_king_moves(ChessBoard board,int x, int y, Color color){
    vector<pair<int, int>> legal_moves;
    legal_moves.push_back({x+1, y});
    legal_moves.push_back({x-1, y});
    legal_moves.push_back({x, y+1});
    legal_moves.push_back({x, y-1});
    legal_moves.push_back({x+1, y+1});
    legal_moves.push_back({x-1, y+1});
    legal_moves.push_back({x+1, y-1});
    legal_moves.push_back({x-1, y-1});

    legal_moves.erase(remove_if(legal_moves.begin(), legal_moves.end(), [](pair<int, int> move){return (0>move.first)||(move.first>7)||(0>move.second)||(move.second>7);}), legal_moves.end());
    legal_moves.erase(remove_if(legal_moves.begin(), legal_moves.end(), [board, color](pair<int, int> move){return board[move.second][move.first].color == color;}), legal_moves.end());
    return legal_moves;
}

bool comp(pair<int, int> a, pair<int, int> b){
    bool result = true;
    if(a.first > b.first) {result = false;}
    else if((a.first == b.first) && (a.second > b.second)) {result = false;}

    return result;
}

void print_moves(std::vector<std::pair<int, int>>& moves){
    trans(moves);
    sort(moves.begin(), moves.end(), comp);
    cout << "Legal moves: ";
    for(auto& move : moves){
        cout << " (" << move.first << ", " << move.second << ")";
    }
    trans(moves);
    cout << endl;
}

void select_move(ChessBoard& board, std::vector<std::pair<int, int>>& moves, int x, int y){
    int select;
    int goX, goY;
    ChessPiece empty = {EMPTY, BLANK};
    cout << "Select a move (0-" << moves.size()-1 << "): ";
    cin >> select;
    goX = moves[select].first;
    goY = moves[select].second;
    board[goY][goX] = board[y][x];
    board[y][x] = empty;
}

bool check_end(ChessBoard& board){
    bool check=false;
    int king_count=0;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(board[i][j].piece == KING) king_count++;
    if(king_count < 2) check=true;

    return check;
}