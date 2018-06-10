package algorithm;

/**
 * @author jobay
 */
public class BubbleSorting {
    
    public static void bubbleSort(int[] array) {
        int length = array.length;
        for (int i = 0; i < length; i++) {
            for (int j = 1; j < (length - i); j++) {
                if (array[j-1] > array[j]) {
                    //Now swap
                    int temp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = temp;
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
        
        bubbleSort(array);
        System.out.println("\nAfter Sort");
        for (int i: array) {
            System.out.print(i+", ");
        }
    }
}
