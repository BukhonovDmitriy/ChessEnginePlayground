#include <iostream>
#include <exception>

#include "arrayboard.h"

const char* PieceUnicode(Piece piece) {
    switch (piece) {
    case Piece::Empty:   return "-";
    case Piece::BPawn:   return "♟";
    case Piece::BKnight: return "♞";
    case Piece::BBishop: return "♝";
    case Piece::BRook:   return "♜";
    case Piece::BQueen:  return "♛";
    case Piece::BKing:   return "♚";
    case Piece::WPawn:   return "♙";
    case Piece::WKnight: return "♘";
    case Piece::WBishop: return "♗";
    case Piece::WRook:   return "♖";
    case Piece::WQueen:  return "♕";
    case Piece::WKing:   return "♔";
    }

    throw std::runtime_error("Something very important is not implemented!");
}

void PrintPosition(const BoardRepr &board, std::ostream &out = std::cout) {
    for (size_t x = 0; x < 8; ++x) {
        for (size_t y = 0; y < 8; ++y) {
            out << PieceUnicode(board.GetCell(x, y)) << " ";
        }
        out << std::endl;
    };
}


int main() {
    std::cout << "let's begin!" << std::endl;
    
    if (Piece::BBishop & Piece::Black)
        std::cout << "BBishop is black" << std::endl;
    
    if (Piece::BBishop & Piece::White)
        std::cout << "BBishop is white" << std::endl;

    ArrayBoard board;
    board.SetStartPosition();
    PrintPosition(board);

    std::cout << "Piece at \"a1\": " << PieceUnicode(board.GetCellStr("a1")) << std::endl;

    board.MakeMove("e2e4");
    PrintPosition(board);
}