

int call_func(int eax, int ebx, int ecx, int edx) {
    int ans;
    __asm__("push %%ebp\n\t"
            "call func\n\t"
            "pop %%ebp\n\t"
            : "=S"(ans)
            : "a"(eax), "b"(ebx), "c"(ecx), "d"(edx));
    return ans;
}

/*int main() {
}*/