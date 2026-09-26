#pragma once

#include "Piece.h"

#include <utility>
#include <vector>

class Pawn : public Piece {
public:
    Pawn(Color color, PiecePosition piecePosition)
        : Piece(color, PieceType::Pawn, piecePosition) {}

    std::vector<PiecePosition> getValidMoves(const Board& board) const override;
};