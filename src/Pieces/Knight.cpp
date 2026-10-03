#include "Pieces/Knight.h"

#include "Board.h"

std::vector<PiecePosition> Knight::getValidMoves(const Board& board) const {
    std::vector<PiecePosition> moves;
    PiecePosition pos = getPiecePosition();

    static const std::vector<std::pair<int, int>> offsets = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2},
        {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
    };

    for (auto [dx, dy] : offsets) {
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
