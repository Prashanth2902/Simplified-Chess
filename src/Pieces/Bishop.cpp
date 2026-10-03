#include "Pieces/Bishop.h"

std::vector<PiecePosition> Bishop::getValidMoves(const Board& board) const {
    static const std::vector<std::pair<int, int>> directions = {
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
    return slidingMoves(board, directions);
}
