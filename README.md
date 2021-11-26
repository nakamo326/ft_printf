# ft_printf
### recode of libc's printf



## Installation

```bash
git clone git@github.com:nakamo326/ft_printf.git
cd ft_printf
make
```

## Feature
- Conversion specifiers
  - d, i as integer
  - %, C as char
  - s as string
  - u as unsigned int
  - p as pointer
  - x, X as unsigned hexadecimal

- Flags
  - "-" as left justify
  - "0" as zero padded
  - Field width and Precision
  - "*" for field width and precision

  this printf doesn't manage line buffer.

