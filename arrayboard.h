#include <array>
#include <stddef.h>

#include "boardrepr.h"

class ArrayBoard : public BoardRepr {
    struct Board8x8 {
        Piece data[8][8]{};
        Piece *operator[] (size_t x) {
            return data[x];
        }
        const Piece *operator[] (size_t x) const {
            return data[x];
        }
    };

    Board8x8 m_board;
    

public:
    Piece GetCell(size_t x, size_t y) const override {
        return m_board[x][y];
    }

    void SetCell(size_t x, size_t y, Piece p) override {
        m_board[x][y] = p;
    }
};