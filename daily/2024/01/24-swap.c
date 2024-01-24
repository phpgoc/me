void swap_without_tmp(void* a, void* b, int size){
    char* a1 = (char*)a;
    char* b1 = (char*)b;
    for(int i = 0; i < size; i++){
        a1[i] = a1[i] ^ b1[i];
        b1[i] = a1[i] ^ b1[i];
        a1[i] = a1[i] ^ b1[i];
    }
}

