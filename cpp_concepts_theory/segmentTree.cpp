class segTree{
    public:
    int lfTreeIdx,rtTreeIdx,infoStored;
    segTree *lf,*rt;

    void modifyInfo(){
        infoStored = 0;
        if(this->lf!=nullptr) infoStored+=this->lf->infoStored;
        if(this->rt!=nullptr) infoStored+=this->rt->infoStored;
    }

    segTree(int lfIdx,int rtIdx){
        lfTreeIdx = lfIdx;
        rtTreeIdx = rtIdx;
        this->lf=nullptr;
        this->rt=nullptr;
        this->infoStored=0;
        if(lfIdx==rtIdx) return;
        int mid=lfIdx+(rtIdx-lfIdx)/2;
        if(mid>=lfIdx) this->lf = new segTree(lfIdx,mid);
        if(mid+1<=rtIdx) this->rt = new segTree(mid+1,rtIdx);
    }

    int getInfo(int lfArIdx,int rtArIdx){
        if(lfArIdx>rtTreeIdx || rtArIdx<lfTreeIdx) return 0;
        if(lfTreeIdx>=lfArIdx && rtTreeIdx<=rtArIdx) return infoStored;
        int ans=0;
        if(this->lf!=nullptr) ans+=this->lf->getInfo(lfArIdx,rtArIdx);
        if(this->rt!=nullptr) ans+=this->rt->getInfo(lfArIdx,rtArIdx);
        return ans;
    }

    void update(int arIdx,int val){
        if(arIdx>rtTreeIdx || arIdx<lfTreeIdx) return;
        if(lfTreeIdx==arIdx && rtTreeIdx==arIdx){
            this->infoStored = val;
            return;
        }
        int mid = lfTreeIdx+(rtTreeIdx-lfTreeIdx)/2;
        if(arIdx<=mid) this->lf->update(arIdx,val);
        else this->rt->update(arIdx,val);
        modifyInfo();
    }
};