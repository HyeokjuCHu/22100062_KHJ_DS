#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> scores_a(n);
    vector<int> scores_b(m);
    
    for(int i = 0; i < n; ++i) {
        cin >> scores_a[i];
    }
    
    for(int i = 0; i < m; ++i) {
        cin >> scores_b[i];
    }
    
    
    vector<int> all_scores;
    all_scores.reserve(n + m); 
    all_scores.insert(all_scores.end(), scores_a.begin(), scores_a.end());
    all_scores.insert(all_scores.end(), scores_b.begin(), scores_b.end());
    
    // 점수 내림차순으로 정렬
    sort(all_scores.begin(), all_scores.end(), greater<int>());
    
    
    for(int score : all_scores) {
        cout << score << " ";
    }
    
    return 0;
}
