#include "pch.h"
#include "gtest/gtest.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int RunTest(int a, char** b) {
    testing::InitGoogleTest(&a, b);
    return RUN_ALL_TESTS();
}

int Restriction(int size) {
    if (size >= 1 && size <= 100) {
        return 1;
    }
    else {
        cout << "Invalid Entry" << endl;
        return -1;
    }
}

///////////////////////////////////////////////////////////////////////////////UNIT TEST SECTION////////////////////////////////////////////////////////////////////////////////////////////
TEST(NextPermutationTest, SwappingTest) {
    //Testing the sort function;
    int arr[5] = { 4,5,1,2,3 };
    sort(arr, arr + 5);
    ASSERT_EQ(arr[0], 1);
    ASSERT_EQ(arr[1], 2);
    ASSERT_EQ(arr[2], 3);
    ASSERT_EQ(arr[3], 4);
    ASSERT_EQ(arr[4], 5);
}

TEST(NextPermutationTest, RestrictionTest) {
    ASSERT_TRUE(Restriction(50) == 1);
    ASSERT_FALSE(Restriction(1000) == 1);
    ASSERT_EQ(1, Restriction(100));
    ASSERT_EQ(1, Restriction(10));
}
/////////////////////////////////////////////////////////////////////////////////////END////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc,char **argv)
{

    int* nums = NULL;
    int length, value;
    
    RunTest(argc, argv);
    cout << "Enter length of array 1 and 100 : ";
    cin >> length;

    if (Restriction(length) == 1) {

        nums = new int[length];

        for (int x = 0; x < length; x++) {
            cout << "Item " << x + 1 << " :";
            cin >> value;
            *(nums + x) = value;
        }

        sort(nums, nums + length);

        do {
            for (int x = 0; x < length; x++) {
                cout << nums[x] << " ";
            }
            cout << endl;
        } while (next_permutation(nums, nums + length));

        cout << "After Loop :";
        for (int x = 0; x < length; x++) {
            cout << nums[x];
        }
        cout << endl;
    }
    
    system("pause");
    return 0;
}