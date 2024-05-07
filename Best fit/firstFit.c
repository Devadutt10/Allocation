#include <stdio.h>

struct block {
    int size;
    int blockNo;
    int allocated;
};

struct memory {
    int size;
    int blockNo;
    int blockSize;
    int fragment;
};

int main() {
    int num_blocks;

    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);

    int num_memory;

    printf("Enter the number of memories: ");
    scanf("%d", &num_memory);

    struct memory memory[num_memory];
    struct block block[num_blocks];

    // Entering the memories
    printf("Enter the memories:\n");
    for (int i = 0; i < num_memory; i++) {
        scanf("%d", &memory[i].size);
    }

    // Entering the size of blocks
    printf("Enter the sizes of the blocks:\n");
    for (int i = 0; i < num_blocks; i++) {
        scanf("%d", &block[i].size);
        block[i].blockNo = i + 1;
        block[i].allocated = 0;
    }

    // Allocating the memory in first fit fashion
    for (int i = 0; i < num_memory; i++) {
        int j;
        for (j = 0; j < num_blocks; j++) {
            if (block[j].allocated == 0 && block[j].size >= memory[i].size) {
                block[j].allocated = 1;
                memory[i].blockNo = block[j].blockNo;
                memory[i].fragment = block[j].size - memory[i].size;
                memory[i].blockSize = block[j].size;
                break; // Memory allocated, break the loop
            }
        }
        if (j == num_blocks) {
            memory[i].blockNo = -1;
            memory[i].fragment = -1;
            memory[i].blockSize = -1;
        }
    }

    // Printing...
    printf("\nAllocated Memory Table:\n");
    printf("Memory Size\tBlock No\tBlock Size\tFragment\n");
    for (int i = 0; i < num_memory; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", memory[i].size, memory[i].blockNo,
               memory[i].blockSize, memory[i].fragment);
    }

    return 0;
}
