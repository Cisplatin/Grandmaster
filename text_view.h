#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "view.h"

/*
    An implementation of an ASCII-based display.
*/

class Text_View : public View {
    private:
        // The character to print for empty squares
        const static char WHITE_SQUARE = '_';
        const static char BLACK_SQUARE = ' ';
    public:
        void print() const;
};

#endif
