class BinaryTree2D {
    int inputArray[][];
    int binaryTree[][];
    int rows;
    int columns;
    BinaryTree2D(int inputArray[][]) {
        this.inputArray = inputArray;
        this.rows = this.inputArray.length;
        this.columns = this.inputArray[0].length;
        this.binaryTree = new int[this.rows][this.columns];
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.columns; j++) {
                this.binaryTree[i][j] = 0;
            }
        }
        this.build();   
    }

    int getSum(int x, int y) {
        int sum = 0;
        for (; x > 0; x -= x & -x) {
            int temp = y;
            for (; y > 0; y -= y & -y) {
                sum += this.binaryTree[x - 1][y - 1];
            }
            y = temp;
        }
        return sum;
    }

    int getSum(int x1, int y1, int x2, int y2) {
        int sum1 = this.getSum(x2, y2);
        int sum2 = this.getSum(x1 - 1, y2);
        int sum3 = this.getSum(x2, y1 - 1);
        int sum4 = this.getSum(x1 - 1, y1 - 1);
        int sum = sum1 - sum2 - sum3 + sum4;
        return sum;
    }

    void update(int x, int y, int value) {
        for (; x <= this.rows; x += x & -x) {
            int temp = y;
            for (; y <= this.columns; y += y & -y) {
                this.binaryTree[x - 1][y - 1] += value; 
            }
            y = temp;
        }
    }

    void build(){
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.columns; j++) {
                this.update(i + 1, j + 1, this.inputArray[i][j]);
            }
            // System.out.println("After " + i + "th iteration");
            // this.printTree();
        }
    }

    void printTree() {
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.columns; j++) {
                System.out.print(this.binaryTree[i][j] + " ");
            }
            System.out.println();
        }
    }
}
public class BinaryTree {
    public static void main(String args[]) {
        System.out.println("Hello");
        int inputArray[][] = {{1, 2, 3, 4}, {5, 3, 8, 1}, {4, 6, 7, 5}, {2, 4, 8, 9}};
        BinaryTree2D biTree = new BinaryTree2D(inputArray);
        System.out.println("Created binary indexed tree");
        // biTree.printTree();
        System.out.println(biTree.getSum(2, 2, 4, 4));
    }
}
