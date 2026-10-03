# Simplified Chess

A simplified chess engine written in C++, built as a learning project for object-oriented programming concepts (inheritance, polymorphism, abstract classes, ownership semantics).

## Design

- `Piece` — abstract base class; each piece type (`Pawn`, `Knight`, `Bishop`, `Rook`, `Queen`, `King`) overrides `getValidMoves()` with its own movement rules.
- `Board` — owns the 8x8 grid of pieces, exposes basic query/mutation methods (`getPieceAt`, `placePiece`, `movePiece`). Has no knowledge of chess rules.
- `Game` — owns a `Board`, tracks whose turn it is, sets up the standard starting position, and decides whether an attempted move is legal.

## Features implemented

- Full piece hierarchy with correct movement rules (including blocking and captures)
- Turn tracking and legal-move checking
- Standard starting position
- Console-based interactive play with a text board display

## Not implemented (by design, for simplicity)

- Check / checkmate detection — a king can be captured like any other piece, which doubles as a win condition
- Castling
- En passant
- Pawn promotion
- Pawn double-step opening move

## Requirements

- CMake 3.10+
- A C++17 compiler

## Building

```
cmake -B build
cmake --build build
```

## Running

```
./build/SimplifiedChess             # Linux/macOS
.\build\Debug\SimplifiedChess.exe   # Windows (Visual Studio generator)
.\build\SimplifiedChess.exe         # Windows (Ninja/MinGW Makefiles generator)
```

## How to play

Moves are entered as two squares separated by a space, e.g.:

```
e2 e4
```

White moves first. Enter `quit` or `exit` to end the game.
