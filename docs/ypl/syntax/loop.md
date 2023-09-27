# ypl loop

## Loop

### while

`while` is a keyword that loops while the condition is true.

```ypl
while true:
    print("Hello, World!")
```

### for

`for` is a keyword that loops for the given range.

```ypl
for i in 0~10:
    print(i)
```

### continue

`continue` is a keyword that skips the current iteration.

```ypl
for i in 0~10:
    if i == 5:
        continue
    print(i)
```

### break

`break` is a keyword that breaks the loop.

```ypl
for i in 0~10:
    if i == 5:
        break
    print(i)
```
