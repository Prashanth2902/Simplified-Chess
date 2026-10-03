#pragma once

#include <utility>
#include <vector>

class Board;

struct PiecePosition {
    char x;
    int y;

    bool isValid() const {
        return (x - 'a' >= 0 && x - 'a' <= 7) && ( y - 1 >= 0 && y - 1 <= 7);
    }

    std::pair<int, int> toArrayIndices() const {
        return {x - 'a', y - 1};
    }

    bool operator==(const PiecePosition& other) const {
        return x == other.x && y == other.y;
    }
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

protected:
    // Shared sliding-move logic for Rook/Bishop/Queen: walks outward from the
    // current position along each (dx, dy) direction until the edge of the
    // board, an own-color piece, or a capturable opponent piece is reached.
    std::vector<PiecePosition> slidingMoves(
        const Board& board,
        const std::vector<std::pair<int, int>>& directions) const;
};