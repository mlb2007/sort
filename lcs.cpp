#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <ctime>

using namespace std;

static int myrand(int low, int high)
{
    int num = low + rand() % (high - low);

    int sgn = rand()% 2;
    if(sgn)
        return num;
    else
        return -num;
}

static void genrandvec(vector<int>& inp, size_t sz)
{
    for(size_t s = 0; s < sz; ++s){
        inp.push_back(myrand(0,100));
    }
}


static void printvec(const vector<int>& inp)
{
    for(size_t s = 0; s < inp.size(); ++s)
        std::cout << "(" << s << ":" << inp[s] << "),";
    std::cout << "\n";
}

/*
given a sequence of integers X = <x1,x2,...,xm>, find the longest
montonically increasing sequence Z = <z1,z2...zk>
The objective function is aggregate of successful find of
monotonically increasing sequence
recurrence relation to find LCS is given by
Length[i] = Length[i-1] + 1, if zi > xi, (also, store the answer) 
Initial conditions
Length[0] = 0;
*/

static void lcs_lookup(vector<int>& Input,
                       vector<int>& c,
                       vector<vector<int> >& Sol,
                       int idx)
{
    std::cout << "lcs_lookup(), idx is:" << idx << std::endl;
    int maxc = -1;
    for(int j = 0; j < idx; ++j){
        int zi = Input[j];
        int xi = Input[idx];
        if(xi > zi){
            if(c[j] > maxc){ // even for sequences in which xi > zi, just increment the
                // sequence that is the longest
                c[j] = c[j] + 1;
                Sol[j].push_back(idx);
                std::cout << "Sol[" << j << "] push_back(" << idx << ")\n";
                maxc = c[j];
            }
        }
    }
}


static void find_LCS(vector<int>& Input,
                     vector<int>& c,
                     vector<vector<int> >& Sol)
{
    int szI = Input.size();
    // initial solution with sequence that starts at that index
    for(int i = 1; i < szI; ++i){
       Sol[i].push_back(i);
    }
    for(int i = 1; i < szI; ++i)
        lcs_lookup(Input,c,Sol,i);
}


// == MAIN ==
int main(int argc, char** argv)
{
    srand(time(NULL) );
    
    vector<int> Input;
    genrandvec(Input,10);
    std::cout << "=== Input ===\n";
    //Input.push_back(33);
    //Input.push_back(1);
    //Input.push_back(2);
    printvec(Input);
    std::cout << "=== Input ===\n";

    vector<int> c;
    c.resize(Input.size());
    vector<vector<int> > Sol;
    Sol.resize(Input.size());
    
    find_LCS(Input,
             c,
             Sol);
    int maxc = 0;
    int idx = 0;
    for(int i = 0; i < c.size();++i) {
        if(c[i] > maxc){
            maxc = c[i];
            idx = i;
        }
    }
    // print solution
    for(int i = 0; i < Sol[idx].size();++i) {
        std::cout << "Sol[" << idx << "][" << i << "]:" << Sol[idx][i]
                  << " the seq value:" << Input[Sol[idx][i]]
                  << std::endl;
    }

    return 0;
}
