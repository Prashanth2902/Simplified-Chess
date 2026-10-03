cmake_minimum_required(VERSION 3.10)
project(SimplifiedChess CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(SimplifiedChess
    src/main.cpp
    src/Board.cpp
    src/Piece.cpp
    src/Pieces/Pawn.cpp
    src/Pieces/Knight.cpp
    src/Pieces/Bishop.cpp
    src/Pieces/Rook.cpp
    src/Pieces/Queen.cpp
    src/Pieces/King.cpp
)
target_include_directories(SimplifiedChess PRIVATE include)