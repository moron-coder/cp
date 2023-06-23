#include <bits/stdc++.h>
using namespace std;

class Position{
    int rowIdx,colIdx;
    public:

    Position(int i,int j){
        rowIdx=i;
        colIdx=j;
    }

    int getRowIdx(){
        return rowIdx;
    }
    int getColIdx(){
        return colIdx;
    }

    void setPos(int i,int j){
        rowIdx=i;
        colIdx=j;
    }
};

class Player{
    static int playerCount;
    int id;
    string name;

    public:

    Player(string &name){
        this->name = name;
        this->id = playerCount;
        playerCount++;
    }

    void move(Position startPos,Position endPos){

    }
};

int Player::playerCount=0;

enum PieceTypes{
    KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN
};

unordered_map<PieceTypes,int> PieceTypesIndex = {
    {KING,0},
    {QUEEN,1},
    {BISHOP,2},
    {KNIGHT,3},
    {ROOK,4},
    {PAWN,5}
};

class Piece{
    Player player;
    bool isActive;
    public:
    static unordered_map<int,vector<pair<int,int>>> pieceMovements;
};

unordered_map<int,vector<pair<int,int>>> Piece::pieceMovements = {
    {0,{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}},
    {1,{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}},
    {2,{{1,1},{-1,1},{-1,-1},{1,-1}}},
    {3,{{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},}},
    {4,{{1,0},{0,1},{-1,0},{0,-1}}},
    {5,{{1,0}}}
};

class Board{
    
    public:



};

int main(){
    cout<<"hello\n";
    return 0;
}