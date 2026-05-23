StackAllocator is one of many strategies to allocate a big chunk of [[memory]] from the heap and use it. It simply works like default stack.
## Methods:
- get() - to get a pointer to the instance of the class.
- allocate() - allocates sizeof(T) memory to the stack.
- deallocate() - deallocates memory form the stack.
- size() - returns a size of occupied memory on the stack.
## How does it work?
**Here is specified data for the next steps:**
T == int;
Header == char;
sizeof(T) == 4;
alignof(T) == 4;
sizeof(Header) == 1;
alignof(Header) == 1;
current stack pointer == 0x01;

StackAllocator is low-level mechanism, its task to allocate/deallocate memory and give control over it. It's used for big data or temporary data usage.

After first allocation for the T object, StackAllocator calls its constructor where it allocates a big amount of memory from the heap.
If during allocation process something gets wrong, it trows a std::bad_alloc() exception.

Then it starts internal allocation process for T object in `allocate()`:
1. It aligns a pointer to T type, so the address `0x01` in our case becomes `0x04`
2. advances stack pointer on size of T type. `0x04` will be `0x08` 
3. adds to the stack a Header type, that stores a range between previous and current pointer. Now the address will be `0x09`
4. returns allocated block of memory

When program done using some object from the StackAllocator it calls `deallocate()`:
1. gets Header object from getting back on sizeof(Header) from current stack pointer. `0x08 = 0x09 - 0x01`;
2. throws exception if header points to address that less than stack initial pointer
3. accesses header and sets current stack pointer to previous header top



