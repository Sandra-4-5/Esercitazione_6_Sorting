#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

    template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};


    template<Sortable T>
void BubbleSort(vector<T>& v){
    for(unsigned int i = 0; i < v.size() - 1; i++){
        for(unsigned int j = i + 1; j < v.size(); j++){
            if(v[j] < v[i]){
                //swap
                T tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }

    }
}



template<Sortable T>
void HeapSort(vector<T>& v){
   
    for(unsigned int i = 0; i <= v.size(); i++){
        push_heap(v.begin(), v.begin() + i);
    }
    for(unsigned int i = 0; i < v.size(); i++){
        pop_heap(v.begin(), v.end() - i);
    }
}
}

