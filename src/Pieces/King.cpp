#include "Pieces/King.h"

#include "Board.h"

std::vector<PiecePosition> King::getValidMoves(const Board& board) const {
    std::vector<PiecePosition> moves;
    PiecePosition pos = getPiecePosition();

    // Castling is deferred for now.
    static const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    for (auto [dx, dy] : directions) {
        PiecePosition candidate{static_cast<char>(pos.x + dx), pos.y + dy};
        if (!candidate.isValid()) {
            continue;
        }

        const Piece* target = board.getPieceAt(candidate);
        if (target == nullptr || target->getColor() != getColor()) {
            moves.push_back(candidate);
        }
    }

    return moves;
}
