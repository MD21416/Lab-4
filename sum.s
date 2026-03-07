.section .text
.globl sum                      # Make function visible to C program
.globl loop
.globl finish

sum: 
    mov $0, %eax                # Set sum (EAX) to 0
    mov $0, %ecx                # Set iterator (ECX) to 0

loop:
    cmpl %esi, %ecx             # Compare ECX to the size of the array
    jge finish                  # Finish loop if sum is complete

    addl (%rdi, %rcx, 4), %eax  # Add current array element to sum
    addl $1, %ecx               # Add 1 to iterator (ECX)
    jmp loop                    # Go to next array element

finish:        
    ret                         # Return control back to C program 

.section .note.GNU-stack,"",@progbits