public class HeapSort {
    private static void print(int[] elements) {
        for (int ele: elements) {
            System.out.print(ele + " ");
        }
        System.out.println();
    }
    
    private static void heapify(int[] elements, int n, int index) {
        int maxIndex = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;
        if (l < n && elements[l] > elements[maxIndex]) {
            maxIndex = l;
        } 
        if (r < n && elements[r] > elements[maxIndex]) {
            maxIndex = r;
        }
        if (maxIndex != index) {
            elements[index] += elements[maxIndex];
            elements[maxIndex] = elements[index] - elements[maxIndex];
            elements[index] = elements[index] - elements[maxIndex];
            heapify(elements, n, maxIndex);
        }
    }

    private static void buildHeap(int[] elements) {
        int n = elements.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(elements, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            elements[0] += elements[i];
            elements[i] = elements[0] - elements[i];
            elements[0] = elements[0] - elements[i];
            heapify(elements, i, 0);
        }
    }

    public static void main(String[] args) {
        int[] elements = {23, 290, 21, 213, 432, 43, 423};
        buildHeap(elements);
        print(elements);
    }
}