# nstdlib

## Stack
### Description

This implementation aims to provide a contiguous, stack allocated data structure implementing the FIFO data access pattern. The size of this data structure is passed as a template parameter in order to accomodate this. A future addition to this class could take inspiration from the shortAlloc allocator written by Howard Hinnit, which provides a stack allocation unless the container exceeds some capacity, where it is then mapped into heap memory instead.

## Circular Buffer
### Description

The circular buffer features a stack allocated contiguous sequence of elements. It takes a template parameter n to determine capacity at compile time. This structure will be most useful to handle large amounts of reads and writes. The nature of the structure is that reads and writes take place in separate locations, meaning that with a double lock approach higher concurrency can be achieved than structures where read and write locations overlap or are ambiguous. The locking mechanism and general thread safety of this data structure is not yet implemented but should be, as it fits concurrent problems well and should prove useful in the future.