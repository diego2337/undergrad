#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <cmath>
#include <map>
#include <queue>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
 
map<string,int> ErdosNumbers;
map<string,bool> Visited;
void ComputeErdosNumbers(string FullName, map<string,vector<string> > CoAuthors, bool start)
{
    vector<string> oldList, newList;
 
            for (int i=0; i<CoAuthors["Erdos, P."].size(); i++)
            ErdosNumbers[CoAuthors["Erdos, P."][i]] = 1;
            newList = CoAuthors["Erdos, P."];
 
            while(!newList.empty())
            {
                for (int i=0; i<newList.size(); i++)
                    for (int j=0; j< CoAuthors[newList[i]].size(); j++)
                        if (ErdosNumbers[CoAuthors[newList[i]][j]]  >  ErdosNumbers[newList[i]] + 1
                            || ErdosNumbers[CoAuthors[newList[i]][j]] == -1)
                        {
                            ErdosNumbers[CoAuthors[newList[i]][j]] = ErdosNumbers[newList[i]] + 1;
                            oldList.push_back(CoAuthors[newList[i]][j]);
                        }
 
                newList = oldList;
                oldList.clear();
            }
 
}
 
vector < string > extract_name(string &line)
{
    vector < string > list;
    string::size_type begin(0);
    string::size_type end = line.find(".,", begin);
 
    while (end != string::npos)
    {
        list.push_back(line.substr(begin, end - begin + 1));
 
        begin = end + 3;
        end = line.find(".,", begin);
    }
 
    if (begin < (line.length() - 1))
        list.push_back(line.substr(begin));
 
    return list;
}
int main()
{
    int N;
    scanf("%d\n",&N);
 
    for (int i=0; i<N; i++)
    {
 
        ErdosNumbers.clear();
        int nAuthors, nPapers;
        scanf("%d %d\n", &nPapers, &nAuthors);
        map<string,vector<string> > CoAuthors;
 
        char PaperString[500000];
 
        for (int j=0; j<nPapers; j++)
        {
            string Names;
 
            gets(PaperString);
            vector<string> PaperAuthors;
            stringstream s(PaperString);
 
            getline(s,Names,':');
            PaperAuthors = extract_name(Names);
 
            for (int k = 0; k<PaperAuthors.size(); k++) ErdosNumbers[PaperAuthors[k]] = -1;
 
            for (int k=0; k<PaperAuthors.size(); k++)
                for (int h=0; h <PaperAuthors.size(); h++)
                    if (PaperAuthors[h] != PaperAuthors[k])
                        {
                            if (find(CoAuthors[PaperAuthors[k]].begin(), CoAuthors[PaperAuthors[k]].end(),PaperAuthors[h]) == CoAuthors[PaperAuthors[k]].end())
                            CoAuthors[PaperAuthors[k]].push_back(PaperAuthors[h]);
                        }
 
        }
 
        ErdosNumbers["Erdos, P."] = 0;
 
        char AName[500000];
        vector<string> ANames;
        for (int j=0; j<nAuthors; j++)
        {
            gets(AName);
            ANames.push_back(AName);
        }
 
        ComputeErdosNumbers("",CoAuthors,true);
        cout << "Scenario " << i+1 << endl;
                for (int j=0; j<nAuthors; j++)
            {
 
                cout << ANames[j] << " ";
                map<string,int>::iterator it = ErdosNumbers.find(extract_name(ANames[j])[0]);
                if (it == ErdosNumbers.end() || it->second == -1) cout << "infinity";
                else cout << it->second;
                cout << endl;
            }
 
    }
 
    return 0;
}