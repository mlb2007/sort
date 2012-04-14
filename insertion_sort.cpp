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
        inp.push_back(10);//myrand(0,100));
    }
}

static void printvec(const vector<int>& inp)
{
    for(size_t s = 0; s < inp.size(); ++s)
        std::cout << "(" << s << ":" << inp[s] << "),";
    std::cout << "\n";
}

template<typename container_type,
         typename comp_type = std::less<typename container_type::value_type> >
static void insertion_sort(container_type& arr)
{
    size_t sz = arr.size();
    typename container_type::value_type to_be_inserted;
    size_t insert_index = -1;
    for(size_t i = 1; i < sz; ++i){
        to_be_inserted = arr[i];
        insert_index = i;
        while((insert_index > 0) && (comp_type()(to_be_inserted,arr[insert_index-1])) ){
            arr[insert_index] = arr[insert_index-1];
            --insert_index;
        }
        // finally, insert the to_be_inserted data aftr pushing all the data after it one after another
        // as the while() loop is traversed
        arr[insert_index] = to_be_inserted;
    }
}

template<typename container_type,
         typename comp_type = std::less<typename container_type::value_type> >
static bool isSorted(container_type& arr)
{
    for(size_t i = 1; i < arr.size(); ++i){
        if(!comp_type()(arr[i-1], arr[i])){
            if(!(arr[i-1] == arr[i]))
                return false;
        }
    }
    return true;
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

    std::cout << "== Insertion sort ==\n";
    insertion_sort(Input);
    std::cout << "=== Output ===\n";
    if(!isSorted(Input)){
        std::cout << "*** not sorted\n";
    } else 
        printvec(Input);
    std::cout << "=== Output ===\n";
    
    return 0;
}
