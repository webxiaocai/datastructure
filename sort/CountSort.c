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
    //ԭʼ����
    printf("raw:\n");
    for(i = 0; i < len; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\nres:\n");

    CountSort(arr, len);

    //���������
    for(i = 0; i < len; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}


/**
    ��������
    1������ռ䣬��ʼ������
    2������ÿ����Ƶ��
    3������˫��ѭ�����������
**/
void CountSort(int a[], int len)
{
    int *Count;
    int i,j,k,l,minV,maxV,countLen;
    minV = maxV = a[0];
    l = 0;

    //���������Сֵ
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
    //��̬�������鲢��ʼ��Ϊ0,������61������������⣬�Լ�����ʼ���Ļ���ϵͳ����ռ�֮��Ĭ�ϲ�Ϊ0��
    Count = (int *)malloc(sizeof(int) * countLen);
    for(i = 0; i < countLen; i++)
    {
        Count[i] = 0;
    }

    //����Ƶ��
    for(i = 0; i < len; i++)
    {
        k = a[i] - minV;
        ++Count[k];
    }

    //����Ƶ������Count��������߻�д������
    for(i = 0; i < countLen; i++)
    {
        for(j = 1; j <= Count[i]; j++) //jҪ��1��ʼ,Ƶ�ʴ���0�ĲŴ�ӡ
        {
            //printf(" %d ", i + minV);
            //���ݻ�д
            a[l++] = i + minV;
        }
    }

    free(Count);//���ͷŵĻ��ᵼ���ڴ�й©
}


