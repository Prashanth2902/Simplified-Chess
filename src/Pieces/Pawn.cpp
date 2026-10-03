#include "Pieces/Pawn.h"

#include "Board.h"

std::vector<PiecePosition> Pawn::getValidMoves(const Board& board) const {
    std::vector<PiecePosition> moves;

    PiecePosition pos = getPiecePosition();
    int direction = (getColor() == Color::White) ? 1 : -1;

    // Single square forward, only if unoccupied.
    PiecePosition forward{pos.x, pos.y + direction};
    if (forward.isValid() && board.getPieceAt(forward) == nullptr) {
        moves.push_back(forward);
    }

    // Diagonal captures.
    for (int dx : {-1, 1}) {
        PiecePosition diagonal{static_cast<char>(pos.x + dx), pos.y + direction};
        if (!diagonal.isValid()) {
            continue;
        }
        const Piece* target = board.getPieceAt(diagonal);
        if (target != nullptr && target->getColor() != getColor()) {
            moves.push_back(diagonal);
        }
    }

    return moves;
}
