//剑指OFFER
//一个整型数组里除了两个数字之外，其他的数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int result=0;
        *num1=0;*num2=0;
        int len=data.size();
        for(int i=0;i<len;i++){
            result=result^data[i];
        }

        int indexof1=FindFirst1(result);

        for(int j=0;j<len;j++){
            if(IsBit(data[j],indexof1))
                *num1^=data[j];
            else
                *num2^=data[j];
        }


    }

private:
    int FindFirst1(int result){
        int index=0;
        while((result&1)==0){
            result=result>>1;
            index++;
        }
        return index;

    }

private:
    bool IsBit(int num,int index){
        num=num>>index;
        return(num&1);
    }
};

int main(void){
    vector<int> num;
    num.push_back(2);
    num.push_back(4);
    num.push_back(3);
    num.push_back(6);
    num.push_back(3);
    num.push_back(2);
    num.push_back(5);
    num.push_back(5);
    Solution solution;
    int* num1;int* num2;
    solution.FindNumsAppearOnce(num,num1,num2);
    cout<<*num1<<*num2<<endl;
}

//调试成功