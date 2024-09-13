#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // �����������󳤶�

// ��������
void add(int arr[], int* size, int element);                               //�����Ӻ���
void delete(int arr[], int* size, int element);                     //ɾ���Ӻ���
void modify(int arr[], int* size, int oldelement, int newelement);  //�޸��Ӻ���
int find(int arr[], int size, int element);                         //�����Ӻ���
void sort(int arr[], int size);                                       //�����Ӻ���
void display(int arr[], int size);                                    //��ʾ�����Ӻ���

int main()
{
    int arr[MAX_SIZE] = { 0 };  // ��ʼ������
    int size = 0;             // ��ǰ�����е�Ԫ�ظ���
    int choice, element, num, newelement, oldelement;

    while (1)                //ѭ����ʵ�ֲ�ͬ����
    {
        printf("\n��ѡ�������\n");
        printf("1. ����\n");
        printf("2. ɾ��\n");
        printf("3. �޸�\n");
        printf("4. ����\n");
        printf("5. ����\n");
        printf("6. �˳�\n");
        scanf_s("%d", &choice);     //���빦�����

        switch (choice)
        {
        case 1:    //�������������Ԫ��
            printf("������Ҫ���ӵ�Ԫ�أ�");
            scanf_s("%d", &element);
            add(arr, &size, element);
            break;
        case 2:    //��ǰ�����˳��ɾ��ָ��Ԫ��
            printf("������Ҫɾ����Ԫ�أ�");
            scanf_s("%d", &element);
            delete(arr, &size, element);
            break;
        case 3:    //�޸�Ԫ��
            printf("������Ҫ�޸ĵ�Ԫ�أ�");
            scanf_s("%d", &oldelement);
            printf("��������ֵ��");
            scanf_s("%d", &newelement);
            modify(arr, &size, oldelement, newelement);
            break;
        case 4:    //����Ԫ��
            printf("������Ҫ���ҵ�Ԫ�أ�");
            scanf_s("%d", &element);
            num = find(arr, size, element);
            if (num != -1)
            {
                printf("Ԫ���ҵ���λ�ã�%d\n", num);  //��ʾ������Ԫ����������λ��
            }
            else
            {
                printf("Ԫ��δ�ҵ�\n");
            }
            break;
        case 5:    //��С���������Ԫ������
            sort(arr, size);
            break;
        case 6:
            printf("�˳�����\n");
            exit(0);
        default:
            printf("��Ч��ѡ�����������롣\n");
        }

        // ��ʾ��ǰ����״̬
        printf("��ǰ���飺");
        display(arr, size);
    }

    return 0;
}

// ʵ�ָ����Ӻ���
void add(int arr[], int* size, int element)
{
    if (*size < MAX_SIZE)
    {
        arr[*size] = element;
        (*size)++;
    }    //ͨ��ָ��int* size ʵ�ֵ�ַ���ݴӶ��ı�size ��������״̬
    else
    {
        printf("�����������޷������Ԫ�ء�\n");
    }
}

void delete(int arr[], int* size, int element)  //����ɾ���޸Ķ���ı�����Ԫ�شӶ���������״̬�ı����Զ�ʹ��ָ��
{
    int i, j;
    for (i = 0; i < *size; i++)
    {
        if (arr[i] == element)
        {
            for (j = i; j < *size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            return;         //��Ҫɾ����Ԫ�ع��ǲ����ֹ��Ǻ�����˳�򲻱�
        }
    }
    printf("Ԫ��δ�ҵ����޷�ɾ����\n");
}

void modify(int arr[], int* size, int oldelement, int newelement)
{
    for (int i = 0; i < *size; i++)
    {
        if (arr[i] == oldelement)
        {
            arr[i] = newelement;
            return;
        }
    }                              //ʵ���¾�Ԫ�ص��滻
    printf("Ԫ��δ�ҵ����޷��޸ġ�\n");
}

int find(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)   //�������鲢��������Ԫ�ص�λ��
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;  // Ԫ��δ�ҵ�
}

void sort(int arr[], int size)
{
    //��С��������
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // ����Ԫ��
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)   //��ǰ������������еĸ�Ԫ��
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



