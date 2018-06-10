package algorithm;

/**
 * @author Ahad
 */
public class InsertionSorting {
    
    public static void insertionSort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = i; j > 0; j--) {
                if (array[j] < array[j-1]) {
                    //Now swap
                    int temp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = temp;
                }
            }
        }
    }
    
    public static void main(String[] args) {
        int[] array = {10,50,7,9,1,2,6,70,9,80};
        System.out.println("Before Sort");
        for (int i: array) {
            System.out.print(i+", ");
        }
        
        insertionSort(array);
        System.out.println("\nAfter Sort");
        for (int i: array) {
            System.out.print(i+", ");
        }
    }
}
