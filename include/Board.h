#pragma once

#include "Piece.h"

#include <array>
#include <memory>

class Board {
private:
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> grid;

public:
    const Piece* getPieceAt(PiecePosition pos) const;
    void placePiece(PiecePosition pos, std::unique_ptr<Piece> piece);
    void movePiece(PiecePosition from, PiecePosition to);
};