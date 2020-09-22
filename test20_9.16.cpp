#if 0
/* 给出两个有序的整数数组A和B，请将数组B合并到数组A中，变成一个有序的数组
注意：
可以假设A数组有足够的空间存放B数组的元素， A和B中初始的元素数目分别为m和 n*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (m == 0) {
            for (int i = 0;i < n - 1;i++) {
                A[i] = B[i];
            }
        }
        int i = m - 1;
        int j = n - 1;
        int s = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j])
            {
                A[s] = A[i];
                i--;
            }
            else {
                A[s] = B[j];
                j--;
            }
            s--;
        }
        //A中i没减到零，而B中没有元素了-->直接返回A
        //A没元素，B中还有
        if (i == -1)
        {
            while (j >= 0) {
                A[s] = B[j];
                s--;
                j--;
            }
        }
    }

#endif