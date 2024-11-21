#!/bin/bash

# 檢查是否有提供參數
if [ $# -ne 1 ]; then
    echo "Usage: $0 <llvm-ir-file>"
    exit 1
fi

# 取得輸入的 LLVM IR 檔案路徑
input_file=$1

# 檢查檔案是否存在
if [ ! -f "$input_file" ]; then
    echo "Error: File '$input_file' not found!"
    exit 1
fi

# 檔案名稱處理
filename=$(basename -- "$input_file")
basename_noext="${filename%.*}"

# 編譯 LLVM IR 檔案為物件檔
llc -filetype=obj "$input_file" -o "${basename_noext}.o"
if [ $? -ne 0 ]; then
    echo "Error: Failed to compile LLVM IR to object file."
    exit 1
fi

# 連結物件檔案產生執行檔
clang "${basename_noext}.o" -o "${basename_noext}"
if [ $? -ne 0 ]; then
    echo "Error: Failed to link object file to binary."
    exit 1
fi

echo "Successfully created binary: ${basename_noext}"
