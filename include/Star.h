#ifndef STAR_H
#define STAR_H

#include <iostream>
#include "stdio.h"

class Star
{
    public:
        Star();
        virtual ~Star();
        int cells[16];
        char ltrs[16];
        char sentence[16];
        int* Lines[8][4];
        void showLines();
        void showUrself();
        void fillCells();
        int sumRow(int n);
        int cellsEmptyOfRow(int n);
        int rowOfCell(int n);
        bool equalSums();
        void showUrself(FILE* F);
        void showUrself(FILE* F,FILE* G);
        void createLetters();
    protected:
    private:
};

#endif // STAR_H
