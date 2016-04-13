#include "FileLoader.h"
#include <string.h>

using namespace std;

FileLoader::FileLoader()
{
    //ctor
}

void printo(vector<string> lis)
{
    for(int i=0;i<lis.size();i++)
        cout << lis[i] << " ";
        cout << endl;
}

void FileLoader::initIndex()
{
    for(int i=0;i<26;i++)
        fstLet[i] = -1;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
          secLet[i][j] = -1;
}

//bool FileLoader::thereIsChance(int j,string chaine)
//{
//    return (j < Wsize)
//}

void FileLoader::getGoodSentences()
{
    int Size = combin.size();
    string chaine;
    string word;
    char c1,c2;
    int j=0;
    int done = 0;
    vector<string> myWords;
    FILE* F = fopen("goodSentences.txt","w+");
    for(int i=0;i<Size;i++)
    {
        chaine = combin[i];
        myWords.clear();
        c1 = chaine[0];
        c2 = chaine[1];
        if(fstLet[c1-'a'] != -1)
        {
            j = fstLet[c1-'a'];
            done = 0;
            while(done < 16)
            {
            word = list[j];
            while(j<Wsize && strncmp(chaine.c_str()+done,word.c_str(),word.size()) > 0)
            {
                j++;
                word = list[j];
            }
            if(strncmp(chaine.c_str()+done,word.c_str(),word.size()) == 0)
            {
                int J=j;
                int result=0;
                do
                {

                if(!result)
                {

                int DONE = word.size() + done;
                if(DONE < 16)
                {
                c1 = chaine[DONE];
//                c2 = chaine[DONE+1];
                j = fstLet[c1-'a'];
                }
                if(j!=-1)
                {
                myStack.push_back(new elem(myWords,done,j));
                myStack[myStack.size()-1]->done += word.size();
                myStack[myStack.size()-1]->words.push_back(word);
                }
                }
                J++;
                word = list[J];
                result = strncmp(chaine.c_str()+done,word.c_str(),word.size());
                }while(result >= 0);
            }
            bool brck=false;
            do
            {
                int stck = myStack.size();
                if(!stck)
                {
                    brck = true;
                    break;
                }
                else
                {
                    done = myStack[stck-1]->done;
                    myWords = myStack[stck-1]->words;
                    j = myStack[stck-1]->j;
                    myStack.pop_back();
                }
            if(done == 16)
            {
                printo(myWords);
                    for(int i=0;i<myWords.size();i++)
        fprintf(F,"%s ",myWords[i].c_str());
        fprintf(F,"\n");
            }

            }while(done == 16);
            if(brck)
                break;
//            if(j==-1)
//                break;
            }
        }

    }
}

void FileLoader::loadCombin()
{
    std::ifstream input( "sentences.txt" );
    for( std::string line; getline( input, line ); )
{
    combin.push_back(line);
}
}

void FileLoader::loadFile(string file)
{
std::ifstream input( file.c_str() );

char c = 'a';
char c2 = 'a';
int i=0;
int i2 = 0;
int k;
initIndex();

for( std::string line; getline( input, line ); )
{
    if(line[0] == c)
    {
        fstLet[i] = list.size();
        i++;
        c++;
        c2 = 'a';
        i2=0;

    }
    if(line.size() > 1 && line[1] == c2)
    {
        secLet[i-1][i2] = list.size();
        i2++;
        c2++;
    }
    else if(line.size() > 1 && line[1] > c2)
    {

        i2 = line[1] - 'a';
        secLet[i-1][i2] = list.size();
        i2++;
        c2 = line[1];
        c2++;

    }
    list.push_back(line);

}
Wsize = list.size();

}


FileLoader::~FileLoader()
{
    //dtor
}

elem::elem(vector<string> word,int don,int n)
{
    int Size = word.size();
    for(int i=0;i<Size;i++)
        words.push_back(word[i]);
    done = don;
    j=n;
}
