.section .text
.globl sum         # Make function visible to C program
.globl loop
.globl finish

sum: 
    mov $0, %eax
    mov $0, %ecx

loop:
    cmpl %esi, %ecx
    jge finish

    addl (%rdi, %rcx, 4), %eax
    addl $1, %ecx
    jmp loop

finish:        
    ret                 # Return control back to C program 

.section .note.GNU-stack,"",@progbits