

using namespace ios;

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int parition(int arr[],int low,int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j = low;
    for (j = low; j< high - 1; j++)
    {
       if (arr[j] < pivot)
       {
           i++;
           swap(&arr[j],&arr[i]);
       }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quicksort(int arr[],int low,int high)
{
    if (low < high)
    {
        int pi = parition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    quicksort(int arr,0,n-1);
    return 0;
}
