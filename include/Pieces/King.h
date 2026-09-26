#pragma once

#include "Piece.h"

#include <utility>
#include <vector>

class King : public Piece {
public:
    King(Color color, PiecePosition piecePosition)
        : Piece(color, PieceType::King, piecePosition) {}

    std::vector<PiecePosition> getValidMoves(const Board& board) const override;
};