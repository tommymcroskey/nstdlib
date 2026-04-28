# nstdlib

## Stack
### Purpose

This implementation aims to provide a contiguous, stack allocated data structure implementing the FIFO data access pattern. The size of this data structure is passed as a template parameter in order to accomodate this. A future addition to this class could take inspiration from the shortAlloc allocator written by Howard Hinnit, which provides a stack allocation unless the container exceeds some capacity, where it is then mapped into heap memory instead.
