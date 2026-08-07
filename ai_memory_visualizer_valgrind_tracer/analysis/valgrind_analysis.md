# Aliasing_Example.c 

aliasing_example: aliasing and use-after-free (Valgrind should report it)
  a=0xaaaae70dd420 b=0xaaaae70dd420 a[2]=22 b[2]=22
  after free(a): b=0xaaaae70dd420 (dangling)
  reading b[2]=1164296088
  wrote b[3]=1234
root@4ed0bb2e59f5:~/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs# valgrind ./alias
==8635== Memcheck, a memory error detector
==8635== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==8635== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
==8635== Command: ./alias
==8635== 
aliasing_example: aliasing and use-after-free (Valgrind should report it)
  a=0x4aae480 b=0x4aae480 a[2]=22 b[2]=22
  after free(a): b=0x4aae480 (dangling)
==8635== Invalid read of size 4
==8635==    at 0x40009B0: main (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635==  Address 0x4aae488 is 8 bytes inside a block of size 20 free'd
==8635==    at 0x48A86B8: free (vg_replace_malloc.c:990)
==8635==    by 0x4000997: main (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635==  Block was alloc'd at
==8635==    at 0x48A5618: malloc (vg_replace_malloc.c:447)
==8635==    by 0x400089B: make_numbers (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635==    by 0x400093B: main (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635== 
  reading b[2]=22
==8635== Invalid write of size 4
==8635==    at 0x40009D0: main (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635==  Address 0x4aae48c is 12 bytes inside a block of size 20 free'd
==8635==    at 0x48A86B8: free (vg_replace_malloc.c:990)
==8635==    by 0x4000997: main (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635==  Block was alloc'd at
==8635==    at 0x48A5618: malloc (vg_replace_malloc.c:447)
==8635==    by 0x400089B: make_numbers (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635==    by 0x400093B: main (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635== 
==8635== Invalid read of size 4
==8635==    at 0x40009DC: main (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635==  Address 0x4aae48c is 12 bytes inside a block of size 20 free'd
==8635==    at 0x48A86B8: free (vg_replace_malloc.c:990)
==8635==    by 0x4000997: main (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635==  Block was alloc'd at
==8635==    at 0x48A5618: malloc (vg_replace_malloc.c:447)
==8635==    by 0x400089B: make_numbers (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635==    by 0x400093B: main (in /root/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs/alias)
==8635== 
  wrote b[3]=1234
==8635== 
==8635== HEAP SUMMARY:
==8635==     in use at exit: 0 bytes in 0 blocks
==8635==   total heap usage: 2 allocs, 2 frees, 1,044 bytes allocated
==8635== 
==8635== All heap blocks were freed -- no leaks are possible
==8635== 
==8635== For lists of detected and suppressed errors, rerun with: -s
==8635== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)

1. Invalid read of size 4 at reading b[2]

Type: Use-after-free (invalid read)
Memory-Object: The heap-allocated integer array returned by make_numbers()
Cause: a and b point to the same allocated array (aliasing). After free(a), the memory is released. b still points to the freed block (a dangling pointer), so reading b[2] accesses memory whose lifetime has ended.

2. Invalid write of size 4 at b[3] = 1234

Type: Use-after-free (invalid write)
Memory-Object: The same heap-allocated integer array
Cause: The block has already been freed through a. Writing through b attempts to modify memory that no longer belongs to the program.

3. Invalid read of size 4 after the write

Type: Use-after-free (invalid write)
Memory-Object: The same heap-allocated integer array
Cause: After the invalid write, the program reads b[3] (or prints it). Since the block is still freed, this is another access to memory after its lifetime ended.

Initially:

a ----+
      |
      v
+----+----+----+----+----+
| 0  | 11 | 22 | 33 | 44 |
+----+----+----+----+----+
      ^
      |
b -----+

Both a and b point to the same address, meaning when a is freed it also frees b. When b is used after a is freed 'use-after-free' occurs. 

# Crash_example.c

==8644== Memcheck, a memory error detector
==8644== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==8644== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
==8644== Command: ./crash
==8644== 
crash_example: deterministic NULL dereference (segmentation fault)
  requesting n=0
==8644== Invalid write of size 4
==8644==    at 0x400094C: main (crash_example.c:32)
==8644==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==8644== 
==8644== 
==8644== Process terminating with default action of signal 11 (SIGSEGV)
==8644==  Access not within mapped region at address 0x0
==8644==    at 0x400094C: main (crash_example.c:32)
==8644==  If you believe this happened as a result of a stack
==8644==  overflow in your program's main thread (unlikely but
==8644==  possible), you can try to increase the size of the
==8644==  main thread stack using the --main-stacksize= flag.
==8644==  The main thread stack size used in this run was 8388608.
==8644== 
==8644== HEAP SUMMARY:
==8644==     in use at exit: 1,024 bytes in 1 blocks
==8644==   total heap usage: 1 allocs, 0 frees, 1,024 bytes allocated
==8644== 
==8644== LEAK SUMMARY:
==8644==    definitely lost: 0 bytes in 0 blocks
==8644==    indirectly lost: 0 bytes in 0 blocks
==8644==      possibly lost: 0 bytes in 0 blocks
==8644==    still reachable: 1,024 bytes in 1 blocks
==8644==         suppressed: 0 bytes in 0 blocks
==8644== Rerun with --leak-check=full to see details of leaked memory
==8644== 
==8644== For lists of detected and suppressed errors, rerun with: -s
==8644== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault         valgrind ./crash

1. Error

Error type: NULL pointer dereference / invalid write.
Memory object involved: No valid memory object; the program attempted to access address 0x0.
Cause: A NULL pointer was dereferenced and used as if it pointed to allocated memory. The program attempted to write through an invalid pointer, causing a segmentation fault.

The function attempted to overwrite the value of nums which was initially set to NULL.

    nums = allocate_numbers(n);

    nums[0] = 42;

leading to an invalid write.

# heap_example.c

==8652== Memcheck, a memory error detector
==8652== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==8652== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
==8652== Command: ./heao
==8652== 
heap_example: allocations and a deliberate leak
  alice=0x4aae480 name=0x4aae4d0 age=30
  bob=0x4aae520 name=0x4aae570 age=41
==8652== 
==8652== HEAP SUMMARY:
==8652==     in use at exit: 6 bytes in 1 blocks
==8652==   total heap usage: 5 allocs, 4 frees, 1,066 bytes allocated
==8652== 
==8652== LEAK SUMMARY:
==8652==    definitely lost: 6 bytes in 1 blocks
==8652==    indirectly lost: 0 bytes in 0 blocks
==8652==      possibly lost: 0 bytes in 0 blocks
==8652==    still reachable: 0 bytes in 0 blocks
==8652==         suppressed: 0 bytes in 0 blocks
==8652== Rerun with --leak-check=full to see details of leaked memory
==8652== 
==8652== For lists of detected and suppressed errors, rerun with: -s
==8652== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

1. Error

Error Type: Memory leak
Memory object involved: definitely lost: 6 bytes in 1 blocks
Cause: The function was not freed correctly, leading one block of allocated memory still filled after exit. 

"Alice" remains not freed after the function exits as only 'person_free_partial(alice);' is used meaning only the data directly is freed, the pointer to "Alice" is freed but not the string with leaves the 6 bytes of memory allocated, 'A''l''i''c''e''\0'.

# stack_example.c

stack_example: recursion and stack frames
[enter] depth=0
  &local_int=0xffffe24596bc  p_local=0xffffe24596bc  local_int=100
  local_buf=0xffffe24596c8  local_buf[0]=A
  &marker=0xffffe2459704  marker=0
[enter] depth=1
  &local_int=0xffffe245968c  p_local=0xffffe245968c  local_int=101
  local_buf=0xffffe2459698  local_buf[0]=B
  &marker=0xffffe24596d4  marker=10
[enter] depth=2
  &local_int=0xffffe245965c  p_local=0xffffe245965c  local_int=102
  local_buf=0xffffe2459668  local_buf[0]=C
  &marker=0xffffe24596a4  marker=20
[enter] depth=3
  &local_int=0xffffe245962c  p_local=0xffffe245962c  local_int=103
  local_buf=0xffffe2459638  local_buf[0]=D
  &marker=0xffffe2459674  marker=30
[exit] depth=3
  &local_int=0xffffe245962c  p_local=0xffffe245962c  local_int=103
  local_buf=0xffffe2459638  local_buf[0]=D
  &marker=0xffffe2459674  marker=30
[exit] depth=2
  &local_int=0xffffe245965c  p_local=0xffffe245965c  local_int=102
  local_buf=0xffffe2459668  local_buf[0]=C
  &marker=0xffffe24596a4  marker=20
[exit] depth=1
  &local_int=0xffffe245968c  p_local=0xffffe245968c  local_int=101
  local_buf=0xffffe2459698  local_buf[0]=B
  &marker=0xffffe24596d4  marker=10
[exit] depth=0
  &local_int=0xffffe24596bc  p_local=0xffffe24596bc  local_int=100
  local_buf=0xffffe24596c8  local_buf[0]=A
  &marker=0xffffe2459704  marker=0
root@4ed0bb2e59f5:~/holbertonschool-low_level_programming/ai_memory_visualizer_valgrind_tracer-main/programs# valgrind ./stack
==8660== Memcheck, a memory error detector
==8660== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==8660== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
==8660== Command: ./stack
==8660== 
stack_example: recursion and stack frames
[enter] depth=0
  &local_int=0x1fff00030c  p_local=0x1fff00030c  local_int=100
  local_buf=0x1fff000318  local_buf[0]=A
  &marker=0x1fff000354  marker=0
[enter] depth=1
  &local_int=0x1fff0002dc  p_local=0x1fff0002dc  local_int=101
  local_buf=0x1fff0002e8  local_buf[0]=B
  &marker=0x1fff000324  marker=10
[enter] depth=2
  &local_int=0x1fff0002ac  p_local=0x1fff0002ac  local_int=102
  local_buf=0x1fff0002b8  local_buf[0]=C
  &marker=0x1fff0002f4  marker=20
[enter] depth=3
  &local_int=0x1fff00027c  p_local=0x1fff00027c  local_int=103
  local_buf=0x1fff000288  local_buf[0]=D
  &marker=0x1fff0002c4  marker=30
[exit] depth=3
  &local_int=0x1fff00027c  p_local=0x1fff00027c  local_int=103
  local_buf=0x1fff000288  local_buf[0]=D
  &marker=0x1fff0002c4  marker=30
[exit] depth=2
  &local_int=0x1fff0002ac  p_local=0x1fff0002ac  local_int=102
  local_buf=0x1fff0002b8  local_buf[0]=C
  &marker=0x1fff0002f4  marker=20
[exit] depth=1
  &local_int=0x1fff0002dc  p_local=0x1fff0002dc  local_int=101
  local_buf=0x1fff0002e8  local_buf[0]=B
  &marker=0x1fff000324  marker=10
[exit] depth=0
  &local_int=0x1fff00030c  p_local=0x1fff00030c  local_int=100
  local_buf=0x1fff000318  local_buf[0]=A
  &marker=0x1fff000354  marker=0
==8660== 
==8660== HEAP SUMMARY:
==8660==     in use at exit: 0 bytes in 0 blocks
==8660==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==8660== 
==8660== All heap blocks were freed -- no leaks are possible
==8660== 
==8660== For lists of detected and suppressed errors, rerun with: -s
==8660== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

At depth 0:

local_int = 100
local_buf[0] = A
marker = 0

At depth 1:

local_int = 101
local_buf[0] = B
marker = 10

At depth 2:

local_int = 102
local_buf[0] = C
marker = 20

Each one has a different address:

depth=0
0x1fff00030c

depth=1
0x1fff0002dc

depth=2
0x1fff0002ac

depth=3
0x1fff00027c

This shows each recursive call has its own memory region.

Error type: No error. The program correctly uses stack memory during recursion.
Memory object involved: Local stack variables (local_int, local_buf, and marker) in each recursive function frame.
Cause/lifetime behavior: Each recursive call creates a separate stack frame with its own variables. The variables remain valid while their function call is active and are automatically destroyed when the function returns. No memory is accessed after its lifetime ends, and no heap memory leaks occur.
