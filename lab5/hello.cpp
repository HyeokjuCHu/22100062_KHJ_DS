#include <iostream>

using namespace std;

int main() {
    int x[3], y[3];
    int checkx, checky;

    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }

    // 차례로 XOR 연산을 수행하여 다른 값들을 찾음
    checkx = x[0] ^ x[1] ^ x[2];
    checky = y[0] ^ y[1] ^ y[2];

    cout << checkx << " " << checky << endl;

    return 0;
}
