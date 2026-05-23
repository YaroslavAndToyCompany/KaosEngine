## Alignment
It is preferred to a align the data if you decided to take control over memory. On some systems unaligned data can cause worse performance, in some cases it even can crush the program.
### How to align data?
You just need to keep your data on addresses that is a multiple of it's data type size.
By that I mean that, for example, we have an int data type that takes 4 bytes (it can vary depending on system) to correctly align it we need to place it on addresses `0x00`, `0x04` `0x08` or `0x0c`. For now you can think of it as `(curAddr + sizeof(T)) - ((curAddr + sizeof(T)) % alignof(T))` or `(0x02 + 4) - ((0x02 + 4) % 4) = 0x04`. If we need to align double type data with 8 byte size you should place it in `0x00`, `0x08`, `0x10`.

Because operator % is quite slow, we're using bit mask (unaligned address + alignment - 1) & ~(alignment). There is function `alignUp(addr, alignment)` in our engine's code that implements this mask. So here is example:
`alignedAddr = alignUp(unalignedAddr, alignof(T))`
`0x04 = alignUp(0x01, 4)` another examples: `0x08 = alignUp(0x01, 8)` | `0x00 = alignUp(0x00, 8)`.

Structs and classes also internally align it's data so we don't need to care about it. But you should know how to write fields properly to avoid bigger memory usage by structs/classes.
For example double == 8 and int == 4 bytes:
```cpp
struct 
{
	double a;
	int b;
}
```
takes 12 bytes
d: double. i: int. x: empty.
Representation in memory: `|d|d|d|d|d|d|d|d|i|i|i|i|`

```cpp
struct 
{
	int b;
	double a;
}
```
takes 16 bytes
Representation in memory: `|i|i|i|i|x|x|x|x|d|d|d|d|d|d|d|d|`
here was used alignment so int placed in 0x00 and double in 0x08 which is correct.

The rule of the thumb here is to place your types from big alignment to small.