#include "Board.h"

#include <stdexcept>

const Piece* Board::getPieceAt(PiecePosition pos) const {
    if (!pos.isValid()) {
        throw std::invalid_argument("getPieceAt: position out of bounds");
    }
    auto [col, row] = pos.toArrayIndices();
    return grid[col][row].get();
}

void Board::placePiece(PiecePosition pos, std::unique_ptr<Piece> piece) {
    if (!pos.isValid()) {
        throw std::invalid_argument("placePiece: position out of bounds");
    }
    auto [col, row] = pos.toArrayIndices();
    grid[col][row] = std::move(piece);
}

void Board::movePiece(PiecePosition from, PiecePosition to) {
    if (!from.isValid() || !to.isValid()) {
        throw std::invalid_argument("movePiece: position out of bounds");
    }
    auto [fromCol, fromRow] = from.toArrayIndices();
    auto [toCol, toRow] = to.toArrayIndices();
    grid[toCol][toRow] = std::move(grid[fromCol][fromRow]);
}
