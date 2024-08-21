// 1. WAP to implement the Euclid’s algorithm to find the GCD of two numbers.
/*

#include <stdio.h>

int count = 0;
// Function to compute GCD using the Euclidean algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
        count++;

        // Display the current step
        printf("Step %d: %d = %d * %d + %d\n", count + 1, a, b, a / b, a % b);
    }

    return a;
}

int main()
{
    int num1, num2;

    // Get input from the user
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate and display the GCD
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    printf("Total comparison steps: %d\n", count);

    return 0;
}
 */

// 2.WAP to sort the array 25, 57, 48, 37, 12, 92, 86, 33 using insertion sort
/*

#include <stdio.h>

int main()
{
    int a[100] = {25, 57, 48, 37, 12, 92, 86, 33}; // Predefined array
    int n = 8;                                     // Number of elements in the array
    int i, j, key, count = 0;

    // Display the original array
    printf("Original array: ");
    count = count + 4;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        count = count + 4;
    }
    printf("\n");
    count = count + 1;

    // Insertion sort algorithm
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        count = count + 7;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
            count = count + 3;
        }
        a[j + 1] = key;
        count = count + 2;
    }

    // Display the sorted array
    printf("Elements in sorted order: ");
    count = count + 4;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        count = count + 4;
    }
    printf("\nTotal execution steps = %d", count);
    count = count + 3;

    return 0;
}
*/

// 3. WAP to implement binary search algorithm to search 31 in given array 10 , 14, 19, 26, 31, 42, 44
/*
#include <stdio.h>
#include <time.h>

int count = 0;

// Binary search function
int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        count++;
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
        {
            return mid;
        }

        // If x greater, ignore left half
        if (arr[mid] < x)
        {
            left = mid + 1;
        }
        // If x is smaller, ignore right half
        else
        {
            right = mid - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

int main()
{
    clock_t st = clock();
    // Predefined array and search element
    int arr[] = {10, 14, 19, 26, 31, 42, 44};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 31;

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, x);

    // Display results
    if (result == -1)
    {
        printf("Element is not present in array\n");
    }
    else
    {
        printf("Element %d is present at index %d\n", x, result);
    }

    printf("Total comparison steps: %d\n", count);

    clock_t et = clock();
    printf("The execution time is: %f seconds\n", (double)(et - st) / CLOCKS_PER_SEC);

    return 0;
}
*/

/* 5.WAP TO Implement the Min - Max algorithm to find the minimum and maximum number in the the
    given array 5,7, 3, 4, 9, 12, 6, 2 */
/*

#include <stdio.h>
#include <time.h>

// Global variable to count comparisons
int count = 0;

// Function to find the minimum and maximum elements in an array
void findMinMax(int arr[], int n, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
            count++;
        }
        if (arr[i] > *max)
        {
            *max = arr[i];
            count++;
        }
    }
}

// Driver code
int main()
{
    clock_t st = clock();

    // Predefined array
    int arr[] = {5, 7, 3, 4, 9, 12, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]); // Number of elements in the array

    int min, max;

    // Calling findMinMax() to find the minimum and maximum elements in the array
    findMinMax(arr, n, &min, &max);

    // Printing the minimum and maximum elements
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    // Calculating and printing the execution time
    printf("Total comparison steps: %d\n", count);
    clock_t et = clock();
    printf("The execution time is: %f seconds\n", (double)(et - st) / CLOCKS_PER_SEC);

    return 0;
}
*/

/*6. WAP to implement randomized quick sort*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variable to count comparisons
int count = 0;

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int left, int right)
{
    int pivot = arr[right]; // Pivot element at the end
    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            count++;
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

// Function to generate a random pivot
int randomPartition(int arr[], int left, int right)
{
    int randomIndex = left + rand() % (right - left + 1);
    swap(&arr[randomIndex], &arr[right]);
    return partition(arr, left, right);
}

// Randomized QuickSort function
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        count++;
        int partitionIndex = randomPartition(arr, left, right);

        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
}

// Driver code
int main()
{
    clock_t st = clock();
    srand(time(NULL)); // Seed the random number generator

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    // Printing the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Calculating and printing the execution time
    clock_t et = clock();
    printf("\nThe execution time is: %f seconds\n", (double)(et - st) / CLOCKS_PER_SEC);
    printf("Total comparison steps: %d\n", count);

    return 0;
}
*/

/*7.WAP to sort 7 4 10 8 3 1 using selection sort*/
/*
#include <stdio.h>
#include <time.h>

// Global variable to count comparisons
int count = 0;

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort function
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Find the index of the minimum element in the unsorted portion
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted portion
        if (minIndex != i)
        {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

// Driver code
int main()
{
    clock_t st = clock();

    // Predefined array
    int arr[] = {7, 4, 10, 8, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]); // Number of elements in the array

    // Calling selectionSort() to sort the given array
    selectionSort(arr, n);

    // Printing the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Calculating and printing the execution time
    clock_t et = clock();
    printf("\nTotal comparison steps: %d\n", count);
    printf("The execution time is: %f seconds\n", (double)(et - st) / CLOCKS_PER_SEC);

    return 0;
}
*/
/*8. WAP to sort 7 4 10 8 3 1 using bubble sort*/
/*

#include <stdio.h>

int main()
{
    int a[] = {7, 4, 10, 8, 3, 1};    // Predefined array
    int n = sizeof(a) / sizeof(a[0]); // Number of elements in the array
    int i, j, temp, count = 0;

    // Bubble Sort algorithm
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            count++; // Increment step count for comparison
            if (a[j] > a[j + 1])
            {
                // Swap if elements are in the wrong order
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                count += 4; // Increment step count for swap
            }
        }
    }

    // Print sorted array
    printf("Elements in sorted order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // Print total execution steps
    printf("\nTotal execution steps = %d\n", count);

    return 0;
}
*/
/*9.WAP to implement heap sort.*/
/*
#include <stdio.h>
#include <time.h>

// Global variable to count comparisons
int count = 0;

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
        count++;
    }
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
        count++;
    }
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        count++;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
        count++;
    }
}

// HeapSort function
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        count++;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Driver code
int main()
{
    clock_t st = clock();
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Calling heapSort() to sort the given array
    heapSort(arr, n);

    // Printing the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Calculating and printing the execution time
    clock_t et = clock();
    printf("\nThe execution time is: %f seconds\n", (double)(et - st) / CLOCKS_PER_SEC);
    printf("Total comparison steps: %d\n", count);

    return 0;
}
*/

/*10.WAP to implement Merge Sort */
/*
#include <stdio.h>
#include <time.h>

// Global variable to count comparisons
int count = 0;

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        count++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to sort the array using merge sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        count++;
        int mid = left + (right - left) / 2;

        // Recursively call mergeSort for left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Driver code
int main()
{
    clock_t st = clock();
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call mergeSort to sort the array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Calculate and print the execution time
    clock_t et = clock();
    printf("\nThe execution time is: %f seconds\n", (double)(et - st) / CLOCKS_PER_SEC);
    printf("Total comparison steps: %d\n", count);

    return 0;
}
*/
/*11. WAP to implement Huffman coding*/
/*

#include <stdio.h>
#include <stdlib.h>

// Constants for Huffman Tree
#define MAX_TREE_HT 100

// Structure for Huffman Tree node
struct MinHeapNode
{
    char data;                        // Character
    unsigned freq;                    // Frequency of the character
    struct MinHeapNode *left, *right; // Left and right children
};

// Structure for Min Heap
struct MinHeap
{
    unsigned size;              // Current size
    unsigned capacity;          // Capacity
    struct MinHeapNode **array; // Array of MinHeapNode pointers
};

// Function to create a new node
struct MinHeapNode *newNode(char data, unsigned freq)
{
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a Min Heap
struct MinHeap *createMinHeap(unsigned capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

// Function to swap two Min Heap nodes
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify the Min Heap
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to extract the minimum value node from Min Heap
struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node to Min Heap
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to build Min Heap
void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Function to print an array of size n
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

// Function to check if the node is a leaf node
int isLeaf(struct MinHeapNode *root)
{
    return !(root->left) && !(root->right);
}

// Function to create and build Min Heap from given data and frequencies
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Function to build the Huffman Tree
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

    while (minHeap->size != 1)
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Function to print Huffman codes from the root of the Huffman Tree
void printCodes(struct MinHeapNode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

// Function to build the Huffman Tree and print codes
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

// Driver code
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {15, 12, 14, 10, 6, 25};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Character Frequencies:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c: %d\t", arr[i], freq[i]);
    }
    printf("\nHuffman Codes:\n");
    HuffmanCodes(arr, freq, size);

    return 0;
}
*/
/*12. WAP to implement Kruskal’s Algorithm */
/*
#include <stdio.h>

#define INF 999

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Initialize parent array
    for (i = 1; i <= n; i++)
        parent[i] = 0;

    printf("The edges of the Minimum Cost Spanning Tree are:\n");

    while (ne < n)
    {
        for (i = 1, min = INF; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum cost = %d\n", mincost);
    return 0;
}

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
*/

/*13. WAP to implement Prim’s Algorithm */
/*

#include <stdio.h>
#include <stdlib.h>
#define inf 99999
#define MAX 10

// Adjacency matrix for the graph
int G[MAX][MAX] = {
    {0, 19, 12, inf, inf},
    {19, 0, 6, inf, inf},
    {12, 6, 0, 45, 11},
    {inf, inf, 45, 0, 23},
    {inf, inf, 11, 23, 0}};

int S[MAX][MAX], n;

int prims();

int main()
{
    int i, j, cost;
    n = 5; // Number of vertices
    cost = prims();
    printf("Spanning tree:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (S[i][j] != 0 && S[i][j] != inf)
                printf("(%d, %d) = %d\n", i, j, S[i][j]);
        }
    }
    printf("\nMinimum cost = %d\n", cost);
    return 0;
}

int prims()
{
    int C[MAX][MAX];
    int u, v, min_dist, dist[MAX], from[MAX];
    int visited[MAX] = {0}, ne, i, min_cost, j;

    // Initialize C[][] matrix and S[][]
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                C[i][j] = inf;
            else
                C[i][j] = G[i][j];
            S[i][j] = 0;
        }
    }

    // Initialize dist[], from[], and visited[]
    dist[0] = 0;
    visited[0] = 1;
    for (i = 1; i < n; i++)
    {
        dist[i] = C[0][i];
        from[i] = 0;
        visited[i] = 0;
    }
    min_cost = 0; // Cost of spanning tree
    ne = n - 1;   // Number of edges to be added

    while (ne > 0)
    {
        // Find the vertex with minimum distance from the tree
        min_dist = inf;
        for (i = 1; i < n; i++)
        {
            if (visited[i] == 0 && dist[i] < min_dist)
            {
                v = i;
                min_dist = dist[i];
            }
        }
        u = from[v];

        // Insert the edge into the spanning tree
        S[u][v] = dist[v];
        S[v][u] = dist[v];
        ne--;
        visited[v] = 1;

        // Update the dist[] array
        for (i = 1; i < n; i++)
        {
            if (visited[i] == 0 && C[i][v] < dist[i])
            {
                dist[i] = C[i][v];
                from[i] = v;
            }
        }
        min_cost += C[u][v];
    }
    return min_cost;
}
*/
/*14. WAP to implement Dijkstra’s Algorithm */
/*

#include <stdio.h>
#include <limits.h>

#define V 5         // Number of vertices in the graph
#define INF INT_MAX // Representation of infinity

void dijkstra(int graph[V][V], int start)
{
    int dist[V];    // The output array dist[i] holds the shortest distance from start to i
    int visited[V]; // visited[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0; // Distance from start to itself is always 0

    for (int count = 0; count < V - 1; count++)
    {
        // Find the vertex with the minimum distance value from the set of vertices not yet processed
        int min = INF, u;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && dist[v] <= min)
            {
                min = dist[v];
                u = v;
            }
        }
        visited[u] = 1;

        // Update the distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the calculated shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main()
{
    // Example graph
    int graph[V][V] = {
        {0, 10, 3, 0, 0},
        {10, 0, 1, 2, 0},
        {3, 1, 0, 8, 2},
        {0, 2, 8, 0, 7},
        {0, 0, 2, 7, 0}};

    int start = 0; // Starting vertex for Dijkstra's algorithm
    dijkstra(graph, start);

    return 0;
}
*/
/*15. WAP to implement Fractional Knapsack Problem*/
/*

#include <stdio.h>

// Structure to represent an item
typedef struct
{
    int value;
    int weight;
    float ratio;
} Item;

// Function to compare items based on their value-to-weight ratio
int compare(const void *a, const void *b)
{
    return ((Item *)b)->ratio - ((Item *)a)->ratio;
}

// Function to calculate the maximum value in the knapsack
float fractionalKnapsack(int W, Item items[], int n)
{
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;
    float maxValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= W)
        {
            currentWeight += items[i].weight;
            maxValue += items[i].value;
        }
        else
        {
            int remainingWeight = W - currentWeight;
            maxValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    return maxValue;
}

int main()
{
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Calculate and print the maximum value
    float maxValue = fractionalKnapsack(W, items, n);
    printf("Maximum value that can be put in the knapsack: %.2f\n", maxValue);

    return 0;
}
*/
/*16. WAP to implement job sequencing algorithm with deadline*/
/*
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a Job
typedef struct Jobs
{
    char id;    // Job Id
    int dead;   // Deadline of Job
    int profit; // Profit if Job is completed before or on deadline
} Jobs;

// Function to compare two jobs based on profit
int compare(const void *a, const void *b)
{
    Jobs *temp1 = (Jobs *)a;
    Jobs *temp2 = (Jobs *)b;
    return (temp2->profit - temp1->profit);
}

// Function to find the minimum between two numbers
int min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

int main()
{
    Jobs arr[] = {
        {'a', 2, 150},
        {'b', 2, 50},
        {'c', 1, 90},
        {'d', 3, 15},
        {'e', 3, 45}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort jobs in descending order of profit
    qsort(arr, n, sizeof(Jobs), compare);

    int result[n]; // To store result sequence of Jobs
    bool slot[n];  // To keep track of free time slots

    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Iterate through all given Jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this Job
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    // Print the result
    printf("Following is the maximum profit sequence of jobs:\n");
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
            printf("%c ", arr[result[i]].id);
    }
    printf("\n");

    return 0;
}
*/
/*17. WAP to implement N-Queen Problem*/
/*

#include <stdio.h>
#include <stdlib.h>

// Function to check if a queen can be placed on board[row][col]
int isSafe(int **board, int row, int col, int N)
{
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i] == 1)
            return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j] == 1)
            return 0;

    return 1;
}

// Recursive function to solve N-Queens problem
int solveNQUtil(int **board, int col, int N, int **solutions, int *solutionCount)
{
    if (col >= N)
    {
        solutions[*solutionCount] = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 1)
                    solutions[*solutionCount][i] = j + 1; // Store column indices (1-based)
            }
        }
        (*solutionCount)++;
        return 1;
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col, N))
        {
            board[i][col] = 1; // Place queen

            // Recur to place queens in next columns
            res = solveNQUtil(board, col + 1, N, solutions, solutionCount) || res;

            // Backtrack if queen placement doesn't lead to a solution
            board[i][col] = 0;
        }
    }

    return res;
}

// Function to solve N-Queens problem
int **nQueen(int N, int *solutionCount)
{
    int **solutions = (int **)malloc(1000 * sizeof(int *)); // Allocate memory for solutions
    *solutionCount = 0;

    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        board[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (!solveNQUtil(board, 0, N, solutions, solutionCount))
    {
        printf("No solution exists\n");
    }

    for (int i = 0; i < N; i++)
    {
        free(board[i]);
    }
    free(board);

    return solutions;
}

int main()
{
    int N = 4; // Example: solve N-Queens for n = 4
    int solutionCount;
    int **solutions = nQueen(N, &solutionCount);

    // Print all solutions
    for (int i = 0; i < solutionCount; i++)
    {
        printf("[");
        for (int j = 0; j < N; j++)
        {
            printf("%d ", solutions[i][j]);
        }
        printf("]\n");
        free(solutions[i]);
    }
    free(solutions);

    return 0;
}
*/
/*18. WAP to implement Vertex Cover Problem*/
/*

#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices
#define E 7 // Number of edges

// Function to print the vertex cover set
void printVertexCover(bool cover[], int n)
{
    printf("Vertex Cover: ");
    for (int i = 0; i < n; i++)
    {
        if (cover[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Greedy function to find an approximate vertex cover
void vertexCover(int graph[V][V])
{
    bool cover[V] = {false}; // Array to store vertex cover

    for (int u = 0; u < V; u++)
    {
        for (int v = u + 1; v < V; v++)
        {
            // If there is an edge between u and v
            if (graph[u][v] == 1)
            {
                // Add both u and v to the cover
                if (!cover[u] && !cover[v])
                {
                    cover[u] = true;
                    cover[v] = true;
                }
            }
        }
    }

    printVertexCover(cover, V);
}

int main()
{
    int graph[V][V] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0}};

    vertexCover(graph);

    return 0;
}
*/