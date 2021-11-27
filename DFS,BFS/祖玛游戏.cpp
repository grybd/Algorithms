#include <bits/stdc++.h>
using namespace std;

struct State{
   string board;
   string hand;
   int step;
   State(const string&board,const string&hand,int step){
     this->board = board;
     this->hand = hand;
     this->step = step;
   }
};
class Solution {
public:
    string clean(const string&s){
      string res;
      vector<pair<char, int>>st;
      for(auto c:s){
        while(!st.empty()&&c!=st.back().first&&st.back().second>=3){
          st.pop_back();
        }
        if(st.empty()||c!=st.back().first){
          st.push_back({c,1});
        }else{
          st.back().second++;
        }
      }
      if(!st.empty()&&st.back().second>=3){
        st.pop_back();
      }
      for(int i=0;i<(int)st.size();++i){
        for(int j=0;j<st[i].second;++j){
          res.push_back(st[i].first);
        }
      }
      return res;
    }
    int findMinStep(string board, string hand) {
        unordered_set<string>visited;
        sort(hand.begin(),hand.end());
        visited.insert(board+" "+hand);
        queue<State>que;
        que.push(State(board,hand,0));
        while(!que.empty()){
          State curr = que.front();
          que.pop();
          for(int j=0;j<(int)curr.hand.size();++j){
             if(j>0&&curr.hand[j]==curr.hand[j-1]){
               continue;
             }
             for(int i=0;i<(int)curr.board.size();++i){
               if(i>0&&curr.board[i-1]==curr.hand[j]){
                 continue;
               }
               bool choose = false;
               if(i<(int)curr.board.size()&&curr.board[i]==curr.hand[j]){
                 choose = true;
               }
               if(i>0&&i<(int)curr.board.size()&&curr.board[i-1]==curr.board[i]&&curr.board[i]!=curr.hand[j]){
                 choose = true;
               }
               if(choose){
                 string new_board = clean(curr.board.substr(0,i))+curr.hand[j]+curr.board.substr(i);
                 string new_hand = curr.hand.substr(0,j)+curr.hand.substr(j+1);
                 if(new_board.size()==0){
                   return curr.step+1;
                 }
                 if(!visited.count(new_board+" "+new_hand)){
                   que.push(State(new_board,new_hand,curr.step+1));
                   visited.insert(new_board+" "+new_hand);
                 }
               }
             }
          }
        }
        return -1;
    }
};
