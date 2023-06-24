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

    int getId(){
        return id;
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
    BLANK
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
        this->pieceType = BLANK;
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

    Player getPlayer(){
        return player;
    }

    vector<pair<int,int>> getPieceMoves(int pieceIndex){
        if(!pieceMovements.count(pieceIndex)) return {};
        return pieceMovements[pieceIndex];
    }
};

// unordered_map<int,vector<pair<int,int>>> Piece::pieceMovements = {
//     {0,{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}},
//     {1,{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}},
//     {2,{{1,1},{-1,1},{-1,-1},{1,-1}}},
//     {3,{{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},}},
//     {4,{{1,0},{0,1},{-1,0},{0,-1}}},
//     {5,{{1,0}}}
// };

class MoveHandler{
    Position startPos,endPos;
    Board board;
    public:

    MoveHandler(Board board, Position startPos,Position endPos){
        this->startPos=startPos;
        this->endPos=endPos;
        this->board = board;
    }

    bool boundaryCheck(Position position, Board board){
        pair<int,int> dimensions = board.getDimensions();
        int n = dimensions.first, m = dimensions.second;
        return (position.getRowIdx()>=0 && position.getRowIdx()<n &&
                position.getColIdx()>=0 && position.getColIdx()<m);
    }

    bool checkValidMove(){
        Piece startPiece = board.getPiece(startPos), endPiece = board.getPiece(endPos);
        if(!boundaryCheck(endPos,board)){
            return false;
        }
        int di = abs(endPos.getRowIdx()-startPos.getRowIdx());
        int dj = abs(endPos.getColIdx()-startPos.getColIdx());
        if(max(di,dj)==0) return false;
        if(startPiece.getIsActive() && 
            (!endPiece.getIsActive() || endPiece.getPlayer().getId()!=startPiece.getPlayer().getId())){
            if(startPiece.getPieceType()==KING){
                return (max(di,dj)<=1);
            }else if(startPiece.getPieceType()==QUEEN){
                return (di==dj || min(di,dj)==0);
            }else if(startPiece.getPieceType()==BISHOP){
                return (di==dj);
            }else if(startPiece.getPieceType()==KNIGHT){
                return ((di==1 && dj==2) || (di==2 && dj==1));
            }else if(startPiece.getPieceType()==ROOK){
                return min(di,dj)==0;
            }
        }
        if(startPiece.getIsActive() && startPiece.getPieceType()==PAWN){
            int n=board.getDimensions().first;
            if(dj==0 && di==1){
                return (endPos.getRowIdx()>startPos.getRowIdx() && startPiece.getPlayer().getId()==0 ||
                        endPos.getRowIdx()<startPos.getRowIdx() && startPiece.getPlayer().getId()==1);
            }else if(dj==0 && di==2){
                return ((startPos.getRowIdx()==1 && startPiece.getPlayer().getId()==0) || 
                        (startPos.getRowIdx()==n-2 && startPiece.getPlayer().getId()==1));
            }else if(di==1 && dj==1){
                bool player0 = (endPos.getRowIdx()>startPos.getRowIdx() && startPiece.getPlayer().getId()==0 && 
                        endPiece.getIsActive() && endPiece.getPlayer().getId()!=startPiece.getPlayer().getId());
                bool player1 = (endPos.getRowIdx()<startPos.getRowIdx() && startPiece.getPlayer().getId()==1 && 
                        endPiece.getIsActive() && endPiece.getPlayer().getId()!=startPiece.getPlayer().getId());
                return (player0 || player1);
            }
        }
        return false;
    }
    
    void changeBoardConfig(){

    }
};

class Cell{
    Piece piece;
    public:

    Cell(){
        this->piece = Piece();      //  default : BLANK pieces (or blank space)
    }

    Piece getPiece(){
        return piece;
    }

    void setPiece(Piece piece){
        this->setPiece(piece);
    }
};

class Board{
    int n,m;
    Cell **boardCell;
    MoveHandler *moveHandler;
    public:
    Board(){
        n=0,m=0;
        moveHandler = nullptr;
        boardCell = nullptr;
    }

    pair<int,int> getDimensions(){
        return {n,m};
    }

    Board(int rowCount,int colCount){
        n=rowCount;
        m=colCount;
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