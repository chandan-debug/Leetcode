class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
  vector<string> s;
  vector<int> v;
  if (n < target.back()) {
    return s;
  }

  int i = 0, c = 1;
  while (i < target.size()) {
 
    if ( c == target[i]) {
      s.push_back("Push");
      i++;
    } else {
        s.push_back("Push");
        s.push_back("Pop");
    }
    c++;
  }
  return s;
}
    
};