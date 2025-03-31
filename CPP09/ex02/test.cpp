#include <iostream>
#include <vector>
using namespace std;
#include <cstdlib> 

// Recursive function that returns true if vector is
// sorted in non-decreasing order.
bool isSorted(const vector<int>& arr, int n)
{
    // Base case
    if (n == 1 || n == 0)
        return true;

    // Check if current and previous elements are in order
    // and recursively check the rest of the array
    return arr[n - 1] >= arr[n - 2] && isSorted(arr, n - 1);
}

// Driver code
int main(int argc, char** argv)
{
    vector<int> arr ;

	for (int i = 1; i < argc; ++i) {
        arr.push_back(std::atoi(argv[i]));
    }
    cout << (isSorted(arr, arr.size()) ? "Yes\n" : "No\n");
    return 0;
}