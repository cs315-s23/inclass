#### Lab<br>Wed. Mar. 8

# memory & project04

## The RISC-V Instruction Set
### What you need to support

* `lb/sb` - (1 byte)
* `lw/sw` - (4 bytes)
* `ld/sd` - (8 bytes)

Some stuff to point out:

* Base: simply `rs1`
* Width: encoded in `funct3`
* Offset: sign-extended *12-bit* immediate value.
  - how you get this differs between loads & stores

#### Loads vs. Stores
You'll have to handle each a bit differently. For some more granularity,
see <u>section 2.6 on page 24</u>. Fundamentally, it's important to note that:

##### Loads are `I-type` instructions
##### Stores are `S-type` instructionnotes


## Memory Operations
### Getting to the Right Place
`base` - base address

`offset` - *byte* offset

```c
void *base = ...;
int32_t offset = 8;

void *p = base + offset 
```

BAD
```c
// imagine you are *trying* to implement sw
// you know sw must touch 4 bytes (32bits)
int32_t *base;
int32_t offset = 8;

int32_t *p = base + offset // 2nd integer or the 8th?
// the eighth!!
```
GOOD

```c
// imagine you are *trying* to implement sw
// you know sw must touch 4 bytes (32bits)
int64_t base;
int32_t offset = 8;

int32_t *p = (int32_t*)(base + offset) // 2nd integer or the 8th?
// the eighth!!
```

### Memory Access
It starts with a pointer to the right place in memory.
```c
void *p = ... // pretend its right
```
And what do you do with it?

If the instruction is a:
* `lw/sw` - you need to tell the c compiler: *this pointer touches words!*
* `ld/sd` - you need to tell the c compiler: *this pointer touches doubles!*
* etc.

For example:
```c
// To grab a byte:
// you need a pointer to bytes... 
char* byte_pointer = (char*)p;
```

```c
void *p;

int8_t *bp = (int8_t*)p;

int8_t byte = '?';

// Load
byte = *bp;
// Store
*bp = byte;
```
