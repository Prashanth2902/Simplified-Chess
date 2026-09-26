#pragma once

#include <utility>
#include <vector>

class Board;

struct PiecePosition {
    char x;
    int y;
};

enum class Color {
    White, Black
};

enum class PieceType {
    Pawn, Knight, Bishop, Rook, Queen, King
};

class Piece {
private:
    Color color;
    PieceType pieceType;
    PiecePosition piecePosition;

public:

    Piece(Color color, PieceType pieceType, PiecePosition piecePosition) 
        : color(color), pieceType(pieceType), piecePosition(piecePosition) {}

    Color getColor() const {return color;}
    PieceType getPieceType() const {return pieceType;}
    PiecePosition getPiecePosition() const {return piecePosition;}

    virtual std::vector<PiecePosition> getValidMoves(const Board& board) const = 0;

    virtual ~Piece() {}
};