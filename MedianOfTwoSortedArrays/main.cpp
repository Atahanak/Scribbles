#include <iostream>
#include <vector>

using namespace std;

int rangedBinarySearch(vector<int> &arr, double val,int from, int to)
{
    //int idx = arr.size() / 2;
    int idx = (to + from) / 2;
    //int searchStep = (arr.size() / 2) + 1;
    int searchStep = ((to - from) / 2) + 1;
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

double getMedianByRange(vector<int>& arr, int from, int to){
    if(from > to){
        int temp = from;
        from = to;
        to = from;
    }
    int len = to - from;
    if(len % 2 == 0){
        //return (double)(arr[arr.size() / 2] + arr[(arr.size() / 2)+1]) / (double)2; 
        return (double)(arr[(from + to) / 2] + arr[((from + to) / 2)-1]) / (double)2; 
    }
    return arr[(from + to) / 2];
}

int main()
{
    int arr1[] = {1,2,3,4,6,7,13,14,15,17,18,19};
    vector<int> varr1 (arr1, arr1 + sizeof(arr1) / sizeof(int) );

    int arr2[] = {2,5,7,9,10,11,12,13,14,15,127};
    vector<int> varr2 (arr2, arr2 + sizeof(arr2) / sizeof(int) );

    //median
    //cout << "Median arr1: " << getMedianByRange(varr1, 0, varr1.size()) << endl;
    //cout << "Median arr12: " << getMedianByRange(varr2, 0, 2) << endl;
    //

    //BINARY SEARCH WORKS
    // int res = rangedBinarySearch(varr2, 15, 5, 6);
    // cout << "Binary search result: " << res << endl;
    // cout << "Arr val: " << varr2[res] << endl;

    int i = 0;
    int from1 = 0;
    int from2 = 0;
    double med1 = getMedianByRange(varr1, from1, varr1.size());
    double med2 = getMedianByRange(varr2, from2, varr2.size());
    int to1 = varr1.size() / 2;
    int to2 = varr2.size() / 2;
    while(true){
        if(i % 2 == 0){
            from2 = rangedBinarySearch(varr2, med1, from2, to2);
            med2 = getMedianByRange(varr2, from2, to2);
            if(med2 == to2){
                cout << "MED: " << varr2[med2] << endl;
                break;
            }
        }
        else{

        }
        i++;
    }
    
    return 0;
}