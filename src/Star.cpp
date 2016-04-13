#include "Star.h"

using namespace std;

Star::Star()
{
    for(int i=0;i<4;i++)
        Lines[0][i] = &cells[i]; // first Line cells
    for(int i=0;i<4;i++)
        Lines[1][i] = &cells[3+i]; // second Line cells
    {
        Lines[2][0] = &cells[6];
        Lines[2][1] = &cells[7];
        Lines[2][2] = &cells[1];
        Lines[2][3] = &cells[8];
    } // line 3


    {
        Lines[3][0] = &cells[8];
        Lines[3][1] = &cells[9];
        Lines[3][2] = &cells[4];
        Lines[3][3] = &cells[10];
    } // line 4


    {
        Lines[4][0] = &cells[10];
        Lines[4][1] = &cells[11];
        Lines[4][2] = &cells[7];
        Lines[4][3] = &cells[12];
    } // line 5

    {
        Lines[5][0] = &cells[12];
        Lines[5][1] = &cells[13];
        Lines[5][2] = &cells[9];
        Lines[5][3] = &cells[14];
    } // line 6

    {
        Lines[6][0] = &cells[14];
        Lines[6][1] = &cells[2];
        Lines[6][2] = &cells[11];
        Lines[6][3] = &cells[15];
    } // line 7

    {
        Lines[7][0] = &cells[15];
        Lines[7][1] = &cells[5];
        Lines[7][2] = &cells[13];
        Lines[7][3] = &cells[0];
    } // line 8

    for(int i=0;i<16;i++)
        cells[i] = 0; //init Cells 0

    ltrs[0] = 'u';
    ltrs[1] = 'd';
    ltrs[2] = 'd';
    ltrs[3] = 'o';
    ltrs[4] = 'y';
    ltrs[5] = 'g';
    ltrs[6] = 't';
    ltrs[7] = 'a';
    ltrs[8] = 'd';
    ltrs[9] = 'a';
    ltrs[10] = 'i';
    ltrs[11] = 'o';
    ltrs[12] = 'o';
    ltrs[13] = 'n';
    ltrs[14] = 'l';
    ltrs[15] = 'r';
}

bool Star::equalSums()
{
    int S=0;
    for(int i=0;i<8;i++)
    {
        S=0;
        for(int j=0;j<4;j++)
            S+= *Lines[i][j];
        if(S != 34)
            return false;
    }
    return true;
}

void Star::showLines()
{
    for(int i=0;i<8;i++)
    {
        cout << "Line " << i << ": ";
        for(int j=0;j<4;j++)
            cout << *Lines[i][j] << " ";
        cout << endl;
    }

}
void Star::fillCells()
{
    for(int i=0;i<16;i++)
        cells[i] = i;
}

int Star::sumRow(int n)
{
    int S=0;
    for(int i=0;i<4;i++)
        S+= *Lines[n][i];
    return S;
}

int Star::cellsEmptyOfRow(int n)
{
    int S=0;
    for(int i=0;i<4;i++)
        if(*Lines[n][i] == 0)
        S++;
    return S;
}


void Star::showUrself()
{
    for(int i=0;i<16;i++)
        cout << cells[i] << " ";
    cout << endl;
}

void Star::showUrself(FILE* F)
{
    for(int i=0;i<16;i++)
    {
        cout << cells[i] << " ";
        fprintf(F,"%d ",cells[i]);
    }
    fprintf(F,"\n");
    cout << endl;
}

void Star::showUrself(FILE* F,FILE* G)
{
    createLetters();
    for(int i=0;i<16;i++)
    {
        cout << cells[i] << " ";
        fprintf(F,"%d ",cells[i]);
        fprintf(G,"%c",sentence[i]);
    }
    fprintf(F,"\n");
    fprintf(G,"\n");
    cout << endl;
}

void Star::createLetters()
{
    for(int i=0;i<16;i++)
        sentence[cells[i]-1] = ltrs[i];
}

Star::~Star()
{
    //dtor
}
