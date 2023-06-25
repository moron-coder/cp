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
        this->id = 0;
    }

    Player(string &name){
        this->name = name;
        this->id = playerCount;
        playerCount++;
    }

    int getId(){
        return id;
    }

    string getName(){
        return name;
    }

    bool move(Board board, Position startPos,Position endPos){
        MoveHandler moveHandler(board, startPos, endPos);
        return moveHandler.changeBoardConfig(startPos,endPos,board);
    }
};

int Player::playerCount=1;

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
    {BLANK,0},
    {KING,1},
    {QUEEN,2},
    {BISHOP,3},
    {KNIGHT,4},
    {ROOK,5},
    {PAWN,6}
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
    
    bool changeBoardConfig(Position startPos, Position endPos, Board board){
        if(checkValidMove()){
            Piece startPiece = board.getPiece(startPos);
            Piece endPiece = board.getPiece(endPos);
            if(endPiece.getIsActive()){
                endPiece.setIsActive(false);
            }
            board.setPiece(startPos,Piece());
            board.setPiece(endPos,startPiece);
            return true;
        }
        return false;
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
    int n,m,currentActivePlayerIndex;
    vector<Player> players;
    Cell **boardCell;
    public:

    void displayBoard(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Piece piece = boardCell[i][j].getPiece();
                int pieceIdx = PieceTypeIndex[piece.getPieceType()];
                string s = to_string(pieceIdx)+"_"+to_string(piece.getPlayer().getId());
                cout<<s<<" ";
            }
            cout<<endl;
        }
    }

    Board(){
        n=0,m=0;
        boardCell = nullptr;
    }

    pair<int,int> getDimensions(){
        return {n,m};
    }

    Board(int rowCount,int colCount, Player player1, Player player2){
        currentActivePlayerIndex=0;
        n=rowCount;
        m=colCount;
        boardCell = new Cell*[rowCount];
        for(int i=0;i<rowCount;i++){
            boardCell[i] = new Cell[colCount]();
            for(int j=0;j<8;j++){
                if(i==1){
                    boardCell[i][j].setPiece(Piece(player1,true,PAWN));
                }else if(i==0){
                    if(j==0 || j==m-1) boardCell[i][j].setPiece(Piece(player1,true,ROOK));
                    else if(j==1 || j==m-2) boardCell[i][j].setPiece(Piece(player1,true,KNIGHT));
                    else if(j==2 || j==m-3) boardCell[i][j].setPiece(Piece(player1,true,BISHOP));
                    else if(j==3) boardCell[i][j].setPiece(Piece(player1,true,QUEEN));
                    else if(j==4) boardCell[i][j].setPiece(Piece(player1,true,KING));
                }else if(i==n-2){
                    boardCell[i][j].setPiece(Piece(player2,true,PAWN));
                }else if(i==n-1){
                    if(j==0 || j==m-1) boardCell[i][j].setPiece(Piece(player2,true,ROOK));
                    else if(j==1 || j==m-2) boardCell[i][j].setPiece(Piece(player2,true,KNIGHT));
                    else if(j==2 || j==m-3) boardCell[i][j].setPiece(Piece(player2,true,BISHOP));
                    else if(j==3) boardCell[i][j].setPiece(Piece(player2,true,KING));
                    else if(j==4) boardCell[i][j].setPiece(Piece(player2,true,QUEEN));
                }
            }
        }
    }

    Player getCurrentActivePlayer(){
        return players[currentActivePlayerIndex];
    }

    void changeCurrentActivePlayer(){
        int totalPlayers = players.size();
        currentActivePlayerIndex=(currentActivePlayerIndex+1)%totalPlayers;
    }

    void setPiece(Position pos, Piece piece){
        boardCell[pos.getRowIdx()][pos.getColIdx()].setPiece(piece);
    }

    Piece getPiece(Position pos){
        boardCell[pos.getRowIdx()][pos.getColIdx()].getPiece();
    }

};

int main(){
    cout<<"Chess Game Begins\n";
    cout<<"Enter player1 name\n";
    string player1Name;
    cin>>player1Name;
    cout<<"Enter player2 name\n";
    string player2Name;
    cin>>player2Name;
    cout<<"Enter dimensions of the board\n";
    int n,m;
    cin>>n>>m;
    Board board(n,m,player1Name,player2Name);
    while (1){
        Player currentPlayer = board.getCurrentActivePlayer();
        cout<<currentPlayer.getName()<<" turn\n";
        int startRow,startCol,endRow,endCol;
        cout<<"Enter starting cell\n";
        cin>>startRow>>startCol;
        cout<<"Enter ending cell\n";
        cin>>endRow>>endCol;
        while (!currentPlayer.move(board,Position(startRow,startCol),Position(endRow,endCol))){
            cout<<"That's an invalid move, please try again!!\n";
            cout<<"Enter starting cell\n";
            cin>>startRow>>startCol;
            cout<<"Enter ending cell\n";
            cin>>endRow>>endCol;
        }
        board.displayBoard();
    }
    return 0;
}