struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ans=nullptr,*tmp=head,*lastAdded=nullptr;
        bool adding=false;
        while (tmp){
            if(tmp->val){
                if(adding){
                    lastAdded->val+=tmp->val;
                }else{
                    //  make new node
                    ListNode *newNode = new ListNode(tmp->val);
                    if(lastAdded) lastAdded->next=newNode;
                    if(!ans){
                        ans=newNode;
                    }
                    lastAdded=newNode;
                    adding=true;
                }
            }else{
                adding=false;
            }
            tmp=tmp->next;
        }
        return ans;
    }
};