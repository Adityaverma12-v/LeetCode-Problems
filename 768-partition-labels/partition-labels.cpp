class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastIndex[26];
         for ( int i=0; i< s.length(); ++i){
             lastIndex[s[i]- 'a']= i;
         }
          vector<int> result;
           int start=0, farthest=0;
            for ( int i=0; i< s.length(); ++i){
                farthest = max(farthest, lastIndex[s[i] - 'a']);

            if (i == farthest) {
                result.push_back(farthest - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};