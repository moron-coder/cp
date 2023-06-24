#include <bits/stdc++.h>
using namespace std;

class Position{
    int rowIdx,colIdx;
    public:
    Position(){
        rowIdx=-1,colIdx=-1;
    }

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
    Player(){
        this->id = -1;
    }

    Player(string &name){
        this->name = name;
        this->id = playerCount;
        playerCount++;
    }

    void move(Position startPos,Position endPos){

    }
};

int Player::playerCount=0;

enum PieceType{
    KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN,
    INVALID
};

unordered_map<PieceType,int> PieceTypeIndex = {
    {KING,0},
    {QUEEN,1},
    {BISHOP,2},
    {KNIGHT,3},
    {ROOK,4},
    {PAWN,5}
};

class Piece{
    PieceType pieceType;
    Player player;
    bool isActive;
    public:
    Piece(){
        this->pieceType = INVALID;
        this->isActive = false;
    }

    static unordered_map<int,vector<pair<int,int>>> pieceMovements;

    Piece(Player player, bool isActive, PieceType pieceType){
        this->player = player;
        this->isActive = isActive;
        this->pieceType = pieceType;
    }

    void setIsActive(bool isActive){
        this->isActive = isActive;
    }

    bool getIsActive(){
        return isActive;
    }

    PieceType getPieceType(){
        return pieceType;
    }

    vector<pair<int,int>> getPieceMoves(int pieceIndex){
        if(!pieceMovements.count(pieceIndex)) return {};
        return pieceMovements[pieceIndex];
    }
};

unordered_map<int,vector<pair<int,int>>> Piece::pieceMovements = {
    {0,{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}},
    {1,{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}},
    {2,{{1,1},{-1,1},{-1,-1},{1,-1}}},
    {3,{{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},}},
    {4,{{1,0},{0,1},{-1,0},{0,-1}}},
    {5,{{1,0}}}
};

class MoveHandler{
    Position startPos,endPos;
    Board board;
    public:

    MoveHandler(Board board, Position startPos,Position endPos){
        this->startPos=startPos;
        this->endPos=endPos;
        this->board = board;
    }

    pair<int,int> getSimplifiedPositions(Position startPos, Position endPos){
        int di = endPos.getRowIdx()-startPos.getRowIdx();
        int dj = endPos.getColIdx()-startPos.getColIdx();
        di=abs(di),dj=abs(dj);
        int gcdDiDj = __gcd(di,dj);
        di/=gcdDiDj,dj/=gcdDiDj;
        return {di,dj};        
    }

    bool checkValidMove(){
        Piece piece = board.getPiece(startPos);
        if(piece.getIsActive()){
            int pieceIndex = PieceTypeIndex[piece.getPieceType()];
            pair<int,int> simplifiedStartEnd = getSimplifiedPositions(startPos,endPos);
            int di = simplifiedStartEnd.first, dj = simplifiedStartEnd.second;
            vector<pair<int,int>> pieceMovements = piece.getPieceMoves(pieceIndex);
            for(auto diDj:pieceMovements){
                if(diDj.first==di && diDj.second==dj){
                    return true;
                }
            }
            return false;
        }
        return false;
    }
    
    void changeBoardConfig(){

    }
};

class Cell{
    Piece piece;
    public:

    Cell(){}                //  default : invalid pieces (or blank space)

    Piece getPiece(){
        return piece;
    }

    void setPiece(Piece piece){
        this->setPiece(piece);
    }
};

class Board{
    Cell **boardCell;
    public:
    Board(){
        boardCell = nullptr;
    }

    Board(int rowCount,int colCount){
        boardCell = new Cell*[rowCount];
        for(int i=0;i<rowCount;i++) boardCell[i] = new Cell[colCount]();
    }

    void setPiece(Position pos, Piece piece){
        boardCell[pos.getRowIdx()][pos.getColIdx()].setPiece(piece);
    }

    Piece getPiece(Position pos){
        boardCell[pos.getRowIdx()][pos.getColIdx()].getPiece();
    }

};

int main(){
    cout<<"hello\n";
    return 0;
}