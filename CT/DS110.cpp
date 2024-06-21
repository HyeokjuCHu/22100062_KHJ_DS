#include <iostream>
#include <queue>

using namespace std;

int findLastRemainingCard(int N) {
    queue<int> cards;
    
    for (int i = 1; i <= N; ++i) {
        cards.push(i);
    }
    
    while (cards.size() > 1) {
        cards.pop();
        int frontCard = cards.front();
        cards.pop();
        cards.push(frontCard);
    }
    
    return cards.front();
}

int main() {
    int N;
    cin >> N;
    
    int result = findLastRemainingCard(N);
    
    cout << result << endl;
    
    return 0;
}
