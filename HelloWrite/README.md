# Using `write()` instead of `printf` in C

A quick reference on writing output with the low-level `write()` syscall.

## What is `write()`?

`write()` is a POSIX **system call** that sends raw bytes directly to a file descriptor. Unlike `printf`, it does no formatting and no buffering.

```c
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
```

- `fd` — file descriptor to write to (1 = stdout, 2 = stderr)
- `buf` — pointer to the bytes you want to write
- `count` — how many bytes to write
- **returns** — number of bytes actually written, or `-1` on error

## Hello, world!

```c
#include <unistd.h>

int main(void)
{
    write(1, "Hello, world!\n", 14);
    return (0);
}
```

`1` is stdout, `"Hello, world!\n"` is the buffer, and `14` is the exact byte count (13 characters + the newline).

## Gotchas

- You must pass the **exact byte length**. Too long reads past your buffer; too short cuts the output.
- No format specifiers — `write()` only sends raw bytes.
- `\0` is *not* written and *not* needed — `write()` uses `count`, not a null terminator.
