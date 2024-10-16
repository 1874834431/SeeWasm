for dir_file in *
do
   echo "$dir_file"
   if [ -d "$dir_file" ]; then
      # 如果是子目录，则进入子目录
      cd "$dir_file"
      
      # 使用find命令查找当前子目录下的所有.wasm文件
      find . -name "*.wasm" -type f | while read file
      do
         # 对每个.wasm文件执行wasm2wat转换
         wat=".wat"
         echo $file
         wasm2wat "$file" -o "${file%.wasm*}${wat}"
      done
      
      # 返回到上级目录
      cd ..
   fi
done
