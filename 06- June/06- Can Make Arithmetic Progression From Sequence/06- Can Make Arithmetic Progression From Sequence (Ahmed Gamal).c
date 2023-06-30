// Author: Ahmed Gamal

// for this problem we need to sort the array first then check if the difference between each two adjacent elements is the same
// if it is the same then we return true else we return false

// compare function for qsort
int compare_ints(const int *a, const int *b) {
    return *a - *b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize){
    // sort the array
    qsort(arr, arrSize, sizeof(int), compare_ints);

    // check if the difference between each two adjacent elements is the same 
    int i;
    int d = arr[1] - arr[0];
    for(i = 0; i < arrSize - 1; i++) {
        if(arr[i + 1] - arr[i] != d) {
            return false;
        }
    }

    return true;
}