#include <iostream>
#include <vector>

using namespace std;

int rangedBinarySearch(vector<int> &arr, double val)
{
    int idx = arr.size() / 2;
    int searchStep = (arr.size() / 2) + 1;
    while (searchStep != 1)
    {
        if(searchStep % 2 == 0){
            searchStep = searchStep / 2;
        }
        else{
            searchStep = (searchStep / 2) + 1;
        }

        if (arr[idx] > val)
        {
            idx -= searchStep;
        }
        else if (arr[idx] < val)
        {
            idx += searchStep;
        }
        else
        {
            return idx;
        }
    }
    return idx;
}

int main()
{
    int arr1[] = {1,2,3,4,6,7,13,14,15,17,18};
    vector<int> varr1 (arr1, arr1 + sizeof(arr1) / sizeof(int) );

    int arr2[] = {2,5,7,9,10,11,12,13,14,15,127};
    vector<int> varr2 (arr2, arr2 + sizeof(arr2) / sizeof(int) );

    //BINARY SEARCH WORKS
    int res = rangedBinarySearch(varr2, 11.5);
    cout << "Binary search result: " << res << endl;
    cout << "Arr val: " << varr2[res] << endl;

    
    return 0;
}