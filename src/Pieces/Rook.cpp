#include "Pieces/Rook.h"

std::vector<PiecePosition> Rook::getValidMoves(const Board& board) const {
    static const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    return slidingMoves(board, directions);
}
