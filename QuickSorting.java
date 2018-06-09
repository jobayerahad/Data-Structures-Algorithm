package algorithm;

/**
 * @author Ahad
 */
public class QuickSorting {
    public static void quickSort(int[] array) {
        quickSort(array, 0, array.length - 1);
    } 
    public static void quickSort(int[] array, int left, int right) {
        if (left >= right) {
            return;
        } else {
            int pivot = array[(left + right) / 2];
            int index = partition(array, left, right, pivot);
            quickSort(array, left, index - 1);
            quickSort(array, index, right);
        }
    }
    
    public static int partition (int[] array, int left, int right, int pivot) {
        while (left <= right) {            
            while (array[left] < pivot) {                
                left++;
            }
            while (array[right] > pivot) {                
                right--;
            }
            if(left <= right) {
                swap(array, left, right);
                left++;
                right--;
            }
        }
        return left;
    }
    
    public static void swap (int[] array, int left, int right) {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
    
    public static void main(String[] args) {
        int[] array = {10,50,7,9,1,2,6,70,9,80};
        System.out.println("Before Sort");
        for (int i: array) {
            System.out.println(i);
        }
        
        quickSort(array);
        System.out.println("After Sort");
        for (int i: array) {
            System.out.println(i);
        }
    }
}
