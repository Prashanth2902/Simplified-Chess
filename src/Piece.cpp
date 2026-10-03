#include "Piece.h"

#include "Board.h"

std::vector<PiecePosition> Piece::slidingMoves(
    const Board& board,
    const std::vector<std::pair<int, int>>& directions) const {
    std::vector<PiecePosition> moves;
    PiecePosition pos = getPiecePosition();

    for (auto [dx, dy] : directions) {
        PiecePosition candidate{pos.x, pos.y};
        while (true) {
            candidate = PiecePosition{static_cast<char>(candidate.x + dx), candidate.y + dy};
            if (!candidate.isValid()) {
                break;
            }

            const Piece* target = board.getPieceAt(candidate);
            if (target == nullptr) {
                moves.push_back(candidate);
                continue;
            }

            if (target->getColor() != getColor()) {
                moves.push_back(candidate);
            }
            break;
        }
    }

    return moves;
}
