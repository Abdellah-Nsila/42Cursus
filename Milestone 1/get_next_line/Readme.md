+------------------------------------------------------+
|                       Application                    |
|                  (User Space - RAM)                  |
|                                                      |
|  +----------------------------------------------+    |
|  | int fd = open("data.txt", O_RDONLY);         |    |
|  |                                              |    |
|  | read(fd, buffer, size);                      |    |
|  |                                              |    |
|  | close(fd);                                   |    |
|  +----------------------------------------------+    |
|                                                      |
|   CPU executes in user mode                          |
+------------------------------------------------------+

                  |
                  |  1. **open() system call**  |
                  V
                  
+------------------------------------------------------+
|                      Kernel Transition               |
|                    (CPU switches to Kernel Mode)     |
+------------------------------------------------------+

                  |
                  |  2. **File Descriptor Allocation**  |
                  V

+------------------------------------------------------+
|        Process File Descriptor Table (Kernel RAM)    |
|                                                      |
|  +-------------------------------+                   |
|  | File Descriptor: fd = 3       |                   |
|  | Points to System-Wide Open    |                   |
|  | File Table entry for "data.txt"                   |
|  +-------------------------------+                   |
|                                                      |
| Managed by OS                                        |
+------------------------------------------------------+

                  |
                  |  3. **System-Wide Open File Table Entry**  |
                  V

+-------------------------------------------------------+
|         System-Wide Open File Table (Kernel RAM)      |
|                                                       |
|  +------------------------------------------------+   |
|  | "data.txt"                                      |  |
|  | - Points to inode in Disk                       |  |
|  | - File Offset: 0 (start of file)                |  |
|  | - Permissions: Read-Only                        |  |
|  +------------------------------------------------+   |
|                                                       |
| OS tracks each open file here                         |
+-------------------------------------------------------+

                  |
                  |  4. **Inode Retrieval**  |
                  V

+------------------------------------------------------+
|                    Disk Storage                      |
|                     (File Inode)                     |
|                                                      |
|  +-------------------------+                         |
|  | Inode for "data.txt"    |                         |
|  | - Metadata (size, type) |                         |
|  | - Points to data blocks |                         |
|  +-------------------------+                         |
|                                                      |
|  OS locates inode on disk                            |
+------------------------------------------------------+

                  |
                  |  5. **Read System Call**  |
                  V

+------------------------------------------------------+
|              System Call to Read Data                |
|              (CPU in kernel mode)                    |
+------------------------------------------------------+

                  |
                  |  6. **Locate Data Blocks**  |
                  V

+------------------------------------------------------+
|                    Disk Storage                      |
|                  (Data Blocks on Disk)               |
|                                                      |
|  +-------------------------+                         |
|  | Block 1: "file data..." |                         |
|  | Block 2: "continues..." |                         |
|  +-------------------------+                         |
|                                                      |
|  OS reads blocks and transfers to RAM                |
+------------------------------------------------------+

                  |
                  |  7. **Transfer Data to Buffer**  |
                  V

+------------------------------------------------------+
|               Kernel Buffer in RAM                   |
|                                                      |
|  +-------------------------------+                   |
|  | Buffer for "data.txt"         |                   |
|  | Loaded with file data from    |                   |
|  | disk                          |                   |
|  +-------------------------------+                   |
|                                                      |
|  Data transferred by OS                              |
+------------------------------------------------------+

                  |
                  |  8. **Update File Offset in System-Wide Table**  |
                  V

+-------------------------------------------------------+
|        System-Wide Open File Table (Kernel RAM)       |
|                                                       |
|  +------------------------------------------------+   |
|  | "data.txt"                                      |  |
|  | - Updated File Offset                           |  |
|  | - Now points to next unread byte                |  |
|  +------------------------------------------------+   |
|                                                       |
|  OS tracks read progress                              |
+-------------------------------------------------------+

                  |
                  |  9. **Return Data to User Buffer**  |
                  V

+------------------------------------------------------+
|                 Application Buffer                   |
|                   (User Space - RAM)                 |
|                                                      |
|  +-------------------------------+                   |
|  | Buffer for "data.txt"         |                   |
|  | Holds data just read from     |                   |
|  | kernel buffer                 |                   |
|  +-------------------------------+                   |
|                                                      |
|  CPU switches back to user mode                      |
+------------------------------------------------------+

                  |
                  | 10. **close() system call**        |
                  V

+------------------------------------------------------+
|                      Kernel Transition               |
|                    (CPU switches to Kernel Mode)     |
+------------------------------------------------------+

                  |
                  | 11. **Release File Descriptor**  |
                  V

+------------------------------------------------------+
|         Process File Descriptor Table (Kernel RAM)   |
|                                                      |
|  +-------------------------------+                   |
|  | FD entry for "data.txt"       |                   |
|  | - Entry removed               |                   |
|  +-------------------------------+                   |
|                                                      |
| OS frees FD for reuse                                |
+------------------------------------------------------+

                  |
                  | 12. **Cleanup System-Wide Open File Table**  |
                  V

+-------------------------------------------------------+
|         System-Wide Open File Table (Kernel RAM)      |
|                                                       |
|  +------------------------------------------------+   |
|  | "data.txt" entry removed if no longer used      |  |
|  | by other processes                              |  |
|  +------------------------------------------------+   |
|                                                       |
| OS clears entry if unused                             |
+-------------------------------------------------------+

# Explanation of Each Step

    1. Application/User Space (Steps 1, 9): The application initiates file operations in user space, which then trigger system calls. Upon completion, the read data is returned to the application’s buffer.

    2. Kernel Mode Transitions (Steps 2, 10): Each system call (open, read, close) requires a CPU mode switch from user mode to kernel mode for safe OS handling.

    3. Process File Descriptor Table (Step 3, 11): The OS manages a separate file descriptor table for each process. Entries here point to the System-Wide Open File Table and are released upon closing the file.

    4. System-Wide Open File Table (Steps 4, 8, 12): This global table in kernel memory tracks open files across all processes, managing the inode, file offset, and permissions.

    5. Inode and Data Blocks on Disk (Steps 5-7): The OS accesses the inode and retrieves file data from disk storage, copying it to a kernel buffer and then to user space.

This step-by-step illustration shows the interaction between application code, OS resources, and memory areas (user and kernel), highlighting the roles of the CPU and OS at each stage in a detailed yet structured manner.


Example 1:

+--------------------+             +---------------------------+              +---------------------+
| Process 1         |             | Process 2                 |              | Process 3           |
| ----------------- |             | ------------------------- |              | -----------------   |
| FD 0 -> STDIN     |             | FD 0 -> STDIN             |              | FD 0 -> STDIN       |
| FD 1 -> STDOUT    |             | FD 1 -> STDOUT            |              | FD 1 -> STDOUT      |
| FD 2 -> STDERR    |             | FD 2 -> STDERR            |              | FD 2 -> STDERR      |
| FD 3 -> File A    |-------------| FD 3 -> File B            |--------------| FD 3 -> File A      |
+--------------------+             +---------------------------+              +---------------------+
              \                               /                                   /
               \                             /                                   /
                \                           /                                   /
                 \                         /                                   /
                  \                       /                                   /
                   \                     /                                   /
                    \                   /                                   /
                  +-----------------------------------------------------------+
                  |                System-Wide Open File Table                |
                  |-----------------------------------------------------------|
                  | FD (3) -> File A (Offset, Permissions, Inode Info)        |
                  | FD (4) -> File B (Offset, Permissions, Inode Info)        |
                  | FD (5) -> File C (Offset, Permissions, Inode Info)        |
                  +-----------------------------------------------------------+
                                      |
                                      |
                                      |
                           +-----------------------------+
                           |        Inode Table          |
                           |-----------------------------|
                           | Inode for File A            |
                           | Inode for File B            |
                           | Inode for File C            |
                           +-----------------------------+



Example 2:

+------------------+       +-----------------------+       +-----------------------------+
|  Application     | ----> | File Descriptor Table | ----> | System-Wide Open File Table |
| (User Space)     |       | (Per Process, RAM)    |       | (Kernel Memory, RAM)        |
+------------------+       +-----------------------+       +-----------------------------+
                                                                    |
                                                                    |
                                                            +----------------+
                                                            |   Inode Table  |
                                                            | (Disk, Cached) |
                                                            +----------------+
                                                                    |
                                                                    |
                                                            +----------------+
                                                            |   Data Blocks  |
                                                            | (Disk Storage) |
                                                            +----------------+
                                                            
