#include <iostream>
#include <memory>

#include "Board.h"
#include "Piece.h"
#include "Pieces/Bishop.h"
#include "Pieces/King.h"
#include "Pieces/Knight.h"
#include "Pieces/Pawn.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"

namespace {
void printMoves(const char* label, const std::vector<PiecePosition>& moves) {
    std::cout << label << " (" << moves.size() << " moves): ";
    for (const PiecePosition& pos : moves) {
        std::cout << pos.x << pos.y << " ";
    }
    std::cout << std::endl;
}
}

int main() {
    Board board;

    // Empty-board sanity checks: known move counts from d4.
    PiecePosition d4{'d', 4};
    board.placePiece(d4, std::make_unique<Rook>(Color::White, d4));
    printMoves("Rook on empty board from d4", board.getPieceAt(d4)->getValidMoves(board));

    board.placePiece(d4, std::make_unique<Bishop>(Color::White, d4));
    printMoves("Bishop on empty board from d4", board.getPieceAt(d4)->getValidMoves(board));

    board.placePiece(d4, std::make_unique<Queen>(Color::White, d4));
    printMoves("Queen on empty board from d4", board.getPieceAt(d4)->getValidMoves(board));

    board.placePiece(d4, std::make_unique<Knight>(Color::White, d4));
    printMoves("Knight on empty board from d4", board.getPieceAt(d4)->getValidMoves(board));

    board.placePiece(d4, std::make_unique<King>(Color::White, d4));
    printMoves("King on empty board from d4", board.getPieceAt(d4)->getValidMoves(board));

    // Pawn: forward move only, nothing to capture yet.
    PiecePosition e2{'e', 2};
    board.placePiece(e2, std::make_unique<Pawn>(Color::White, e2));
    printMoves("Pawn on empty board from e2", board.getPieceAt(e2)->getValidMoves(board));

    // Blocking + capture check: white rook on d4, white pawn on d6 (blocks),
    // black pawn on d7 (beyond the block, should not be reachable).
    board.placePiece(d4, std::make_unique<Rook>(Color::White, d4));
    board.placePiece(PiecePosition{'d', 6}, std::make_unique<Pawn>(Color::White, PiecePosition{'d', 6}));
    printMoves("Rook on d4 blocked by own pawn on d6", board.getPieceAt(d4)->getValidMoves(board));

    board.placePiece(PiecePosition{'d', 6}, std::make_unique<Pawn>(Color::Black, PiecePosition{'d', 6}));
    printMoves("Rook on d4 with capturable black pawn on d6", board.getPieceAt(d4)->getValidMoves(board));

    return 0;
}
