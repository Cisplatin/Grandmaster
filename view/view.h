#ifndef VIEW_H
#define VIEW_H

#include "../constants.h"

/*
    An abstract class for a view: can be used to generate both text-displays
    and graphic displays.
*/
class View {
    protected:
        char **board; // A two-dimensional array of characters used to store
                      // where pieces are in the current display. If there is
                      // no piece, put a 0 instead.
    public:
        View();
        virtual ~View();
        virtual void print() const = 0;

        // Adds/removes the appropriate piece
        void add(const char, const int, const int); 
        void remove(const int, const int);
};

#endif
