#include "cellContext.h"

cellContext::cellContext()
{

       for(int i=0;i<16;i++)
       {
           cellCon[0].left.push_back(i+1);
       }
       cellCon[0].index = -1;
       cellCon[0].current = 0;

}

vector<int> cellContext::LeftOf(int n)
{
    if(0<=n && n<16)
        return cellCon[n].left;
    else
        cout << "cellContext::leftOf out of bounds error\n";
}
int cellContext::currentOf(int n)
{
        if(0<=n && n<16)
        return cellCon[n].current;
    else
        cout << "cellContext::currentOf out of bounds error\n";
}

int cellContext::nextOf(int n)
{
    if(!cellCon[n].current)
    {
        cellCon[n].index = 0;
        cellCon[n].current = cellCon[n].left[0];
    }
    else
    {
        cellCon[n].current = cellCon[n].left[++cellCon[n].index];
    }
    return cellCon[n].current;
}

int cellContext::testNextOf(int n)
{
    if(!cellCon[n].current)
    {
return cellCon[n].left[0];
    }
    else
    {
        if(cellCon[n].index < cellCon[n].left.size())
        return cellCon[n].left[cellCon[n].index+1];
        else return 100000; // big value to get false at there is next option
    }
}

vector<int> cellContext::CopyV(vector<int> V)
{
    vector<int>* V2 = new vector<int>;
    int Size = V.size();
    for(int i=0;i<Size;i++)
        V2->push_back(V[i]);
    return *V2;
}
vector<int> cellContext::deleteV(vector<int> V,int index)
{
    vector<int>* V2 = new vector<int>;
    int Size = V.size();
    for(int i=0;i<Size;i++)
        if(i!=index)
        V2->push_back(V[i]);
    return *V2;
}
Context cellContext::copyC(Context C,int index)
{
    Context* C2 = new Context;
    C2->index = -1;
    C2->left = deleteV(C.left,index);
    C2->current = 0;
    return *C2;
}

Context cellContext::nextContext()
{
    return copyC(cellCon[currentCell],cellCon[currentCell].index);
}

void cellContext::goNextCell()
{
    if(currentCell < 15)
    cellCon[currentCell+1] = nextContext();
    if(currentCell == 3 && currentLine == 0)
        currentLine = 1;
    if(currentCell == 6 && currentLine == 1)
        currentLine = 2;
    if(currentCell == 8 && currentLine == 2)
        currentLine = 3;
    if(currentCell == 10 && currentLine == 3)
        currentLine = 4;
    if(currentCell == 12 && currentLine == 4)
        currentLine = 5;
    if(currentCell == 14 && currentLine == 5)
        currentLine = 6;
    if(currentCell == 15 && currentLine == 6)
        currentLine = 7;
    currentCell++;
}

void cellContext::goPreviusCell()
{
    currentCell--;
    if(currentCell == 3 && currentLine == 1)
        currentLine = 0;
    if(currentCell == 6 && currentLine == 2)
        currentLine = 1;
    if(currentCell == 8 && currentLine == 3)
        currentLine = 2;
    if(currentCell == 10 && currentLine == 4)
        currentLine = 3;
    if(currentCell == 12 && currentLine == 5)
        currentLine = 4;
    if(currentCell == 14 && currentLine == 6)
        currentLine = 5;
    if(currentCell == 15 && currentLine == 7)
        currentLine = 6;

}

int cellContext::getCellValue(int mini,int maxi) // suppose next value exists
{
    while(nextOf(currentCell) < mini);
    if(currentOf(currentCell) > maxi) cout << "error value overflow in cellContext::getCellValue!" << endl;
    return currentOf(currentCell);
}

cellContext::~cellContext()
{
    //dtor
}
