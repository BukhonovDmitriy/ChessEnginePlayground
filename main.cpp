#include <iostream>

enum class Piece : unsigned char {
    Empty,
    BPawn = 1, BKnight, BBishop, BRook, BQueen, BKing,
    WPawn = 1 << 4, WKnight, WBishop, WRook, WQueen, WKing,
    Black = 1, White = 1 << 4
};

unsigned char operator &(Piece lhs, Piece rhs) {
    using uc = unsigned char;
    return static_cast<uc>(lhs) & static_cast<uc>(rhs);
}

class IBoard {
public:
    virtual Piece GetCell(size_t x, size_t y) const = 0;
    virtual void SetCell(size_t x, size_t y, Piece p) = 0;

    void SetStartPosition() {
        using P = Piece;

        static const P board_defauld[8][8] = {
            {P::BRook,  P::BKnight, P::BBishop, P::BQueen, P::BKing,  P::BBishop, P::BKnight, P::BRook},
            {P::BPawn,  P::BPawn,   P::BPawn,   P::BPawn,  P::BPawn,  P::BPawn,   P::BPawn,   P::BPawn},
            {P::Empty,  P::Empty,   P::Empty,   P::Empty,  P::Empty,  P::Empty,   P::Empty,   P::Empty},
            {P::Empty,  P::Empty,   P::Empty,   P::Empty,  P::Empty,  P::Empty,   P::Empty,   P::Empty},
            {P::Empty,  P::Empty,   P::Empty,   P::Empty,  P::Empty,  P::Empty,   P::Empty,   P::Empty},
            {P::Empty,  P::Empty,   P::Empty,   P::Empty,  P::Empty,  P::Empty,   P::Empty,   P::Empty},
            {P::WPawn,  P::WPawn,   P::WPawn,   P::WPawn,  P::WPawn,  P::WPawn,   P::WPawn,   P::WPawn},
            {P::WRook,  P::WKnight, P::WBishop, P::WQueen, P::WKing,  P::WBishop, P::WKnight, P::WRook}
        };


        for (size_t x = 0; x < 8; ++x)
            for (size_t y = 0; y < 8; ++y)
                SetCell(x, y, board_defauld[x][y]);
    }
};


#include <array>

class ArrayBoard : public IBoard {
    Piece m_board[8][8]{};

public:
    Piece GetCell(size_t x, size_t y) const override {
        return m_board[x][y];
    }

    void SetCell(size_t x, size_t y, Piece p) override {
        m_board[x][y] = p;
    }
};



void PrintPosition(const IBoard &board, std::ostream &out = std::cout) {
    for (size_t x = 0; x < 8; ++x) {
        for (size_t y = 0; y < 8; ++y) {
            switch (board.GetCell(x, y)) {
            case Piece::Empty:   out << " "; break;
            case Piece::BPawn:   out << "♟"; break;
            case Piece::BKnight: out << "♞"; break;
            case Piece::BBishop: out << "♝"; break;
            case Piece::BRook:   out << "♜"; break;
            case Piece::BQueen:  out << "♛"; break;
            case Piece::BKing:   out << "♚"; break;
            case Piece::WPawn:   out << "♙"; break;
            case Piece::WKnight: out << "♘"; break;
            case Piece::WBishop: out << "♗"; break;
            case Piece::WRook:   out << "♖"; break;
            case Piece::WQueen:  out << "♕"; break;
            case Piece::WKing:   out << "♔"; break;
            }
        }
        out << std::endl;
    }
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
}