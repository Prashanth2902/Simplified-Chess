#pragma once

#include "Piece.h"

#include <utility>
#include <vector>

class Queen : public Piece {
public:
    Queen(Color color, PiecePosition piecePosition)
        : Piece(color, PieceType::Queen, piecePosition) {}

    std::vector<PiecePosition> getValidMoves(const Board& board) const override;
};