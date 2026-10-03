#include <iostream>

#include "Game.h"

namespace {
const char* colorName(Color color) {
    return color == Color::White ? "White" : "Black";
}
}

int main() {
    Game game;

    std::cout << "Turn: " << colorName(game.getCurrentTurn()) << std::endl;

    // Legal: white pawn e2 -> e3.
    bool moved = game.tryMove(PiecePosition{'e', 2}, PiecePosition{'e', 3});
    std::cout << "e2->e3: " << (moved ? "ok" : "rejected") << std::endl;
    std::cout << "Turn: " << colorName(game.getCurrentTurn()) << std::endl;

    // Illegal: moving out of turn (white piece again, but it's black's turn).
    moved = game.tryMove(PiecePosition{'e', 3}, PiecePosition{'e', 4});
    std::cout << "e3->e4 (wrong turn): " << (moved ? "ok" : "rejected") << std::endl;

    // Double-step is deferred for now, so two squares forward is correctly rejected.
    moved = game.tryMove(PiecePosition{'e', 7}, PiecePosition{'e', 5});
    std::cout << "e7->e5 (double-step, not yet supported): " << (moved ? "ok" : "rejected") << std::endl;

    // Legal: black pawn e7 -> e6 (single step).
    moved = game.tryMove(PiecePosition{'e', 7}, PiecePosition{'e', 6});
    std::cout << "e7->e6: " << (moved ? "ok" : "rejected") << std::endl;
    std::cout << "Turn: " << colorName(game.getCurrentTurn()) << std::endl;

    // Illegal: not a valid knight move.
    moved = game.tryMove(PiecePosition{'b', 1}, PiecePosition{'b', 3});
    std::cout << "b1->b3 (invalid knight move): " << (moved ? "ok" : "rejected") << std::endl;

    // Legal: knight b1 -> c3.
    moved = game.tryMove(PiecePosition{'b', 1}, PiecePosition{'c', 3});
    std::cout << "b1->c3: " << (moved ? "ok" : "rejected") << std::endl;

    return 0;
}
