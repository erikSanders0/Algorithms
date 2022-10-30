#include <iostream>
#include <math.h>

int algorithm01(int A, int B){
    std::cout << "--- Algorithm 01 Starting ---\n";

    // Initialize array
    int nums[B-1];

    // Break it down
    for(int i = 0; i <= B - 1; i++){
        nums[i] = B - i;
        A -= B - i;

        if(i == B - 1){
            nums[i] = A + 1;
        }
    }

    // Visually inspect
    for(int i = 0; i <= B - 1; i++){
        std::cout << nums[i];
        std::cout << "\n";
    } 
    
    std::cout << "--- Algorithm 01 Ending ---\n\n";
    return 0;
}

int algorithm02(int A, int B){
    std::cout << "--- Algorithm 02 Starting ---\n";

    // DISCLAIMER: I use stack overflow to learn about this greedy algorithm
    int result[B-1];
    int left = A - B*(B + 1)/2;

    for(int i = 0; i < B; i++){
        result[i] = i + 1 + left/B;
        if(i >= B - (left % B)){//Add extra one for last left % n elements
            result[i]++;
    }}
    
    // Visually inspect
    for(int i = 0; i <= B - 1; i++){
        std::cout << result[i];
        std::cout << "\n";
    } 
    
    std::cout << "--- Algorithm 02 Ending ---\n\n";
    return 0;
}

int algorithm03(int A, int B){
    std::cout << "--- Algorithm 03 Starting ---\n";

    int list[A];
    int sol[B];
    int sum = 0;

    for(int i = 0; i <= A; i++){
        list[i]  = i + 1;
    }

    for(int i = 0; i < A; i++){
        sum = 0;
        
        for(int j = 0; j < B; j++){
            sol[j] = i + j;
        }
        for(int k = 0; k < B; k++){
            sum += sol[k];
        }
        if(sum == A){
            std::cout << "broke\n";
            break;
        }
        else if(sum > A){
            for(int j = 0; j < B; j++){
                sol[j] = (i) + (j) - 1;
        }
        break;
        }
        
    }

    sum = 0;
    for(int i = 0; i < B; i++){
        sum += sol[i];
    }
    // Add remainder
    int remainder = A - sum;
    sol[B-1] += remainder;

    // Visually inspect
    for(int i = 0; i < B; i++){
        std::cout << sol[i];
        std::cout << "\n";
    } 

    std::cout << "--- Algorithm 03 Ending ---\n\n";

    return 0;
}

int main(){
    std::cout << "--- Program Starting ---\n";

    int A = 80;
    int B = 6;

    algorithm01(A, B);
    algorithm02(A, B);
    algorithm03(A, B);

    return 0;
}