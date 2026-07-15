This project has been created as part of the 42 curriculum by asaunina.

# ft_printf

## Description

`ft_printf` is a reimplementation of the standard C `printf()` function. The goal is to understand variadic functions in C and produce a library that mimics the original `printf()` behavior.

The library is compiled as `libftprintf.a` and can be linked into any C project.

### Supported conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in hexadecimal lowercase |
| `%X` | Prints a number in hexadecimal uppercase |
| `%%` | Prints a literal percent sign |

## Instructions

### Compilation

```bash
make
```

This produces `libftprintf.a` at the root of the repository.

### Linking with project

```bash
cc your_file.c -L. -lftprintf -o your_program
```

### Makefile rules

| Rule | Description |
|------|-------------|
| `make` / `make all` | Compile the library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the library |
| `make re` | Recompile everything from scratch |

## Algorithm and Data Structure

### Architecture

The library is split into two files:

- `ft_printf.c` — contains `ft_printf()` and the internal `format()` dispatcher
- `ft_printf_utils.c` — contains one helper function per conversion type

### How it works

`ft_printf` iterates through the format string character by character. When it encounters a `%`, it advances to the next character and passes it to `format()`, which dispatches to the appropriate output function based on the conversion specifier.

`va_list` is passed by pointer (`va_list *`) to `format()` to ensure that `va_arg` advances the argument list correctly across function calls. Passing by value would cause the argument position to reset on each call.

Each helper function returns the number of bytes written, which `ft_printf` accumulates and returns as the total character count — matching the behavior of the original `printf()`.

### Why no buffer management

The original `printf()` buffers output internally before flushing. This implementation calls `write()` directly for each character, which is simpler and sufficient for the scope of this project.

## Resources

- [man 3 printf](https://linux.die.net/man/3/printf) — official printf documentation
- [man 3 stdarg](https://linux.die.net/man/3/stdarg) — variadic functions: va_start, va_arg, va_end
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf) — format specifier reference

### AI usage

Claude (claude.ai) was used during this project as a learning aid — to discuss concepts, identify bugs, and ask guiding questions. Claude did not provide complete implementations. All code was written and understood by the author.

Chat GPT was used during this project for the same reason.