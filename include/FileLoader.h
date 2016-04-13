#ifndef FILELOADER_H
#define FILELOADER_H

#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class elem
{
public:
    elem(vector<string> word,int don,int n);
    vector<string> words;
    int done;
    int j;
};
class FileLoader
{
    public:
        FileLoader();
        virtual ~FileLoader();
        int fstLet[26];
        int secLet[26][26];
        int Wsize;
        void loadFile(string file);
        void loadCombin();
        void initIndex();
        void getGoodSentences();
        vector<string> list;
        vector<string> combin;
        vector<elem*> myStack;
    protected:
    private:
};

#endif // FILELOADER_H
