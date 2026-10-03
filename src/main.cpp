#include <cctype>
#include <iostream>
#include <optional>
#include <string>

#include "Game.h"

namespace {

const char* colorName(Color color) {
    return color == Color::White ? "White" : "Black";
}

char pieceLetter(PieceType type) {
    switch (type) {
        case PieceType::Pawn:   return 'p';
        case PieceType::Knight: return 'n';
        case PieceType::Bishop: return 'b';
        case PieceType::Rook:   return 'r';
        case PieceType::Queen:  return 'q';
        case PieceType::King:   return 'k';
    }
    return '?';
}

char pieceChar(const Piece& piece) {
    char letter = pieceLetter(piece.getPieceType());
    return piece.getColor() == Color::White
        ? static_cast<char>(std::toupper(letter))
        : letter;
}

void printBoard(const Board& board) {
    for (int rank = 8; rank >= 1; --rank) {
        std::cout << rank << " ";
        for (char file = 'a'; file <= 'h'; ++file) {
            const Piece* piece = board.getPieceAt(PiecePosition{file, rank});
            std::cout << (piece != nullptr ? pieceChar(*piece) : '.') << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "  a b c d e f g h" << std::endl;
}

// Parses a square like "e2" into a PiecePosition, rejecting anything
// malformed or out of range so callers never pass an invalid position
// into Board/Game (which assume validity has already been checked).
std::optional<PiecePosition> parseSquare(const std::string& text) {
    if (text.size() != 2 || !std::isdigit(static_cast<unsigned char>(text[1]))) {
        return std::nullopt;
    }

    PiecePosition pos{text[0], text[1] - '0'};
    if (!pos.isValid()) {
        return std::nullopt;
    }
    return pos;
}

}  // namespace

int main() {
    Game game;

    std::cout << "Simplified Chess" << std::endl;
    std::cout << "Enter moves as two squares, e.g. 'e2 e4'. Type 'quit' to exit." << std::endl;
    std::cout << "(Castling, en passant, promotion, and check detection are not implemented.)"
              << std::endl << std::endl;

    while (true) {
        printBoard(game.getBoard());
        std::cout << colorName(game.getCurrentTurn()) << " to move: ";

        std::string fromText;
        if (!(std::cin >> fromText)) {
            break;
        }
        if (fromText == "quit" || fromText == "exit") {
            break;
        }

        std::string toText;
        if (!(std::cin >> toText)) {
            break;
        }

        std::optional<PiecePosition> from = parseSquare(fromText);
        std::optional<PiecePosition> to = parseSquare(toText);
        if (!from.has_value() || !to.has_value()) {
            std::cout << "Invalid square. Use a file a-h and rank 1-8, e.g. e2." << std::endl << std::endl;
            continue;
        }

        if (!game.tryMove(*from, *to)) {
            std::cout << "Illegal move." << std::endl << std::endl;
            continue;
        }

        std::cout << std::endl;
    }

    std::cout << "Goodbye." << std::endl;
    return 0;
}
