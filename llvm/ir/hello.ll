@string = private constant [15 x i8] c"Hello, world!\0A\00"

declare i32 @puts(i8*)

define i32 @main() {
  %address = getelementptr [15 x i8], [15 x i8]* @string, i64 0, i64 0
  call i32 @puts(i8* %address)
  ret i32 0
}
