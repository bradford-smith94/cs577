# Bradford Smith (bsmith8)
# CS 577 Lab 3 hello.S
# 09/30/2015
# "I pledge my honor that I have abided by the Stevens Honor System."
################################################################################

# compile with: gcc -nostdlib hello.S
.global _start
.text
_start:
    # write(1, message, 13)
    xor     %rax, %rax
    inc     %rax        # syscall 1 is write
    xor     %rdi, %rdi
    inc     %rdi        # fd 1 is stdout

    xor     %rsi, %rsi
    # put relative address of message in %rsi
    lea     0x11111132(%rip), %rsi #(%rip) is next instruction at 0x4000ea
    sub     $0x11111119, %rsi #message is at 0x400103, need diff of 0x19
    xor     %rdx, %rdx
    addb    $13, %dl
    syscall

    # exit (0)
    xor     %rax, %rax
    addb    $60, %al
    xor     %rdi, %rdi
    syscall
message: #message starts at 0x400103
    .ascii "Hello, World\n"
