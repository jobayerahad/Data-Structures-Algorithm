package algorithm;

import java.util.Scanner;

/**
 * @author Ahad
 */
public class BinarySearch {
    
    public static int binarySearch(int search, int[] array) {
        int start = 0;
        int end = array.length - 1;

        while (start <= end) {
            int middle = (start + end) / 2;

            if (search < array[middle]) {
                    end = middle - 1;
            }

            else if (search > array[middle]) {
                    start = middle + 1;
            }

            else if (search == array[middle]) {
                    return middle;
            }
        }
        return -1;
    }
    
    public static void main(String[] args) {
        //Declared Scanner object for taking input from users
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of elements : ");
        
        //Take the number of elements of array from user
        int numberOfElements = input.nextInt();
        int arr[] = new int[numberOfElements];
        System.out.println("Enter Sorted Array Elements : ");
        
        //Reading Elements
        for (int i = 0; i < numberOfElements; i++) {
            arr[i] = input.nextInt();
        }
        //Taking a value for search in the array
        System.out.println("Please Enter a value for Search : ");
        int search = input.nextInt();
        
        int result = BinarySearch.binarySearch(search, arr);
        
        if (result == -1) {
            System.out.println(search+" not found in the array");
        } else {
            System.out.println(search+" has found at index no : "+result);
        }
    }
}
