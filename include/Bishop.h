#pragma once

#include "Piece.h"

#include <utility>
#include <vector>

class Bishop : public Piece {
public:
    Bishop(Color color, PiecePosition piecePosition)
        : Piece(color, PieceType::Bishop, piecePosition) {}

    std::vector<PiecePosition> getValidMoves(const Board& board) const override;
};