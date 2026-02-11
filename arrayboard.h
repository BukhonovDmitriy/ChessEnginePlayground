#include <array>
#include "boardrepr.h"

class ArrayBoard : public BoardRepr {
    Piece m_board[8][8]{};

public:
    Piece GetCell(size_t x, size_t y) const override {
        return m_board[x][y];
    }

    void SetCell(size_t x, size_t y, Piece p) override {
        m_board[x][y] = p;
    }
};