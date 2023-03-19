class Solution {
public:
    int n;
    int maxu = 0;
    void recurPermute(int index, vector<vector<int>> & students, vector<vector<int>> & mentors) {
      if(index == students.size()) {
          int counto = 0;
          for(int j = 0 ; j < n ; j++){
              for(int kk = 0 ; kk < students[j].size() ; kk++){
                  if(students[j][kk] == mentors[j][kk]){
                      counto++;
                  }
              }
          }
          maxu = max(counto, maxu);
      }
      for (int i = index; i < students.size(); i++) {
        swap(students[index], students[i]);
        recurPermute(index + 1, students, mentors);
        swap(students[index], students[i]);
      }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = mentors.size(); // or students.size();
        recurPermute(0, students, mentors);
        return maxu;
    }
};