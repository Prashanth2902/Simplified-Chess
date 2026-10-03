#pragma once

#include "Board.h"
#include "Piece.h"

class Game {
public:
    Game();

    // Attempts to move the piece at `from` to `to`. Fails (returns false,
    // board unchanged) if there's no piece at `from`, it isn't the current
    // player's piece, or `to` isn't in that piece's valid moves. On success,
    // performs the move and advances the turn.
    bool tryMove(PiecePosition from, PiecePosition to);

    Color getCurrentTurn() const { return currentTurn; }
    const Board& getBoard() const { return board; }

private:
    Board board;
    Color currentTurn;

    void setupStandardPosition();
    void placeBackRank(Color color, int rank);
};
