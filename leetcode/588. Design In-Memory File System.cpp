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

class FileTrie{
    string fName;
    vector<string> files;
    unordered_map<string,int> filePos;      //  index of file in files array
    vector<FileTrie*> subDirs;
    unordered_map<string,int> subDirPos;    //  index of sub directory in subDirs array
    public:

    FileTrie(string s){
        this->fName=s;
        while (files.size()) files.pop_back();
        filePos.clear();
        while (subDirs.size()) subDirs.pop_back();
        subDirPos.clear();
    }
    // ls
    vector<string> getContentFromDirSorted(vector<string> &v){
        int i=1,n=v.size();
        FileTrie *ptr=this;
        vector<string> ans;
        for(;i<n;i++){
            if(i==n-1 && ptr->filePos.count(v.back())){
                return {v.back()};
            }
            int nextDirPos = ptr->subDirPos[v[i]];
            ptr=(ptr->subDirs[nextDirPos]);
        }
        for(auto it:ptr->filePos) ans.push_back(it.first);
        for(auto it:ptr->subDirPos) ans.push_back(it.first);
        sort(ans.begin(),ans.end());
        return ans;
    }
    // mkdir
    FileTrie* insertPath(vector<string> &v){
        FileTrie* ptr=this;
        for(int i=1;i<v.size();i++){
            if(ptr->subDirPos.count(v[i])){
                int pos = ptr->subDirPos[v[i]];
                ptr=ptr->subDirs[pos];
            }else{
                ptr->subDirPos[v[i]]=ptr->subDirs.size();
                ptr->subDirs.push_back(new FileTrie(v[i]));
                ptr=ptr->subDirs.back();
            }
        }
        return ptr;
    }
    // addContentToFile
    void addContentToFile(vector<string> &path,string &content){
        string fileName = path.back();
        path.pop_back();
        FileTrie* ptr = this->insertPath(path);
        if(ptr->filePos.count(fileName)){
            int pos = ptr->filePos[fileName];
            ptr->files[pos]+=content;
        }else{
            ptr->filePos[fileName]=ptr->files.size();
            ptr->files.push_back(content);
        }
    }
    //  readContentFromFile
    string getContentFromFile(vector<string> &v){
        FileTrie *ptr=this;
        for(int i=1,n=v.size();i<n-1;i++){
            int nextDirPos = ptr->subDirPos[v[i]];
            ptr=(ptr->subDirs[nextDirPos]);
        }
        int pos = ptr->filePos[v.back()];
        return ptr->files[pos];
    }
};

class FileSystem {
    FileTrie *ft;
public:
    FileSystem() {
        ft=new FileTrie("root");
    }

    vector<string> getPathInVec(string &path){
        vector<string> pathInVec;
        string cur;
        for(auto it:path){
            if(it=='/'){
                pathInVec.push_back(cur);
                while (cur.size()) cur.pop_back();
            }else{
                cur.push_back(it);
            }
        }
        if(cur.size()) pathInVec.push_back(cur);
        return pathInVec;
    }
    
    vector<string> ls(string path) {
        vector<string> pathInVec=getPathInVec(path);
        return ft->getContentFromDirSorted(pathInVec);
    }
    
    void mkdir(string path) {
        vector<string> pathInVec=getPathInVec(path);
        ft->insertPath(pathInVec);
    }
    
    void addContentToFile(string path, string content) {
        vector<string> pathInVec=getPathInVec(path);
        ft->addContentToFile(pathInVec,content);
    }
    
    string readContentFromFile(string filePath) {
        vector<string> pathInVec=getPathInVec(filePath);
        return ft->getContentFromFile(pathInVec);
    }
};