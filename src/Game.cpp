#include "Game.h"

#include <algorithm>
#include <memory>

#include "Pieces/Bishop.h"
#include "Pieces/King.h"
#include "Pieces/Knight.h"
#include "Pieces/Pawn.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"

Game::Game() : currentTurn(Color::White) {
    setupStandardPosition();
}

void Game::setupStandardPosition() {
    for (char file = 'a'; file <= 'h'; ++file) {
        PiecePosition whitePawnPos{file, 2};
        board.placePiece(whitePawnPos, std::make_unique<Pawn>(Color::White, whitePawnPos));

        PiecePosition blackPawnPos{file, 7};
        board.placePiece(blackPawnPos, std::make_unique<Pawn>(Color::Black, blackPawnPos));
    }

    placeBackRank(Color::White, 1);
    placeBackRank(Color::Black, 8);
}

void Game::placeBackRank(Color color, int rank) {
    board.placePiece({'a', rank}, std::make_unique<Rook>(color, PiecePosition{'a', rank}));
    board.placePiece({'b', rank}, std::make_unique<Knight>(color, PiecePosition{'b', rank}));
    board.placePiece({'c', rank}, std::make_unique<Bishop>(color, PiecePosition{'c', rank}));
    board.placePiece({'d', rank}, std::make_unique<Queen>(color, PiecePosition{'d', rank}));
    board.placePiece({'e', rank}, std::make_unique<King>(color, PiecePosition{'e', rank}));
    board.placePiece({'f', rank}, std::make_unique<Bishop>(color, PiecePosition{'f', rank}));
    board.placePiece({'g', rank}, std::make_unique<Knight>(color, PiecePosition{'g', rank}));
    board.placePiece({'h', rank}, std::make_unique<Rook>(color, PiecePosition{'h', rank}));
}

bool Game::tryMove(PiecePosition from, PiecePosition to) {
    const Piece* piece = board.getPieceAt(from);
    if (piece == nullptr || piece->getColor() != currentTurn) {
        return false;
    }

    std::vector<PiecePosition> validMoves = piece->getValidMoves(board);
    bool isLegal = std::find(validMoves.begin(), validMoves.end(), to) != validMoves.end();
    if (!isLegal) {
        return false;
    }

    board.movePiece(from, to);
    currentTurn = (currentTurn == Color::White) ? Color::Black : Color::White;
    return true;
}
