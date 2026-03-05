#ifndef CARD_H
#define CARD_H

#include <string>

enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank {
    Two = 2, Three, Four, Five, Six, Seven, Eight,
    Nine, Ten, Jack, Queen, King, Ace
};

struct Card {
    Suit suit;
    Rank rank;
};

inline std::string cardToString(const Card& c) {
    static const char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    static const char* ranks[] = {
        "", "", "2","3","4","5","6","7","8","9","10","J","Q","K","A"
    };
    return std::string(ranks[(int)c.rank]) + " of " + suits[(int)c.suit];
}

#endif