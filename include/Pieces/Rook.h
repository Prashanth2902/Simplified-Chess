#pragma once

#include "Piece.h"

#include <utility>
#include <vector>

class Rook : public Piece {
public:
    Rook(Color color, PiecePosition piecePosition)
        : Piece(color, PieceType::Rook, piecePosition) {}

    std::vector<PiecePosition> getValidMoves(const Board& board) const override;
};