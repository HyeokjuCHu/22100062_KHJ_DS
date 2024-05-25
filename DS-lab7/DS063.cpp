#include <iostream>
#include "linkedlist.h"

using namespace std;

int calculateBattleNumber(int currentCard, int prevWinnerBattleNumber, int prevLoserBattleNumber, bool isWinner) {
    if (isWinner) {
        return currentCard + (prevWinnerBattleNumber - prevLoserBattleNumber - 1);
    } else {
        return currentCard;
    }
}

int main() {
    int numCards;
    cin >> numCards;

    LinkList player1Deck;
    for (int i = 0; i < numCards; ++i) {
        int card;
        cin >> card;
        player1Deck.enqueue(card);
    }

    LinkList player2Deck;
    for (int i = 0; i < numCards; ++i) {
        int card;
        cin >> card;
        player2Deck.enqueue(card);
    }

    int player1Points = 0;
    int player2Points = 0;

    int player1BattleNumber = player1Deck.dequeue();
    int player2BattleNumber = player2Deck.dequeue();

    for (int i = 1; i <= numCards; ++i) {
        if (player1BattleNumber > player2BattleNumber) {
            player1Points++;
            cout << "Round " << i << " - P1 win!" << endl;
        } else if (player2BattleNumber > player1BattleNumber) {
            player2Points++;
            cout << "Round " << i << " - P2 win!" << endl;
        } else {
            cout << "Round " << i << " - Draw!" << endl;
        }

        if (i < numCards) {
            int player1Card = player1Deck.dequeue();
            int player2Card = player2Deck.dequeue();
            if (player1BattleNumber > player2BattleNumber) {
                player1BattleNumber = calculateBattleNumber(player1Card, player1BattleNumber, player2BattleNumber, true);
                player2BattleNumber = player2Card;
            } else if (player2BattleNumber > player1BattleNumber) {
                player2BattleNumber = calculateBattleNumber(player2Card, player2BattleNumber, player1BattleNumber, true);
                player1BattleNumber = player1Card;
            } else {
                player1BattleNumber = player1Card;
                player2BattleNumber = player2Card;
            }
        }
    }

    if (player1Points > player2Points) {
        cout << "Final - P1 win!" << endl;
    } else if (player2Points > player1Points) {
        cout << "Final - P2 win!" << endl;
    } else {
        cout << "Final - Draw!" << endl;
    }

    return 0;
}
