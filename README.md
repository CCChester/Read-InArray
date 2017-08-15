# Read-InArray

We typically use arrays to store collections of items (say, integers). We can allow for limited
growth of a collection by allocating more space than typically needed, and then keeping
track of how much space was actually used. We can allow for unlimited growth of the
array by allocating the array on the heap and resizing as necessary. The following structure
encapsulates a partially-lled array:
struct IntArray {
int size; // number of elements the array currently holds
int capacity; // number of elements the array could hold, given current
// memory allocation to contents
int *contents;
};

 Write the function readIntArray which returns an IntArray structure, and whose sig-
nature is as follows:
IntArray readIntArray();
The function readIntArray consumes as many integers from cin as are available, pop-
ulates an IntArray structure in order with these, and then returns the structure. If a
token that cannot be parsed as an integer is encountered before the structure is full,
then readIntArray lls as much of the array as needed, leaving the rest unlled. If
a non-integer is encountered, the rst oending character should be removed from the
input stream (i.e., call cin.ignore once with no arguments). In all circumstances, the
eld size should accurately represent the number of elements actually stored in the
array and capacity should represent the amount of storage currently allocated to the
array.

 Write the function addToIntArray, which takes a pointer to an intArray structure
and adds as many integers to the structure as are available on cin. The behaviour is
identical to readIntArray, except that integers are being added to the end of an existing
intArray. The signature is as follows:
void addToIntArray(IntArray&);

 Write the function printIntArray, which takes a pointer to an IntArray structure, and
whose signature is as follows:
void printIntArray(const IntArray&);
The function printIntArray(a) prints the contents of a (as many elements as are
actually present) to cout, on the same line, separated by spaces, and followed by a
newline. There should be a space after each element in the array (including the last
element), and not before the rst element.
It is not valid to print or add to an array that has not previously been read,
because its elds may not be properly set. You should not test this.
