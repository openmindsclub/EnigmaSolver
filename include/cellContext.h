#ifndef CELLCONTEXT_H
#define CELLCONTEXT_H

#include <iostream>
#include "vector"

using namespace std;

typedef struct Context
{
    std::vector<int> left;
    int current;
    int index;
} Context;

class cellContext
{
    public:
        cellContext();
        virtual ~cellContext();
        Context cellCon[16];
        int currentCell = 0;
        int currentLine = 0;
        vector<int> LeftOf(int n);
        int currentOf(int n);
        int nextOf(int n);
        static vector<int> CopyV(vector<int> V);
        static vector<int> deleteV(vector<int> V,int index);
        static Context copyC(Context C,int index);
        Context nextContext();
        void goNextCell();
        void goPreviusCell();
        int getCellValue(int mini,int maxi);
        int testNextOf(int n);
    protected:
    private:
};

#endif // CELLCONTEXT_H
