# Aliasing_Example.c 

1. Program Starts

Only main() exists.
Stack
+-------------------------------+
| main()                        |
|-------------------------------|
| a = NULL                      |
| b = NULL                      |
| n = 5                         |
+-------------------------------+

Heap
(empty) - no current memory allocation

2. Make_Numbers(5) is called 

As 5 is the value of n - placed ito the function call.

Stack
+-------------------------------+
| make_numbers()                |
|-------------------------------|
| n = 5                         |
| i = 0                         |
| arr = NULL                    |
+-------------------------------+
| main()                        |
|-------------------------------|
| a = NULL                      |
| b = NULL                      |
| n = 5                         |
+-------------------------------+

Heap
(empty) - no current memory allocation

3. Malloc used (succeed)

Suppose malloc() returns address 0x1000.

Stack
+-------------------------------+
| make_numbers()                |
|-------------------------------|
| arr -----------+              |
+----------------|--------------+
                 |
                 v

Heap
0x1000
+------+------+------+------+------+
| ??? | ??? | ??? | ??? | ??? |
+------+------+------+------+------+

The heap contains five uninitialized integers.

4. After loop

for (i = 0; i < 5; i++)
    arr[i] = i * 11;

Heap now contains

Heap
0x1000

+------+------+------+------+------+
|  0  | 11 | 22 | 33 | 44 |
+------+------+------+------+------+

5. return arr

The pointer value 0x1000 is returned.

The make_numbers() stack frame disappears.

Stack
+-------------------------------+
| main()                        |
|-------------------------------|
| a = 0x1000                    |
| b = NULL                      |
| n = 5                         |
+-------------------------------+

Heap
0x1000

+------+------+------+------+------+
| 0 | 11 | 22 | 33 | 44 |
+------+------+------+------+------+

The array is still alive because it lives on the heap.

6. b = a

Now both pointers hold exactly the same address.

Stack

+-------------------------------+
| main()                        |
|-------------------------------|
| a -----------+                |
|              |                |
| b -----------|----------------+
|              |                |
| n = 5        |                |
+--------------|----------------+
               |
               v

Heap
0x1000

+------+------+------+------+------+
| 0 | 11 | 22 | 33 | 44 |
+------+------+------+------+------+

a ----\
       \
        > same array
       /
b ----/

There is only one array.
There are two pointers referring to it.

7. First printf
printf("%d %d", a[2], b[2]);

Both pointers read

array[2] = 22
Memory is unchanged.

8. free(a)

The heap object's lifetime ends.

Stack

+-------------------------------+
| main()                        |
|-------------------------------|
| a = 0x1000                    |
| b = 0x1000                    |
| n = 5                         |
+-------------------------------+

Heap
memory at 0x1000 has been released

Important:
The pointers still contain the address.
The object no longer exists.
Both pointers are now dangling pointers.

a ----\
       \
        X (dead object)
       /
b ----/

9. printf("%p", b)

b == 0x1000

The pointer value still exists.
The object does not.
Memory map
Stack

a = 0x1000
b = 0x1000

Heap
(no valid object at 0x1000)

10. printf("%d", b[2])

This attempts

*(b + 2)

which means
address = 0x1000 + 2*sizeof(int)
There is no object there anymore.

b
 |
 v

0x1000

X
freed memory
This is undefined behavior.

11. b[3] = 1234

This attempts to write into freed memory.
0x1000
X
freed block

attempted write

Again, this is undefined behavior.

Valgrind typically reports:
"Invalid write of size 4"

12. Memory was already freed

Because the memory was already freed,

free(a);
there is no memory leak.
The only problem is using the dangling pointer afterward.

# Crash_example.c

1. Program starts

Only the main() stack frame exists.

Stack
+--------------------------------+
| main()                         |
|--------------------------------|
| nums = NULL                    |
| n = 0                          |
+--------------------------------+

Heap
(empty)
nums points to nothing (NULL).
No heap memory has been allocated.

2. Call allocate_numbers(0)
A new stack frame is created.

Stack
+--------------------------------+
| allocate_numbers()             |
|--------------------------------|
| n = 0                          |
| arr = NULL                     |
| i = 0                          |
+--------------------------------+
| main()                         |
|--------------------------------|
| nums = NULL                    |
| n = 0                          |
+--------------------------------+

Heap
(empty)

3. n <= 0

The function executes:
if (n <= 0)
    return NULL;

No allocation occurs.
Stack
+--------------------------------+
| allocate_numbers()             |
|--------------------------------|
| returns NULL                   |
+--------------------------------+
| main()                         |
|--------------------------------|
| nums = NULL                    |
| n = 0                          |
+--------------------------------+

Heap
(empty)

4. Return to main()

The allocate_numbers() stack frame is destroyed.
The returned pointer (NULL) is assigned to nums.

Stack
+--------------------------------+
| main()                         |
|--------------------------------|
| nums = NULL                    |
| n = 0                          |
+--------------------------------+

Heap
(empty)

At this point:
nums
 |
 v
NULL

5. Execute nums[0] = 42

This statement is equivalent to
*(nums + 0) = 42;
Since
nums == NULL

the CPU attempts to write to address 0x0.

Stack
+--------------------------------+
| main()                         |
|--------------------------------|
| nums = NULL                    |
| n = 0                          |
+--------------------------------+

Heap
(empty)
Attempted write

NULL
 |
 v
0x00000000

This address is not mapped into the process.
The operating system immediately raises:
Segmentation fault (SIGSEGV)

6. Program terminates

Execution stops immediately.
The following lines are never executed:
printf("nums[0]=%d\n", nums[0]);
free(nums);

# heap_example.c

1. Program starts

Only main() is on the stack.

Stack
+-------------------------------------------+
| main()                                    |
|-------------------------------------------|
| alice = NULL                              |
| bob   = NULL                              |
+-------------------------------------------+

Heap
(empty)
No heap objects exist.

2. alice = person_new("Alice", 30)

A new stack frame is created.
Stack
+-------------------------------------------+
| person_new()                              |
|-------------------------------------------|
| name --> "Alice" (string literal)         |
| age = 30                                  |
| len = 0                                   |
| i = 0                                     |
| p = NULL                                  |
+-------------------------------------------+
| main()                                    |
| alice = NULL                              |
| bob = NULL                                |
+-------------------------------------------+
Notice that "Alice" is a string literal, stored in the program's read-only data section—not on the heap.

3. Allocate the Person
p = malloc(sizeof(Person));

Assume:
Person object → 0x1000
Stack

p
 |
 v
Heap

0x1000
+----------------------+
| name = ?             |
| age  = ?             |
+----------------------+
The structure exists but its fields are not initialized yet.

4. Allocate the name
p->name = malloc(len + 1);

Suppose:

name buffer → 0x2000
Heap

0x1000
+----------------------+
| name ----+           |
| age=?    |           |
+----------|-----------+
           |
           v
0x2000
+----------------+
| ? ? ? ? ? ?    |
+----------------+
Two heap objects now exist

5. Copy "Alice"

After the loop:

Heap
0x1000
+----------------------+
| name ----+           |
| age =30  |           |
+----------|-----------+
           |
           v
0x2000
+---+---+---+---+---+----+
| A | l | i | c | e | \0 |
+---+---+---+---+---+----+

person_new() returns 0x1000.

6. Return to main

The person_new() stack frame disappears.
Stack

+-------------------------------------------+
| main()                                    |
|-------------------------------------------|
| alice -----------+                        |
| bob = NULL       |                        |
+------------------|------------------------+
                   |
                   v
Heap
0x1000 (Person)
+----------------------+
| name ----+           |
| age =30  |           |
+----------|-----------+
           |
           v
0x2000
"Alice"

7. Create bob

Exactly the same process occurs.

Assume

Person → 0x3000
Name   → 0x4000
Stack

alice ----------------------+
                            |
bob ------------------+     |
                      |     |
                      v     v

Heap

0x1000                 0x3000
+------------+         +------------+
| name --+   |         | name --+   |
| age 30 |   |         | age 41 |   |
+--------|---+         +--------|---+
         |                      |
         v                      v

0x2000                 0x4000

"Alice"                "Bob"
8. Print both people

Nothing changes.
Both structures and both strings are still alive.

9. free(bob->name)

The "Bob" string is destroyed.

Stack
alice ------------+
                  |
bob --------+     |
             |    |
             v    v

Heap
0x1000              0x3000
+----------+        +----------+
| name ----|------X | name=0x4000
| age=30   |        | age=41
+----------+        +----------+

0x2000
"Alice"
0x4000
(freed)

Notice:
bob->name still contains the old address, but the object no longer exists.
It is now a dangling pointer.

10. free(bob)

Now the Person structure is also destroyed.

Stack
alice ------------+
                  |
bob = dangling ---X

Heap
0x1000
+----------------+
| name ->0x2000  |
| age=30         |
+----------------+

0x2000
"Alice"

0x3000
(freed)

0x4000
(freed)

Everything associated with Bob has been released.

11. person_free_partial(alice)

The function executes
free(p);

Only the structure is freed.

Stack
alice = dangling

Heap
0x1000
(freed)

0x2000
+----------------+
| A l i c e \0   |
+----------------+

The "Alice" string still exists.
Nothing points to it anymore.

12. Program exits

Remaining heap:
0x2000
+----------------+
| A l i c e \0   |
+----------------+
This block is unreachable.
Valgrind reports it as definitely lost.

# stack_example.c
1. Program starts

Only main() exists.

Stack (top)

+-------------------------------+
| main()                        |
+-------------------------------+

Heap
(empty)
There are no heap allocations.

2. walk_stack(0)

A new stack frame is pushed.
Stack (top)

+--------------------------------------+
| walk_stack(depth=0)                  |
|--------------------------------------|
| depth = 0                            |
| max_depth = 3                        |
| marker = 0                           |
+--------------------------------------+

+--------------------------------------+
| main()                               |
+--------------------------------------+

Heap
(empty)

3. dump_frame("enter",0)

Another function call creates another frame.
Stack

+--------------------------------------+
| dump_frame(depth=0)                  |
|--------------------------------------|
| local_int = 100                      |
| local_buf = {'A','\0',...}           |
| p_local -----------+                 |
+--------------------|-----------------+
                     |
                     v
               local_int

+--------------------------------------+
| walk_stack(depth=0)                  |
| marker = 0                           |
+--------------------------------------+
+--------------------------------------+
| main()                               |
+--------------------------------------+
Pointer relationship
p_local
   │
   ▼
local_int

No aliases exist because only one pointer refers to local_int.

4. dump_frame() returns
Its stack frame disappears.

Stack

+--------------------------------------+
| walk_stack(depth=0)                  |
| marker = 0                           |
+--------------------------------------+

+--------------------------------------+
| main()                               |
+--------------------------------------+

Everything that belonged to dump_frame() is gone.
The following objects no longer exist:

local_int
local_buf
p_loca

l5. Recursive call walk_stack(1)

A second recursive frame is pushed.

Stack (top)

+--------------------------------------+
| walk_stack(depth=1)                  |
| marker = 10                          |
+--------------------------------------+

+--------------------------------------+
| walk_stack(depth=0)                  |
| marker = 0                           |
+--------------------------------------+

+--------------------------------------+
| main()                               |
+--------------------------------------+

Notice:

There are now two completely different variables named marker.
depth 1 marker = 10
depth 0 marker = 0
They occupy different addresses.

6. Continue recursion

Eventually the stack becomes
Stack (top)
+--------------------------------------+
| walk_stack(depth=3)                  |
| marker = 30                          |
+--------------------------------------+
+--------------------------------------+
| walk_stack(depth=2)                  |
| marker = 20                          |
+--------------------------------------+
+--------------------------------------+
| walk_stack(depth=1)                  |
| marker = 10                          |
+--------------------------------------+
+--------------------------------------+
| walk_stack(depth=0)                  |
| marker = 0                           |
+--------------------------------------+
+--------------------------------------+
| main()                               |
+--------------------------------------+

Each recursive call has completely separate local variables.

7. Dump_frame(depth=3)

Inside the deepest recursion:
Stack
+--------------------------------------+
| dump_frame(depth=3)                  |
|--------------------------------------|
| local_int = 103                      |
| local_buf = {'D','\0'}               |
| p_local -----------+                 |
+--------------------|-----------------+
                     |
                     ▼
                 local_int

+--------------------------------------+
| walk_stack(depth=3)                  |
| marker = 30                          |
+--------------------------------------+
+--------------------------------------+
| walk_stack(depth=2)                  |
+--------------------------------------+
+--------------------------------------+
| walk_stack(depth=1)                  |
+--------------------------------------+
+--------------------------------------+
| walk_stack(depth=0)                  |
+--------------------------------------+

Again,

p_local
   │
   ▼
local_int

8. Returning from recursion

After walk_stack(3) finishes:

Stack
+--------------------------------------+
| walk_stack(depth=2)                  |
| marker = 20                          |
+--------------------------------------+
+--------------------------------------+
| walk_stack(depth=1)                  |
+--------------------------------------+
+--------------------------------------+
| walk_stack(depth=0)                  |
+--------------------------------------+
+--------------------------------------+
| main()                               |
+--------------------------------------+

The entire depth=3 frame has disappeared.

9. Program finishes

Eventually every recursive frame is popped.

Stack

+-------------------------------+
| main()                        |
+-------------------------------+
↓
(empty after program exit)
