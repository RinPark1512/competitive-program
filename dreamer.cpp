#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std; 

int checkSmallest(int nums[8], int smallest[8]);
bool checkLeap(int nums[8]);
bool isValidDate(int nums[8]);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,temp;
    cin>>n;
    for (int i = 0; i <n; i++){
        int nums[8];
        int smallest[8] = {10, 10, 10, 10, 10, 10, 10, 10};
        double valid_dates = 0;
        cin>>temp;
        //day
        nums[0]=temp/10;
        nums[1]=temp%10;
        // month
        cin>>temp;
        nums[2]=temp/10;
        nums[3]=temp%10;
        //year
        cin>>temp;
        nums[4]=temp/1000;
        temp = temp % 1000;
        nums[5]=temp/100;
        temp = temp % 100;
        nums[6]=temp/10;
        nums[7]=temp%10;

        //sort ascending order, start at smallest
        sort(nums, nums+8);

        do {
            // make sure date is valid
            if (isValidDate(nums)){
                valid_dates++;
                checkSmallest(nums, smallest);
            } else{
                
            }
        } while (next_permutation(nums, nums+8));
        cout<<valid_dates;
        if (valid_dates){
            cout<<" ";
            cout<<smallest[0]<<smallest[1]<<" ";
            cout<<smallest[2]<<smallest[3]<<" ";
            cout<<smallest[4]<<smallest[5]<<smallest[6]<<smallest[7];
        }
        cout<<"\n";
    }
    return 0;
}

bool inline checkLeap(int nums[8]){
    // if divisible by 400
    int year = (nums[4]*1000)+(nums[5]*100)+(nums[6]*10)+nums[7];
    if (!(year % 400)){
        return true;
    }
    if (!(year % 4)){
        if ((year % 100)){
            return true;
        }
    }
    return false;
    // if divisible by 4 NOT 100
}
int checkSmallest(int nums[8], int smallest[8]){
    double val, small;
    // put into year month day format
    // y y y y m m d d
    val += nums[4]*(pow(10,8));
    val += nums[5]*(pow(10,7));
    val += nums[6]*(pow(10,6));
    val += nums[7]*(pow(10,5));
    val += nums[2]*(pow(10,4));
    val += nums[3]*(pow(10,3));
    val += nums[0]*(pow(10,2));
    val += nums[1]*(10);

    small += smallest[4]*(pow(10,8));
    small += smallest[5]*(pow(10,7));
    small += smallest[6]*(pow(10,6));
    small += smallest[7]*(pow(10,5));
    small += smallest[2]*(pow(10,4));
    small += smallest[3]*(pow(10,3));
    small += smallest[0]*(pow(10,2));
    small += smallest[1]*(10);

    if (small > val){
        smallest[0] = nums[0];
        smallest[1] = nums[1];
        smallest[2] = nums[2];
        smallest[3] = nums[3];
        smallest[4] = nums[4];
        smallest[5] = nums[5];
        smallest[6] = nums[6];
        smallest[7] = nums[7];
    }
    return 0;
}

bool isValidDate(int nums[8]){
    if (nums[4]>=2){
        int months = (nums[2]*10)+nums[3];
        int day = (nums[0] * 10) + nums[1];
        int day_arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (months && day && months <= 12){
            if (months == 2){
                if (checkLeap(nums)){
                    return (day <= 29);
                } else{
                    return (day <= 28);
                }
            } else{
                return (day <= day_arr[months-1]);
            }
        }
    }
    return false;
}

// 02 02 4988
// under count 411