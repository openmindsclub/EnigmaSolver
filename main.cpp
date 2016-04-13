#include <iostream>
#include "Star.h"
#include "StarBoss.h"
#include "FileLoader.h"
#include <string.h>

using namespace std;

int main()
{
    Star* str = new Star();
    StarBoss* strBoss = new StarBoss(str);

//    strBoss->fillStar();
    FileLoader* FL = new FileLoader();
    FL->loadCombin();
    FL->loadFile("wordsEn.txt");
    FL->getGoodSentences();
    int x;
        return 0;
}
