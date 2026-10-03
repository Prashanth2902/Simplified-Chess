#include "Pieces/Queen.h"

std::vector<PiecePosition> Queen::getValidMoves(const Board& board) const {
    static const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
    return slidingMoves(board, directions);
}
