# Makefile for compiling test1-1 and test1-2

CC = gcc        # 使用 gcc 编译器
CFLAGS = -Wall  # 编译时的警告选项
TARGETS = test1-1 test1-2  # 目标文件

# 默认目标
all: $(TARGETS)

# 生成 test1-1 可执行文件
test1-1: test1-1.c
	$(CC) $(CFLAGS) -o test1-1 test1-1.c

# 生成 test1-2 可执行文件
test1-2: test1-2.c
	$(CC) $(CFLAGS) -o test1-2 test1-2.c

# 清理目标文件
clean:
	rm -f $(TARGETS)
