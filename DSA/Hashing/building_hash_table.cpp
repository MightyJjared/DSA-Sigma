#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string key;
    int value;
    node* next;

    node(string key, int value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~node() {
        // Recursively delete the next node in the chain to free memory
        if (next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totalsize;   // Total number of buckets
    int currentsize; // Total number of key-value pairs stored
    node** arr;      // Array of pointers to linked list heads

    /*
     Hash Function Logic:
     --------------------
     - Goal: Convert a string key into an index in the array.
     - Approach: Iterate over each character of the string.
       For each character:
         1. Convert it to its ASCII value.
         2. Square the ASCII value to increase variability.
         3. Add it to the running total.
     - Finally, take the sum modulo `totalsize` to ensure it maps to a valid bucket index.
     */
    int hashfuntion(string key) {
        int idx = 0;
        for (int i = 0; i < key.size(); i++) {
            idx = idx + (key[i] * key[i]);
        }
        idx = idx % totalsize;
        return idx;
    }

    /*
     Rehashing Logic:
     ----------------
     - Triggered when the load factor (currentsize / totalsize) exceeds 1.
     - Steps:
         1. Store the old array and size.
         2. Double the table size to reduce collisions.
         3. Allocate a new empty array of the new size.
         4. Reset currentsize to 0 because we'll re-insert everything.
         5. Traverse each bucket of the old array and insert all key-value pairs into the new array using the hash function (which now uses the larger totalsize).
         6. Delete all nodes from the old array and then delete the array itself to free memory.
     */
    void rehashing() { // O(n)
        node** old_arr = arr;
        int old_size = totalsize;

        totalsize = 2 * totalsize;
        currentsize = 0; // reset before reinserting

        arr = new node*[totalsize];
        for (int i = 0; i < totalsize; i++) {
            arr[i] = NULL;
        }

        // Reinserting old key-value pairs
        for (int i = 0; i < old_size; i++) {
            node* temp = old_arr[i];
            while (temp != NULL) {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            // delete linked list of this bucket
            if (old_arr[i] != NULL) {
                delete old_arr[i];
            }
        }

        delete[] old_arr;
    }

public:
    /*
     Constructor Logic:
     ------------------
     - Initialize totalsize to the given size.
     - Set currentsize to 0 since no elements are present.
     - Allocate a dynamic array of `node*` and set all buckets to NULL.
     */
    HashTable(int size) {
        totalsize = size;
        currentsize = 0;

        arr = new node*[totalsize];
        for (int i = 0; i < totalsize; i++) {
            arr[i] = NULL;
        }
    }

    /*
     Insert Logic:
     -------------
     - Compute the bucket index using the hash function.
     - Create a new node for the key-value pair.
     - Insert it at the head of the linked list for that bucket (separate chaining method).
     - Increment currentsize.
     - Compute load factor. If > 1, trigger rehashing to maintain efficiency.
     */
    void insert(string key, int value) { // average O(1), worst O(n) due to rehashing
        int idx = hashfuntion(key);

        node* newnode = new node(key, value);

        newnode->next = arr[idx];
        arr[idx] = newnode;

        currentsize++;

        double lambda = currentsize / (double)totalsize;
        if (lambda > 1) {
            rehashing();
        }
    }

    /*
     Remove Logic:
     -------------
     - Find the bucket index for the given key.
     - Traverse the linked list in that bucket.
     - If the node with the key is found:
         1. If it's the first node, update the bucket head.
         2. If it's in the middle/end, adjust the `next` pointer of the previous node.
     - Delete the node to free memory.
     - Decrement currentsize.
     */
    void remove(string key) {
        int idx = hashfuntion(key);

        node* temp = arr[idx];
        node* prev = temp;
        while (temp != NULL) {
            if (temp->key == key) {
                if (temp == prev) {
                    arr[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                temp->next = NULL; // avoid recursive delete of rest of list
                delete temp;
                currentsize--;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    /*
     Exist Logic:
     ------------
     - Compute bucket index using hash function.
     - Traverse linked list in that bucket.
     - If key is found, return true; else false.
     */
    bool exist(string key) {
        int idx = hashfuntion(key);

        node* temp = arr[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    /*
     Search Logic:
     -------------
     - Compute bucket index.
     - Traverse linked list in that bucket.
     - If key is found, return its associated value.
     - If not found, return -1.
     */
    int search(string key) {
        int idx = hashfuntion(key);

        node* temp = arr[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }

    /*
     Print Logic:
     ------------
     - Iterate over each bucket.
     - For each bucket, traverse the linked list and print all key-value pairs in order.
     - Useful for debugging.
     */
    void printlist() {
        for (int i = 0; i < totalsize; i++) {
            node* temp = arr[i];
            cout << "idx" << i << "->";
            while (temp != NULL) {
                cout << "(" << temp->key << "," << temp->value << ") ->";
                temp = temp->next;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    HashTable ht(5);

    ht.insert("india", 150);
    ht.insert("usa", 50);
    ht.insert("china", 150);
    ht.insert("russia", 80);
    ht.insert("england", 40);

    ht.printlist();

    ht.remove("india");
    ht.printlist();
    return 0;
}
