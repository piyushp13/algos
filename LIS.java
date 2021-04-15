import java.io.*;
import java.util.*;

public class LIS {

    // Complete the longestIncreasingSubsequence function below.
    static int longestIncreasingSubsequence(int[] arr) {
        List<Integer> maxSubsequenceList = new ArrayList<Integer>(arr.length);
        maxSubsequenceList.add(arr[0]);
        for (int i = 1; i < arr.length; i++) {
            replaceElementInSortedList(maxSubsequenceList, arr[i]);
        }
        return maxSubsequenceList.size();
    }

    static void replaceElementInSortedList(List<Integer> sortedArray, int element) {
        int left = 0, right = sortedArray.size() - 1;
        if (element > sortedArray.get(right)) {
            sortedArray.add(element);   
        } else {
            while (left < right - 1) {
                int mid = (left + right) / 2;
                if (element > sortedArray.get(mid)) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            if (element <= sortedArray.get(left)) {
                sortedArray.set(left, element);
            } else {
                sortedArray.set(right, element);   
            }
            
        }
    }

    public static void main(String[] args) throws IOException {
        int[] arr = new int[10000];
        File file = new File("input.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));
        String line = "";
        StringBuffer inputStr = new StringBuffer();
        while ((line = br.readLine()) != null) {
            inputStr.append(line);
        }

        String[] inputStringArr = inputStr.toString().split(", ");
        for (int i = 0; i < inputStringArr.length; i++) {
            arr[i] = Integer.parseInt(inputStringArr[i]);
        }
        br.close();
        // int[] arr2 = {10, 22, 9, 33, 21, 50, 41, 60, 80};
        // int[] arr2 = {50, 3, 10, 7, 40, 80};

        System.out.println(longestIncreasingSubsequence(arr));
    }
}

