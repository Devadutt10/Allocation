#include<stdio.h>

struct block {
    int size;
    int allocated;
    int blockNo;
};

struct memory {
    int size;
    int blockNo;
    int blockSize;
    int fragment;
};

int main() {
    int num_memory;
    printf("Enter the number of memories: ");
    scanf("%d", &num_memory);

    int num_blocks;
    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);

    struct memory memory[num_memory];
    struct block b[num_blocks];

    // Entering the memories
    printf("Enter the memories:\n");
    for(int i = 0; i < num_memory; i++) {
        scanf("%d", &memory[i].size);
    }

    // Entering the size of blocks
    printf("Enter the sizes of the blocks:\n");
    for(int i = 0; i < num_blocks; i++) {
        scanf("%d", &b[i].size);
        b[i].blockNo = i + 1;
        b[i].allocated = 0; // Initializing all blocks as not allocated
    }

    // Finding the best-fit block to allocate each memory
    for(int i = 0; i < num_memory; i++) {
        int bestIndex = -1;
        for(int j = 0; j < num_blocks; j++) {
            if(b[j].allocated != 1 && b[j].size >= memory[i].size) {
                if(bestIndex == -1 || b[j].size < b[bestIndex].size) {
                    bestIndex = j;
                }
            }
        }
        if(bestIndex != -1) {
            // Allocate memory
            b[bestIndex].allocated = 1;
            memory[i].blockNo = b[bestIndex].blockNo;
            memory[i].fragment = b[bestIndex].size - memory[i].size;
            memory[i].blockSize = b[bestIndex].size;
        }
        else{
            memory[i].blockNo = 0;
            memory[i].fragment = 0;
            memory[i].blockSize = 0;
        }
    }

    // Printing...

    printf("Allocated Memory Table:\n");
    printf("Memory Size\tBlock No\tBlock Size\tFragment\n");
    for(int i = 0; i < num_memory; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", memory[i].size, memory[i].blockNo, memory[i].blockSize, memory[i].fragment);
    }

    return 0;
}
