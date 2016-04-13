#include "StarBoss.h"

StarBoss::StarBoss(Star* st)
{
    str = st;
}

void StarBoss::fillStar()
{
    Con = new cellContext();
    int j=1;
    FILE* F = NULL;
    FILE* G = NULL;
    F = fopen("combinations.txt","w+");
    G = fopen("sentences.txt","w+");
    if(!F || !G)
    {
        cout << "error file" << endl;
    }
    else
    while(Con->currentCell != -1) // cell 0 still have options
    {

        if(thereIsNextOption())
        {
            str->cells[Con->currentCell] = getNextValue();
            if(Con->currentCell !=15)
            Con->goNextCell();
            else
            {
                cout << j << ": ";
                fprintf(F,"%d: ",j);
                str->showUrself(F,G);
                j++;
            str->cells[Con->currentCell] = 0; // reset value
            Con->goPreviusCell();
            str->cells[Con->currentCell] = 0; // reset value
            }
        }
        else
        {
            str->cells[Con->currentCell] = 0; // reset value
            Con->goPreviusCell();
            str->cells[Con->currentCell] = 0; // reset value
        }


    }
}

int StarBoss::minOfValue(int value)
{
    vector<int> left = Con->LeftOf(Con->currentCell);
    if(value <= left[0])
        return left[0];
    else if(value >left[left.size()-1])
    {
                return 0; // no options left
    }
    else
    {
            int i;
        for(i=0;left[i] < value;i++);
            return left[i];
    }

}

int StarBoss::minOfRow(int n)
{
    int ECells = str->cellsEmptyOfRow(n);
    int S = str->sumRow(n);
    int mini;
    vector<int> left = Con->LeftOf(Con->currentCell);
    int Size = left.size();
    switch(ECells)
    {
        case 4 : return left[0]; // return min that exists currently
        case 3 : mini = 34-S; for(int i=1;i<3;i++) mini -= left[Size-i]; // 34 - S - 3 biggest numbers
                 return minOfValue(mini);
        case 2 : mini = 34-S; mini -= left[Size-1]; // 34 - S - 2 biggest numbers
                 return minOfValue(mini);
        case 1 : mini = 34-S;  // 34 - S -  biggest number
                 return minOfValue(mini);
    }
    if(ECells)
    cout << "Error StarBoss::minOfRow! maybe problem on cellsEmptyOfRow()\n";
    return 0;
}

int StarBoss::maxOfValue(int value)
{
    vector<int> left = Con->LeftOf(Con->currentCell);
    if(value >= left[left.size()-1])
        return left[left.size()-1];
    else if(value < left[0])
        return 0; // no options left
    else
    {
        int i=left.size()-1;
        for(;left[i] > value;i--);
            return left[i];
    }
}

int StarBoss::maxOfRow(int n)
{
    int ECells = str->cellsEmptyOfRow(n);
    int S = str->sumRow(n);
    int maxi;
    vector<int> left = Con->LeftOf(Con->currentCell);
    int Size = left.size();
    switch(ECells)
    {
        case 4 : return left[Size-1]; // return min that exists currently
        case 3 : maxi = 34-S; for(int i=0;i<2;i++) maxi -= left[i]; // 34 - S - 3 biggest numbers
                 return maxOfValue(maxi);
        case 2 : maxi = 34-S; maxi -= left[0]; // 34 - S - 2 biggest numbers
                 return maxOfValue(maxi);
        case 1 : maxi = 34-S;  // 34 - S -  biggest number
                 return maxOfValue(maxi);
    }
    if(ECells)
    cout << "Error StarBoss::maxOfRow! maybe problem on cellsEmptyOfRow()\n";
    return 0;
}


bool StarBoss::thereIsNextOption()
{
    int maxV = maxOfRow(Con->currentLine),minV = minOfRow(Con->currentLine);
    if(!maxV || !minV)
        return false;
    else if(minV > maxV)
        return false;
    else if( Con->currentOf(Con->currentCell) >= maxV || Con->testNextOf(Con->currentCell) > maxV)
        return false;
    return true;
}

int StarBoss::getNextValue() // supposing there is nextValue
{
    int maxV = maxOfRow(Con->currentLine),minV = minOfRow(Con->currentLine);
    return Con->getCellValue(minV,maxV);
}


StarBoss::~StarBoss()
{
    //dtor
}
