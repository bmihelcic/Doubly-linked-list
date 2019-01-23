# Doubly-linked-list
Created by Branimir Mihelčić
Dec 2018/Jan 2019

language: C

Program which presents doubly linked list. Two main components are two structs: list and node.
List is a struct which contains pointer to the beginning of the list (HEAD) and a pointer to the end of the list (TAIL)
Node is a struct which contains value of data as integer, pointer to the previous node (prev) and a pointer to the next node (next)

Functions implemented:
1. init (initializes list, allocation of memory, points head and tail to null)
2. add (adds element to the end of the list)
3. print_list (nothing fancy)
4. delete (delets n-th element of the list)
5. deleteAll (delets all elements from the list)
6. print_mid (print from middle element, then print the one closer to the end, then the one closer to the beginning etc.
   e.g. if the list has 9 elements (1,2,3,4,5,6,7,8,9) the order of printing would be 5,6,4,7,3,8,2,9,1
   if the list has an even number of elements take the one closer to the beginning as the middle node)
