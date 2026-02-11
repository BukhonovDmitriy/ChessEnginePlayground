#include <stddef.h>

enum class Piece : unsigned char {
    Empty,
    BPawn = 1, BKnight, BBishop, BRook, BQueen, BKing,
    WPawn = 1 << 4, WKnight, WBishop, WRook, WQueen, WKing,
    Black = 1, White = 1 << 4
};

unsigned char operator&(Piece lhs, Piece rhs) {
    return static_cast<unsigned char>(lhs) & static_cast<unsigned char>(rhs);
}

unsigned char operator|(Piece lhs, Piece rhs) {
    return static_cast<unsigned char>(lhs) | static_cast<unsigned char>(rhs);
}

class BoardRepr {
public:
    virtual Piece GetCell(size_t x, size_t y) const = 0;
    virtual void SetCell(size_t x, size_t y, Piece p) = 0;

    Piece GetCellStr(const char *cell) const {
        return GetCell('8' - cell[1], cell[0] - 'a');
    }
    void SetCellStr(const char *cell, Piece p) {
        SetCell('8' - cell[1], cell[0] - 'a', p);
    }

    void MakeMove(const char *move) {
        SetCellStr(move + 2, GetCellStr(move));
        SetCellStr(move, Piece::Empty);
    }

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