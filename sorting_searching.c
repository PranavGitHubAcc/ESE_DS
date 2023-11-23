#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void linear_itterative(int arr[], int size, int key){
    int flag=0;
    for(int i = 0; i<size; i++){
        if(arr[i]==key){
            printf("Element found at position %d", i+1);
            flag = 1;
        }
    }
    if(!flag){
        printf("Element not found");
    }
}

void linear_recc(int arr[], int size, int key, int itter){
    if(itter>=size){
        printf("Element not found");
        return;
    }
    if(arr[itter]==key){
        printf("Element found at position %d", itter+1);
        return;
    }else{
        linear_recc(arr, size, key, itter+1);
    }
}

void binary_search_itter(int arr[], int size, int key){
    int lb = 0, ub = size-1, found = 0;
    while(lb<ub){
        int mid = (lb+ub)/2;
        if(arr[mid] == key){
            printf("Element found at position %d", mid+1);
            found= 1;
            return;
        }
        if(key < arr[mid]){
            ub = mid-1;
        }else{
            lb = mid+1;
        }
    }
    if(!found){
        printf("Element not present");
    }
}

void binary_search_reccur(int arr[], int size, int key, int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        if(arr[mid]==key){
            printf("Element found at position %d", mid+1);
            return;
        }
        else if(key<arr[mid]){
            binary_search_reccur(arr, size, key, lb, mid-1);
        }else{
            binary_search_reccur(arr, size, key, mid+1, ub);
        }
    }
    else{
        printf("Element not found");
    }
}

void bubble_sort(int arr[], int size){
    for(int i = 0; i<size-1; i++){
        int flag = 0;
        for(int j = 0; j<size-i-1; j++){
            if(arr[j+1]>arr[j]){
                swap(&arr[j+1], &arr[j]);
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
}

void bubble_reccur(int arr[], int size, int itter){
    if(itter<size-1){
        for(int j = 0; j<size-itter-1; j++){
            if(arr[j+1]>arr[j]){
                swap(&arr[j+1], &arr[j]);
            }
        }
        bubble_reccur(arr, size, itter+1);
    }
    return;
}

void selection(int arr[], int size){
    for(int i = 0; i<size-1; i++){
        int min = i;
        for(int j = i+1; j<size-1;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min!=i){
            swap(&arr[i], &arr[min]);
        }
    }
}

void selection_reccur(int arr[], int size, int itter){
    if(itter<size-1){
        int min = itter;
        for(int j = itter+1; j<size-1; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
            if(min != itter){
                swap(&arr[itter], &arr[min]);
            }
        }
        selection_reccur(arr, size, itter+1);
    }
    return;
}

void insertion_sort(int arr[], int size){
    for(int i = 1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void insertion_reccur(int arr[], int size, int itter){
    if(itter<size){
        int key = arr[itter];
        int j = itter -1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    insertion_reccur(arr, size, itter+1);
}


void Quick(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[low]; // Choose the pivot element
        int i = low;   
        int j = high;

        while (i <= j)
        {
            while (a[i]<=pivot)
            {
                i++;
            }
            while (a[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // Place pivot in its correct position
        int temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        // Recursively sort the two sub-arrays
        Quick(a, low, j - 1);
        Quick(a, j + 1, high);
    }
}

void merge(int arr[], int lb, int ub, int mid, int size){
    int i = lb, j = mid + 1, b[size], k = lb;
    if(lb<ub){
        while(i<=mid && j<=ub){
            if(arr[i]<=arr[j]){
                b[k] = arr[i];
                i++;
            }else{
                b[k] = arr[j];
                j++;
            }
            k++;
        }
        if(i>mid && j<=ub){
            while(j<=ub){
                b[k] = arr[j];
                k++;
                j++;
            }
        }else{
            while(i<=mid){
                b[k] = arr[i];
                i++;
                k++;
            }
        }
    }
    for (k = lb; k <= ub;k++){
        arr[k] = b[k];
    }
}

void sort(int arr[], int lb, int ub, int size){
    if(lb<ub){
        int mid = (lb + ub) / 2;
        sort(arr, lb, mid, size);
        sort(arr, mid + 1, ub, size);
        merge(arr, lb, ub, mid, size);
    }
}

int main(){
    int arr[5] = {23, 12 , 9 ,20, 10};
    Quick(arr, 0, 4);
    for(int i = 0; i<5; i++){
        printf("%d ", arr[i]);
    } 
}
