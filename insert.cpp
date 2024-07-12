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
         newroot->terminate=true;
         return ;
      }
      int idx=str[0]-65;
      if(newroot->arr[idx]==NULL){
         newroot->arr[idx]=new node(str[0]);
      }
      
         insert_(str.substr(1),newroot->arr[idx]);
      
   }

   bool search_(string str,node* newroot){
        
        if(str.size()==0){
         return newroot->terminate;
        }

        int idx=str[0]-65;

        if(newroot->arr[idx]==NULL) return false;

        return search_(str.substr(1),newroot->arr[idx]);
   }
   public:
    void insert(string str){
      insert_(str,root);
    }

  bool search(string str){
      return search_(str,root);
  }  
       
 };

int main(){
     int n;

     cin>> n;
   trie word;
     while(n--){
        string str;
        cin >> str;
       word.insert(str);
       
     }

     int m;
     cin>>m;
     while(m--){
     string str;
     cin>>str;
     cout<<word.search(str)<<endl;

     }
      
}