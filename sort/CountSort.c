#include <stdio.h>
#include <stdlib.h>

void CountSort(int a[], int len);

int main(int argc, char **argv)
{
    int i;
    //int arr[] = {200,195,199,1,8,3};
    //int arr[] = {99,8,1,102,999,335,2,4,0};
    //int arr[] = {9, 7, 6, 3, 9, 2, 7, 3, 2, 8};
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
    int len;

    len = sizeof(arr) / sizeof(int);
	printf(" %d \n", len);
    //原始数据
    printf("raw:\n");
    for(i = 0; i < len; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\nres:\n");

    CountSort(arr, len);

    //输出排序结果
    for(i = 0; i < len; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}


/**
    计数排序：
    1、申请空间，初始化操作
    2、计算每个数频率
    3、利用双重循环输出排序结果
**/
void CountSort(int a[], int len)
{
    int *Count;
    int i,j,k,l,minV,maxV,countLen;
    minV = maxV = a[0];
    l = 0;

    //计算最大最小值
    for(i = 0; i < len; i++)
    {
        if (a[i] > maxV)
        {
            maxV = a[i];
        }

        if (a[i] < minV)
        {
            minV = a[i];
        }
    }

    countLen = maxV - minV + 1;
    //动态申请数组并初始化为0,否则在61行输出就有问题，自己不初始化的话向系统申请空间之后默认不为0的
    Count = (int *)malloc(sizeof(int) * countLen);
    for(i = 0; i < countLen; i++)
    {
        Count[i] = 0;
    }

    //计算频率
    for(i = 0; i < len; i++)
    {
        k = a[i] - minV;
        ++Count[k];
    }

    //遍历频率数组Count，输出或者回写排序结果
    for(i = 0; i < countLen; i++)
    {
        for(j = 1; j <= Count[i]; j++) //j要从1开始,频率大于0的才打印
        {
            //printf(" %d ", i + minV);
            //数据回写
            a[l++] = i + minV;
        }
    }

    free(Count);//不释放的话会导致内存泄漏
}


