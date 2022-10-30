#include <iostream>
#include <cstdlib>
#include <vector>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

std::vector<int> selectionSort(std::vector<int> &zappy, int n){
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++){
        min_idx = i;

        for (j = i+1; j < n; j++)
        if (zappy[j] < zappy[min_idx])
            min_idx = j;

        if(min_idx!=i)
            swap(&zappy[min_idx], &zappy[i]);
    }

    return zappy;
}
 
int main(){
    std::vector<int> fluffy;

    for(int i = 0; i < 100; i++){
        fluffy.push_back(std::rand());
    }

    fluffy = selectionSort(fluffy, 100);

    for(auto itr = fluffy.begin(); itr != fluffy.end(); itr++){
        std::cout << *itr << " ";
    }
    return 0;
}