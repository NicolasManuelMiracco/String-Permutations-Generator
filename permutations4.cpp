#include <iostream>
#include <algorithm> // For std::swap
using namespace std;

int permutation(string &subString, int leftIndex, int rightIndex) {
    if (leftIndex == rightIndex) {
        cout << subString << endl;
        return 1;
    } else {
        std::sort(subString.begin() + leftIndex, subString.end()); // Sort for uniqueness
        int count = 0;
        for (int i = leftIndex; i <= rightIndex; i++) {
            // Skip if current character is the same as the previous one
            if (i > leftIndex && subString[i] == subString[i - 1]) {
                continue;
            }
            std::swap(subString[leftIndex], subString[i]);
            count += permutation(subString, leftIndex + 1, rightIndex);
            std::swap(subString[leftIndex], subString[i]); // Backtrack
        }
        return count;
    }
}

int main() {
    string myString = "123"; // Example case
    int sizeString = myString.size();
    cout << endl << permutation(myString, 0, sizeString - 1) << " Permutations.";
    return 0;
}