#include <bits/stdc++.h>
using namespace std;

class cell{
    public:
    int pos;
    cell *nxt;

    cell(int num){
        pos=num;
        nxt=nullptr;
    }
};

class Snake{
    const int di[4] = {0,0,1,-1};       //  R L D U
    const int dj[4] = {1,-1,0,0};

    public:
    unordered_map<int,int> cellsOccuppied;
    cell *head,*tail;

    Snake(){
        head=new cell(0),tail=head;
        cellsOccuppied.clear();
        cellsOccuppied[0]++;
    }

    bool moveHead(int dir,int n,int m){
        int headPos = head->pos, headI=headPos/m, headJ = headPos%m;
        int newI=headI+di[dir],newJ=headJ+dj[dir];
        if(newI<0 || newJ<0 || newI>=n || newJ>=m){
            return false;
        }
        if(cellsOccuppied.count(newI*m+newJ) && tail->pos!=(newI*m+newJ)){
            return false;
        }

        cellsOccuppied[newI*m+newJ]++;
        cell *newHead = new cell(newI*m+newJ);
        head->nxt = newHead;
        head=newHead;
        return true;
    }

    void moveTail(){
        cell *newTail = tail->nxt;
        tail->nxt=nullptr;
        cellsOccuppied[tail->pos]--;
        if(cellsOccuppied[tail->pos]==0){
            cellsOccuppied.erase(tail->pos);
        }
        delete tail;
        tail = newTail;
    }

    bool eats(vector<int> &pos,int m){
        return (pos[0]*m+pos[1])==(head->pos);
    }
};

class SnakeGame {
    Snake *snk;
    int scr,foodPos,n,m;
    vector<vector<int>> foodAr;
    unordered_map<string,int> directionMap;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        foodPos=0;
        scr=0;
        foodAr=food;
        n=height,m=width;
        directionMap["R"]=0;
        directionMap["L"]=1;
        directionMap["D"]=2;
        directionMap["U"]=3;
        snk = new Snake();
    }
    
    int move(string direction) {
        int directionNum = directionMap[direction];
        if(!snk->moveHead(directionNum,n,m)){
            return -1;
        }
        if(foodPos<foodAr.size() && snk->eats(foodAr[foodPos],m)){
            foodPos++;
            scr++;
        }else{
            snk->moveTail();
        }
        return scr;
    }
};