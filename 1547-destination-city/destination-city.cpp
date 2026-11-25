class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      map<string , int> outdegree;
      for ( auto it : paths){
         string u= it[0];
         string v= it[1];
       outdegree[u]++;
      }
       for ( auto it : paths ){
        string a = it[1];
         if ( outdegree[a] ==0){
           return a;
            
         }
       }
        return " ";

    }
};