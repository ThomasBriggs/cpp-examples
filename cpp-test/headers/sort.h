namespace sort
{

    void bubbleSort(int sort_array[], int length) {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - 1 - i; j++) {
                if (sort_array[j] > sort_array[j+1]) {
                    int temp = sort_array[j];
                    sort_array[j] = sort_array[j+1];
                    sort_array[j+1] = temp;
                }
            }      
        }    
    }

    void insertionSort(int sort_array[], int length) {
        for (int i = 1; i < length; i++)
        {
            while (sort_array[i] < sort_array[i-1]) {

            }
        }
        
    }
}