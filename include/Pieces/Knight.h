#pragma once

#include "Piece.h"

#include <utility>
#include <vector>

class Knight : public Piece {
public:
    Knight(Color color, PiecePosition piecePosition)
        : Piece(color, PieceType::Knight, piecePosition) {}

    std::vector<PiecePosition> getValidMoves(const Board& board) const override;
};