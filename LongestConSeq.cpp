#include "pch.h"
#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int RunningUnitTests(int a, char** b) {
    testing::InitGoogleTest(&a,b);
    return RUN_ALL_TESTS();
}

void arrValues(int*& arr, int sentinel) {

    int value;

    if (sentinel != -1) {
        arr = new int[sentinel];
        for (int x = 0; x < sentinel; x++) {
            cout << "Item " << x + 1 << " : ";
            cin >> value;
            *(arr + x) = value;
        }
    }
    else { exit(-1); }
}

int sortedAarry(int* arr, int sentinel, int index) {

    int temp;

    for (int i = 0; i < sentinel; i++)
    {
        for (int j = i + 1; j < sentinel; j++)
        {
            //If there is a smaller element found on right of the array then swap it.
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return *(arr + index);
}

//This function is responsible for loading the numbers that are in sequence in an array
void storeConsectiveNumbers(int*& arr1, int*& arr2, int cnt, int senti) {
    for (int x = 0; x < cnt; x++) {
        if (sortedAarry(arr2, senti, x + 1) - sortedAarry(arr2, senti, x) != 0) {
            *(arr1 + x) = sortedAarry(arr2, senti, x);
        }
    }
}

//The function is responsible for counting the number of consecutive numbers 
int countConsecutiveNumbers(int* arr, int sentinel, int& count) {
    count = 1;
    for (int x = 0; x < sentinel + 1; x++) {
        int difference = sentinel > 1 ? (sortedAarry(arr, sentinel, x + 1) - sortedAarry(arr, sentinel, x)) : sortedAarry(arr, sentinel, 0);
        if (difference == 1) {
            count++;
        }
    }
    return count;
}

////////////////////////////////////////////////////////////////////////////////////////////UNIT TEST SECTION////////////////////////////////////////////////////////////////////////////

TEST(LongestConSequence,TestSortFunction) { 
    int* val{ new int[6]{5, 9, 7, 6, 2, 1} };
    ASSERT_EQ(sortedAarry(val, 6, 0) , 1);
    ASSERT_EQ(sortedAarry(val, 6, 1), 2);
    ASSERT_EQ(sortedAarry(val, 6, 2), 5);
    ASSERT_EQ(sortedAarry(val, 6, 3), 6);
    ASSERT_EQ(sortedAarry(val, 6, 4), 7);
    ASSERT_EQ(sortedAarry(val, 6, 5), 9);
}

//tresting the countConsecutiveNumbers function
TEST(LongestConSequence, SequenceArray) {
        
    int* arr{ new int[10]{0 , 3 , 7 , 2 , 5 , 8 , 4 , 6 , 0 , 1 } };
    int counter;
    for (int x = 0; x < 10; x++) {
        *(arr + x) = sortedAarry(arr, 10, x);
    }
    ASSERT_EQ(countConsecutiveNumbers(arr, 10, counter), 9); 
}
////////////////////////////////////////////////////////////////////////////////////////////END OF SECTION///////////////////////////////////////////////////////////////////////////////

int main(int argc,char **argv)
{
    int* array = NULL;
    int sen;
    cout << endl << endl;
    cout << "How many items are you going to enter or (Enter -1 to terminate)?";
    cin >> sen;
    //The function below loads the values into the array
    arrValues(array, sen);
    RunningUnitTests(argc, argv);
    int* longestSeq = NULL;
    int counter;
    countConsecutiveNumbers(array, sen, counter);
    longestSeq = new int[counter];
    storeConsectiveNumbers(longestSeq, array,counter,sen);
    cout << endl;
    cout << "Longest Consecutive Sequence : " << counter;
    cout << endl << endl << endl;
    system("pause");
    return 0;
}
