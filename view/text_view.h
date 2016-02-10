#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "view.h"

/*
    An implementation of an ASCII-based display.
*/

class Text_View : public View {
    public:
        void print() const;
};

#endif
