#include<iostream>

using namespace std;

class node{
   
   public:
     char ch;
     node* arr[26];
    bool terminate;

     node(char data){
        ch=data;
        for(int i=0;i<26;i++){
            arr[i]=NULL;
            
        }
        terminate=false;

     }
};

 class trie{

    node* root;


    public:
    trie(){
      root=new node('\0');
    }
   private:
   void insert_(string str,node* newroot){
      
      if(str.size()==0){
         root->terminate=true;
         return ;
      }
      int idx=str[0]-65;
      if(root->arr[idx]==NULL){
         root->arr[idx]=new node(str[0]);
      }
      
         insert_(str.substr(1),root->arr[idx]);
      
   }
   public:
    void insert(string str){
      insert_(str,root);
    }
       
 };

int main(){
     int n;

     cin>>n;
   trie word;
     while(n--){
        string str;
        cin>>str;
       word.insert(str);
       
     }
      
}