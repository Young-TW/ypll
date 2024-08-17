# ypl

ypl - Young's Programming language 是一個程式語言，
希望擁有更簡潔的語法的同時不犧牲效能。

ypll 是一個 LLVM 前端處理器，
負責將 ypl 語言轉換為 LLVM IR，
接著交由 LLVM 做最佳化並且處理後端生成二進位檔案。

ypl - Young's programming language.
It is desirable to have a more concise syntax without sacrificing performance.

ypll is a LLVM IR frontend,
make ypl language into LLVM IR,
then use LLVM will optimize the IR and generate binary code.

## Expectation

1. Easy to debug
2. Easy to make big project
3. Easy to read
4. Minimize the use of parentheses
5. Do not use semicolons
6. Fast execute time
7. Less memory usage
8. Memeory safety
9. No hidden control flow
10. No hidden type conversion
11. No hidden memory allocation
12. No hidden memory deallocation

## property

- Strong Type
- Static Type
- Compile Language

## Feature

- [ ] Syntax Design
    - [ ] function
    - [ ] varible
    - [ ] operator
    - [ ] flow control
    - [ ] standard library
    - [ ] standard input
    - [ ] standard output
    - [ ] comment

- [ ] Compiler
    - [ ] Minimal Feature
        - [ ] preprocessor
        - [ ] parser
        - [ ] main function
        - [ ] return
        - [ ] print
    - [ ] Basic Feature
        - [ ] varible types
        - [ ] standard library (io, data scructure, algorithm)
        - [ ] debugger
        - [ ] flow control
            - [ ] if else
            - [ ] loop
    - [ ] Advanced Feature
        - [ ] function
    - [ ] Final Feature
        - [ ] self-hosting

## Docs

All Docs and detail are in the `/docs` folder
