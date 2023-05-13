#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mii map<int, int>
#define mll map<ll, ll>
#define pii pair<int, int>
#define pic pair<int, char>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define vvi vector<vector<int>>
#define ull unsigned long long int
#define mod 1000000007
#define ll long long int

class Player{
    string name;
    int id;
    public:

    Player(string name,int id){
        this->name=name;
        this->id=id;
    }

    int getPlayerId(){
        return id;
    }

    string getPlayerName(){
        return name;
    }
};

class Cell{
    int playerId;
    int *allDirCounts;
    public:

    Cell(){
        playerId=-1;
        allDirCounts = new int[8](); 
    }

    bool markCell(int playerId){
        if(this->playerId!=-1){
            cout<<"cell is already marked\n";
            return false;
        }
        this->playerId=playerId;
        return true;
    }

    int getDirCount(int dir){
        if(dir>=8){
            cout<<"Getting invalid direction "<<dir<<endl;
            return -1;
        }
        return allDirCounts[dir];
    }

    bool setDirCount(int dir,int newCt){
        if(dir>=8){
            cout<<"Setting invalid direction "<<dir<<endl;
            return false;
        }
        allDirCounts[dir]=newCt;
        return true;
    }

    int getPlayerId(){
        return playerId;
    }
};

class Board{
    vector<Player> players;
    int playerCt,winner,rowCt,colCt,winningCount,currentPlayer;
    int di[8]={-1,-1,-1,0,1,1,1,0};
    int dj[8]={1,0,-1,-1,-1,0,1,1};
    Cell **cells;
    public:

    bool validCell(int i,int j){
        return (i>=0 && i<rowCt && j>=0 && j<colCt);
    }
    
    Board(int playerCt,int n,int m,int winningCount){
        if(winningCount>min(n,m)){
            cout<<"Invalid winningCount for board\n";
            return;
        }
        this->winningCount = winningCount;
        rowCt=n;
        colCt=m;
        cells=new Cell*[n];
        for(int i=0;i<n;i++) cells[i]=new Cell[m]();
        this->playerCt=playerCt;
        winner=-1;
        currentPlayer=0;
        while (players.size()) players.pop_back();
        
        for(int i=0;i<playerCt;i++){
            string playerName;
            cout<<"player name: ";
            cin>>playerName;
            Player player(playerName,i);
            players.push_back(player);
        }
    }
    
    void updateCounts(int i,int j){
        for(int dir=0;dir<8;dir++){
            int newI=i+di[dir],newJ=j+dj[dir],prevCt=0;
            if(newI>=0 && newI<rowCt && newJ>=0 && newJ<colCt && cells[newI][newJ].getPlayerId()==currentPlayer){
                prevCt = cells[newI][newJ].getDirCount(dir);
            }
            cells[i][j].setDirCount(dir,prevCt+1);
        }
    }

    bool isWinningCountReached(int i,int j){
        for(int dir=0;dir<8;dir++){
            if(cells[i][j].getDirCount(dir)>=winningCount){
                return true;
            }
        }
        return false;
    }

    void markMove(int i,int j,int playerId){
        if(playerId!=currentPlayer){
            cout<<"Invalid player trying to mark\n";
            return;
        }
        if(!validCell(i,j)){
            cout<<"Invalid cell ("<<i<<", "<<j<<")\n";
            return;
        }
        cells[i][j].markCell(playerId);
        updateCounts(i,j);
        if(isWinningCountReached(i,j)){
            winner = currentPlayer;
        }
    }

    int getWinner(){
        if(winner==-1){
            return -1;
        }
        return winner;
    }

    Player getPlayerById(int playerId){
        if(playerId<0 || playerId>=playerCt){
            cout<<"Invalid playerId\n";
            return Player("invalid_player",-1);
        }
        return players[playerId];
    }

    Player getCurrentPlayer(){
        return players[currentPlayer];
    }

    bool isValidMove(int i,int j){
        return (validCell(i,j) && cells[i][j].getPlayerId()==-1);
    }

    void changeCurrentPlayer(){
        int newPlayerId = (currentPlayer+1)%playerCt;
        currentPlayer = newPlayerId;
    }

    void dispBoard(){
        cout<<"Board status:\n";
        for(int i=0;i<rowCt;i++){
            for(int j=0;j<colCt;j++){
                cout<<cells[i][j].getPlayerId()<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Board board(2,3,3,3);
    while (board.getWinner()==-1){
        cout<<board.getCurrentPlayer().getPlayerName()<<"\'s move\n";
        int i,j;
        cin>>i>>j;
        while (!board.isValidMove(i,j)){
            cout<<"Invalid move, please try again\n";
            cin>>i>>j;
        }
        board.markMove(i,j,board.getCurrentPlayer().getPlayerId());
        board.changeCurrentPlayer();
    }
    cout<<board.getPlayerById(board.getWinner()).getPlayerName()<<" is the winner!!\n";
    return 0;
}