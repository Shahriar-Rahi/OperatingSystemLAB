.model    small

org 100h

.data

str1 db 'ab00 c', 0

.code
    lea bx, str1
           mov ax, 0

compare:
    cmp [bx], 0
        je done
        inc ax
        inc bx
        jmp compare

done:
    mov bx, ax
    mov cx, 8

print:    
    mov ah, 2
    mov dx, ax
    add dx, 48
    int 21h

    mov ah, 0
    int 16h
endp
