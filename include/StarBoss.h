#ifndef STARBOSS_H
#define STARBOSS_H

#include "Star.h"
#include "cellContext.h"

class StarBoss
{
    public:
        StarBoss(Star* st);
        virtual ~StarBoss();
        void fillStar();
        Star* str;
        cellContext* Con;
        bool thereIsNextOption();
        int minOfRow(int n);
        int minOfValue(int value);
        int maxOfRow(int n);
        int maxOfValue(int value);
        int getNextValue();
    protected:
    private:
};

#endif // STARBOSS_H
